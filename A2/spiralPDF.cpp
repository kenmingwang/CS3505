/*
 * << Alternative PDF Library 1.0.0 >> -- text_demo2.c
 *
 * Copyright (c) 1999-2006 Takeshi Kanno <takeshi_kanno@est.hi-ho.ne.jp>
 *
 * Permission to use, copy, modify, distribute and sell this software
 * and its documentation for any purpose is hereby granted without fee,
 * provided that the above copyright notice appear in all copies and
 * that both that copyright notice and this permission notice appear
 * in supporting documentation.
 * It is provided "as is" without express or implied warranty.
 *
 * Modified by David Johnson, University of Utah, 2016.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "HaruPDF.h"
#include "Spiral.h"

// argc is the number of arguments. Argv is an array of character arrays, or C-style strings.
// If you call the program like ./pdfExample "Hello", then argv[1] would contain "Hello\0".
// argv[0] would be "pdfExample\0" - the name of the executing program.
int main (int argc, char **argv)
{
    char fname[256];
    float rad1;
    unsigned int i;
    string SAMP_TXT ;
    if(argc > 1){
      SAMP_TXT.assign(argv[1],strlen(argv[1]));
    }
    else{
      cout << "NO TEXT ERROR: Please try again with text provided.";
      exit(EXIT_FAILURE);
    }

    // argv are the command line arguments
    // argv[0] is the name of the executable program
    // This makes an output pdf named after the program's name
    strcpy (fname, argv[0]);

    /* Create PDF */
    HaruPDF myPDF(fname,1);
    /* Spiral text */
    Spiral mySpiral(210,300,75,90);
    // Place characters one at a time on the page.
    for (i = 0; i < SAMP_TXT.length(); i++) {

      //Text rotations
      rad1 = (mySpiral.getTextAngle() - 90) / 180 * 3.141592;
      //Write text with position
      myPDF.writeOneLetter(0,SAMP_TXT[i],30,cos(rad1),
                            sin(rad1), -sin(rad1), cos(rad1),mySpiral.getTextX(), mySpiral.getTextY());
      //update mySpiral
      mySpiral++;
    }

    //Save myPDF obj into pdf
    myPDF.saveAsPDF();

    return 0;
}
