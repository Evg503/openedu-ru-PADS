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
const int inf = 1000000001;
std::vector<Node> v;

bool check(int idx, int from, int to)
{
  if(idx == 0) return true;
  if(v[idx].key <= from || v[idx].key >= to) return false;

  return check(v[idx].left, from,v[idx].key) && check(v[idx].right, v[idx].key, to);
}



int main()
{

  int n = in.next_i32(0);
  if (n ==0)
  {
    out << "YES";
  }
  else
  {
    v.resize(n+1);

    for(int i = 1; i <= n; ++i)
    {
      v[i].key = in.next_i32(0);
      v[i].left = in.next_i32(0);
      v[i].right = in.next_i32(0);
    }
    if( check(1, -inf, inf))
      out << "YES";
    else
      out << "NO";
  }
}

/*
Пример
input.txt

output.txt
6
-2 0 2
8 4 3
9 0 0
3 6 5
6 0 0
0 0 0

	YES

0
YES

3
5 2 3
6 0 0
4 0 0
NO

*/
