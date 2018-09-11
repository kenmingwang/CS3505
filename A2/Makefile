LIBHARU = libharu

spiralpdf: spiralPDF.o Spiral.o HaruPDF.o $(LIBHARU)/include/hpdf.h $(LIBHARU)/src/libhpdfs.a
	g++ -o spiralpdf spiralPDF.o Spiral.o HaruPDF.o -I $(LIBHARU)/include -L $(LIBHARU)/src -lhpdfs

spiralPDF.o : HaruPDF.h spiralPDF.cpp
	g++ -c spiralPDF.cpp -I $(LIBHARU)/include -L $(LIBHARU)/src -lhpdfs

Spiral.o : Spiral.h Spiral.cpp
	g++ -c Spiral.cpp

HaruPDF.o: HaruPDF.h HaruPDF.cpp  $(LIBHARU)/include/hpdf.h $(LIBHARU)/src/libhpdfs.a
	g++ -c HaruPDF.cpp -I $(LIBHARU)/include -L $(LIBHARU)/src -lhpdfs
