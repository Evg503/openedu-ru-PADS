#include "openedu.hpp"
#include <vector>
#include <algorithm>

openedu_in in;
openedu_out out;

int main() {

  int n = in.next_i32(0);
  std::vector<int> v;

  v.reserve(n);

  for(int i = 0; i < n; ++i)
  {
      v.push_back(in.next_i32(0));
  }

  int m = in.next_i32(0);
  for(int i = 0; i<m; ++i)
  {
      int x = in.next_i32(0);
      auto range = std::equal_range(v.begin(), v.end(), x);
      if (range.first == range.second)
        out.print("-1 -1\n");
      else
      {
        int idx1 = std::distance(v.begin(), range.first)+1;
        int idx2 = std::distance(v.begin(), range.second);
        out << idx1 <<" "<<idx2<<"\n";
      }

  }
}


/*

input.txt
5
1 1 2 2 2
3
1 2 3

output.txt
1 2
3 5
-1 -1
*/
