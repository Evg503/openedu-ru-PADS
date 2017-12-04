#include "openedu.hpp"
#include <vector>
#include <deque>
#include <array>
#include <unordered_map>
#include <algorithm>

openedu_in in;
openedu_out out;

struct VM
{
  typedef unsigned short num;
  struct Command;
  std::deque<num> queue;
  std::vector<num> r;
  std::unordered_map<std::string, int> labels;
  std::vector<Command*> prog;
  int ip;
  bool is_running;
  void run()
  {
    r.resize(26);
    is_running = true;
    ip = 0;
    for(auto cmd: prog)
      cmd->link(this);
    while(is_running)
    {
      prog[ip]->exec(this);
      ++ip;
    }
  }
  num get()
  {
    num a = queue.front();
    queue.pop_front();
    return a;
  }
  void put(num a)
  {
    queue.push_back(a);
  }

  struct Command
  {
    virtual void exec(VM* vm)=0;
    virtual void link(VM* vm){}
  };
  struct Nop:Command
  {
    virtual void exec(VM* vm) override
    {

    }
  };

  struct Plus:Command
  {
    virtual void exec(VM* vm) override
    {
      num a = vm->get();
      num b = vm->get();
      num c = a+b;
      vm->put(c);
    }
  };
  struct Minus:Command
  {
    virtual void exec(VM* vm) override
    {
      num a = vm->get();
      num b = vm->get();
      num c = a-b;
      vm->put(c);
    }
  };
  struct Mul:Command
  {
    virtual void exec(VM* vm) override
    {
      num a = vm->get();
      num b = vm->get();
      num c = a*b;
      vm->put(c);
    }
  };
  struct Div:Command
  {
    virtual void exec(VM* vm) override
    {
      num a = vm->get();
      num b = vm->get();
      num c = b?a/b:0;
      vm->put(c);
    }
  };
  struct Mod:Command
  {
    virtual void exec(VM* vm) override
    {
      num a = vm->get();
      num b = vm->get();
      num c = b?a%b:0;
      vm->put(c);
    }
  };
  struct SetRegister:Command
  {
    int r;
    SetRegister(int r):r(r){}
    virtual void exec(VM* vm) override
    {
      num a = vm->get();
      vm->r[r] = a;
    }
  };

  struct GetRegister:Command
  {
    int r;
    GetRegister(int r):r(r){}
    virtual void exec(VM* vm) override
    {
      num a = vm->r[r];
      vm->put(a);
    }
  };
  struct Print:Command
  {
    int r;
    virtual void exec(VM* vm) override
    {
      num a = vm->get();
      out.print_i32(a).print("\n");
    }
  };
  struct PrintRegister:Command
  {
    int r;
    PrintRegister(int r):r(r){}
    virtual void exec(VM* vm) override
    {
      num a = vm->r[r];
      out.print_i32(a).print("\n");
    }
  };
  struct PrintChar:Command
  {
    int r;
    virtual void exec(VM* vm) override
    {
      num a = vm->get();
      out.print_char(a);
    }
  };
  struct PrintCharRegister:Command
  {
    int r;
    PrintCharRegister(int r):r(r){}
    virtual void exec(VM* vm) override
    {
      num a = vm->r[r];
      out.print_char(a);
    }
  };
  struct Label:Command
  {
    Label(VM&vm, std::string label)
    {
      vm.labels[label]= vm.prog.size();
    }
    virtual void exec(VM* vm) override
    {
    }
  };
  struct Jump:Command
  {
    std::string label;
    int ip;
    Jump(const char* label):label(label)
    {
    }
    virtual void exec(VM* vm) override
    {
      jump(vm);
    }
    void jump(VM* vm)
    {
      vm->ip = ip-1;
    }
    virtual void link(VM* vm)
    {
      ip = vm->labels[label];
    }

  };
  struct Jump0:Jump
  {
    int r;

