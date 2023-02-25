/*
Name : Md Ashikur Rahman
ID   : 20170919
Frameworke : Framework for project 05
Projecert name : Numbers
Date   :  22 October 2021
Aouthor : MD ASHIKUR RAHMNA
Copyright : @ashikurrahman
Description : A Framework that includes Menu and user choices
*/

#include <iostream>
#include <cmath>
#include "windows.h"
#include<stdio.h>

using namespace std;

void Color(int Color) { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color); }
void ShowMenu();

void Perfect();
void Friendly();
void Narcissistic();
void Armstrong();
void Pythagorean();
void Mantissa();
void LCMandGCD();
void Exit();
int ProperDivSum(int num);
bool IsPairofFriendlyNums(int a,int b);
int DivSum(int num);
void PrintDivisors(int num);
void divs2nums(int num1,int num2);
int Exponent(int base,int power);
int gcd(int firstnum,int secondnum);
int lcm(int firstnum,int secondnum);



int main(int argc, char*argv[])
{

	int choice = 0;
	while(choice !=8)
	{
		ShowMenu();
		Color(14);
		cout<<"\n\n\tPlease choose option from Menu: ";
		while(!(cin>>choice)|| (choice<1) || (choice>8))
		{
			Color(15);
			cout<<"\tInvalid choice. Please choose of given numbers! \n";
			cin.clear();
			cin.sync();
			Color(15);
		}
		cout<<"\tYour choice is : "<<choice<<endl;
		cin.sync();
		switch (choice)
		{
			case 1:
				Perfect();
				break;
			case 2:
				Friendly();
				break;
			case 3:
				Narcissistic();
				break;
			case 4:
				Armstrong();
				break;
			case 5:
				Pythagorean();
				break;
			case 6:
				Mantissa();
				break;
			case 7:
				LCMandGCD();
				break;
			case 8:
				Exit();
				break;


		}
		Color(10);
		cout<<"\tPress any key to return to the Menu: ";
		getchar();
	}
	getchar();
	return 0;
}

void ShowMenu()
{
	Color(10);
	cout<<"\n";
	cout<<"\t\t================================================================"<<endl;
    cout<<"\t\t====================== PROJECT 5 NUMBERS ======================="<<endl;
    cout<<"\n";
    Color(12);
    cout<<"\t\t================================================================"<<endl;
    cout<<"\t\t========================= NUMBERS MENU ========================="<<endl;
    cout<<"\t\t=                                                              ="<<endl;
    cout<<"\t\t=                                                              ="<<endl;
    cout<<"\t\t=    1. Perfect Number                                         ="<<endl;
    cout<<"\t\t=                                                              ="<<endl;
    cout<<"\t\t=    2. Friendly Number                                        ="<<endl;
    cout<<"\t\t=                                                              ="<<endl;
    cout<<"\t\t=    3. Narcissistic Number                                    ="<<endl;
    cout<<"\t\t=                                                              ="<<endl;
    cout<<"\t\t=    4. Armstrong Number                                       ="<<endl;
    cout<<"\t\t=                                                              ="<<endl;
    cout<<"\t\t=    5. Pythagorean Triple                                     ="<<endl;
    cout<<"\t\t=                                                              ="<<endl;
    cout<<"\t\t=    6. Mantissa                                               ="<<endl;
    cout<<"\t\t=                                                              ="<<endl;
    cout<<"\t\t=    7. Lowest Common Multiple & Greatest Common Divisor       ="<<endl;
    cout<<"\t\t=                                                              ="<<endl;
    cout<<"\t\t=    8. Exit                                                   ="<<endl;
    cout<<"\t\t=                                                              ="<<endl;
    cout<<"\t\t=                                                              ="<<endl;
    cout<<"\t\t======================= @ashikurrahman ========================="<<endl;
    cout<<"\t\t================================================================"<<endl;
    cout<<"\n\n\tONCE YOU ARE READY. CHOUSE ANY NUMBER TO START THE SHOW: ";
}

