#include "openedu.hpp"
#include <vector>

openedu_in in;
openedu_out out;

int main() {

  int n = in.next_i32(0);
  std::vector<char> v;
  v.reserve(1001);
  bool NO;
  for(int i = 0; i<n; ++i)
  {
    NO = false;
    v.clear();
    std::string seq = in.next();
    for(char ch : seq)
    {
      if (ch == '(' || ch == '[')
      {
          v.push_back(ch);
      }
      else if(ch==')')
      {
          if(v.size()>0 && v.back() == '(')
          {
            v.pop_back();
          }
          else
          {
            NO = true;
            break;
          }
      }  else if(ch==']')
      {
          if(v.size()>0 && v.back() == '[')
          {
            v.pop_back();
          }
          else
          {
            NO = true;
            break;
          }
      }
    }
    if(!NO &&v.size() == 0 )
    {
      out.print("YES\n");
    }
    else
    {
      out.print("NO\n");
    }
  }

}


/**

5
()()
([])
([)]
((]]
)(

 	YES
YES
NO
NO
NO
*/
