/*
Name           : Md Ashikur Rahman
ID             : 20170919
Frameworke     : Framework for project 06
Projecert name : Conjectures
Date           : 05 november 2021
Aouthor        : MD ASHIKUR RAHMNA
Copyright      : @ashikurrahman
Description    : A Framework that includes Menu and user choices

*/


#include <iostream>
#include <math.h>       // sqrt()
#include "windows.h"    // SetConsoleTextAttribute

using namespace std;

void ShowMenu();
bool SetTextColor(int code);
bool IsPrime(int n);
bool IsEven(int n);
bool IsOdd(int n);

void Goldbach();
void Collatz();
void NicoChester();
void FourSquare();
void Eratosthenes();
void BrideNGroom();
void TruthOrLie();
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
            cin.clear();
            cin.sync();
        }
        cout<<"\n\tYour choice is: "<<choice<<"\n\n";
        cin.sync();
        switch(choice)
        {
        case 1:
            Goldbach();
            break;
        case 2:
            Collatz();
            break;
        case 3:
            NicoChester();
            break;
        case 4:
            FourSquare();
            break;
        case 5:
            Eratosthenes();
            break;
        case 6:
            BrideNGroom();
            break;
        case 7:
            TruthOrLie();
            break;
        case 8:
            Goodbye();
            break;
        }
        cout<<"\n\Press the ENTER KEY to return to the menu."<<endl;
        getchar();
    }
    getchar();
	return 0;
}

void ShowMenu()
{
    cout<<"\n\n\t\t8888888888888888888888 Project 06 Conjectures 8888888888888888888888\n\n"<<endl;

    cout<<"\t\t888888888888888888888888 Conjectures Menu 88888888888888888888888888"<<endl;
    cout<<"\t\t88888888888888888888888888888888888888888888888888888888888888888888"<<endl;
    cout<<"\t\t88                                                                88"<<endl;
    cout<<"\t\t88                                                                88"<<endl;
    cout<<"\t\t88        1. Goldbach's Conjecture                                88"<<endl;
    cout<<"\t\t88                                                                88"<<endl;
    cout<<"\t\t88        2. Collatz Conjecture                                   88"<<endl;
    cout<<"\t\t88                                                                88"<<endl;
    cout<<"\t\t88        3. Nico Chester Theorem                                 88"<<endl;
    cout<<"\t\t88                                                                88"<<endl;
    cout<<"\t\t88        4. Four Square Theorem                                  88"<<endl;
    cout<<"\t\t88                                                                88"<<endl;
    cout<<"\t\t88        5. Sieve of Eratosthenes                                88"<<endl;
    cout<<"\t\t88                                                                88"<<endl;
    cout<<"\t\t88        6. Bride & Groom                                        88"<<endl;
    cout<<"\t\t88                                                                88"<<endl;
    cout<<"\t\t88        7. Truth or Lie                                         88"<<endl;
    cout<<"\t\t88                                                                88"<<endl;
    cout<<"\t\t88        8. Exit                                                 88"<<endl;
    cout<<"\t\t88                                                                88"<<endl;
    cout<<"\t\t88                                                                88"<<endl;
    cout<<"\t\t888888888888888888888888888 @ashikurrahman 8888888888888888888888888"<<endl;
    cout<<"\t\t88888888888888888888888888888888888888888888888888888888888888888888"<<endl;
    cout<<"\n\n\tPlease select any number from Menu : ";
}

bool SetTextColor(string color)
{
	if 		(color == "Green") 	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	else if (color == "Red") 	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	else if (color == "Purple") SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
	else if (color == "White") 	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
}

bool IsPrime(int n)
{
    if (n <= 1) return false;

    for (int i = 2; i < n; i++)
        if (n % i == 0) return false;

    return true;
}

bool IsEven(int n){ return n%2==0; }
bool IsOdd (int n){ return n%2==1; }

