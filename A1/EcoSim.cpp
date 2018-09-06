/*
  Name: MingFeng(Ken) Wang
  Assignment: A1: C++ Starter
  C++ programming related to ecological simulation of rabbit and fox.
*/

//Libraries needed to compile
#include <iostream>
#include <cmath>
using namespace std;

//Methods declaration
void plotPopulations(double,double,double);
void updatePopulations(double,double,double,double,double,double&,double&);
void incrementCounter(int*);

//Main function that does the simulation and plots within a loop.
int main()
{
  //User input
  double initRabbit, initFox;

  //Static parameters
  double raGrowth = 0.2, preRate = 0.002, FoxPreyCon = 0.6,
   foxMorRate = 0.2, carryCap = 1000.0;

   //Promt and initialize variables.
   cout << "Enter the initial amount of Rabbit(s): ";
   if(!(cin >> initRabbit)){
     cout << "Invalid input, please enter a double value." << endl;
     exit(EXIT_FAILURE);
   }
   cout << "Enter the initial amount of Fox(s): ";
   if(!(cin >> initFox)){
     cout << "Invalid input, please enter a double value." << endl;
     exit(EXIT_FAILURE);
   }

   //Making a int to store the counter as well as a pointer poiting to it.
   int i = 0;
   int* ptr = &i;

   //iteration of the simulation
   while(i < 500)
   {
     if(initFox < 1 || initRabbit <1){
       break;
     }
     updatePopulations(raGrowth, preRate, FoxPreyCon, foxMorRate, carryCap, initRabbit, initFox);
     plotPopulations(initRabbit,initFox,0.1);
     cout << endl;
     incrementCounter(ptr);
   }
  return 0;
}

//Void function to update the numbers of rabbit and fox for every each iteration in main.
void updatePopulations(double g, double p, double c, double m, double K, double& numRabbits,
                        double& numFoxes)
{
  //Computing the change of rabbit and fox
  double delRab = g * numRabbits * (1 - numRabbits / K) - p * numRabbits * numFoxes;
  double delFox = c * p * numRabbits * numFoxes - m * numFoxes;

  //Updating the numbers of rabbit and foxes
  numRabbits += delRab;
  numFoxes += delFox;
}

//Void funcion to help plotCharacterAtPosition
void helper(int number, char ch) {
  for(int i = 0; i< number -1; i++){
    cout << ' ';
  }
  cout << ch;
}

//Void function for charting and plotting the updatePopulations
void plotPopulations(double numRabbits, double numFoxes, double scale){
  int rabPos = floor(numRabbits * scale) + 1, foxPos = floor(numFoxes * scale) + 1;
  //Special case when rabbit equals to foxes
  if(rabPos - foxPos == 0){
    helper(rabPos,'*');
    return;
  }
  //Usual case where either one is in front of the other.
  (rabPos - foxPos < 0) ? (helper(rabPos,'r'),helper(foxPos - rabPos, 'F')) : (helper(foxPos, 'F'),helper(rabPos - foxPos,'r'));
}

//Method for step 5 incrementing a pointer counter.
void incrementCounter(int* p){
  *p = *p +1;
}
