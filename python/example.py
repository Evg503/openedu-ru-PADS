from math import sqrt
from openedu_io import openedu_io

with openedu_io() as io:
    io.writeln(sqrt(io.next_int()))
