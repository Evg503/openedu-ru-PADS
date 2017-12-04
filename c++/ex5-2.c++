#include "openedu.hpp"
#include <vector>

openedu_in in;
openedu_out out;
struct Elem
{
  int key;
  int line;
  bool operator < (const Elem& r) const
  {
      return key < r.key;
  }
  Elem(int key, int line):key(key), line(line){}
};

 openedu_out const  &operator << ( openedu_out const& o, const Elem& value)
{
  o << value.key;
  return o;
}

struct MinQueue
{
  MinQueue(int n)
  {
    v.reserve(n);
    idx.resize(n);
  }

  void insert(int key, int line)
  {
    //out << "insert(" << key << ", " << line << ")\n";
    v.push_back(Elem(key, line));
    reindex(v.size()-1);
    decrease_key(v.size()-1, key);
  }
  void swap(int p , int i)
  {
    //out << "swap(" << p << ", " << i << ")\n";
    std::swap(v[i], v[p]);
    reindex(i);
    reindex(p);

  }
  void heapify(int i)
  {
    int l = left(i);
    int r = right(i);
    int smallest = i;
    //out << "heapify(" << i << ") "<< "l="<<l<<" r=" << r<<"\n";

    if(l < v.size() && v[l] < v[smallest])
      smallest = l;

    if(r < v.size() && v[r] < v[smallest])
      smallest = r;

    if(smallest != i)
    {
      swap(smallest, i);
      heapify(smallest);

    }
    //out << "AFTER heapify(" << i << ")\n v= ";
  //out.println(v.begin(), v.end());
  }
  int parent(int i)
  { return i>0?(i-1)/2:-1;}
  int left(int i)
  { return 2*i+1;}
  int right(int i)
  { return 2*i+2;}
  void reindex(int i)
  {
    idx[v[i].line] = i;
  }

  const Elem& minimum() const {return v[0];}
  void extract_minimum()
  {
    //out << "extract_minimum()\n";
    v[0] = v.back();
    reindex(0);
    v.pop_back();
    heapify(0);

  }
  void decrease_key(int i, int new_key)
  {
    //out << "decrease_key(" << i << ", " << new_key << ")\n in ";
    //out.println(v.begin(), v.end());
    v[i].key = new_key;
    while( i>0 && v[i] < v[parent(i)])
    {
      int p = parent(i);
      swap(i, p);
      reindex(i);
      reindex(p);
      i = p;
    }
    //out << "AFTER decrease_key(" << new_key << ")\n in ";
    //out.println(v.begin(), v.end());
  }

  void D(int line, int new_key)
  {
    decrease_key(idx[line], new_key);
  }

  void X()
  {
    if(v.empty())
      out.print("*\n");
    else
    {
      out.print_i32(minimum().key);
      //out.print(" ");
      //out.print_i32(minimum().line);
      extract_minimum();
      out.print("\n");
    }
  }
  std::vector<Elem> v;
  std::vector<int> idx;
};

int main() {

  int n = in.next_i32(0);
  MinQueue mq(n);

  std::string buf;
  int k, idx;
  for(int i = 1; i <= n; ++i)
  {

    in >> buf;
    switch (buf[0]) {
      case 'A':
        k = in.next_i32(0);
        mq.insert(k, i);
        break;
      case 'D':
        idx = in.next_i32(0);
        k = in.next_i32(0);
        mq.D(idx, k);
        break;
      case 'X':
        mq.X();
        break;
    }
  }
}

/*

input.txt

8
A 3
A 4
A 2
X
D 2 1
X
X
X

output.txt
2
1
3
*
*/
