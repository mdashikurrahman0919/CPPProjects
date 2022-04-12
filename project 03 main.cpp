/*
Name : Md Ashikur Rahman 
ID   : 20170919
Frameworke : Framework for project 03 
Projecert name : Calculator
Date   :  15 October 2021
Aouthor : MD ASHIKUR RAHMNA 
Copyright : @mdashikurrahman 
Description : A Framework that includes Menu and user choices
*/
#include <iostream>
#include <string.h>
#include <ctime>
#include <time.h>
#include <windows.h>
using namespace std;

int num;
void showmenu();
void addition();
void subtraction();
void multiplication();
void division();
void mixed();
void correct(int x);
void incorrect(int x);
void emain();
void changeColor(int desiredColor);
int main()
{
    changeColor(7);
    while(1)
    {
        showmenu();
        cout<<"\n\n\t\tPlease, choose the operation: ";
        cin>>num;
        if(num==6)
        {
            cout<<"\t\tNow exiting the program. Goodbye!"<<endl;
            break;
        }
        else
        {
            changeColor(4);
            cout<<"\n\t\t================Input 666 to end the practice================"<<endl;
            changeColor(7);
            switch(num)
            {
                case 1:
                    addition();
                    break;
                case 2:
                    subtraction();
                    break;
                case 3:
                    multiplication();
                    break;
                case 4:
                    division();
                    break;
                case 5:
                    mixed();
                    break;
                default:
                changeColor(12);
                cout<<"\t\tInvalid input"<<endl;
                changeColor(7);
            }
        }
        cin.sync();
        if(num!=6)
        {
            cout<<"\t\t\n\n\nPress any key"<<endl;
            getchar();
        }
    }
    return 0;
}
void showmenu()
{
   cout << "\n\n\t\t=================== project calculator ====================\n\n" << endl;

    cout << "\t\t==================== Calculator Menu =======================" << endl;
    cout << "\t\t#                                                          #" << endl;
    cout << "\t\t#                                                          #" << endl;
    cout << "\t\t#                                                          #" << endl;
    cout << "\t\t#       1-Addition               2-Subtraction             #" << endl;
    cout << "\t\t#                                                          #" << endl;
    cout << "\t\t#                                                          #" << endl;
    cout << "\t\t#                                                          #" << endl;
    cout << "\t\t#       3-Multiplication         4-Division                #" << endl;
    cout << "\t\t#                                                          #" << endl;
    cout << "\t\t#                                                          #" << endl;
    cout << "\t\t#                                                          #" << endl;
    cout << "\t\t#       5-Mixed                  6-Exit                    #" << endl;
    cout << "\t\t#                                                          #" << endl;
    cout << "\t\t#                                                          #" << endl;
    cout << "\t\t====================== mdashikurrahman =====================" << endl;
}
void addition()
{
    int num1,num2,result=0;
    while(1)
    {
        srand(time(0));
        num1=rand()%10;
        num2=rand()%10;
        cout<<"\n\t\t"<<num1<<" + "<<num2<<" = ";
        cin.clear();
        cin.sync();
        cin>>result;
        if(result==(num1+num2))
        {
            correct(rand()%6+1);
        }
        else if(result==666)
        {
            cout<<"\n\t\tNow exiting addition practice."<<endl;
            break;
        }
        else
        {
            incorrect(rand()%5+1);
            while(!0)
            {
                cin.clear();
                cin.sync();
                cout<<"\n\t\t"<<num1<<" + "<<num2<<" = ";
                cin>>result;
                if(result==(num1+num2))
                {
                    correct(rand()%6+1);
                    break;
                }
                else if(result==666)
                {
                    cout<<"\n\t\tNow exiting addition practice."<<endl;
                    break;
                }
                else
                {
                    incorrect(rand()%5+1);
                }
            }
        }
        if(result==666)
            break;
    }
    emain();
}
void subtraction()
{
    int num1,num2,result=0,temp=0;
    while(1)
        {
            srand(time(0));
            num1=rand()%10;
            num2=rand()%10;
            if(num1<num2)
            {
                temp=num2;
                num2=num1;
                num1=temp;
            }
            cin.clear();
            cin.sync();
            cout<<"\n\t\t"<<num1<<" - "<<num2<<" = ";
            cin>>result;
            if(result==(num1-num2))
            {
                correct(rand()%6+1);
            }
            else if(result==666)
            {
                cout<<"\n\t\tNow exiting substraction practice."<<endl;
                break;
            }
            else
            {
                incorrect(rand()%5+1);
                while(!0)
                {
                    cin.clear();
                    cin.sync();
                    cout<<"\n\t\t"<<num1<<" - "<<num2<<" = ";
                    cin>>result;
                    if(result==(num1-num2))
                    {
                        correct(rand()%6+1);
                        break;
                    }
                    else if(result==666)
                    {
                        cout<<"\n\t\tNow exiting substraction practice."<<endl;
                        break;
                    }
                    else
                    {
                        incorrect(rand()%5+1);
                    }
                }
            }
            if(result==666)
            break;
        }
    emain();
}

