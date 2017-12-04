#include "openedu.hpp"
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstring>


void radix(const std::string& si, std::vector<int> &idx_in, std::vector<int> &idx_out,int n)
{
  const int k = 'z'-'a'+1;
  static int c[k];

  std::memset(c, 0, sizeof(c));

  for(int i = 0; i<n; ++i)
  {
    int j = si[idx_in[i]]-'a';
    ++c[j];
  }
  for(int i = 1; i<k; ++i)
  {
    c[i]+=c[i-1];
  }

  for(int i= n-1; i>=0; --i)
  {
    int j = si[idx_in[i]]-'a';
    idx_out[--c[j]] = idx_in[i];
  }

}

int main() {
  openedu_in in;
  openedu_out out;

  int n = in.next_i32(0);
  int m = in.next_i32(0);
  int k = in.next_i32(0);
  std::vector<std::string> data;
  data.reserve(m);
  for(int i = 0; i< m; ++i)
  {
    data.push_back(in.next());
  }
  std::vector<int> idx;
  idx.reserve(n);
  for(int i = 0; i< n; ++i)
  {
    idx.push_back(i);
  }

  std::vector<int> idx2(n, 0);
  for(int i = 1; i<=k; ++i)
  {
    radix(data[m-i], idx, idx2, n);
    idx.swap(idx2);
  }

  for(int i = 0; i< n-1; ++i)
  {
    out.print_i32(idx[i]+1).print(" ");
  }
    out.print_i32(idx[n-1]+1).print("\n");
}


/*
3 3 1
bab
bba
baa
 	2 3 1


3 3 2
bab
bba
baa
 	3 2 1

3 3 3
bab
bba
baa
 	2 3 1

*/
