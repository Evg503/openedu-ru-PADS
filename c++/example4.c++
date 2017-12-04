#include "openedu.hpp"
#include <cmath>
#include <vector>
#include <algorithm>

int main() {
    openedu_in in;
     
    int n = in.next_i32(0);
    std::vector<int> data;
    std::vector<int> idx;
    std::vector<int> idx2;
    data.reserve(n);
    idx.reserve(n);
    idx2.reserve(n);
    for(int i = 0; i< n; ++i)
    {
    	data.push_back(in.next_i32(0));
	idx.push_back(i);
	idx2.push_back(i);
    }

   
   for(int i =1; i<n; ++i)
	{
	    int j = i - 1;
	    while( j>=0 && data[idx[j]] > data[idx[j+1]])
	    {
		std::swap(idx[j], idx[j+1]);
		j--;
	    }
	}
    openedu_out out;
    for(int i = 0; i < n-1; ++i)
    {
	int i2 = std::distance(idx2.begin(), std::find(idx2.begin()+i, idx2.end(), idx[i]));
	if (i2 != i)
	{
    	    out << "Swap elements at indices " << i+1 <<  " and " << i2+1 <<  ".\n";
	    std::swap(idx2[i], idx2[i2]);
	}
    }
    out << "No more swaps needed.\n";

    out<< data[idx[0]];
    for(int i = 1; i<n; ++i)
    {
	out << " " << data[idx[i]];
    }
    out << "\n";
    //out.println(data.begin(), data.end());
    //out.println(idx.begin(), idx.end());
    return 0;
}
