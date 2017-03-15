/* 
  File:   main.cpp
  Author: Colleen Carleton
  Created on February 8, 2017, 9:10 AM
  Purpose:  Menu for Assignment 1 programs
 */

//System Libraries
#include <iostream>//Input Output Library
#include <iomanip> //Format Library
#include <string>  //String Library
#include <fstream> //File Library
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from system of units to another

//Function Prototypes
void prob1();
void prob2();
void prob3();
void prob4();
void prob5();
void prob6();
void prob7();
void prob8();
void prob9();
void prob10();

signed int celsius(int); //Used in program 7

void arySort(string[], int); //Used in program 9
int arySrch(string[], int);  //Used in program 9

//Executable code begins here!!!
int main(int argc, char** argv) {
    //Declare Variables
    char choice;
    
    //Loop on the menu
    do{
    
        //Input values
        cout<<"Choose from the list"<<endl;
        cout<<"Type 1 for Problem 1 (3.12)"<<endl;
        cout<<"Type 2 for Problem 2 (3.13)"<<endl;
        cout<<"Type 3 for Problem 3 (4.10)"<<endl;
        cout<<"Type 4 for Problem 4 (4.4)"<<endl;
        cout<<"Type 5 for Problem 5 (4.9)"<<endl;
        cout<<"Type 6 for Problem 6 (5.11)"<<endl;
        cout<<"Type 7 for Problem 7 (6.7)"<<endl;
        cout<<"Type 8 for Problem 8 (7.6)"<<endl;
        cout<<"Type 9 for Problem 9 (8.7)"<<endl;
        cout<<"Type 0 for Problem 10 (7.2)"<<endl;
        cin>>choice;

        //Switch to determine the Problem
        switch(choice){
            case '1':{prob1();break;}
            case '2':{prob2();break;}
            case '3':{prob3();break;}
            case '4':{prob4();break;}
            case '5':{prob5();break;}
            case '6':{prob6();break;}
            case '7':{prob7();break;}
            case '8':{prob8();break;}
            case '9':{prob9();break;}
            case '0':{prob10();break;}
            default:
                cout<<"You are exiting the program"<<endl;
        }
    }while(choice>='0'&&choice<='9');
    
    //Exit
    return 0;
}

void prob10() {
    //Declare Variables
    const int NUMMON=12;    //Total number of months, size of array
    float rainFal[NUMMON];  //Array to hold rainfall
    int rCount;             //Loop counter
    
    //Input values
    //Input rainfall
    for (rCount=0; rCount<NUMMON; rCount++) {
	cout<<"Enter the rainfall in inches for month  "<<(rCount+1)<<endl;
	cin>>rainFal[rCount];
	while (rainFal[rCount]<0) {
            cout<<"Amount of rainfall cannot be negative."<<endl;
            cin>>rainFal[rCount];
	}
    }
    
    //Process Calculations
    //Calculate total rainfall for year
    int totRain=0; //Counter for total rain
    for (int rCount=0; rCount<NUMMON; rCount++) {
	totRain+=rainFal[rCount];
    }
    
    //Calculate average rainfall
    float avrgRn=0; //Stores average
    avrgRn=totRain/NUMMON;
    
    //Find highest rainfall
    int hiRain; //Stores highest value
    hiRain=rainFal[0]; //Set highest value to element 1's value
    for (rCount=1; rCount<NUMMON; rCount++) {
	if (rainFal[rCount]>hiRain) {
            hiRain=rainFal[rCount];
	}
    }
    
    //Find lowest rainfall
    int lowRain; //Stores smallest value
    lowRain=rainFal[0]; //Set lowest value to element 1's value
    for (rCount=1; rCount<NUMMON; rCount++) {
	if (rainFal[rCount]<lowRain) {
            lowRain=rainFal[rCount];
	}
    }
    
    //Output Results
    cout<<"The total rainfall for the year was "<<totRain<<" inches."<<endl;
    cout<<"The average rainfall was "<<avrgRn<<endl;
    cout<<"The highest amount of rainfall in one month was "<<hiRain<<" inches."<<endl;
    cout<<"The lowest amount of rainfall in one month was "<<lowRain<<" inches."<<endl;

}