void Perfect()
{
	int start,end, perfectNumCount=0;
	int flag=1;

    Color(10);
    cout<<"\t=======================Perfect Number======================="<<endl;
    cout<<"\n";
    cout<<"\tA perfect number is a positive integer that is equal to"<<endl;
    cout<<"\tthe sum of all its proper divisors. For example, 6, whose"<<endl;
    cout<<"\tproper divisors are 1, 2, and 3, and indeed 6 = 1+2+3."<<endl;
    cout<<"\n";
	Color(12);

    Color(15);
    cout<<"\tNOTICE:Print 888 if you want to return to The MENU."<<endl;
    while (start != 888)
    {
		cout<<"\n\tPlease input the start number: ";
		cin>>start;
		if (start != 888)
		{
			cout<<"\n";
		    cout<<"\tPlease input the end number: ";
		    cin>>end;
		    cout<<"\n";
		    for(int i=start; i<=end; i++)
			{
		    	if (ProperDivSum(i) == i && i!=1){
		    		perfectNumCount++;
		    		Color(10);
					cout<<"\t"<<i<<" is a Perfect Number. ";
					Color(15);
					cout<<i<<" = ";
					PrintDivisors(i);
					cout<<"\n";
				}
		    }
		    Color(10);
		    cout<<"\n\tThere are "<<perfectNumCount<<" Perfect Numbers between "<<start<<" and "<<end<<"."<<endl;
		    Color(15);
		    perfectNumCount=0;
		} else {
    		cout<<"\n\tReturning to menu. . ."<<endl;
    	}
    }
   getchar();
}

int ProperDivSum(int num)
{
    int result = 0;

    for (int i=2; i<=sqrt(num); i++)
    {
        if (num%i==0)
        {
            if (i==(num/i))
                result += i;
            else
                result += (i + num/i);
        }
    }
    return (result + 1);
}

void PrintDivisors(int num)
{
	int sum=0;
	for (int i=1; i<num; i++){
		if (num%i==0)
		{
			sum += i;
			if (sum!=num) 	cout<<i<<"+";
			else			cout<<i;
		}
	}
}


void Friendly()
{
	int start,end,count=0;

    Color(10);
    cout<<"\t===================Friendly Number====================="<<endl;
    cout<<"\n";
    cout<<"\tThere are 2 integers a and b. If the sum of b's divisors"<<endl;
    cout<<"\tequals to a, and the sum of a's divisors equals to b, we call"<<endl;
    cout<<"\tthese 2 integers \"Friendly Numbers\"."<<endl;
    cout<<"\n";
    cout<<"\tEx:"<<endl;
    cout<<"\n";
    cout<<"\t284 and 220"<<endl;
    cout<<"\n";
    cout<<"\t284's divisors: 1+2+4+71+142 = 220"<<endl;
    cout<<"\n";
    cout<<"\t220's divisors: 1+2+4+5+10+11+20+22+44+55+110 = 284"<<endl;
    cout<<"\n";
    cout<<"\tSo 284 and 220 are Friendly Numbers."<<endl;
    cout<<"\n";
	Color(12);
    cout<<"\tNOTICE:Print 888 if you want to return to The MENU."<<endl;
    Color(15);

	while (start != 888)
    {
	    cout<<"\n\tPlease input the start number: ";
	    cin>>start;

   		if (start != 888)
		{
		    cout<<"\n";
		    cout<<"\tPlease input the end number: ";
		    cin>>end;
		    cout<<"\n";

		    Color(10);
		    for(int i=start; i<end; i++)
			{
				for(int j=i+1; j<=end; j++)
				{
					if (IsPairofFriendlyNums(i,j))
					{
						count++;
						Color(10);
						cout<<"\tFound a pair: "<<i<<" & "<<j<<endl;
						Color(15);
						cout<<"\n\t"<<i<<"'s divisor: "<<endl;
						cout<<"\n\t";
						divs2nums(i, j);
						cout<<"\n";
						cout<<"\n\t"<<j<<"'s divisor: "<<endl;
						cout<<"\n\t";
						divs2nums(j, i);
						cout<<"\n\n";
						Color(10);
						cout<<"\n\tThere are "<<count<<" pairs of Friendly Numbers between "<<start<<" and "<<end<<"."<<endl;
						Color(15);
					}
				}
		    }
		    count=0;
		} else {
			cout<<"\n\tGo Back to the Menu.";
		}
    }
    getchar();
    cout<<"\n";
}


bool IsPairofFriendlyNums(int a, int b)
{
	return (DivSum(a) == b && DivSum(b) == a && DivSum(a) != 1);
}
int DivSum(int num)
{
   int result=0,i;
	for( i=1; i<num; i++)
	{
		if (num%i == 0) result += i;
	}
	return result;
}
void divs2nums(int num1, int num2)
{
	int sum=0,i;
	for (i=1; i<num1; i++){
		if (num1%i==0)
		{
			sum += i;
			if (sum!=num2) 	cout<<i<<"+";
			else			cout<<i;
		}
	}
}


