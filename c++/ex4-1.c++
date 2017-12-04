#include "openedu.hpp"
#include <vector>

openedu_in in;
openedu_out out;

int main() {

  int m = in.next_i32(0);
  std::vector<int> v;

  for(int i = 0; i<m; ++i)
  {
    std::string command = in.next();
    if(command == "+")
    {
      v.push_back(in.next_i32(0));
    } else
    {
      out.print_i32(v.back()).print("\n");
      v.pop_back();
    }
  }

  return 0;
}

/*
6
+ 1
+ 10
-
+ 2
+ 1234
- 	10
1234
*/