void prob9() {
    //Declare and initialize variables
    int result=0;
    
    //Create and initialize string array to store names
    const int NUMNAME=20; //Size of the array
    string names[NUMNAME]={"Collins, Bill", "Smith, Bart", "Allen, Jim",
                           "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
                           "Taylor, Terri", "Johnson, Jill", "Allison, Jeff",
                           "Looney, Joe", "Wolfe, Bill", "James, Jean",
                           "Weaver, Jim", "Pore, Bob", "Rutherford, Greg",
                           "Javens, Renee", "Harrison, Rose", "Setzer, Cathy",
                           "Pike, Gordon", "Holland, Beth"};
    
    //Call function to sort names
    arySort(names, NUMNAME);
    
    //Call function to search for a name
    result=arySrch(names, NUMNAME);
    
    //Output Located Here
    if (result==-1) {
        cout<<"That name was not found in the array."<<endl;
    } else {
        cout<<"That name was found in position "<<result<<" in the array."<<endl;
    }
}

int arySrch(string names[], int NUMNAME) {
    //Declare and initialize variable
    string name="";
    
    //Get the name that must be found
    cin.ignore();
    cout<<"Enter the name of the person to search for."<<endl;
    getline(cin, name);
    
    //Perform search
    //Variables
    int first=0,            //First element in array
        last=NUMNAME-1,     //Last element in array
        middle,             //Midpoint of array
        positon= -1;       //Position of name
    bool found=false;       //Flag
    //Search
    while (!found && first<=last) {
        middle= (first+last)/2;     //calculate midpoint
        if (names[middle]==name) {
            //if name is found at middle
            found=true; //set found to true
            positon=middle; //set position to middle
        } else if (names[middle]>name) {
            //if name is in lower half
            last=middle-1;          //set last to middle-1
        } else if (names[middle]<name) {
            //if name is in upper half
            first=middle+1;         //set first to middle+1
        } else {
            cout<<"Error"<<endl;
        }
    }
    
    //Return position
    return positon;
}

void arySort(string names[], int NUMNAME) {
    //Declare and initialize variables
    bool swap;
    string temp;
    
    //Swap so names are in alphabetical order
    do {
        swap=false; //Set swap to false
        for (int count=0; count<(NUMNAME-1); count++) {
            if (names[count]>names[count+1]) {
                temp=names[count]; //fill temporary variable to store value
                names[count]=names[count+1]; //swap value count+1 to count
                names[count+1]=temp;         //swap value count to count+1
                swap=true; //Set swap to true because a swap occurred
            }
        }
    } while (swap);
}

