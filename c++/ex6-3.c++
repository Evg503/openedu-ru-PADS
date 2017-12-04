#include "openedu.hpp"
#include <vector>
#include <algorithm>

openedu_in in;
openedu_out out;

struct Node
{
  int key;
  int left;
  int right;

};

std::vector<Node> v;

int hight(int idx)
{
  if(idx == 0) return 0;

  return 1 + std::max(hight(v[idx].left), hight(v[idx].right));
}
int main()
{

  int n = in.next_i32(0);

  if (n ==0)
  {
    out << 0;
  } else
  {
    v.resize(n+1);

    for(int i = 1; i <= n; ++i)
    {
      v[i].key = in.next_i32(0);
      v[i].left = in.next_i32(0);
      v[i].right = in.next_i32(0);
    }

    out <<  hight(1);
  }
}

/*
nput.txt

6
-2 0 2
8 4 3
9 0 0
3 6 5
6 0 0
0 0 0

output.txt
 	4
*/
