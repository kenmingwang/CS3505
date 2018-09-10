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
   Spiral(int X, int Y, int rad, int ang);
   Spiral& operator++();
   Spiral operator++(int);
   double getTextX();
   double getTextY();
   double getTextAngle();
   double getRadius();
   friend ostream& operator<<(ostream& os, const Spiral& sp);
 };
