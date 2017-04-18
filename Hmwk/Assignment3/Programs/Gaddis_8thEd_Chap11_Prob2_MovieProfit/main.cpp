/* 
  File:   main.cpp
  Author: Colleen Carleton
  Created on March 26, 2017, 6:40 PM
  Purpose: Modification of program 1, calculates the profit/loss from year
 * one revenue
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

#include "Movieprofit.h"

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from system of units to 
//another

//Function Prototypes
void movDisp(MoviPro);

//Executable code begins here!!!
int main(int argc, char** argv) {
    //Declare variables
MoviPro movie1; //First Movie
MoviPro movie2; //Second Movie

//Get information for each movie
//Movie 1
cout<<"Enter the name of the first movie."<<endl;
getline(cin, movie1.title);
cout<<"Enter the director of movie 1."<<endl;
getline(cin, movie1.directr);
cout<<"Enter the year of release for movie 1."<<endl;
cin>>movie1.yrReles;
cout<<"Enter the run time of movie 1."<<endl;
cin>>movie1.rnTime;
cout<<"Enter the production costs for movie 1."<<endl;
cin>>movie1.proCost;
cout<<"Enter the first year revenue for movie 1."<<endl;
cin>>movie1.revenue;
cin.ignore();
//Movie2
cout<<"Enter the name of the second movie."<<endl;
getline(cin, movie2.title);
cout<<"Enter the director of movie 2."<<endl;
getline(cin, movie2.directr);
cout<<"Enter the year of release for movie 2."<<endl;
cin>>movie2.yrReles;
cout<<"Enter the run time (in minutes) of movie 2."<<endl;
cin>>movie2.rnTime;
cout<<"Enter the production costs for movie 2."<<endl;
cin>>movie2.proCost;
cout<<"Enter the first year revenue for movie 2."<<endl;
cin>>movie2.revenue;

//Call function to display info for movie 1
movDisp(movie1);

//Call function  to display info for movie 2
movDisp(movie2);
    
    //Exit
    return 0;
}

void movDisp(MoviPro movie) {
cout<<"Title: "<<movie.title<<endl;
cout<<"Director: "<<movie.directr<<endl;
cout<<"Year of release: "<<movie.yrReles<<endl;
cout<<"Run time: "<<movie.rnTime<<endl;
if (movie.revenue-movie.proCost>=0) {
	cout<<"First year's profit: $"<<movie.revenue-movie.proCost<<endl;
} else {
	cout<<"First year's loss: $"<<movie.revenue-movie.proCost<<endl;
}
}