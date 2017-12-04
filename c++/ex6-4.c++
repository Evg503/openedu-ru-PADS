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

int count(int idx)
{
  if(idx == 0) return 0;

  return 1 + count(v[idx].left) + count(v[idx].right);
}

int delete_key_tree(int key)
{
    //if(key == v[1].key) return 0;
    int idx = 1;
    int prev = 0;
    while(idx !=0 && key != v[idx].key)
    {
      prev = idx;
      if(key > v[idx].key)
        idx = v[idx].right;
      else
        idx = v[idx].left;
    }
    if(idx == 0)
      return 0;

    if(key > v[prev].key)
      v[prev].right = 0;
    else
      v[prev].left = 0;
    return idx;
}

int main()
{

  int n = in.next_i32(0);

  {
    v.resize(n+1);

    for(int i = 1; i <= n; ++i)
    {
      v[i].key = in.next_i32(0);
      v[i].left = in.next_i32(0);
      v[i].right = in.next_i32(0);
    }

    int m =  in.next_i32(0);
    for(int i = 1; i <= m; ++i)
    {
      int idx = delete_key_tree(in.next_i32(0));
      n -= count(idx);
      out << n << "\n";
    }
  }
}

/*
Пример
input.txt


6
-2 0 2
8 4 3
9 0 0
3 6 5
6 0 0
0 0 0
4
6 9 7 8

output.txt

5
4
4
1

*/
