/* 
  File:   main.cpp
  Author: Colleen Carleton
  Created on March 13, 2017, 4:10 PM
  Purpose:  Menu for the assignment 2 programs
 */

//System Libraries
#include <iostream>//Input Output Library
#include <iomanip> //Format Library
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

//Function Prototypes for Programs
//Program 9.2
void testSrt(int *, int);
float avgTest(int *, int);
//Program 9.6
void arrSort(int *, int);
void showAry(int *, int);
void showPtr(int *, int);
//Program 9.7
void arrSrt2(int *, int);
void shwAry2(int *, int);
void shwPtr2(int *, int);
//Mean Median Mode
void sortMMM(int *, int);
float averg(int *, int);
float medin(int *, int);
//Program 9.3
void tstSrt2(int *, int);
float avgTst2(int *, int);
//Program 9.10
int *reverse(int [], int);
//Program 9.11
int *incrAry(int *, int);
//Program 9.13
void sort(int *, int);

//Executable code begins here!!!
int main(int argc, char** argv) {
    //Declare Variables
    char choice;
    
    //Loop on the menu
    do{
    
        //Input values
        cout<<"Choose from the list"<<endl;
        cout<<"Type 1 for Problem 1 (9.2)"<<endl;
        cout<<"Type 2 for Problem 2 (9.6)"<<endl;
        cout<<"Type 3 for Problem 3 (9.7)"<<endl;
        cout<<"Type 4 for Problem 4 (Mean Median Mode)"<<endl;
        cout<<"Type 5 for Problem 5 (9.3)"<<endl;
        cout<<"Type 6 for Problem 6 (9.10)"<<endl;
        cout<<"Type 7 for Problem 7 (9.11)"<<endl;
        cout<<"Type 8 for Problem 8 (9.13)"<<endl;
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
            default:
                cout<<"You are exiting the program"<<endl;
        }
    }while(choice>='1'&&choice<='8');
    
    //Exit
    return 0;
}

void prob8() {
    //Declare and initialize variables
    int size=0;
    int sum=0;
    float avrg=0;
    float median=0;
    int mode=0;

    //Get size for array
    cout<<"Enter the number of students surveyed."<<endl;
    cin>>size;
    while (size<0) {
	cout<<"Number of students cannot be negative."<<endl;
	cin>>size;
    }

    //Create array
    int *moviAry=nullptr;
    moviAry= new int[size];

    //Fill array
    for (int count=0; count<size; count++) {
	cout<<"Enter the number of movies student "<<count+1<<" saw in one month."<<endl;
	cin>>*(moviAry+count);
	while (*(moviAry+count)<0) {
		cout<<"Number of movies cannot be negative."<<endl;
		cin>>*(moviAry+count);
	}
    }

    //Calculate and Output Average
    for (int i=0; i<size; i++) {
	sum+=*(moviAry+i);
    }
    avrg=(sum/static_cast<float>(size));
    cout<<setprecision(2)<<fixed<<showpoint;
    cout<<"The average number of movies seen per month is: "<<avrg<<endl;

    //Calculate and Output Median
    //Sort array
    sort(moviAry, size);
    //Find midpoint
    if (size%2==1) {
	//Odd
	median=moviAry[(size)/2];
    } else if (size%2==0) {
	//Even
	median=(moviAry[size/2]+moviAry[(size/2)-1])/static_cast<float>(2);
    }
    cout<<"The median number of movies seen per month is: "<<median<<endl;

    //Calculate and Output Mode
    int freq=0;
    int mode1=0;
    int *modeptr=nullptr;
    modeptr= new int[size];
    for (int i=0; i<size; i++) {
	if (moviAry[i]==moviAry[i+1]) {
		freq++;
	} else {
		*(modeptr+i)=freq;
		if (freq>mode1) { mode1=freq; }
		freq=0;
	}
    }
    //Search modeptr for the highest frequency (mode1) and output mode(s)
    if (mode1==0) { 
        cout<<"There was no mode."<<endl; 
    } else {
    cout<<"The mode appeared "<<mode1+1<<" times, and was: ";
    for (int count=0; count<size; count++) {
        if (*(modeptr+count)==mode1) {
            cout<<moviAry[count]<<" ";
        }
    }
    cout<<endl;
    }

    //Delete dynamic memory
    delete [] moviAry;
    moviAry=nullptr;
    delete [] modeptr;
    modeptr=nullptr;
}