void Goldbach()
{
	int num, primeA, primeB, pairCount=0;

	cout<<"\t====================Goldbach's Conjecture======================="<<endl;
    cout<<"\n";
    cout<<"\tFor any even number N greater than or equal to 4, there exists"<<endl;
    cout<<"\tat least one pair of prime numbers p1 and p2 such that N = p1 + p2."<<endl;
    cout<<"\n";
	SetTextColor("Red");
    cout<<"\tNOTICE: Input 888 to return to the menu."<<endl;
    SetTextColor("White");

    while (num != 888)
    {
    	cout<<"\n\tPlease input a positive even integer: ";
	    cin>>num;

	    if (num != 888)
	    {
    		for (int i=1; i<num; i++)
			{
				if (IsPrime(i)){
					int temp = num - i;
					if (IsPrime(temp) && i < temp){							// i<temp is to avoid repeating the same case, i.e c=a+b and c=b+a
						pairCount++;
						primeA = i;
						primeB = temp;
						cout<<"\n\t"<<num<<" = "<<primeA<<" + "<<primeB<<endl;
					}
				}
		    }
		    cout<<"\n\t"<<"There are "<<pairCount<<" pairs of primes that add up to "<<num<<endl;
    	} else cout<<"\n\tReturning to main menu. . ."<<endl;
    }
}

void Collatz()
{
	int num;
	cout<<"\t============================Collatz Conjecture========================="<<endl;
    cout<<"\n";
    cout<<"\tTake any positive number: if it's even you divide it by 2 and if it's odd"<<endl;
    cout<<"\tmultiply it by 3 and add 1. Repeat this process indefinitely, no matter what number you"<<endl;
    cout<<"\tstart with, you will always end up at 1."<<endl;
    cout<<"\n";
    cout<<"\tThe conjecture remains stubbornly unproven. Mathematics is not yet ready for such problems."<<endl;
	SetTextColor("Red");
    cout<<"\tNOTICE: Input 888 to return to the menu."<<endl;
    SetTextColor("White");

    while (num != 888)
    {
	   	cout<<"\n\t"<<"Please input a positive integer: ";
	    cin>>num;
	    if (num != 888)
	    {
	   		cout<<"\n";
		    cout<<num<<"->";
		    while (num != 1)
		    {
		    	if (IsEven(num))
				{
					num/=2;
					if (num!= 1) cout<<num<<"->";
					else		 cout<<num;
			    }
				else if (IsOdd(num))
				{
					num*=3; num+=1;
					cout<<num<<"->";
				}
		    }
		    cout<<"\n";
    	} else cout<<"\n\tReturning to main menu. . ."<<endl;
    }
}

void NicoChester()
{
	int num, sum;

	cout<<"\t===================Nico Chester Theorem======================="<<endl;
    cout<<"\n";
    cout<<"\tAny integer to the third power can be represented as the sum of"<<endl;
    cout<<"\ta series of consecutive odd numbers."<<endl;
    cout<<"\n";
	SetTextColor("Red");
    cout<<"\tNOTICE: Input 888 to return to the menu."<<endl;
    SetTextColor("White");

    while (num != 888)
    {
	   	cout<<"\n\t"<<"Please input a positive integer: ";
	    cin>>num;

	    if (num != 888)
	    {
	   		cout<<"\n";
		    int cube=num*num*num;
		    for(int i=1; i<cube; i+=2)
			{
				sum=0;
				for(int j=i; j<cube; j+=2)
				{
					sum += j;
					if (sum==cube)
					{
						cout<<"\n\t"<<num<<"^3 = "<<cube<<" = ";
						for(int k=i; k<j; k+=2){
							cout<<k<<"+";
						}
						cout<<j<<endl;

						if (num>50){
							cout<<"There are too many solutions."<<endl;
							i=cube;
						}
					}
				}
		    }
    	} else cout<<"\n\tReturning to main menu. . ."<<endl;
    }
}

