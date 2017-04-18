/* 
  File:   main.cpp
  Author: Colleen Carleton
  Created on April 14, 2017, 10:07 AM
  Purpose: Program that allows the user to play a Random Color Puzzle game.
 * Version 1.1:
 * Added in the functions of the various colors. An issue arose where colors 
 * that could not be stepped on surrounded the finish area. A fix for this will
 * be added in the next version.
 */

//System Libraries
#include <iostream> //Input/output
#include <fstream>  //File input/output
#include <cstdlib>  //For random number seed
#include <ctime>    //Time
#include <cctype>   //Case conversions
using namespace std;

//User Libraries
#include "Mode.h"

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from system of units to 
//another

//Function Prototypes
void gmeInfo();
void game();

void fillAry(Mode, int, int);

//Executable code begins here!!!
int main(int argc, char** argv) {
    //Declare variables
    char choice; //Player's selection from the menu
    char cont;   //Does player want to continue?
    
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));

    //Get player's choice
    cout<<"Welcome to the Random Color Puzzle!"<<endl;
    do {
            cout<<"Select an option:"<<endl;
            cout<<"Enter 1 for game instructions."<<endl;
            cout<<"Enter 2 to play the game."<<endl;
            cout<<"Enter 3 to quit the game."<<endl;
            cin>>choice;

            switch (choice) {
                    case '1': gmeInfo(); break;
                    case '2': game(); break;
                    default: cout<<"Thanks for playing!"<<endl; break;
            }
            
            //Do they want to play again/continue?
            cout<<"Do you want to continue or play again? Enter y to continue, and n to quit."<<endl;
            cin>>cont;
    } while (cont==tolower('y'));
    
    //Exit
    return 0;
}

void gmeInfo() {
    //Declare Variable
    char a; //Stores player's choice

    cout<<"The Random Color Puzzle will create a unique puzzle of random colors every time you play it."<<endl;
    cout<<"The goal of the game is to reach the end of the puzzle (denoted by the character 'f' in the puzzle)."<<endl;
    cout<<"The rest of the characters making up the puzzle will represent colors, each of which has a different function."<<endl;
    do {
	cout<<"Enter 1 for the functions of the colors, 2 for controls, and 3 for information on modes.  Enter e if you are finished reading."<<endl;
	cin>>a;

	//Display info
	if (a=='1') {
	//Display character/color information
	cout<<"In the puzzle, there will be 8 different characters. 'c' marks the location of your character, and 'f' marks the ending point of the puzzle."<<endl;
	cout<<"The character 'b' stands for blue, which is water. You can cross it, unless the space you were standing on before was 'o', which represents orange."<<endl;
	cout<<"Furthermore, spaces marked 'y', for yellow, cannot be crossed, and if they are next to a blue space, you cannot cross the blue space either."<<endl;
	cout<<"Spaces marked 'p', for purple, and 'g', for green, have no effect. Spaces marked 'r' for red cannot be crossed."<<endl;
	cout<<"The color that will appear in each space will be chosen randomly."<<endl;
	} else if (a=='2') {
	cout<<"The controls for the game are simple, use the wasd keys to travel through the puzzle. To go up, press 'w'; to go down, press 's'; to go back a space, press 'a';";
	cout<<" and to go forward a space, press 'd'."<<endl;
	//cout<<"You can exit the puzzle at any time by pressing 'q'."<<endl;
	} else if (a=='3') {
	cout<<"At the beginning of the game, you will be asked to select a mode. There are 3 modes, easy, medium, and hard."<<endl;
	cout<<"Selecting easy means the puzzle created will have dimensions of 3x5."<<endl;
	cout<<"Selecting medium means the puzzle created will have dimensions of 5x5."<<endl;
	cout<<"Selecting hard means the puzzle created will have dimensions of 7x10."<<endl;
	}
    } while (a>='1' && a<='3');
}

