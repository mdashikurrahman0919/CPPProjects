/*
Name : Md Ashikur Rahman
ID   : 20170919
Frameworke : Framework for project 04
Projecert name : Application
Date   :  15 October 2021
Aouthor : MD ASHIKUR RAHMNA
Copyright : @ashikurrahman
Description : A Framework that includes Menu and user choices
*/
#include <iostream>
#include <math.h>		// sqrt()
#include <string>		// for string variables.
#include <stdlib.h>		// isdigit()..
#include <ctype.h>		// .. etc
#include "windows.h"	// SetConsoleTextAttribute

using namespace std;

void ShowMenu();
void Chicken100();
void Book5Children3();
void CarPlate();
void MultiplicationTable99();
void Chessboard();
void Factorization();
void CharacterAnalysis();
bool SetTextColor(int code);
void Goodbye();

int main(int argc, char *argv[])
{
	int choice=0;
 	while (choice != 8)
 	{
		ShowMenu();
      	while (!(cin >> choice) || (choice < 1) || (choice > 8))
      	{
          	cout<<"\n\tINVALID INPUT! Please input from number between 1-8: ";
          	cin.clear(); cin.sync();
      	}
		cout<<"\n\tYour choice is: "<<choice<<"\n\n";
		cin.sync();
		switch(choice)
		{
		case 1:
			Chicken100();
		    break;
		case 2:
			Book5Children3();
		    break;
		case 3:
			CarPlate();
		    break;
		case 4:
			MultiplicationTable99();
		    break;
		case 5:
			Chessboard();
		    break;
		case 6:
			Factorization();
		    break;
		case 7:
			CharacterAnalysis();
		    break;
		case 8:
			Goodbye();
		    break;

		}
		cout<<"\n\tPress the ENTER key to return to the menu."<<endl;
		getchar();
	}
	getchar();
	return 0;
}

void ShowMenu()
{
	cout<<"\n\n";
	cout<<"\t\t================== PROJECT APPLICATIONS =================="<<endl;
	cout<<"\n";
	cout<<"\t\t=========================================================="<<endl;
	cout<<"\t\t================== APPLICATION MENU ======================"<<endl;
	cout<<"\t\t##########################################################"<<endl;
	cout<<"\t\t#                                                        #"<<endl;
	cout<<"\t\t#    1. $100 & 100 Chickens                              #"<<endl;
	cout<<"\t\t#                                                        #"<<endl;
	cout<<"\t\t#    2. 5 Books to 3 Children                            #"<<endl;
	cout<<"\t\t#                                                        #"<<endl;
	cout<<"\t\t#    3. Criminal's Car Plate                             #"<<endl;
	cout<<"\t\t#                                                        #"<<endl;
	cout<<"\t\t#    4. 9x9 Multiplication Table                         #"<<endl;
	cout<<"\t\t#                                                        #"<<endl;
	cout<<"\t\t#    5. Chess Board                                      #"<<endl;
	cout<<"\t\t#                                                        #"<<endl;
	cout<<"\t\t#    6. Factorization                                    #"<<endl;
	cout<<"\t\t#                                                        #"<<endl;
	cout<<"\t\t#    7. Character Analysis                               #"<<endl;
	cout<<"\t\t#                                                        #"<<endl;
	cout<<"\t\t#    8. Exit                                             #"<<endl;
	cout<<"\t\t#                                                        #"<<endl;
	cout<<"\t\t##########################################################"<<endl;
	cout<<"\t\t==================== @ashikurrahman ======================"<<endl;
	cout<<"\t\t=========================================================="<<endl;

	cout<<"\n\n\tPlease select any number whenever you are ready : ";
}

void Chicken100()
{
	SetTextColor(10);
	cout<<"\tZhang Qiujian, an ancient Chinese mathematician, once put forward"<<endl;
	cout<<"\tthe famous problem of \"a hundred dollars for a hundred chickens\"."<<endl;
	cout<<"\tA rooster's price is $5; a hen's price is $3, and three chicks' price is $3."<<endl;
	cout<<"\tQUESTION: To buy 100 chickens with $100, how many are each of the"<<endl;
	cout<<"\troosters, hens, and chickens?\n"<<endl;
	SetTextColor(15);

	int rooster, hen, chick;
	int cnt=0;
	for (rooster=0; rooster<100/5; rooster++){
		for (hen=0; hen<100/3; hen++){
			chick = 100-rooster-hen;
			if (rooster*15 + hen*9 + chick == 300)		//(rooster*5 + hen*3 + chick/3 == 100)*3 == 100*3
			{
				cnt++;
				cout<<"\tSolution "<<cnt<<" => Rooster: " <<rooster<<", Hen: "<<hen<<", Chick: "<<chick<<endl;
				getchar();
			}
		}
	}

	cout<<"\n\tInput Q to close program, or press ENTER key to return to menu: ";
	if (cin.peek() == 'q') exit(0);

}

