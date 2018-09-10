LIBHARU = libharu

spiralpdf: spiralPDF.o Spiral.o HaruPDF.o libhpdfs.a
	g++ -o spiralPDF.o Spiral.o HaruPDF.o

spiralPDF.o : spiralPDF.cpp HaruPDF.h
	g++ -c spiralPDF.cpp -I $(LIBHARU)/include -L $(LIBHARU)/src -lhpdfs

Spiral.o : Spiral.h
	g++ -c Spiral.cpp

HaruPDF.o: HaruPDF.h hpdf.h HaruPDF.cpp libhpdfs.a
	g++ -c HaruPDF.cpp -I $(LIBHARU)/include -L $(LIBHARU)/src -lhpdfs
