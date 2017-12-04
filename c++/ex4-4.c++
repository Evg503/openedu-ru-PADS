#include "openedu.hpp"
#include <vector>
#include <set>
#include <algorithm>

openedu_in in;
openedu_out out;

int main() {

  int m = in.next_i32(0);
  std::vector<int> v;
  v.reserve(m);
  std::multiset<int> set;
  int head = 0;
  // int cached_min;
  // bool is_cached_min=false;

  for(int i = 0; i<m; ++i)
  {
    std::string command = in.next();
    if(command == "+")
    {
      int value = in.next_i32(0);
      // if(is_cached_min && value < cached_min)
      //   cached_min = value;

      v.push_back(value);
      set.insert(value);
    } else if(command == "?")
    {
      // if(!is_cached_min)
      // {
      //   cached_min = *std::min_element(v.begin()+head, v.end());
      //   is_cached_min = true;
      // }
      out.print_i32(*set.begin()).print("\n");
    }
    else
    {
      set.erase(set.find(v[head]));
      // if(v[head] == cached_min)
      //   is_cached_min = false;
      //out.print_i32(v[head]).print("\n");
      ++head;
    }
  }

  return 0;
}

/**

7
+ 1
?
+ 10
?
-
?
- 	1
1
10
*/