void Book5Children3()
{
	SetTextColor(10);
	cout<<"\tThere are 5 books to lend to A, B, and C."<<endl;
	cout<<"\tIf everyone could borrow only 1 book,"<<endl;
	cout<<"\thow many different ways could they borrow the books?"<<endl;
	SetTextColor(15);

	int aBook=0, bBook=0, cBook=0;
	int i=1, j=1, k=1, count=0;

	for(i=1; i<=5; i++)
	{
		switch(i)
		{
			case 1:
				SetTextColor(8);
				break;
			case 2:
				SetTextColor(9);
				break;
			case 3:
				SetTextColor(11);
				break;
			case 4:
				SetTextColor(13);
				break;
			case 5:
				SetTextColor(14);
				break;
		}
		aBook = i;
		for(j=1; j<=5; j++)
		{
			bBook = j;
			for(k=1; k<=5 ; k++)
			{
				cBook = k;
				if (bBook!=aBook && cBook!=aBook && cBook!=bBook)
				{
					count++;
					if (count<10) 	cout<<"\tSolution  "<<count<<": "<<aBook<<","<<bBook<<","<<cBook<<"\t";
					else			cout<<"\tSolution "<<count<<": "<<aBook<<","<<bBook<<","<<cBook<<"\t";
				}
			}
			cout<<"\n";
		}
	}
	SetTextColor(15);

	cout<<"\n\tInput Q to close program, or press ENTER key to return to menu: ";
	if (cin.peek() == 'q') exit(0);
}

void CarPlate()
{
	SetTextColor(10);
	cout<<"\tA car hit a man and ran away. No one remembers the"<<endl;
	cout<<"\tcar plate number, only some characteristics about it."<<endl;
	cout<<"\n";
	cout<<"\tA said: the first two numbers of the license are the same."<<endl;
	cout<<"\n";
	cout<<"\tB said: the last two numbers of the license are the same,"<<endl;
	cout<<"\tbut different from the first two."<<endl;
	cout<<"\tC is a mathematician, and he said: the four-digit car number"<<endl;
	cout<<"\tis exactly the square of an integer."<<endl;
	cout<<"\n";
	cout<<"\tWhat is the car plate number?\n"<<endl;


	int digit1=0, digit2=0, digit3=0, digit4=0;		// The order is 1234. Ex: 1168 => digit1=1, digit4=8.
	int plateNum=0;

	for(int i=0; i<100; i++)						// 99*99 = 9801, the last square of an integer to have 4 digits.
	{
		int num=i*i;
		if (num>=1000)
		{
			digit1 = num/1000;
			digit2 = (num/100)%10;
			digit3 = (num/10)%10;
			digit4 = num%10;

			if(digit1==digit2 && digit3==digit4 && digit1 != digit3)
			{
				SetTextColor(15);
				cout<<"\n\n\tThe plate number is: ";
				SetTextColor(9);
				cout<<i*i<<endl;
				SetTextColor(15);
			}
		}
	}
	cout<<"\n\tInput Q to close program, or press ENTER key to return to menu: ";
	if (cin.peek() == 'q') exit(0);
}

void MultiplicationTable99()
{
	SetTextColor(10);
	for(int i=1; i<=9; i++){
		for(int j=1; j<=i; j++){
			cout<<" "<<j<<"x"<<i<<"="<<j*i<<"\t";
		}
		cout<<"\n";
	}
	SetTextColor(15);

	cout<<"\n\tInput Q to close program, or press ENTER key to return to menu: ";
	if (cin.peek() == 'q') exit(0);
}

void Chessboard()
{
	int size = 17;
	char a=219;

	for(int i=0; i<size; i++) {
		cout<<"\t";
		for(int j=0; j<size; j++) {
			if((i+j)%2 == 0)
				cout<<a<<a;
			else
				cout<<"  ";
		}
		cout<<"\n";
	}
	cout<<"\n\tInput Q to close program, or press ENTER key to return to menu: ";
	if (cin.peek() == 'q') exit(0);
}