    Jump0(int r, const char* label):r(r),Jump(label)
    {
    }
    virtual void exec(VM* vm) override
    {
      if(vm->r[r] == 0 )
        jump(vm);
    }
  };
  struct JumpEqu:Jump
  {
    int r1;
    int r2;

    JumpEqu(int r1, int r2, const char* label):r1(r1),r2(r2),Jump(label)
    {
    }
    virtual void exec(VM* vm) override
    {
      if(vm->r[r1] == vm->r[r2] )
        jump(vm);
    }
  };
  struct JumpGreat:Jump
  {
    int r1;
    int r2;
    JumpGreat(int r1, int r2, const char* label):r1(r1),r2(r2),Jump(label)
    {
    }
    virtual void exec(VM* vm) override
    {
      if(vm->r[r1] > vm->r[r2] )
        jump(vm);
    }
  };
  struct Stop:Command
  {
    virtual void exec(VM* vm) override
    {
        vm->is_running = false;
    }
  };
  struct Number:Command
  {
    num value;
    Number(num value):value(value){}

    virtual void exec(VM* vm) override
    {
        vm->put(value);
    }
  };
};

int main(int argc, char const *argv[]) {
  VM vm;
  std::string cmd;
  while (true)
  {
     in >> cmd;
    if(cmd.empty())
      break;
    switch (cmd[0]) {
      case '+':
      {
        vm.prog.push_back(new VM::Plus());
        break;
      }
      case '-':
      {
        vm.prog.push_back(new VM::Minus());
        break;
      }
      case '*':
      {
        vm.prog.push_back(new VM::Mul());
        break;
      }
      case '/':
      {
        vm.prog.push_back(new VM::Div());
        break;
      }
      case '%':
      {
        vm.prog.push_back(new VM::Mod());
        break;
      }
      case '>':
      {
        vm.prog.push_back(new VM::SetRegister(cmd[1]-'a'));
        break;
      }
      case '<':
      {
        vm.prog.push_back(new VM::GetRegister(cmd[1]-'a'));
        break;
      }
      case 'P':
      {
        if(cmd.size() == 1)
          vm.prog.push_back(new VM::Print());
        else
          vm.prog.push_back(new VM::PrintRegister(cmd[1]-'a'));
        break;
      }
      case 'C':
      {
        if(cmd.size() == 1)
          vm.prog.push_back(new VM::PrintChar());
        else
          vm.prog.push_back(new VM::PrintCharRegister(cmd[1]-'a'));
        break;
      }
      case ':':
      {
        VM::Label(vm, cmd.substr(1));
        //vm.prog.push_back(new VM::Label(vm, cmd.substr(1)));
        break;
      }
      case 'J':
      {
        vm.prog.push_back(new VM::Jump(cmd.c_str()+1));
        break;
      }
      case 'Z':
      {
        vm.prog.push_back(new VM::Jump0(cmd[1]-'a', cmd.c_str()+2));
        break;
      }
      case 'E':
      {
        vm.prog.push_back(new VM::JumpEqu(cmd[1]-'a', cmd[2]-'a', cmd.c_str()+3));
        break;
      }
      case 'G':
      {
        vm.prog.push_back(new VM::JumpGreat(cmd[1]-'a', cmd[2]-'a', cmd.c_str()+3));
        break;
      }
      case 'Q':
      {
        vm.prog.push_back(new VM::Stop());
        break;
      }
      default:
      {
        vm.prog.push_back(new VM::Number(std::stoi(cmd)));
        break;
      }
    }
  }
  
  vm.prog.push_back(new VM::Stop());
  vm.run();


  return 0;
}

/*
100
0
:start
>a
Zaend
<a
<a
1
+
-
>b
<b
Jstart
:end
P

 	5050
*/

/*
58
49
10
62
97
10
80
97
10
90
97
50
10
60
97
10
74
49
10
58
50
10
48
10
58
51
10
62
97
10
90
97
52
10
67
97
10
74
51
10
58
52
10
0
:1
>a
Pa
Za2
<a
J1
:2
0
:3
>a
Za4
Ca
J3
:4
*/
