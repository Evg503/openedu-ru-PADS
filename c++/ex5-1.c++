#include "openedu.hpp"
#include <vector>

openedu_in in;
openedu_out out;

int main() {

  int n = in.next_i32(0);
  std::vector<int> v;

  v.reserve(n+1);
  v.push_back(0);
  for(int i = 0; i < n; ++i)
  {
      v.push_back(in.next_i32(0));
  }

  int m = (n-1)/2;
  for(int i = 1; i<=m; ++i)
  {
    if(v[i] > v[2*i] || v[i] > v[2*i+1])
    {
        out.print("NO");
        return 0;
    }
  }

  if(v[n/2] > v[n])
  {
    out.print("NO");
    return 0;
  }

      out.print("YES");
  }


/*

input.txt

output.txt
5
1 0 1 2 0

 	NO
5
1 3 2 5 4

 	YES

*/
