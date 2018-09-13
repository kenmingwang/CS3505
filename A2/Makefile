CC = g++
CFLAG = -c -Wall
LIBHARU = libharu

test: spiralPDF.o Spiral.o HaruPDF.o
	$(CC) -o spiralPDF spiralPDF.o Spiral.o HaruPDF.o -L $(LIBHARU)/src -lhpdfs

spiralPDF.o : HaruPDF.h spiralPDF.cpp Spiral.h
	$(CC) $(CFLAG) spiralPDF.cpp -I $(LIBHARU)/include

Spiral.o : Spiral.h Spiral.cpp
	$(CC) $(CFLAG) Spiral.cpp

HaruPDF.o: HaruPDF.h HaruPDF.cpp $(LIBHARU)/include/hpdf.h
	$(CC) $(CFLAG) HaruPDF.cpp -I $(LIBHARU)/include

clean:
		rm -f *.o  test
