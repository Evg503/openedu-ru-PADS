#include "openedu.hpp"
#include <cmath>

int main() {
    openedu_out() << openedu_in().next_i32(0) + openedu_in().next_i32(0) << "\n";
    return 0;
}