void multiplication()
{
    int num1,num2,result=0;
    while(1)
    {
        srand(time(0));
        num1=rand()%10;
        num2=rand()%10;
        cin.clear();
        cin.sync();
        cout<<"\n\t\t"<<num1<<" * "<<num2<<" = ";
        cin>>result;
        if(result==(num1*num2))
        {
            correct(rand()%6+1);
        }
        else if(result==666)
        {
            cout<<"\n\t\tNow exiting multiplication practice."<<endl;
            break;
        }
        else
        {
            incorrect(rand()%5+1);
            while(!0)
            {
                cin.clear();
                cin.sync();
                cout<<"\n\t\t"<<num1<<" * "<<num2<<" = ";
                cin>>result;
                if(result==(num1*num2))
                {
                    correct(rand()%6+1);
                    break;
                }
                else if(result==666)
                {
                    cout<<"\n\t\tNow exiting multiplication practice."<<endl;
                    break;
                }
                else
                {
                    incorrect(rand()%5+1);
                }
            }
        }
        if(result==666)
            break;
    }
    emain();
}

void division()
{
    int num1,num2,result=0;
    int tmp=0;
    int mult;
    while(1)
    {
        srand(time(0));
        num1=rand()%10+1;
        num2=rand()%10+1;
        mult = num1*num2;
        cin.clear();
        cin.sync();
        cout<<"\n\t\t"<<mult<<" / "<<num2<<" = ";
        cin>>result;
        if(result==(mult/num2))
        {
            correct(rand()%6+1);
        }
        else if(result==666)
        {
            cout<<"\n\t\tNow exiting division practice."<<endl;
            break;
        }
        else
        {
            incorrect(rand()%5+1);
            while(!0)
            {
                cin.clear();
                cin.sync();
                cout<<"\n\t\t"<<mult<<" / "<<num2<<" = ";
                cin>>result;
                if(result==(mult/num2))
                {
                    correct(rand()%6+1);
                    break;
                }
                else if(result==666)
                {
                    cout<<"\n\t\tNow exiting division practice."<<endl;
                    break;
                }
                else
                {
                    incorrect(rand()%5+1);
                }
            }
        }
        if(result==666)
            break;
    }
    emain();
}

