/* 
  File:   main.cpp
  Author: Colleen Carleton
  Created on March 26, 2017, 5:40 PM
  Purpose: Program that collects data from movies and displays the information
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

#include "Moviedata.h"

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from system of units to 
//another

//Function Prototypes
void moviDis(MoviDat);

//Executable code begins here!!!
int main(int argc, char** argv) {
    //Declare variables
MoviDat movie1; //First Movie
MoviDat movie2; //Second Movie

//Get information for each movie
//Movie 1
cout<<"Enter the name of the first movie."<<endl;
getline(cin, movie1.title);
cout<<"Enter the director of movie 1."<<endl;
getline(cin, movie1.directr);
cout<<"Enter the year of release for movie 1."<<endl;
cin>>movie1.yrReles;
cout<<"Enter the run time of movie 1."<<endl;
cin>>movie1.rnTime; cin.ignore();
//Movie2
cout<<"Enter the name of the second movie."<<endl;
getline(cin, movie2.title);
cout<<"Enter the director of movie 2."<<endl;
getline(cin, movie2.directr);
cout<<"Enter the year of release for movie 2."<<endl;
cin>>movie2.yrReles;
cout<<"Enter the run time (in minutes) of movie 2."<<endl;
cin>>movie2.rnTime;

//Call function to display info for movie 1
moviDis(movie1);

//Call function  to display info for movie 2
moviDis(movie2);
    
    //Exit
    return 0;
}

void moviDis(MoviDat movie) {
cout<<"Title: "<<movie.title<<endl;
cout<<"Director: "<<movie.directr<<endl;
cout<<"Year of release: "<<movie.yrReles<<endl;
cout<<"Run time: "<<movie.rnTime<<endl;
}