void prob8() {
    //Declare all Variables Here
    short int sun1=0, sun2=0, sun3=0; //Stores the number of sunny days each month
    short int rain1=0, rain2=0, rain3=0; //Stores the number of rainy days each month
    short int cloud1=0, cloud2=0, cloud3=0; //Stores the number of cloudy days each month
    
    //Create array to store values
    const int SIZEROW=3; //Store size of rows
    const int SIZECOL=30; //Store size of columns
    char rainAry[SIZEROW][SIZECOL]; //Array to store values
    
    //Fill array
    //Open file
    ifstream inFile;
    inFile.open("RainOrShine.txt");
    //Fill Array
    for (int i=0; i<SIZEROW; i++) {
        for (int j=0; j<SIZECOL; j++) {
            inFile>>rainAry[i][j];
        }
    }
    
    //Determine number of Sunny/Rainy/Cloudy days in each month
    //Month 1 (June)
    for (int k=0; k<SIZECOL; k++) {
        if (rainAry[0][k]=='S') {
            sun1++;
        } else if (rainAry[0][k]=='R') {
            rain1++;
        } else if (rainAry[0][k]=='C') {
            cloud1++;
        } else {
            cout<<"Error (Month 1)"<<endl;
        }
    }
    //Month 2 (July)
    for (int l=0; l<SIZECOL; l++) {
        if (rainAry[1][l]=='S') {
            sun2++;
        } else if (rainAry[1][l]=='R') {
            rain2++;
        } else if (rainAry[1][l]=='C') {
            cloud2++;
        } else {
            cout<<"Error (Month 2)"<<endl;
        }
    }
    //Month 3 (August)
    for (int m=0; m<SIZECOL; m++) {
        if (rainAry[2][m]=='S') {
            sun3++;
        } else if (rainAry[2][m]=='R') {
            rain3++;
        } else if (rainAry[2][m]=='C') {
            cloud3++;
        } else {
            cout<<"Error (Month 3)"<<endl;
        }
    }
    
    //Output Located Here
    //Month 1
    cout<<"The amount of sunny days in June was "<<sun1<<endl;
    cout<<"The amount of rainy days in June was "<<rain1<<endl;
    cout<<"The amount of cloudy days in June was "<<cloud1<<endl;
    //Month 2
    cout<<"The amount of sunny days in July was "<<sun2<<endl;
    cout<<"The amount of rainy days in July was "<<rain2<<endl;
    cout<<"The amount of cloudy days in July was "<<cloud2<<endl;
    //Month 3
    cout<<"The amount of sunny days in August was "<<sun3<<endl;
    cout<<"The amount of rainy days in August was "<<rain3<<endl;
    cout<<"The amount of cloudy days in August was "<<cloud3<<endl;
    //Totals
    cout<<"The total number of sunny days was "<<(sun1+sun2+sun3)<<endl;
    cout<<"The total number of rainy days was "<<(rain1+rain2+rain3)<<endl;
    cout<<"The total number of cloudy days was "<<(cloud1+cloud2+cloud3)<<endl;
    
    //Close File
    inFile.close();
}

void prob7() {
    //Declare all Variables Here
    signed int cels=0; //Stores value in Celsius
    
    //Output table header
    cout<<"Fahrenheit     Celsius"<<endl;
    cout<<"______________________"<<endl;
    
    //Call function to determine conversions
    for (int f=0; f<=20; f++) {
        cels=celsius(f); //Calls function
        cout<<setw(2)<<f<<"              "<<cels<<endl; //Output results
    }
}

signed int celsius(int f) {
    //Declare Variables
    signed int cel; //Stores Celsius
    
    //Calculate Celsius degrees
    cel=(f-32)*5/9;
    
    //Return Celsius degrees
    return cel;
}

void prob6() {
    //Declare all Variables Here
    int populat=0, inPop=0, avgInc=0, days=0, totPop=0;
    
    //Input or initialize values Here
    cout<<"Enter the starting size of the population"<<endl;
    cin>>inPop;
    while (inPop<2) {
        cout<<"Initial population must be at least 2"<<endl;
        cin>>inPop;
    }
    cout<<"Enter the percentage of the average daily population increase"<<endl;
    cin>>avgInc;
    while(avgInc<0) {
        cout<<"Negative numbers are not valid"<<endl;
        cin>>avgInc;
    }
    cout<<"Enter the number of days"<<endl;
    cin>>days;
    while (days<1) {
        cout<<"The number of days cannot be less than 1"<<endl;
        cin>>days;
    }
    
    //Output Located Here
    for (int numDays=1; numDays<=days; numDays++) {
        populat=inPop+(avgInc*numDays);
        totPop+=populat;
        cout<<"On day "<<numDays<<" the population will be "<<totPop<<endl;
    }
}

