#include "openedu.h"
#include <math.h>

int main() {
    openedu_io_open();
    println_double(sqrt(next_i32(-1)));
    openedu_io_close();
    return 0;
}
