/*
 Name: MingFeng(Ken) Wang
 Class: CS3505
 Date: Sept.5.2018
 */
#include "hpdf.h"
#include <string>
using namespace std;
 class HaruPDF{
 private:
   HPDF_Doc doc;
   string file_name;
   int page;
   int size;
   HPDF_Page pages[];
 public:
    // Constructor of a HaruPDF object, the filename will be
    // the result pdf filename, page will be the pages that
    // the pdf file will contain.
    HaruPDF(string filename, int page);

    // print a single letter c of size 'size', other params
    // are for posistion and rotation use.
    void writeOneLetter(int pg, char c, int size,
    float r1, float r2, float r3,
    float r4, float x, float y);

    // Save the doc file into a PDF file with the name of file_name.
    void saveAsPDF();
 };
