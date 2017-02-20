#include "openedu.hpp"
#include <cmath>

int main() {
    openedu_out() << sqrt(openedu_in().next_i32(-1)) << "\n";
    return 0;
}
