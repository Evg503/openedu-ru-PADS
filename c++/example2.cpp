#include "openedu.hpp"
#include <cmath>

int main() {
    openedu_in in;
    long long a,b; 
    a = in.next_i32(0);
    b = in.next_i64(0);
    openedu_out() << (a + b * b) << "\n";
    return 0;
}