void Factorization()
{
	int num;
	int factors[32];
	int arraySize=-1;
	bool isOne=false, isTwo=false;

    cout<<"\tPlease input a positive integer (input 888 to exit): ";

	while(num != 888)
    {
    	while (!(cin>>num) || num<1)
      	{
          	cout<<"\n\tINVALID INPUT! Please input positive integer: ";
          	cin.clear(); cin.sync();
      	}
      	if (num != 888)
	 	{
		 	if 		(num == 1) isOne = true;
	 		else if (num == 2) isTwo = true;

	    	while (num%2==0)
		    {
	    		arraySize++;
		        factors[arraySize] = 2;
		        num = num/2;
		    }

		    for (int i=3; i<=sqrt(num); i+=2)
		    {
		        while (num%i==0)
		        {
		            arraySize++;
		        	factors[arraySize] = i;
		            num = num/i;
		        }
		    }

		    if (num>2)
		    {
		    	if (arraySize != -1)				// If arraySize == 1, means no factorization happened. Which means the number shouldn't be added to the factors..
				{									// ..in order for the program to be able to evaluate the in as prime.
					arraySize++;
			        factors[arraySize] = num;
		    	}
		    }
			cout<<"\n\t";

			if (isTwo) arraySize = -1;

			if (arraySize == -1)
			{
				SetTextColor(9);
				if (isOne) 	cout<<"1 is neither prime nor composite.\n";
				else		cout<<"The input is a prime.\n";
				SetTextColor(15);
			}
			else {
				for(int i=0; i<=arraySize; i++){
					SetTextColor(10);
		    		if (i != arraySize) cout<<factors[i]<<" x ";
		   			else				cout<<factors[i]<<endl;
		   			SetTextColor(15);
		    	}
			}
			arraySize = -1; isOne = false; isTwo = false;						// Variable resets.
		    cout<<"\n\tPlease input your number (input 888 to exit): ";
		} else cout<<"\n\tExiting the loop.\n";
    }
    getchar();
    cout<<"\n\tInput Q to close program, or press ENTER key to return to menu: ";
	if (cin.peek() == 'q') exit(0);
}

void CharacterAnalysis()
{
	string input = "";
	int letters=0, digits=0, spaces=0, chars=0;

	while (input != "888")
	{
		cout<<"\n\tPlease enter string ";
		SetTextColor(12);
		cout<<"(ENTER 888 TO RETURN TO MAIN MENU): ";
		SetTextColor(15);
		getline(cin,input);

		if (input != "888")
		{
			for (int i = 0; i < input.size(); i++){
		    	if (isalpha(input[i])) letters++;
		    	else if (isdigit(input[i])) digits++;
		    	else if (isspace(input[i])) spaces++;
				else chars++;
			}
			cout<<"\n\tLetters: "<<letters<<endl;
			cout<<"\n\tDigits: "<<digits<<endl;
			cout<<"\n\tSpaces: "<<spaces<<endl;
			cout<<"\n\tOthers: "<<chars<<endl;
			letters=0; digits=0; spaces=0; chars=0;
		}
		else cout<<"\n\tReturning to main menu. . .\n";
	}
	cout<<"\n\tInput Q to close program, or press ENTER key to return to menu: ";
	if (cin.peek() == 'q') exit(0);
}

bool SetTextColor(int code){ SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),code); }

void Goodbye()
{
	SetTextColor(10);
	cout<<"\n\n";
	cout<<"\t\t                   *****************                       "<<endl;
    cout<<"\t\t               ******               ******                 "<<endl;
    cout<<"\t\t           ****                           ****             "<<endl;
    cout<<"\t\t        ****                                 ***           "<<endl;
    cout<<"\t\t      ***                                       ***        "<<endl;
    cout<<"\t\t     **           ***               ***           **       "<<endl;
    cout<<"\t\t   **           *******           *******          ***     "<<endl;
    cout<<"\t\t  **            *******           *******            **    "<<endl;
    cout<<"\t\t **             *******           *******             **   "<<endl;
    cout<<"\t\t **               ***               ***               **   "<<endl;
    cout<<"\t\t**                                                     **  "<<endl;
    cout<<"\t\t**       *                                     *       **  "<<endl;
    cout<<"\t\t**      **                                     **      **  "<<endl;
    cout<<"\t\t **   ****                                     ****   **   "<<endl;
    cout<<"\t\t **      **                                   **      **   "<<endl;
    cout<<"\t\t  **       ***                             ***       **    "<<endl;
    cout<<"\t\t   ***       ****                       ****       ***     "<<endl;
    cout<<"\t\t     **         ******             ******         **       "<<endl;
    cout<<"\t\t      ***            ***************            ***        "<<endl;
    cout<<"\t\t        ****                                 ****          "<<endl;
    cout<<"\t\t           ****                           ****             "<<endl;
    cout<<"\t\t               ******               ******                 "<<endl;
    cout<<"\t\t                    *****************    MD ASHIKUR RAHMAN "<<endl;
    cout<<"\n\n\t\t\tHOPE YOU ENJOYED THE APPLICATION . (THANKE YOU) ";

    SetTextColor(15);

    exit(0);
}
