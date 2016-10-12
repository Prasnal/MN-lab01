set term png
set out 'rysunek.png'
set xlabel "t"
set ylabel "x(t)" rotate parallel
set title "Wykres zależności wychylenia od czasu"
plot 'dane.dat' u 1:2 w l
