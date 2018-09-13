/*
 Name: MingFeng(Ken) Wang
 Class: CS3505
 Date: Sept.5.2018
 */
#include <iostream>
using namespace std;
 class Spiral{
   double CenterX, CenterY, radius, angle;
   double count;
 public:
   /* Construct a spiral obj with x y coordinates, the initial radius and angle.*/
   Spiral(int X, int Y, int rad, int ang);
   //Pre++
   Spiral& operator++();
   //Post++
   Spiral operator++(int);
   //Getter for X
   double getTextX();
   //Getter for Y
   double getTextY();
   //Getter for angle in degrees
   double getTextAngle();
   //Overloading << operator, returns the Spiral specifications.
   friend ostream& operator<<(ostream& os, const Spiral& sp);
 };