void FourSquare()
{
	int num, count=0;
	cout<<"\t=====================Four-square Theorem======================"<<endl;
    cout<<"\n";
    cout<<"\tEach positive integer may be expressed as the sum of"<<endl;
    cout<<"\tthe squares of four integers."<<endl;
    cout<<"\n";
	SetTextColor("Red");
    cout<<"\tNOTICE: Input 888 to return to the menu."<<endl;
    SetTextColor("White");

    while (num != 888)
	{
		cout<<"\n\t"<<"Please input a positive integer: ";
	    cin>>num;

	    if (num != 888)
	    {
	   		cout<<"\n";
		    for(int a=0; a<num; a++){
		    	for(int b=a; b<num; b++){
		       		for(int c=b; c<num; c++){
		    			for(int d=c; d<num; d++){
							if (a*a+b*b+c*c+d*d == num)
								cout<<"\n\tnum: "<<num<<" => "<<a<<"*"<<a<<" + "<<b<<"*"<<b<<" + "<<c<<"*"<<c<<" + "<<d<<"*"<<d<<endl;

							count++;
		    			}
		    		}
		    	}
		    }
		    cout<<"\n\tTotal loops: "<<count<<endl;
    	} else cout<<"\n\tReturning to main menu. . ."<<endl;
    }
}

void Eratosthenes()
{
	int end;
	cout<<"\t==================Sieve of Eratosthenes======================="<<endl;
	SetTextColor("Red");
    cout<<"\tNOTICE: Input 888 to return to the menu."<<endl;
    SetTextColor("White");
    cout<<"\n";

    while (end != 888)
    {
	   	cout<<"\tStart from 1, please input the end number: ";
		cin>>end;

		if (end != 888)
		{
			cout<<"\n";
		    bool prime[end+1];
		    memset(prime, true, sizeof(prime)); 		// Fill all the elements of the array 'prime' with true.

		    for (int p=2; p*p<=end; p++){
		        if (prime[p] == true)
		            for (int i=p*p; i<=end; i += p)
		                prime[i] = false;
		    }

		    for (int p=2; p<=end; p++)
		       if (prime[p]) cout<<p<<"\t";

		    cout<<"\n";
		} else cout<<"\n\tReturning to main menu. . ."<<endl;
    }
}

void BrideNGroom()
{
	char xBride,yBride,zBride;

	cout<<"\t==================Bride and Groom========================"<<endl;
    cout<<"\n";
    SetTextColor("Green");
    cout<<"\tThere are 3 brides <A, B, and C> and 3 grooms <X, Y, Z>."<<endl;
    cout<<"\tA: I will marry X."<<endl;
    cout<<"\tX: My fianc�e is C."<<endl;
    cout<<"\tC: I will marry Z."<<endl;
    cout<<"\tIt is known that they are all kidding."<<endl;
    cout<<"\tSo, do you know who are the real couples?"<<endl;
    cout<<"\n";
    SetTextColor("White");
    cout<<"\tPress any key to show the answer."<<endl;

    for(xBride='A'; xBride<='C'; xBride++){
    	for(yBride='A'; yBride<='C'; yBride++){
    		for(zBride='A'; zBride<='C'; zBride++){
    			if ( xBride!='A' && xBride!='C' && zBride!='C' && xBride!=zBride && xBride!=yBride && yBride!=zBride ){
			    	cout<<"\n\tThe groom X's bride is "<<xBride<<".\n";
			    	cout<<"\n\tThe groom Y's bride is "<<yBride<<".\n";
			    	cout<<"\n\tThe groom Z's bride is "<<zBride<<".\n";
			    }
    		}
    	}
    }
}