void mixed()
{
    int num1,num2,result,tmp=0;
    int mult;
    while(1)
    {
        srand(time(0));
        num1=rand()%10;
        num2=rand()%10;
        switch(rand()%4+1)
        {
            case 0:
            case 1:
            {
                cin.clear();
                cin.sync();
                cout<<"\n\t\t"<<num1<<" + "<<num2<<" = ";
                cin>>result;
                if(result==(num1+num2))
                {
                    correct(rand()%6+1);
                }
                else if(result==666)
                {
                    cout<<"\n\t\tNow exiting mixed practice."<<endl;
                    break;
                }
                else
                {
                    incorrect(rand()%5+1);
                    while(!0)
                    {
                        cin.clear();
                        cin.sync();
                        cout<<"\n\t\t"<<num1<<" + "<<num2<<" = ";
                        cin>>result;
                        if(result==(num1+num2))
                        {
                            correct(rand()%6+1);
                            break;
                        }
                        else if(result==666)
                        {
                            cout<<"\n\t\tNow exiting mixed practice."<<endl;
                            break;
                        }
                        else
                        {
                            incorrect(rand()%5+1);
                        }
                    }
                }
                if(result==666)
                    break;
            }
            case 2:
            {
                cin.clear();
                cin.sync();
                if(num1<num2)
                {
                    tmp=num2;
                    num2=num1;
                    num1=tmp;
                }
                cin.clear();
                cin.sync();
                cout<<"\n\t\t"<<num1<<" - "<<num2<<" = ";
                cin>>result;
                if(result==(num1-num2))
                {
                    correct(rand()%6+1);
                }
                else if(result==666)
                {
                    cout<<"\n\t\tNow exiting mixed practice."<<endl;
                    break;
                }
                else
                {
                    incorrect(rand()%5+1);
                    while(!0)
                    {
                        cin.clear();
                        cin.sync();
                        cout<<"\n\t\t"<<num1<<" - "<<num2<<" = ";
                        cin>>result;
                        if(result==(num1-num2))
                        {
                            correct(rand()%6+1);
                            break;
                        }
                        else if(result==666)
                        {
                            cout<<"\n\t\tNow exiting mixed practice."<<endl;
                            break;
                        }
                        else
                        {
                            incorrect(rand()%5+1);
                        }
                    }
                }
                if(result==666)
                break;
            }
            case 3:
            {
                cin.clear();
                cin.sync();
                cout<<"\n\t\t"<<num1<<" * "<<num2<<" = ";
                cin>>result;
                if(result==(num1*num2))
                {
                    correct(rand()%6+1);
                }
                else if(result==666)
                {
                    cout<<"\n\t\tNow exiting mixed practice."<<endl;
                    break;
                }
                else
                {
                    incorrect(rand()%5+1);
                    while(!0)
                    {
                        cin.clear();
                        cin.sync();
                        cout<<"\n\t\t"<<num1<<" * "<<num2<<" = ";
                        cin>>result;
                        if(result==(num1*num2))
                        {
                            correct(rand()%6+1);
                            break;
                        }
                        else if(result==666)
                        {
                            cout<<"\n\t\tNow exiting mixed practice."<<endl;
                            break;
                        }
                        else
                        {
                            incorrect(rand()%5+1);
                        }
                    }
                }
                if(result==666)
                    break;
            }
            case 4:
            {
                num2=rand()%10+1;
                mult = num1*num2;
                cin.clear();
                cin.sync();
                cout<<"\n\t\t"<<mult<<" / "<<num2<<" = ";
                cin>>result;
                if(result==(mult/num2))
                {
                    correct(rand()%6+1);
                }
                else if(result==666)
                {
                    cout<<"\n\t\tNow exiting mixed practice."<<endl;
                    break;
                }
                else
                {
                    incorrect(rand()%5+1);
                    while(!0)
                    {
                        cin.clear();
                        cin.sync();
                        cout<<"\n\t\t"<<mult<<" / "<<num2<<" = ";
                        cin>>result;
                        if(result==(mult/num2))
                        {
                            correct(rand()%6+1);
                            break;
                        }
                        else if(result==666)
                        {
                        cout<<"\n\t\tNow exiting mixed practice."<<endl;
                            break;
                        }
                        else
                        {
                            incorrect(rand()%5+1);
                        }
                    }
                }
                if(result==666)
                    break;
            }
            if(result==666)
                break;
        }
        if(result==666)
                break;
    }
    emain();
}
void emain()
{
    cout<<"\n\t\tPress enter to return to menu."<<endl;
    getchar();
    if( num!=6)
    {
        cin.clear();
        cin.sync();
        getchar();
        main();
    }
}

void correct(int x)
{
    changeColor(2);
    switch(x)
    {
        case 1:
            cout<<"\t\t\t.....Correct."<<endl;
            break;
        case 2:
            cout<<"\t\t\t.....Very good."<<endl;
            break;
        case 3:
            cout<<"\t\t\t.....Awesome."<<endl;
            break;
        case 4:
            cout<<"\t\t\t.....Nice."<<endl;
            break;
        case 5:
            cout<<"\t\t\t.....Fantastic."<<endl;
            break;
        case 6:
            cout<<"\t\t\t.....Great."<<endl;
            break;
        default:
            cout<<"\t\t\t.....Good job."<<endl;
            break;
    }
    changeColor(7);
}

void incorrect(int x)
{
    changeColor(12);
    switch(x)
    {
        case 1:
            cout<<"\t\t\t.....Wrong."<<endl;
            break;
        case 2:
            cout<<"\t\t\t.....Have a another try."<<endl;
            break;
        case 3:
            cout<<"\t\t\t.....Not really."<<endl;
            break;
        case 5:
            cout<<"\t\t\t.....Close."<<endl;
            break;
        default:
            cout<<"\t\t\t.....Incorrect."<<endl;
            break;
    }
    changeColor(7);
}
void changeColor(int desiredColor)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), desiredColor);
}

