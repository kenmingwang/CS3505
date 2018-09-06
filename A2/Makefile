INC = -I ./include/


pdf: pdfExample.o
	g++ pdfExample.o

pdfExample.o: pdfExample.cpp include/hpdf.h
	g++ $INC -c pdfExample.cpp

g++ -I libharu/include -c pdfExample.cpp

g++ pdfExample.o -L libharu/src/ -lhpdfs