void Narcissistic()
{
	Color(12);
	  cout<<"\t=========================Narcissistic Number======================="<<endl;
    cout<<"\n";
    cout<<"\tIf a positive 3-digits integer is equal to the sum of its"<<endl;
    cout<<"\tevery square's 3th power, we call the number Narcissistic Number."<<endl;
    cout<<"\n";
    Color(15);
    cout<<"\tThe Narcissistic numbers are: ";
    int hund,ten,unit,i;
    for (i=100;i<1000;i++)
    {
    	hund= 1/100;
    	ten= (i%100)/10;
    	unit= i%10;
    	if ( i == (Exponent(hund, 3) + Exponent(ten, 3) + Exponent(unit, 3)) )
    	{
		    cout<<i<<" ";
		}
	}
	cout<<"\n";
}


void Armstrong()
{
       Color(10);
	    cout<<"\t=====================Armstrong Number========================"<<endl;
    cout<<"\n";
    cout<<"\tAn Armstrong Number is a number that is equal to the sum of"<<endl;
    cout<<"\tall its digits raised to the power of the amount of digits it has."<<endl;
    cout<<"\n";
    Color(15);
    int i,j,k,sum,temp;
    for(i=1;i<=8;i++)
    {
    	cout<<"\n\tThe Armstrong Number of"<<i<<"digit are: ";
    	for(j= Exponent(10, i-1); j<Exponent(10,i);j++)
    	{
    		sum=0;
    		temp=j;
    		while(temp!=0)
    		{
    			k= temp%10;
    			sum=sum+Exponent(k,1);
    			temp=temp/10;
			}
			if(sum==j)
			{
				cout<<j<<"";
			}
		}
	}
	cout<<"\n";
}
int Exponent(int base,int power)
{
	int result = 1;
	for (int i=0; i<power; i++){
		result *= base;
	}
	return result;
}

void Pythagorean()
{
	int start,end;
	Color(10);
	 cout<<"\t=====================Pythagorean Triples========================"<<endl;
    cout<<"\n";
    cout<<"\tTriples of positive integers that can construct a right triangle"<<endl;
    cout<<"\twith segments of lengths corresponding to triple."<<endl;
    cout<<"\n";
    cout<<"\tFor example (3,4,5) (5,12,13) (6,8,10)."<<endl;
    cout<<"\n";
    Color(12);
    cout<<"\tNOTICE:Print 888 if you want to return to The MENU."<<endl;
    Color(15);
    while(start!=888)
    {
    	cout<<"\n";
    	Color(15);
    		cout<<"\tPlease input the start number: ";
    		cin>>start;
    		cout<<"\n";
    		if(start!=888)
    		{
    			  cout<<"\tPlease input the end number: ";
		    cin>>end;
		    cout<<"\n";
			}
			if(end!=888)
			{
				int a,b,c=0;
				int x=start,count=0,i;
				while(c<end)
				{
					for(i=1;i<x;i++)
					{
						a= x*x-i*i;
						b= 2*x*i;
						c= x*x+i*i;

						if(c>end)
						{
							break;
						}
						count++;
						cout<<" "<<a<<" "<<b<<" "<<c<<"\t";
						if(count%3==0)
						{
							cout<<"\n";
						}
					}
					x++;
				}
				cout<<"\n";
			}
			else
			 {
			 	break;

		}
	}
	cout<<"\n\tGo Back to the Menu.";
	cout<<"\n";
	getchar();
}

