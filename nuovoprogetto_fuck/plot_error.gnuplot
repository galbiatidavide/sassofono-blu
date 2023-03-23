set logscale x
set logscale y
set xlabel "time step"
set ylabel "error"
plot "error.dat" u 1:2 w lp title "L2-conv-rate", "error.dat" u 1:3 w lp title "infinite-conv-rate"
pause -1