void game() {
	//Declare variables
	int mode; //Stores mode
	fstream pzzlFil; //Opens puzzle-storing file
	char ch; //Stores the characters as they are input from the file
	char movmnt; //Stores character's movements
	char temp; //Holds character's temporary location (rows)
	char temp2; //Holds character's temporary location (columns)
        int rowsize; //Stores size of rows
        int colsize; //Stores size of columns

	//Get player's mode
	cout<<"Choose a mode to play: Enter 1 for Easy, 2 for Medium, and 3 for Hard."<<endl;
	cin>>mode;
	//Validate input
	while (mode<1 || mode>3) {
	cout<<"Enter only 1 (Easy), 2 (Medium), or 3 (Hard)."<<endl;
	cin>>mode;
	}
	
	//Set up array size based on mode
	if (mode==1) {
            Mode easy={3, 5};
            rowsize=easy.row;
            colsize=easy.col;
            //Fill Array
            fillAry(easy, rowsize, colsize);
	} else if (mode==2) {
            Mode medium={5, 5};
            rowsize=medium.row;
            colsize=medium.col;
            //Fill Array
            fillAry(medium, rowsize, colsize);
	} else if (mode==3) {
            Mode hard={7, 10};
            rowsize=hard.row;
            colsize=hard.col;
            //Fill Array
            fillAry(hard, rowsize, colsize);
	}

	//Open file for input
	pzzlFil.open("puzzle.txt", ios::in);
        
        //Create array to store the colors
        char coloray[rowsize][colsize];
        //Fill array
        for (int i=0; i<rowsize; i++) {
            for (int j=0; j<colsize; j++) {
                pzzlFil.get(ch);
                coloray[i][j]=ch;
            }
        }
        pzzlFil.clear(); pzzlFil.seekp(0, ios::beg); //Clear eof flag, return to beginning

	//Create second array to store character's position in array
	char charPos[rowsize][colsize]={'0'};
	charPos[0][0]='c';

	//Output the array, but with c in the character's position
	for (int i=0; i<rowsize; i++) {
		for (int j=0; j<colsize; j++) {
			if (charPos[i][j]=='c') {
				cout<<"c"<<" ";
                                pzzlFil.get(ch);
			} else if (i==rowsize-1 && j==colsize-1) {
                            cout<<"f"<<" ";
                        } else {
				pzzlFil.get(ch);
				cout<<ch<<" ";
			}
		}
		cout<<endl;
	}
        pzzlFil.clear(); pzzlFil.seekp(0, ios::beg); //Clear eof flag, return to beginning

	//Start game
	do {
		//Get user's first movement
		cout<<"Enter w, a, s, or d to move up, backwards, down, or forward one step."<<endl;
		cin>>movmnt;
		while (movmnt!='w' && movmnt!='a' && movmnt!='s' && movmnt!='d') {
			cout<<"You can only move using w, a, s, or d."<<endl;
			cin>>movmnt;
		}

		//Move character according to user's input
		if (movmnt=='w') {
			for (int i=0; i<rowsize; i++) {
				for (int j=0; j<colsize; j++) {
					if (charPos[i][j]=='c') {
						temp=i; //Store position in rows
						temp2=j; //Store position in columns
					}
				}
			}

			//Input validation
			if (temp-1<0 || coloray[temp-1][temp2]=='r' || coloray[temp-1][temp2]=='y') {
				cout<<"Invalid movement."<<endl;
			} else {
			//Place 'c' in new location
			charPos[(temp-1)][temp2]='c';

			//Clear old location of 'c'
			charPos[temp][temp2]='0';
			}

		} else if (movmnt=='a') {
			for (int i=0; i<rowsize; i++) {
				for (int j=0; j<colsize; j++) {
					if (charPos[i][j]=='c') {
						temp=i; //Store position in rows
						temp2=j; //Store position in columns
					}
				}
			}

			//Input validation
			if (temp2-1<0 || coloray[temp][temp2-1]=='r' || coloray[temp][temp2-1]=='y') {
				cout<<"Invalid movement."<<endl;
			} else {
			//Place 'c' in new location
			charPos[temp][(temp2-1)]='c';

			//Clear old location of 'c'
			charPos[temp][temp2]='0';
			}

		} else if (movmnt=='s') {
			for (int i=0; i<rowsize; i++) {
				for (int j=0; j<colsize; j++) {
					if (charPos[i][j]=='c') {
						temp=i; //Store position in rows
						temp2=j; //Store position in columns
					}
				}
			}
			
			//Input validation
			if (temp+1>(rowsize-1) || coloray[temp+1][temp2]=='r' || coloray[temp+1][temp2]=='y') {
				cout<<"Invalid movement."<<endl;
			} else {
			//Place 'c' in new location
			charPos[(temp+1)][temp2]='c';

			//Clear old location of 'c'
			charPos[temp][temp2]='0';
			}
		} else {
			for (int i=0; i<rowsize; i++) {
				for (int j=0; j<colsize; j++) {
					if (charPos[i][j]=='c') {
						temp=i; //Store position in rows
						temp2=j; //Store position in columns
					}
				}
			}
			
			//Input validation
			if (temp2+1>(colsize-1) || coloray[temp][temp2+1]=='r' || coloray[temp][temp2+1]=='y') {
				cout<<"Invalid movement"<<endl;
			} else {
			//Place 'c' in new location
			charPos[temp][(temp2+1)]='c';

			//Clear old location of 'c'
			charPos[temp][temp2]='0';
			}

		}

		//Ouput new position in puzzle
		for (int i=0; i<rowsize; i++) {
			for (int j=0; j<colsize; j++) {
				if (charPos[i][j]=='c') {
					cout<<"c"<<" ";
                                        pzzlFil.get(ch);
				} else if (i==rowsize-1 && j==colsize-1) {
                                    cout<<"f"<<" ";
                                } else {
					pzzlFil.get(ch);
					cout<<ch<<" ";
				}
			}
			cout<<endl;
		}
                pzzlFil.clear(); pzzlFil.seekp(0, ios::beg); //Clear eof, return to beginning
		
	} while (charPos[(rowsize-1)][(colsize-1)]!='c');

	//Once they reach the end, congratulate them
	cout<<"Congratulations! You have reached the end of the puzzle!"<<endl;
        
        //Close file
        pzzlFil.close();

}

void fillAry(Mode ezmedhd, int rowsize, int colsize) {
	//declare variables
	int random; //Stores random number
        fstream pzzl1; //Opens file for output
        
        //Create Array
	char puzzle[rowsize][colsize];
	
	//Fill array with random colors
	for (int i=0; i<rowsize; i++) {
		for (int j=0; j<colsize; j++) {
			//Get random number
			random=rand()%6+1; //Random number from 1-6

			//Get character
			if (random==1) {
				puzzle[i][j]='y'; //If 1
			} else if (random==2) {
				puzzle[i][j]='b'; //If 2
			} else if (random==3) {
				puzzle[i][j]='p'; //If 3
			} else if (random==4) {
				puzzle[i][j]='r'; //If 4
			} else if (random==5) {
				puzzle[i][j]='o'; //If 5
			} else {
				puzzle[i][j]='g'; //If 6
			}
		}
	}
        
        //Change last element in array to f
	puzzle[(rowsize-1)][(colsize-1)]='f';
        
        //Write array to file
	pzzl1.open("puzzle.txt", ios::out);
	for (int i=0; i<rowsize; i++) {
		for (int j=0; j<colsize; j++) {
			pzzl1.put(puzzle[i][j]);
		}
	}
        
        //Close file for output
	pzzl1.close();

}