void TruthOrLie()
{
	// Solved with Graph Theory technique

    // We evaluate each person.
	// Assume if that person is indeed the liar, find out how many people are accusing that person. Those people would be the honest ones.
    // Since there can only be 1 person telling the truth, if the number of honest people exceeds 1 in a particular case, it will be a contradiction.
	// Thus, it is not possible for the person in that case to be the liar.
	// On the contrary, when the honest people count is 1, it means that the case is valid, and thus the accused is indeed a liar.

	// The matrix representation of the graph. [x][y] -> x accuses y.
	int accusations[3][3] = { {0, 1, 0},						// Ben accuses Bob.
							  {0, 0, 1},						// Bob accuses Bill.
							  {1, 1, 0} };						// Bill accuses everyone else.
	// 0=Ben, 1=Bob, 2=Bill.
	int susCount[3] = {0, 0, 0};
	int amtOfHonestPeople=1;

	string result;

	cout<<"\t===================Truth or Lies====================="<<endl;
    cout<<"\n";
    SetTextColor("Green");
    cout<<"\tBen says that Bob is lying."<<endl;
    cout<<"\tBob says that Bill is lying."<<endl;
    cout<<"\tBill says that they are all lying."<<endl;
    cout<<"\tSo, do you know who is lying?"<<endl;
    cout<<"\n";
    cout<<"\tPress any key to show the answer."<<endl;
	SetTextColor("Red");
    cout<<"\tNOTICE: Input 888 to return to the menu."<<endl;
    SetTextColor("White");

    int i, j;
    for(i=0; i<3; i++)	// 0: Ben, 1: Bob, 2: Bill
	{
		for (j=0; j<3; j++)
		{
			if (accusations[j][i] == 1)
			{
				if 		(i == 0) susCount[0]++;
				else if (i == 1) susCount[1]++;
				else if (i == 2) susCount[2]++;
			}
		}
		switch(i)
 		{
 			case 0:
 				result = susCount[0] > amtOfHonestPeople ? "honest" : "lying";
    			cout<<"\n\tBen is "<<result<<"."<<endl;
    			break;
  			case 1:
  				result = susCount[1] > amtOfHonestPeople ? "honest" : "lying";
  				cout<<"\n\tBob is "<<result<<"."<<endl;
  				break;
			case 2:
				result = susCount[2] > amtOfHonestPeople ? "honest" : "lying";
    			cout<<"\n\tBill is "<<result<<"."<<endl;
    			break;
 		}
		susCount[0] = 0; susCount[1] = 0; susCount[2] = 0;
   	}
}

void Goodbye()
{
    SetTextColor("Green");
    cout<<"\n\n";
    cout<<"                       .::::::."<<endl;
    cout<<"                     .:::::::::."<<endl;
    cout<<"                     :::::::::::"<<endl;
    cout<<"                  :::::::::::::."<<endl;
    cout<<"             ..:::::::::::::::"<<endl;
    cout<<"           ':::::::::::::::"<<endl;
    cout<<"              .::::::::::::"<<endl;
    cout<<"         '::::::::::::::::.."<<endl;
    cout<<"              ..:::::::::::::."<<endl;
    cout<<"              ''::::::::::::::::           .:::."<<endl;
    cout<<"              ::::' ':::::::::'         .::::::::."<<endl;
    cout<<"             ::::'   '::::::'        .:::::::':::::."<<endl;
    cout<<"           .::::'      ::::        .::::::::'  ':::::."<<endl;
    cout<<"          .:::'        :::::      .::::::::'     ':::::."<<endl;
    cout<<"        .::'          :::::::::.::::::::::'         '::::."<<endl;
    cout<<"       .::'           ::::::::::::::::::'              '':::."<<endl;
    cout<<"   ...:::             ::::::::::::::::'                  ''::."<<endl;
    cout<<"  '''' ':.            '::::::::::::::'                      ::::.."<<endl;
    cout<<"                       '.:::::::::::'                       ':'''''.."<<endl;
    cout<<"\n\tHave a good day!!! See you next time~~! :)\n\n";
    SetTextColor("White");
    exit(0);
}