void prob5() {
    //Declare Variables
    int pennies, nickles, dimes, quartrs, total;
    
    //Input values
    cout<<"This program is a game with the goal of entering an amount of change";
    cout<<" equivalent in value to that of a dollar"<<endl;
    cout<<"Enter a number of pennies, nickles, dimes, and quarters that will be ";
    cout<<"equivalent to a dollar in value"<<endl;
    cout<<"Pennies:"<<endl;
    cin>>pennies;
    cout<<"Nickles:"<<endl;
    cin>>nickles;
    cout<<"Dimes:"<<endl;
    cin>>dimes;
    cout<<"Quarters:"<<endl;
    cin>>quartrs;
    
    //Process by mapping inputs to outputs
    total=(pennies*1)+(nickles*5)+(dimes*10)+(quartrs*25);
    
    //Output values
    if (total==100) {
        cout<<"Congratulations! You won the game!"<<endl;
    } else if (total>100) {
        cout<<"The total you entered was greater than a dollar in value"<<endl;
    } else {
        cout<<"The total you entered was less than a dollar in value"<<endl;
    }
}

void prob4() {
    //Declare all Variables Here
    int leng1, leng2, width1, width2, area1, area2;
    
    //Input or initialize values Here
    cout<<"This program will determine which of two rectangles has the greater area"<<endl;
    cout<<"Enter the length of the first rectangle"<<endl;
    cin>>leng1;
    cout<<"Enter the width of the first rectangle"<<endl;
    cin>>width1;
    cout<<"Enter the length of the second rectangle"<<endl;
    cin>>leng2;
    cout<<"Enter the width of the second rectangle"<<endl;
    cin>>width2;
    
    //Process/Calculations Here
    area1=leng1*width1;
    area2=leng2*width2;
    
    //Output Located Here
    if (area1==area2){
        cout<<"The rectangles have the same area"<<endl;
    } else if (area1>area2) {
        cout<<"The first rectangle has a larger area"<<endl;
    } else {
        cout<<"The second rectangle has a larger area"<<endl;
    }
}

void prob3() {
    //Declare Variables
    int month, year;
    
    //Input values
    cout<<"This program will display the number of days in a month, ";
    cout<<"including leap years"<<endl;
    cout<<"Enter a month in numeric form"<<endl;
    cin>>month;
    cout<<"Enter a four digit year"<<endl;
    cin>>year;
    
    //Process by mapping inputs to outputs
    
    //Output values
    if (month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12) {
        cout<<"There are 31 days in this month"<<endl;
    } else if (month==4 || month==6 || month==9 || month==11) {
        cout<<"There are 30 days in this month"<<endl;
    } else if (month==2) {
        if (((year%100)==0) && ((year%400)==0)) {
            cout<<"There are 29 days in this month! It is a leap year."<<endl;
        } else if (((year%100)==0) && ((year%400)!=0)) {
            cout<<"There are 28 days in this month"<<endl;
        } else if (((year%100)!=0) && ((year%4)==0)) {
            cout<<"There are 29 days in this month! It is a leap year."<<endl;
        } else {
            cout<<"There are 28 days in this month"<<endl;
        }
    } else {
        cout<<"The number entered for month is not a valid option. Please ";
        cout<<"select a number between 1 and 12"<<endl;
    }
}

void prob2() {
    //Declare all Variables Here
    //Constants
    const float YENDOLR=98.93;
    const float EURODLR=0.74;
    //Variables
    float dollars, totYen, totEuro;
    
    //Input or initialize values Here
    cout<<"This program converts dollar amounts to yen and euros"<<endl;
    cout<<"Enter a dollar amount"<<endl;
    cin>>dollars;
    
    //Process/Calculations Here
    totYen=dollars*YENDOLR;
    totEuro=dollars*EURODLR;
    
    //Output Located Here
    cout<<setprecision(2)<<fixed<<showpoint;
    cout<<dollars<<" is equivalent to "<<totYen<<" yen and "<<totEuro<<" Euros"<<endl;

}

void prob1() {
    //Declare all Variables Here
    float celsius, fahren;
    
    //Input or initialize values Here
    cout<<"This program will convert temperatures in Celsius to Fahrenheit"<<endl;
    cout<<"Enter the temperature in degrees Celsius"<<endl;
    cin>>celsius;
    
    //Process/Calculations Here
    fahren=(9/5)*celsius+32;
    
    //Output Located Here
    cout<<celsius<<" degrees Celsius is equivalent to "<<fahren<<" degrees Fahrenheit"<<endl;
}