void sort(int *moviAry, int size) {
    int srtStrt, mindex, minElem;

    for (srtStrt=0; srtStrt<size; srtStrt++) {
	mindex=srtStrt;
	minElem=moviAry[srtStrt];
            for (int index=srtStrt+1; index<size; index++) {
		if (*(moviAry+index) < minElem) {
                    minElem=moviAry[index];
                    mindex=index;
		}
	}
	moviAry[mindex] = moviAry[srtStrt];
	moviAry[srtStrt]=minElem;
    }
}

void prob7() {
    //Declare and initialize variables
    int *ptr= nullptr;
    const int SIZE=10;
    int ary1[SIZE]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    //Print array
    cout<<"These are the values in the array:"<<endl;
    for (int i=0; i<SIZE; i++) {
	cout<<ary1[i]<<" ";
    }
    cout<<endl;

    //Call function to increase size
    ptr=incrAry(ary1, SIZE);

    //Print increased array
    cout<<"These are the values in the increased array:"<<endl;
    for (int count=0; count<SIZE*2; count++) {
	cout<<*(ptr+count)<<" ";
    }
    cout<<endl;

    //Delete dynamic memory
    delete [] ptr;
    ptr=nullptr;
}

int *incrAry(int *arry1, int SIZE) {
    //Create new array
    int *array = nullptr;
    array = new int[SIZE*2];

    //Fill 2nd array
    for (int count=0; count<SIZE; count++) {
	array[count]=arry1[count];
    }
    for (int i=SIZE; i<(SIZE*2); i++) {
        array[i]=0;
    }

    //Return pointer
    return array;
}

