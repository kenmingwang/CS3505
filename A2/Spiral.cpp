/*
 Name: MingFeng(Ken) Wang
 Class: CS3505
 Date: Sept.5.2018
 */
 #include "Spiral.h"
 #include <math.h>
 using namespace std;

 /* Construct a spiral obj with x y coordinates, the initial radius and angle.*/
 Spiral::Spiral(int X, int Y, int rad, int ang){
   CenterX = X;
   CenterY = Y;
   radius > 75 ? radius = rad : radius = 75;
   angle = 90;
   count = 0;
   float rad2 = angle / 180 * M_PI;
   CenterX += cos(rad2) * radius;
   CenterY += sin(rad2) * radius;
  }
  //Pre++
  Spiral& Spiral::operator++(){
    count++;
    angle = angle - 15.5 + pow(count,0.458); // change the angle around the circle
    radius += 1 - 0.0015*pow(count,1.1);
    float rad2 = angle / 180 * M_PI;
    CenterX = 210 + cos(rad2) * radius;
    CenterY = 300 + sin(rad2) * radius;

    return *this;
  }
  //Post++
  Spiral Spiral::operator++(int){
    Spiral temp = *this;
    count++;
    angle = angle - 15.5 + pow(count,0.458); // change the angle around the circle
    radius += 1 - 0.0015*pow(count,1.1);
    float rad2 = angle / 180 * M_PI;
    CenterX = 210 + cos(rad2) * radius;
    CenterY = 300 + sin(rad2) * radius;
    return temp;
  }
  //Getter for X
  double Spiral::getTextX(){
    return CenterX;
  }
  //Getter for Y
  double Spiral::getTextY(){
    return CenterY;
  }
  //Getter for angle in degrees
  double Spiral::getTextAngle(){
    return angle;
  }
  //Overloading << operator, returns the Spiral specifications.
  ostream& operator<<(ostream& os, const Spiral& sp){
    //os ask how many end?
    os << "X: " << sp.CenterX << "\nY: " << sp.CenterY << "\nRadius: " << sp.radius << endl;
    return os;
  }
