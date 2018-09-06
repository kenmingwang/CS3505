HARUDIR = harulib


pdf: pdfExample.o
	g++ -o pdftest pdfExample.o -L $(HARUDIR)/lib -lHaruPDF

pdfExample.o: pdfExample.cpp
	g++ -c pdfExample.cpp -I $(HARUDIR)/include
