set xlabel "t"
set ylabel "y(t)"
plot [0:1] "result.dat" u 1:2 w points title "uh", log(-0.5*x*x+1) w lines title "u_{ex}"
pause -1

