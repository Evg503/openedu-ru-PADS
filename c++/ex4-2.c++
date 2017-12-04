#include "openedu.hpp"
#include <vector>

openedu_in in;
openedu_out out;

int main() {

  int m = in.next_i32(0);
  std::vector<int> v;
  v.reserve(m);
  int head = 0;

  for(int i = 0; i<m; ++i)
  {
    std::string command = in.next();
    if(command == "+")
    {
      v.push_back(in.next_i32(0));
    } else
    {
      out.print_i32(v[head]).print("\n");
      ++head;
    }
  }

  return 0;
}

/*
4
+ 1
+ 10
-
- 	1
10
*/
