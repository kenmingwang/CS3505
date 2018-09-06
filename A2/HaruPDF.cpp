#include "HaruPDF.h"
#include <string>
// Constructor
HaruPDF::HaruPDF(string filename, int p){
  doc = HPDF_New(NULL,NULL);
  file_name = filename + ".pdf";

  for(int i = 0; i<p; i++){
    HPDF_Page page = HPDF_AddPage (doc);
    HPDF_Page_SetSize (page, HPDF_PAGE_SIZE_A5, HPDF_PAGE_PORTRAIT);
    HPDF_Page_SetTextLeading (page, 20);
    HPDF_Page_SetGrayStroke (page, 0);
    pages[i] = page;
  }
}


void HaruPDF::writeOneLetter(int pg, char c, int size,
                             float r1, float r2, float r3,
                             float r4, float x, float y){
    char buf[2];

    HPDF_Page_BeginText (p);
    HPDF_Font font = HPDF_GetFont (doc, "Courier-Bold", NULL);
    HPDF_Page_SetFontAndSize (p, font, size);
    HPDF_Page_SetTextMatrix(p,r1,r2,r3,r4,x,y);
    buf[0] = c;
    buf[1] = 0;
    HPDF_Page_ShowText (p, buf);
    HPDF_Page_EndText (p);
}

void HaruPDF::saveAsPDF(){
  HPDF_SaveToFile (doc,file_name.c_str());
  HPDF_Free (doc);
}