void prob6() {
    //Declare and initialize variables
    const int SIZE=10;
    int arry1[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *ptr= nullptr;

    //Print array
    cout<<"These are the values in the array:"<<endl;
    for (int i=0; i<SIZE; i++) {
	cout<<arry1[i]<<" ";
    }
    cout<<endl;

    //Call function to reverse array
    ptr=reverse(arry1, SIZE);

    //Print reversed array
    cout<<"These are the values in the array reversed:"<<endl;
    for (int count=0; count<SIZE; count++) {
	cout<<*(ptr+count)<<" ";
    }
    cout<<endl;

    //Delete dynamic memory
    delete [] ptr;
    ptr=nullptr;
}

int *reverse(int arry1[], int SIZE) {
    //Create new array
    int *array = nullptr;
    array = new int[SIZE];

    //Fill 2nd array
    for (int count=0; count<SIZE; count++) {
	*(array+count)=arry1[(SIZE-1)-count];
    }

    //Return pointer
    return array;
}

void prob5() {
    //Declare all Variables Here
    int size=0; //Stores number of tests
    int *tests=nullptr; //pointer for array
    float avrage=0; //Stores average 
    
    //Get number of test scores
    cout<<"This program will sort and average test scores.";
    cout<<"Enter the number of tests."<<endl;
    cin>>size;
    while (size<2) {
	cout<<"There must be at least 2 tests."<<endl;
	cin>>size;
    }
    
    //Dynamically allocate array
    tests= new int[size];
    
    //Fill array with test scores
    for (int count=0; count<size; count++) {
        cout<<"Enter test score "<<count+1<<endl;
        cin>>tests[count];
        while (tests[count]<0) {
            cout<<"Test score cannot be negative."; //Validate test score
            cin>>tests[count];
        }
    }
    
    //Call function to sort the array
    tstSrt2(tests, size);
    
    //Find average

    avrage=avgTst2(tests, size);
    
    //Display sorted list and average
    //Display list
    cout<<"The test scores sorted are: ";
    for (int count=0; count<size; count++) {
        cout<<tests[count]<<" ";
    }
    cout<<endl;
    //Display average
    cout<<"The average of the test scores was "<<avrage<<endl;
    
    //Delete dynamically allocated array
    delete [] tests;
    tests=nullptr; //Make tests a null pointer again
}

void tstSrt2(int *tests, int size) {
    //Declare and initialize variables
    int index;
    int minElem;
    
    //Sort
    for (int start=0; start<size; start++) {
        index=start;
        minElem=*(tests+start);
        for (int i=start+1; i<size; i++) {
            if (*(tests+i) < minElem) {
                minElem=*(tests+i);
                index=i;
            }
        }
        *(tests+index) = *(tests+start);
        *(tests+start) = minElem;
    }
}

float avgTst2(int *tests, int size) {
    //Declare and initialize variables
    int total=0; //Stores total of scores
    float avrg=0; //Stores average
    
    //Get total
    for (int count=1; count<size; count++){
        total+=*(tests+count);
    }
    
    //Average
    avrg=static_cast<float>(total)/(size-1);
    
    //Return average
    return avrg;
}

void prob4() {
    //Declare all Variables Here
    int size=0;
    float avrg=0;
    float median=0;
    int mode=0;
    
    //Get size of array
    cout<<"Enter the number of values to be entered."<<endl;
    cin>>size;
    while (size<0) {
	cout<<"Number of values cannot be negative."<<endl;
	cin>>size;
    }
    
    //Create array
    int *aryMMM=nullptr;
    aryMMM= new int[size];

    //Fill array
    for (int count=0; count<size; count++) {
	cout<<"Enter the number for value "<<count+1<<endl;
	cin>>*(aryMMM+count);
	while (*(aryMMM+count)<0) {
		cout<<"Number cannot be negative."<<endl;
		cin>>*(aryMMM+count);
	}
    }
    
    //Call function to calculate average
    avrg=averg(aryMMM, size);
    cout<<"The average value was "<<avrg<<endl;
    
    //Call function to calculate median
    median=medin(aryMMM, size);
    cout<<"The median value was "<<median<<endl;
    
    //Calculate and Output Mode
    int freq=0;
    int mode1=0;
    int *modeptr=nullptr;
    modeptr= new int[size];
    for (int i=0; i<size; i++) {
	if (aryMMM[i]==aryMMM[i+1]) {
		freq++;
	} else {
		*(modeptr+i)=freq;
		if (freq>mode1) { mode1=freq; }
		freq=0;
	}
    }
    //Search modeptr for the highest frequency (mode1) and output mode(s)
    if (mode1==0) {
        cout<<"There was no mode."<<endl;
    } else {
    cout<<"The mode appeared "<<mode1+1<<" times, and was: ";
    for (int count=0; count<size; count++) {
        if (*(modeptr+count)==mode1) {
            cout<<aryMMM[count]<<" ";
        }
    }
    cout<<endl;
    }
    
    //Delete dynamic memory
    delete [] aryMMM;
    aryMMM=nullptr;
    delete [] modeptr;
    modeptr=nullptr;
}

float medin(int *aryMMM, int size) {
    //Variable
    float medi=0;
    
    //Find midpoint
    if (size%2==1) {
	//Odd
	medi=aryMMM[(size)/2];
    } else if (size%2==0) {
	//Even
	medi=(aryMMM[size/2]+aryMMM[(size/2)-1])/static_cast<float>(2);
    }
    
    //return median
    return medi;
}

float averg(int *aryMMM, int size) {
    //Variables
    float avrg=0;
    float sum=0;
    
    //Get sum and average
    for (int i=0; i<size; i++) {
	sum+=*(aryMMM+i);
    }
    avrg=(sum/static_cast<float>(size));
    
    //Return average
    return avrg;
}

void sortMMM(int *aryMMM, int size) {
    int srtStrt, mindex, minElem;

    for (srtStrt=0; srtStrt<size; srtStrt++) {
	mindex=srtStrt;
	minElem=aryMMM[srtStrt];
            for (int index=srtStrt+1; index<size; index++) {
		if (*(aryMMM+index) < minElem) {
                    minElem=aryMMM[index];
                    mindex=index;
		}
	}
	aryMMM[mindex] = aryMMM[srtStrt];
	aryMMM[srtStrt]=minElem;
    }
}

void prob3() {
    const int NUMDON = 15; //Number of donations

    //An array containing the donation amounts
    int donatns[NUMDON] = {5, 100, 5, 25, 10, 5, 25, 5, 5, 100, 10, 15, 10, 5, 10};

    //Display donations (original order)
    cout<<"The donations, in their original order, are:"<<endl;
    shwAry2(donatns, NUMDON);
    
    //An array of pointers to int
    int *arrPtr[NUMDON] = {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr};

    //Make each element point to an element in the first array
    for (int i=0; i<NUMDON; i++) {
	*(arrPtr+i)=&donatns[i];
    }

    //Call sort function
    arrSrt2(*arrPtr, NUMDON);

    //Display sorted donations (pointer array)
    cout<<"The donations, in sorted order, are: "<<endl;
    shwPtr2(*arrPtr, NUMDON);
}

void arrSrt2(int *arrPtr, int NUMDON) {
	int srtStrt, mindex, minElem;

	for (srtStrt=0; srtStrt<NUMDON; srtStrt++) {
		mindex=srtStrt;
		minElem=arrPtr[srtStrt];
		for (int index=srtStrt+1; index<NUMDON; index++) {
			if (*(arrPtr+index) > minElem) {
				minElem=arrPtr[index];
				mindex=index;
			}
		}
		arrPtr[mindex] = arrPtr[srtStrt];
		arrPtr[srtStrt]=minElem;
	}
}

void shwAry2(int donatns[], int NUMDON) {
	for (int count=0; count<NUMDON; count++) {
		cout<<donatns[count]<<" ";
	}
	cout<<endl;
}

void shwPtr2(int *arrPtr, int NUMDON) {
	for (int count=0; count<NUMDON; count++) {
		cout<<*(arrPtr+count)<<" ";
	}
	cout<<endl;
}

void prob2() {
    //Declare Variables, pointer
    int numDon=0;
    int *donPtr = nullptr;
    int *arrPtr = nullptr;
    
    //Get number of donations
    cout<<"Enter the number of donations received."<<endl;
    cin>>numDon;
    
    //Create array
    donPtr = new int[numDon];

    //Fill Array
    for (int count=0; count<numDon; count++) {
	cout<<"Enter the donation amount for donation "<<count+1<<endl;
	cin>>donPtr[count];
    }

    //An array of pointers to int
    arrPtr = new int[numDon];

    //Make each element point to an element in the first array
    for (int i=0; i<numDon; i++) {
	arrPtr[i]=donPtr[i];
    }
    
    //Call sort function
    arrSort(arrPtr, numDon);
    
    //Display sorted donations (pointer array)
    cout<<"The donations, in sorted order, are: "<<endl;
    showPtr(arrPtr, numDon);
    
    //Display donations (original order)
    cout<<"The donations, in their original order, are:"<<endl;
    showAry(donPtr, numDon);
    
    //Delete dynamically allocated arrays
    delete [] donPtr;
    donPtr=nullptr;
    delete [] arrPtr;
    arrPtr=nullptr;
}

void arrSort(int *arrPtr, int NUMDON) {
	int srtStrt, mindex, minElem;

	for (srtStrt=0; srtStrt<NUMDON; srtStrt++) {
		mindex=srtStrt;
		minElem=arrPtr[srtStrt];
		for (int index=srtStrt+1; index<NUMDON; index++) {
			if (*(arrPtr+index) < minElem) {
				minElem=arrPtr[index];
				mindex=index;
			}
		}
		arrPtr[mindex] = arrPtr[srtStrt];
		arrPtr[srtStrt]=minElem;
	}
}

void showAry(int *arrPtr, int NUMDON) {
	for (int count=0; count<NUMDON; count++) {
		cout<<*(arrPtr+count)<<" ";
	}
	cout<<endl;
}

void showPtr(int *arrPtr, int NUMDON) {
	for (int count=0; count<NUMDON; count++) {
		cout<<*(arrPtr+count)<<" ";
	}
	cout<<endl;
}

void prob1() {
    //Declare all Variables Here
    int size=0; //Stores number of tests
    int *tests=nullptr; //pointer for array
    float avrage=0; //Stores average 
    
    //Get number of test scores
    cout<<"This program will sort and average test scores.";
    cout<<"Enter the number of tests."<<endl;
    cin>>size;
    
    //Dynamically allocate array
    tests= new int[size];
    
    //Fill array with test scores
    for (int count=0; count<size; count++) {
        cout<<"Enter test score "<<count+1<<endl;
        cin>>tests[count];
        while (tests[count]<0) {
            cout<<"Test score cannot be negative."; //Validate test score
            cin>>tests[count];
        }
    }
    
    //Call function to sort the array
    testSrt(tests, size);
    
    //Find average

    avrage=avgTest(tests, size);
    
    //Display sorted list and average
    //Display list
    cout<<"The test scores sorted are: ";
    for (int count=0; count<size; count++) {
        cout<<tests[count]<<" ";
    }
    cout<<endl;
    //Display average
    cout<<"The average of the test scores was "<<avrage<<endl;
    
    //Delete dynamically allocated array
    delete [] tests;
    tests=nullptr; //Make tests a null pointer again
}

void testSrt(int *tests, int size) {
    //Declare and initialize variables
    int index;
    int minElem;
    
    //Sort
    for (int start=0; start<size; start++) {
        index=start;
        minElem=*(tests+start);
        for (int i=start+1; i<size; i++) {
            if (*(tests+i) < minElem) {
                minElem=*(tests+i);
                index=i;
            }
        }
        *(tests+index) = *(tests+start);
        *(tests+start) = minElem;
    }
}

float avgTest(int *tests, int size) {
    //Declare and initialize variables
    int total=0; //Stores total of scores
    float avrg=0; //Stores average
    
    //Get total
    for (int count=0; count<size; count++){
        total+=*(tests+count);
    }
    
    //Average
    avrg=static_cast<float>(total)/size;
    
    //Return average
    return avrg;
}