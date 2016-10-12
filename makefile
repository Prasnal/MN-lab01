all:
	make clean; make program; make run; make plot

# dla C++ wszedzie zmieniamy .c na .cpp

CC= gcc		# dla C++:   CC=g++
CFLAGS=
INCLUDE=
LIB= -lm	# dla lapacka:	LIB= -lm -llapack -lblas
SOURCES= 
OBJECTS= $(SOURCES:.c=.o)

TARGET = program

$(TARGET): main.c $(OBJECTS)
	$(CC) -o $@ $^ $(LIB)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

run:
	./program

plot:
	gnuplot 'plot.gp'


.PHONY: clean

clean:
	rm -f *.o *.txt *.png $(TARGET)