void Mantissa()
{
	Color(10);
	 cout<<"\t=====================Mantissa Problem==================="<<endl;
    cout<<"\n";
    cout<<"\tFind the last n digits of Base to the Exponent power."<<endl;
    cout<<"\tFor example, find the last 3 digits of 13^16."<<endl;
    cout<<"\n";
    Color(12);
    cout<<"\tNOTICE:Print 888 if you want to return to The MENU."<<endl;
    int base,exp,digits;
    while(base!=888)
    {
    	cout<<"\n";
    	Color(15);
    		cout<<"\tPlease input a positive integer for thr base: ";
    		cin>>base;
    		cout<<"\n";
    		if(base!=888)
    		{
    			  cout<<"\tPlease input a positive integer for the exponent: ";
		    cin>>exp;
		    	cout<<"\n\tPlease input a positive integer for the amount of last digits (1-6): ";
			while (!(cin>>digits) || digits>8 || digits<1)
	      	{
	          	cout<<"\n\tINVALID INPUT! Please input positive integer from 1-6: ";
	          	cin.clear(); cin.sync();
	      	}
	      	Color(10);
	      	cout<<"\n\tThe last "<<digits<<" digits are "<<": ";
			int raisedNum = Exponent(base, exp);
			for(int i=digits; i>=1; i--)
			{
				cout<<(raisedNum % Exponent(10, i)) / Exponent(10, i-1);
			}
			cout<<"\n";
			Color(15);
}
else
{
	cout<<"\n\tGo Back to the Menu.";
}
}
 cout<<"\n";
	getchar();
}
void LCMandGCD()
{
	Color(10);
    cout<<"\t========================Lowest Common Multiple============================="<<endl;
    cout<<"\tThe smallest common multiple of 2 or more numbers."<<endl;
    cout<<"\n";
    cout<<"\t========================Greatest Common Divisor============================"<<endl;
    cout<<"\tThe largest integer that is an exact divisor of each of 2 or more integers."<<endl;
    Color(12);
    cout<<"\tNOTICE:Print 888 if you want to return to The MENU."<<endl;
    Color(15);

    int num1, num2;
	while (num1 != 888)
    {
    	cout<<"\n";
        cout<<"\tPlease input the first number: ";
        cin>>num1;
        if (num1 == 888)
        {
        	break;
		}
        cout<<"\n";
        cout<<"\tPlease input the second number: ";
        cin>>num2;
        if (num2 == 888)
        {
        	break;
		}
		Color(10);
		cout<<"\tThe Lowest Common Multitple of " << num1 << " And " << num2 << " is " << lcm(num1, num2) << "." << endl;
        cout<<"\tThe Lowest Common Multitple of " << num1 << " And " << num2 << " is " << gcd(num1, num2) << "."  << endl;
       Color(15);
    }
    cout<<"\n\tGo Back to the Menu.";
    cout<<"\n";
	getchar();
}
int gcd(int firstnum, int secondnum)
{
    int r = 0, a, b;
    a = (firstnum > secondnum) ? firstnum : secondnum;
    b = (firstnum < secondnum) ? firstnum : secondnum;
    r = b;
    while (a % b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return r;
}
int lcm(int firstnum, int secondnum)
{
    int a;
    a = (firstnum > secondnum) ? firstnum : secondnum;
    while (1)
    {
        if (a % firstnum == 0 && a % secondnum == 0)
            return a;
        ++a;
    }
}

void Exit()
{
	cout<<"\n";
Color(1);
    cout<<"\t :====++++===========*  ======                                  ======          \n";
    cout<<"\t :./:::========......:  +:::::                                  :`::::          \n";
    cout<<"\t :..`................:  +.::::                                  :`::::          \n";
    cout<<"\t :..=====............:  +:-:::                                  ::::::          \n";
    cout<<"\t         =======        +:-:::                       ======='   :o.:::    ====  \n";
    cout<<"\t         =======        +:-:/o/--``   `.::/===//`  :/://::///:  :o.-::++//--++  \n";
    cout<<"\t         =======        +:-::::::+/. .+:...-::.+-  /:........:: :+--::/:.-+/-   \n";
    cout<<"\t         *******        +:-:/++/::/+.+..-------/+` //`........: ://.::::++.`    \n";
    cout<<"\t         *******        /:-+/``:+-/o//`-+/:+----+/`-+`.-///-..: :-+.:+o-/o`     \n";
    cout<<"\t         *******        :/-o`  `o-/+:/.-++//`----+/`+:-o.`-+`-+ :o.:o/+:+/`     \n";
    cout<<"\t         =======        .+:o.  `o:+:`+:::::/++////:`.+/o. -o//: ::/::o..+/o=    \n";
    cout<<"\t         =======        ====`  `====` `.===. `=`     ===   ==== ======   ===    \n";
    cout<<"\t                                                                                \n";
    cout<<"\t                                                                                \n";
    cout<<"\t          `=========      =========                                             \n";
    cout<<"\t           .+:://////     :/:.-::::                            =======          \n";
    cout<<"\t            `//////////  /-.:////                              -+`..//          \n";
    cout<<"\t             `-/+////// //::////   ` `====.`   ====`  `====    -+`--+/          \n";
    cout<<"\t               `.:++/////////+/   `:/-.--/+-``+:-o`  -+.:o`    -+`--+:          \n";
    cout<<"\t                  `.:+/://++:.`  `+:`.....-+:.o`:+:://..:+-    .o:::+:          \n";
    cout<<"\t                     /:./o:`     .o`.-///..:o-+`::::---::/+`   `:::/:.          \n";
    cout<<"\t                    `+--/+:      `+-./+:o../+.o.::::::::::+    .o-::+:          \n";
    cout<<"\t                    -o://+/`      `//://://:``-+::::::::+++    .o`--+/          \n";
    cout<<"\t                    =======         `===```    `:++///+/-``    =======          \n";
    cout<<"\t                                                  `'''`MD ASHIKUR RAHMAN        \n";
    cout<<"\n\tHave a good day!!! See you next time~~! :)\n\n";
Color(11);
exit(0);
}



