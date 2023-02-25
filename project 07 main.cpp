/*
Name           : Md Ashikur Rahman
ID             : 20170919
Frameworke     : Framework for project 07
Projecert name : Students MIS
Date           : 03 December 2021
Aouthor        : MD ASHIKUR RAHMNA
Copyright      : @ashikurrahman
Description    : A Framework that includes Menu Students MIS user choices.
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

typedef struct student
{
    string StuNo;
    string Name;
    string Gender;
    string PhoneNumber;
    string Wechat;
    string Dorm;
    int score;
}stud;

void color (int i)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),i);
}

string lower(string s)
{
    int i=0;
    string result;
    for(i=0; i<s.length(); i++)
    {
        s[i]=tolower(s[i]);
    }

    return s;
}

void swap(stud* s1, stud* s2)
{
    stud temp;
    temp.StuNo=s1->StuNo;
    temp.Name=s1->Name;
    temp.Gender=s1->Gender;
    temp.PhoneNumber=s1->PhoneNumber;
    temp.Wechat=s1->Wechat;
    temp.Dorm=s1->Dorm;
    temp.score=s1->score;

    s1->StuNo=s2->StuNo;
    s1->Name=s2->Name;
    s1->Gender=s2->Gender;
    s1->PhoneNumber=s2->PhoneNumber;
    s1->Wechat=s2->Wechat;
    s1->Dorm=s2->Dorm;
    s1->score=s2->score;

    s2->StuNo=temp.StuNo;
    s2->Name=temp.Name;
    s2->Gender=temp.Gender;
    s2->PhoneNumber=temp.PhoneNumber;
    s2->Wechat=temp.Wechat;
    s2->Dorm=temp.Dorm;
    s2->score=temp.score;
}

void menu();
void load();
void showStudents();
void searchstudents();
void addStudent();
void modify();
void Delete();
void sortStuNo();
void sortName();
void sortGender();
void sortPhone();
void sortWechat();
void sortDorm();
void sortScore();
void statistics();
void clearData();
void save();
void showOrHide();

stud Data[1000];
int flag=0;
int counter=0;
int main()
{
    int chose=0;
    string choice;
    while(1)
    {
        menu();
        while(!(cin>>chose) || 18<chose || chose<=0)
        {
            cout<<"Invalid. Please choose again: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        if(chose==18)
        break;
        else
        {
            switch(chose)
            {
                case 1 :
                {
                 load();
                 break;
                }
                case 2 :
                {
                 showStudents();
                 break;
                }
                case 3 :
                {
                 searchstudents();
                 break;
                }
                case 4 :
                {
                 addStudent();
                 break;
                }
                case 5 :
                {
                 modify();
                 break;
                }
                case 6 :
                {
                 Delete();
                 break;
                }
                case 7 :
                {
                    sortStuNo();
                    break;
                }
                case 8 :
                {
                    sortName();
                    break;
                }
                case 9 :
                {
                    sortGender();
                    break;
                }
                case 10 :
                {
                    sortPhone();
                    break;
                }
                case 11 :
                {
                    sortWechat();
                    break;
                }
                case 12 :
                {
                    sortDorm();
                    break;
                }
                case 13 :
                {
                    sortScore();
                    break;
                }
                case 14 :
                {
                    statistics();
                    break;
                }
                case 15 :
                {
                    clearData();
                    break;
                }
                case 16 :
                {
                    save();
                    break;
                }
                case 17 :
                {
                    showOrHide();
                    break;
                }
                case 18 :
                {
                    break;
                }
            }
        }
        cout<<"\n\n\tPRESS ANY KEY TO RETURN TO THE MENU. ";
        if(chose==18)
            break;

        getline(cin, choice);
        cout<<"\n";
    }
    return 0;
}

void menu()
{
    cout<<"\n\n\t\t****************************** Project 07 Students MIS ************************"<<endl;
    cout<<"\t\t###############################################################################\n\n"<<endl;


    cout<<"\t\t##===========================================================================##"<<endl;
    cout<<"\t\t##============================= Students MIS Menu ===========================##"<<endl;
    cout<<"\t\t##                                                                           ##"<<endl;
    cout<<"\t\t##        1. Load Data                         2. Show All Students          ##"<<endl;
    cout<<"\t\t##                                                                           ##"<<endl;
    cout<<"\t\t##        3. Search Student                     4. Add Student               ##"<<endl;
    cout<<"\t\t##                                                                           ##"<<endl;
    cout<<"\t\t##        5. Modify Student                     6. Delete Student            ##"<<endl;
    cout<<"\t\t##                                                                           ##"<<endl;
    cout<<"\t\t##        7. Sort by StuNo                      8. Sort by Name              ##"<<endl;
    cout<<"\t\t##                                                                           ##"<<endl;
    cout<<"\t\t##        9. Sort by Gender                     10.Sort by Phone             ##"<<endl;
    cout<<"\t\t##                                                                           ##"<<endl;
    cout<<"\t\t##        11.Sort by WeChat                     12.Sort by Dormitory         ##"<<endl;
    cout<<"\t\t##                                                                           ##"<<endl;
    cout<<"\t\t##        13.Sort by Score                      14.Statistics Data           ##"<<endl;
    cout<<"\t\t##                                                                           ##"<<endl;
    cout<<"\t\t##        15.Clear Data                         16.Save Data To File         ##"<<endl;
    cout<<"\t\t##                                                                           ##"<<endl;
    cout<<"\t\t##        17.Show Selected Data                 18.Exit                      ##"<<endl;
    cout<<"\t\t##                                                                           ##"<<endl;
    cout<<"\t\t##============================= @ashikurrahman ==============================##"<<endl;
    cout<<"\t\t##===========================================================================##"<<endl;
    cout<<"\n\tPlease choose: ";
}

void load()
{
    ifstream my_file;
    string filename;
    string mumble;
    color(4);
    cout<<"\n\tNOTCE: Input 000 to Return to the Menu."<<endl;
    color(15);
    cout<<"\n\tPress ENTER to load default file(stu.txt), or input a file name:";
    cin.get();
    while(!my_file.is_open())
    {
        getline(cin, filename);
        if(filename=="000")
            break;
        if(filename=="")
            {
                my_file.open("stu.txt");
                cout<<"\n\tFile stu.txt opened successfully."<<endl;
            }
        else
            {
            my_file.open(filename);
            if(!my_file.is_open())
                cout<<"\n\tFile "<<filename<<" couldn't open.\n\n\tPress ENTER to load default file(stu.txt), or input a file name:";
            else cout<<"\n\tFile "<<filename<<" opened successfully."<<endl;
            }
    }
    if(my_file.is_open())
    {
        counter=0;
        flag=1;
        getline(my_file, mumble);
        while(my_file >> Data[counter].StuNo >> Data[counter].Name >> Data[counter].Gender >> Data[counter].PhoneNumber >> Data[counter].Wechat >> Data[counter].Dorm >> Data[counter].score)
        {
            counter++;
            my_file.get();

        }
        cout<<"\n\tThere are "<<counter<<" students imported"<<endl;
    }

}

void showStudents()
{
    cin.get();
    if(flag==0)
        {
        ifstream my_file;
        string filename;
        string mumble;
        color(4);
        cout<<"\n\tNOTCE: Input 000 to Return to the Menu."<<endl;
        color(15);
        cout<<"\n\tThere is no data in the Students Management Information System.";
        cout<<"\n\tPress ENTER to load default file(stu.txt), or input a file name:";

        while(!my_file.is_open())
        {
            getline(cin, filename);
            if(filename=="000")
                break;
            if(filename=="")
                {
                    my_file.open("stu.txt");
                    cout<<"\n\tFile stu.txt opened successfully."<<endl;
                }
            else
                {
                my_file.open(filename);
                if(!my_file.is_open())
                    cout<<"\n\tFile "<<filename<<" couldn't open.\n\n\tPress ENTER to load default file(stu.txt), or input a file name:";
                else cout<<"\n\tFile "<<filename<<" opened successfully."<<endl;
                }
        }
        if(my_file.is_open())
        {
            counter=0;
            flag=1;
            getline(my_file, mumble);
            while(my_file >> Data[counter].StuNo >> Data[counter].Name >> Data[counter].Gender >> Data[counter].PhoneNumber >> Data[counter].Wechat >> Data[counter].Dorm >> Data[counter].score)
            {
                counter++;
            }
            cout<<"\n\tThere are "<<counter<<" students imported"<<endl;
        }
        }
    color(2);
    cout<<setw(9)<<left<<"StuNo."<<" "<<setw(13)<<left<<"Name"<<setw(7)<<left<<"Gender"<<" "<<setw(12)<<left<<"  Phone"<<" "<<setw(10)<<left<<"WeChat"<<" "<<setw(10)<<left<<"Dormitory"<<" "<<setw(5)<<left<<"Score"<<"\n";
    color(15);
    for(int i=0; i<counter; i++)
    {
        cout<<setw(9)<<left<<Data[i].StuNo<<" "<<setw(13)<<left<<Data[i].Name<<setw(7)<<left<<Data[i].Gender<<" "<<setw(12)<<left<<Data[i].PhoneNumber<<" "<<setw(10)<<left<< Data[i].Wechat<<" "<<setw(10)<<left<<Data[i].Dorm<<" "<<setw(5)<<left<<Data[i].score<<"\n";
    }
}

void searchstudents()
{
    int re=0;
    if(flag==0)
    {
        re=1;
        ifstream my_file;
        string filename;
        string mumble;
        color(4);
        cout<<"\n\tNOTCE: Input 000 to Return to the Menu."<<endl;
        color(15);
        cout<<"\n\tThere is no data in the Students Management Information System.";
        cout<<"\n\tPress ENTER to load default file(stu.txt), or input a file name:";
        cin.get();
        while(!my_file.is_open())
        {
            getline(cin, filename);
            if(filename=="000")
                break;
            if(filename=="")
                {
                    my_file.open("stu.txt");
                    cout<<"\n\tFile stu.txt opened successfully."<<endl;
                }
            else
                {
                my_file.open(filename);
                if(!my_file.is_open())
                    cout<<"\n\tFile "<<filename<<" couldn't open.\n\n\tPress ENTER to load default file(stu.txt), or input a file name:";
                else cout<<"\n\tFile "<<filename<<" opened successfully."<<endl;
                }
        }
        if(my_file.is_open())
        {
            counter=0;
            flag=1;
            getline(my_file, mumble);
            while(my_file >> Data[counter].StuNo >> Data[counter].Name >> Data[counter].Gender >> Data[counter].PhoneNumber >> Data[counter].Wechat >> Data[counter].Dorm >> Data[counter].score)
            {
                counter++;
                my_file.get();

            }
            cout<<"\n\tThere are "<<counter<<" students imported"<<endl;
        }
    }
    if(flag==1)
    {
    string information;
    if(re==0)
        cin.get();
    while(1)
    {
        int ctr=0;
        color(4);
        cout<<"\n\tNOTCE: Input 000 to Return to the Menu."<<endl;
        color(15);
        do
        {
            cout<<"\n\tPlease input information of the student: ";
            getline(cin, information);
        } while(information=="");
        if(information=="000")
            break;
        if(information=="Male")
            information="M";
        if(information=="Female")
            information="F";
        color(2);
        cout<<"\n"<<setw(9)<<left<<"StuNo."<<" "<<setw(13)<<left<<"Name"<<setw(7)<<left<<"Gender"<<" "<<setw(12)<<left<<"  Phone"<<" "<<setw(10)<<left<<"WeChat"<<" "<<setw(10)<<left<<"Dormitory"<<" "<<setw(5)<<left<<"Score"<<"\n";
        color(15);
        for(int i=0; i<counter; i++)
        {
            if(!lower(information).compare(lower(Data[i].StuNo)) || !lower(information).compare(lower(Data[i].Name)) || !lower(information).compare(lower(Data[i].Gender)) || !lower(information).compare(lower(Data[i].PhoneNumber)) || !lower(information).compare(lower(Data[i].Wechat)) || !lower(information).compare(lower(Data[i].Dorm)) || !lower(information).compare(lower(to_string(Data[i].score))))
            {
                ctr++;
                cout<<setw(9)<<left<<Data[i].StuNo<<" "<<setw(13)<<left<<Data[i].Name<<setw(7)<<left<<Data[i].Gender<<" "<<setw(12)<<left<<Data[i].PhoneNumber<<" "<<setw(10)<<left<< Data[i].Wechat<<" "<<setw(10)<<left<<Data[i].Dorm<<" "<<setw(5)<<left<<Data[i].score<<"\n";
            }

        }
        cout<<"\n\tThere are "<<ctr<<" students with \""<<information<<"\"";
    }
    }
}

void addStudent()
{

    while(1)
    {
        color(4);
        cout<<"\n\tNOTICE: Input 000 to Return to the Menu."<<endl;
        color(15);
        cout<<"\n\tInput student No. :";
        cin>>Data[counter].StuNo;
        if(Data[counter].StuNo=="000")
            break;
        cout<<"\n\tInput student Name: ";
        cin>>Data[counter].Name;
        cout<<"\n\tInput student Gender(M/F): ";
        while(1)
        {
            char genderino;
            cin>>genderino;
            cin.ignore(100000,'\n');
            if(genderino=='M' || genderino=='m')
            {
                Data[counter].Gender="M";
                break;
            }
            else if(genderino=='F' || genderino=='f')
            {
                Data[counter].Gender="F";
                break;
            }
            else cout<<"\n\tInvalid. Please input 'M' or 'F' :";
        }
        cout<<"\n\tInput student Phone: ";
        cin>>Data[counter].PhoneNumber;
        cout<<"\n\tInput student Wechat: ";
        cin>>Data[counter].Wechat;
        cout<<"\n\tInput student Dormitory: ";
        cin>>Data[counter].Dorm;
        cout<<"\n\tInput student Score: ";
        int sc;
        while(!(cin>>sc) || sc<0)
        {
            cout<<"\n\tInvalid. Please input a positive number: ";
            cin.clear();
            cin.ignore(100000,'\n');
        }
        Data[counter].score=sc;
        cout<<"\n\tA student has been added.\n";
        cout<<setw(9)<<left<<Data[counter].StuNo<<" "<<setw(13)<<left<<Data[counter].Name<<setw(7)<<left<<Data[counter].Gender<<" "<<setw(12)<<left<<Data[counter].PhoneNumber<<" "<<setw(10)<<left<< Data[counter].Wechat<<" "<<setw(10)<<left<<Data[counter].Dorm<<" "<<setw(5)<<left<<Data[counter].score<<"\n";
        counter++;
        flag=1;
    }
    cin.get();
}

void modify()
{
    int re=0;
    if(flag==0)
    {
        re=1;
        ifstream my_file;
        string filename;
        string mumble;
        color(4);
        cout<<"\n\tNOTCE: Input 000 to Return to the Menu."<<endl;
        color(15);
        cout<<"\n\tThere is no data in the Students Management Information System.";
        cout<<"\n\tPress ENTER to load default file(stu.txt), or input a file name:";
        cin.get();
        while(!my_file.is_open())
        {
            getline(cin, filename);
            if(filename=="000")
                break;
            if(filename=="")
                {
                    my_file.open("stu.txt");
                    cout<<"\n\tFile stu.txt opened successfully."<<endl;
                }
            else
                {
                my_file.open(filename);
                if(!my_file.is_open())
                    cout<<"\n\tFile "<<filename<<" couldn't open.\n\n\tPress ENTER to load default file(stu.txt), or input a file name:";
                else cout<<"\n\tFile "<<filename<<" opened successfully."<<endl;
                }
        }
        if(my_file.is_open())
        {
            counter=0;
            flag=1;
            getline(my_file, mumble);
            while(my_file >> Data[counter].StuNo >> Data[counter].Name >> Data[counter].Gender >> Data[counter].PhoneNumber >> Data[counter].Wechat >> Data[counter].Dorm >> Data[counter].score)
            {
                counter++;
                my_file.get();

            }
            cout<<"\n\tThere are "<<counter<<" students imported"<<endl;
        }
    }
    if(flag==1)
    {
    int table[counter];
    string information;
    if(re==0)
        cin.get();
    while(1)
    {
        int ctr=0;
        color(4);
        cout<<"\n\tNOTCE: Input 000 to Return to the Menu."<<endl;
        color(15);
        do
        {
            cout<<"\n\tTo modify students, we need to find them first.";
            cout<<"\n\tPlease input information of the students to be changed: ";
            getline(cin, information);
        } while(information=="");
        if(information=="000")
            break;
        if(information=="Male")
            information="M";
        if(information=="Female")
            information="F";
        color(2);
        cout<<"\n"<<setw(9)<<left<<"StuNo."<<" "<<setw(13)<<left<<"Name"<<setw(7)<<left<<"Gender"<<" "<<setw(12)<<left<<"  Phone"<<" "<<setw(10)<<left<<"WeChat"<<" "<<setw(10)<<left<<"Dormitory"<<" "<<setw(5)<<left<<"Score"<<"\n";
        color(15);
        for(int i=0; i<counter; i++)
        {
            if(!lower(information).compare(lower(Data[i].StuNo)) || !lower(information).compare(lower(Data[i].Name)) || !lower(information).compare(lower(Data[i].Gender)) || !lower(information).compare(lower(Data[i].PhoneNumber)) || !lower(information).compare(lower(Data[i].Wechat)) || !lower(information).compare(lower(Data[i].Dorm)) || !lower(information).compare(lower(to_string(Data[i].score))))
            {
                table[ctr]=i;
                ctr++;
                cout<<setw(9)<<left<<Data[i].StuNo<<" "<<setw(13)<<left<<Data[i].Name<<setw(7)<<left<<Data[i].Gender<<" "<<setw(12)<<left<<Data[i].PhoneNumber<<" "<<setw(10)<<left<< Data[i].Wechat<<" "<<setw(10)<<left<<Data[i].Dorm<<" "<<setw(5)<<left<<Data[i].score<<"\n";
            }

        }
        cout<<"\n\tThere are "<<ctr<<" students with \""<<information<<"\""<<endl;
        if(ctr!=0)
        {
        cout<<"\n\tPress ENTER to modify all or input the StudentNo. :";
        string choice;
        getline(cin, choice);
        if(choice=="")
        {
            cout<<"\n\tYou are going to change all the above students. Input the information to be changed, If make no change, press the ENTER key."<<endl;
        }
        else
        {
            ctr=0;
            while(ctr==0)
            {
                for(int i=0; i<counter; i++)
                {
                    if(!lower(choice).compare(lower(Data[i].StuNo)))
                    {
                        table[ctr]=i;
                        ctr++;
                        break;
                    }
                }
                if(ctr==0)
                {
                    cout<<"\n\tThere is no student with StudentNo. : "<<choice<<endl;
                    cout<<"\n\tPlease input a StudentNo. again: ";
                    getline(cin, choice);
                }
            }
            cout<<"You are going to change the students with StudentNo. : "<<choice<<". Input the information to be changed. If make no change, press the ENTER key."<<endl;
        }
        string StudNo, Name, Gender, Phone, Wechat, Dorm, Score;
        cout<<"\n\tInput a new student No. :";
        getline(cin,StudNo);
        cout<<"\n\tInput student Name: ";
        getline(cin,Name);
        cout<<"\n\tInput student Gender(M/F): ";
        getline(cin,Gender);
        if(Gender!="")
        {
            char genderino;
            genderino=Gender[0];
        while(1)
        {
                if(genderino=='M' || genderino=='m')
                {
                    Gender="M";
                    break;
                }
                else if(genderino=='F' || genderino=='f')
                {
                    Gender="F";
                    break;
                }
                else cout<<"\n\tInvalid. Please input 'M' or 'F' :";
                cin>>genderino;
                cin.ignore(1000000,'\n');
            }
        }
        cout<<"\n\tInput student Phone: ";
        getline(cin,Phone);
        cout<<"\n\tInput student WeChat: ";
        getline(cin,Wechat);
        cout<<"\n\tInput student Dormitory: ";
        getline(cin,Dorm);
        cout<<"\n\tInput student Score: ";
        int sc=-1;
        getline(cin,Score);
        if(Score!="")
        {
            stringstream scr(Score);
            if(!(scr>>sc) || sc<0)
            {
                cout<<"\n\tInvalid. Please input a positive number: ";
                while(!(cin>>sc) || sc<0)
                {
                    cout<<"\n\tInvalid. Please input a positive number: ";
                    cin.clear();
                    cin.ignore(10000,'\n');
                }
                cin.get();
            }
        }
        if(choice=="" && StudNo=="" && Name=="" && Gender=="" && Phone=="" && Wechat=="" && Dorm=="" && Score=="")
            cout<<"\n\tThere are 0 students changed."<<endl;
        else{
            for(int i=0; i<ctr; i++)
            {
                if(StudNo!="")
                    Data[table[i]].StuNo=StudNo;
                if(Name!="")
                    Data[table[i]].Name=Name;
                if(Gender!="")
                    Data[table[i]].Gender=Gender;
                if(Phone!="")
                    Data[table[i]].PhoneNumber=Phone;
                if(Wechat!="")
                    Data[table[i]].Wechat=Wechat;
                if(Dorm!="")
                    Data[table[i]].Dorm=Dorm;
                if(Score!="")
                    Data[table[i]].score=sc;
                cout<<setw(9)<<left<<Data[table[i]].StuNo<<" "<<setw(13)<<left<<Data[table[i]].Name<<setw(7)<<left<<Data[table[i]].Gender<<" "<<setw(12)<<left<<Data[table[i]].PhoneNumber<<" "<<setw(10)<<left<< Data[table[i]].Wechat<<" "<<setw(10)<<left<<Data[table[i]].Dorm<<" "<<setw(5)<<left<<Data[table[i]].score<<"\n";
            }
            if(choice=="")
            cout<<"\n\tThere are "<<ctr<<" students changed."<<endl;
            if(choice!="")
            cout<<"\n\tThe students with StudentNo. "<<choice<<" have been changed."<<endl;
            }
        }
    }
    }
}

void Delete()
{
    int re=0;
    if(flag==0)
    {
        re=1;
        ifstream my_file;
        string filename;
        string mumble;
        color(4);
        cout<<"\n\tNOTCE: Input 000 to Return to the Menu."<<endl;
        color(15);
        cout<<"\n\tThere is no data in the Students Management Information System.";
        cout<<"\n\tPress ENTER to load default file(stu.txt), or input a file name:";
        cin.get();
        while(!my_file.is_open())
        {
            getline(cin, filename);
            if(filename=="000")
                break;
            if(filename=="")
                {
                    my_file.open("stu.txt");
                    cout<<"\n\tFile stu.txt opened successfully."<<endl;
                }
            else
                {
                my_file.open(filename);
                if(!my_file.is_open())
                    cout<<"\n\tFile "<<filename<<" couldn't open.\n\n\tPress ENTER to load default file(stu.txt), or input a file name:";
                else cout<<"\n\tFile "<<filename<<" opened successfully."<<endl;
                }
        }
        if(my_file.is_open())
        {
            counter=0;
            flag=1;
            getline(my_file, mumble);
            while(my_file >> Data[counter].StuNo >> Data[counter].Name >> Data[counter].Gender >> Data[counter].PhoneNumber >> Data[counter].Wechat >> Data[counter].Dorm >> Data[counter].score)
            {
                counter++;
                my_file.get();

            }
            cout<<"\n\tThere are "<<counter<<" students imported"<<endl;
        }
    }
    if(flag==1)
    {
    int table[counter];
    string information;
    if(re==0)
        cin.get();
    while(1)
    {
        int ctr=0;
        color(4);
        cout<<"\n\tNOTCE: Input 000 to Return to the Menu."<<endl;
        color(15);
        do
        {
            cout<<"\n\tTo delete students, we need to find them first.";
            cout<<"\n\tPlease input information of the students to be changed: ";
            getline(cin, information);
        } while(information=="");
        if(information=="000")
            break;
        if(information=="Male")
            information="M";
        if(information=="Female")
            information="F";
        color(2);
        cout<<"\n"<<setw(9)<<left<<"StuNo."<<" "<<setw(13)<<left<<"Name"<<setw(7)<<left<<"Gender"<<" "<<setw(12)<<left<<"  Phone"<<" "<<setw(10)<<left<<"WeChat"<<" "<<setw(10)<<left<<"Dormitory"<<" "<<setw(5)<<left<<"Score"<<"\n";
        color(15);
        for(int i=0; i<counter; i++)
        {
            if(!lower(information).compare(lower(Data[i].StuNo)) || !lower(information).compare(lower(Data[i].Name)) || !lower(information).compare(lower(Data[i].Gender)) || !lower(information).compare(lower(Data[i].PhoneNumber)) || !lower(information).compare(lower(Data[i].Wechat)) || !lower(information).compare(lower(Data[i].Dorm)) || !lower(information).compare(lower(to_string(Data[i].score))))
            {
                table[ctr]=i;
                ctr++;
                cout<<setw(9)<<left<<Data[i].StuNo<<" "<<setw(13)<<left<<Data[i].Name<<setw(7)<<left<<Data[i].Gender<<" "<<setw(12)<<left<<Data[i].PhoneNumber<<" "<<setw(10)<<left<< Data[i].Wechat<<" "<<setw(10)<<left<<Data[i].Dorm<<" "<<setw(5)<<left<<Data[i].score<<"\n";
            }

        }
        cout<<"\n\tThere are "<<ctr<<" students with \""<<information<<"\""<<endl;
        if(ctr!=0)
        {
        cout<<"\n\tPress ENTER to delete all or input the StudentNo. :";
        string choice;
        getline(cin, choice);
        if(choice=="000")
        {
            cout<<"\n\tThere are 0 students deleted with StudentNo. :"<<choice<<endl;
        }
        else if(choice=="")
        {
            for(int i=0; i<ctr; i++)
            {
                for(int j=table[i]; j<counter-1; j++)
                {
                    Data[j].StuNo=Data[j+1].StuNo;
                    Data[j].Name=Data[j+1].Name;
                    Data[j].Gender=Data[j+1].Gender;
                    Data[j].PhoneNumber=Data[j+1].PhoneNumber;
                    Data[j].Wechat=Data[j+1].Wechat;
                    Data[j].Dorm=Data[j+1].Dorm;
                    Data[j].score=Data[j+1].score;
                }
                for(int k=0; k<ctr; k++)
                {
                    table[k]--;
                }
                counter--;
            }
            cout<<"\n\tThere are "<<ctr<<" students deleted.";
        }
        else
        {
            ctr=0;
            while(ctr==0)
            {
                if(choice=="000")
                    break;
                for(int i=0; i<counter; i++)
                {
                    if(!lower(choice).compare(lower(Data[i].StuNo)))
                    {
                        table[ctr]=i;
                        ctr++;
                        break;
                    }
                }
                if(ctr==0)
                {
                    cout<<"\n\tThere is no student with StudentNo. : "<<choice<<endl;
                    cout<<"\n\tPlease input a StudentNo. again: ";
                    getline(cin, choice);
                }
            }
            if(ctr==0)
            {
                cout<<"\n\tThere are 0 students deleted with StudentNo. :"<<choice<<endl;
            }
            else
            {
                for(int i=0; i<ctr; i++)
            {
                for(int j=table[i]; j<counter-1; j++)
                {
                    Data[j].StuNo=Data[j+1].StuNo;
                    Data[j].Name=Data[j+1].Name;
                    Data[j].Gender=Data[j+1].Gender;
                    Data[j].PhoneNumber=Data[j+1].PhoneNumber;
                    Data[j].Wechat=Data[j+1].Wechat;
                    Data[j].Dorm=Data[j+1].Dorm;
                    Data[j].score=Data[j+1].score;
                }
                counter--;
            }
                cout<<"\n\tThere are 1 students deleted with StudNo. :"<<choice<<endl;
            }
        }
        }
        if(counter==0)
            {
                cout<<"\n\tThere is no more Data. All the Data is deleted.";
                flag=0;
                break;
            }
    }
    }
}

void sortStuNo()
{
    cin.get();
    if(flag==0)
    {
        ifstream my_file;
        string filename;
        string mumble;
        color(4);
        cout<<"\n\tNOTCE: Input 000 to Return to the Menu."<<endl;
        color(15);
        cout<<"\n\tThere is no data in the Students Management Information System.";
        cout<<"\n\tPress ENTER to load default file(stu.txt), or input a file name:";
        while(!my_file.is_open())
        {
            getline(cin, filename);
            if(filename=="000")
                break;
            if(filename=="")
                {
                    my_file.open("stu.txt");
                    cout<<"\n\tFile stu.txt opened successfully."<<endl;
                }
            else
                {
                my_file.open(filename);
                if(!my_file.is_open())
                    cout<<"\n\tFile "<<filename<<" couldn't open.\n\n\tPress ENTER to load default file(stu.txt), or input a file name:";
                else cout<<"\n\tFile "<<filename<<" opened successfully."<<endl;
                }
        }
        if(my_file.is_open())
        {
            counter=0;
            flag=1;
            getline(my_file, mumble);
            while(my_file >> Data[counter].StuNo >> Data[counter].Name >> Data[counter].Gender >> Data[counter].PhoneNumber >> Data[counter].Wechat >> Data[counter].Dorm >> Data[counter].score)
            {
                counter++;
                my_file.get();

            }
            cout<<"\n\tThere are "<<counter<<" students imported"<<endl;
        }
    }
    if(flag==1)
    {
        string choice;
        cout<<"\n\tTo sort the students by their student Numbers.\n";
        cout<<"\n\tPress ENTER to sort in ASC order, others in DESC order:";
        getline(cin,choice);
        if(choice=="")
        {
            int minIndex;
            for(int i=0; i<counter-1; i++)
            {
                minIndex=i;
                for(int j=i+1; j<counter; j++)
                {
                    if(Data[j].StuNo.compare(Data[minIndex].StuNo)<0)
                    minIndex=j;
                }
                swap(Data[minIndex], Data[i]);
            }
        }
        else
        {
            int maxIndex;
            for(int i=0; i<counter-1; i++)
            {
                maxIndex=i;
                for(int j=i+1; j<counter; j++)
                {
                    if(Data[j].StuNo.compare(Data[maxIndex].StuNo)>0)
                    maxIndex=j;
                }
                swap(Data[maxIndex], Data[i]);
            }
        }
        color(2);
        cout<<setw(9)<<left<<"StuNo."<<" "<<setw(13)<<left<<"Name"<<setw(7)<<left<<"Gender"<<" "<<setw(12)<<left<<"  Phone"<<" "<<setw(10)<<left<<"WeChat"<<" "<<setw(10)<<left<<"Dormitory"<<" "<<setw(5)<<left<<"Score"<<"\n";
        color(15);
        for(int i=0; i<counter; i++)
        {
            cout<<setw(9)<<left<<Data[i].StuNo<<" "<<setw(13)<<left<<Data[i].Name<<setw(7)<<left<<Data[i].Gender<<" "<<setw(12)<<left<<Data[i].PhoneNumber<<" "<<setw(10)<<left<< Data[i].Wechat<<" "<<setw(10)<<left<<Data[i].Dorm<<" "<<setw(5)<<left<<Data[i].score<<"\n";
        }
    }
}

void sortName()
{
    cin.get();
    if(flag==0)
    {
        ifstream my_file;
        string filename;
        string mumble;
        color(4);
        cout<<"\n\tNOTCE: Input 000 to Return to the Menu."<<endl;
        color(15);
        cout<<"\n\tThere is no data in the Students Management Information System.";
        cout<<"\n\tPress ENTER to load default file(stu.txt), or input a file name:";
        while(!my_file.is_open())
        {
            getline(cin, filename);
            if(filename=="000")
                break;
            if(filename=="")
                {
                    my_file.open("stu.txt");
                    cout<<"\n\tFile stu.txt opened successfully."<<endl;
                }
            else
                {
                my_file.open(filename);
                if(!my_file.is_open())
                    cout<<"\n\tFile "<<filename<<" couldn't open.\n\n\tPress ENTER to load default file(stu.txt), or input a file name:";
                else cout<<"\n\tFile "<<filename<<" opened successfully."<<endl;
                }
        }
        if(my_file.is_open())
        {
            counter=0;
            flag=1;
            getline(my_file, mumble);
            while(my_file >> Data[counter].StuNo >> Data[counter].Name >> Data[counter].Gender >> Data[counter].PhoneNumber >> Data[counter].Wechat >> Data[counter].Dorm >> Data[counter].score)
            {
                counter++;
                my_file.get();

            }
            cout<<"\n\tThere are "<<counter<<" students imported"<<endl;
        }
    }
    if(flag==1)
    {
        string choice;
        cout<<"\n\tTo sort the students by their names.\n";
        cout<<"\n\tPress ENTER to sort in ASC order, others in DESC order:";
        getline(cin,choice);
        if(choice=="")
        {
            int minIndex;
            for(int i=0; i<counter-1; i++)
            {
                minIndex=i;
                for(int j=i+1; j<counter; j++)
                {
                    if(Data[j].Name.compare(Data[minIndex].Name)<0)
                    minIndex=j;
                }
                swap(Data[minIndex], Data[i]);
            }
        }
        else
        {
            int maxIndex;
            for(int i=0; i<counter-1; i++)
            {
                maxIndex=i;
                for(int j=i+1; j<counter; j++)
                {
                    if(Data[j].Name.compare(Data[maxIndex].Name)>0)
                    maxIndex=j;
                }
                swap(Data[maxIndex], Data[i]);
            }
        }
        color(2);
        cout<<setw(9)<<left<<"StuNo."<<" "<<setw(13)<<left<<"Name"<<setw(7)<<left<<"Gender"<<" "<<setw(12)<<left<<"  Phone"<<" "<<setw(10)<<left<<"WeChat"<<" "<<setw(10)<<left<<"Dormitory"<<" "<<setw(5)<<left<<"Score"<<"\n";
        color(15);
        for(int i=0; i<counter; i++)
        {
            cout<<setw(9)<<left<<Data[i].StuNo<<" "<<setw(13)<<left<<Data[i].Name<<setw(7)<<left<<Data[i].Gender<<" "<<setw(12)<<left<<Data[i].PhoneNumber<<" "<<setw(10)<<left<< Data[i].Wechat<<" "<<setw(10)<<left<<Data[i].Dorm<<" "<<setw(5)<<left<<Data[i].score<<"\n";
        }
    }
}

void sortGender()
{
    cin.get();
    if(flag==0)
    {
        ifstream my_file;
        string filename;
        string mumble;
        color(4);
        cout<<"\n\tNOTCE: Input 000 to Return to the Menu."<<endl;
        color(15);
        cout<<"\n\tThere is no data in the Students Management Information System.";
        cout<<"\n\tPress ENTER to load default file(stu.txt), or input a file name:";
        while(!my_file.is_open())
        {
            getline(cin, filename);
            if(filename=="000")
                break;
            if(filename=="")
                {
                    my_file.open("stu.txt");
                    cout<<"\n\tFile stu.txt opened successfully."<<endl;
                }
            else
                {
                my_file.open(filename);
                if(!my_file.is_open())
                    cout<<"\n\tFile "<<filename<<" couldn't open.\n\n\tPress ENTER to load default file(stu.txt), or input a file name:";
                else cout<<"\n\tFile "<<filename<<" opened successfully."<<endl;
                }
        }
        if(my_file.is_open())
        {
            counter=0;
            flag=1;
            getline(my_file, mumble);
            while(my_file >> Data[counter].StuNo >> Data[counter].Name >> Data[counter].Gender >> Data[counter].PhoneNumber >> Data[counter].Wechat >> Data[counter].Dorm >> Data[counter].score)
            {
                counter++;
                my_file.get();

            }
            cout<<"\n\tThere are "<<counter<<" students imported"<<endl;
        }
    }
    if(flag==1)
    {
        string choice;
        cout<<"\n\tTo sort the students by their Gender.\n";
        cout<<"\n\tPress ENTER to sort in ASC order, others in DESC order:";
        getline(cin,choice);
        if(choice=="")
        {
            int minIndex;
            for(int i=0; i<counter-1; i++)
            {
                minIndex=i;
                for(int j=i+1; j<counter; j++)
                {
                    if(Data[j].Gender.compare(Data[minIndex].Gender)<0)
                    minIndex=j;
                }
                swap(Data[minIndex], Data[i]);
            }
        }
        else
        {
            int maxIndex;
            for(int i=0; i<counter-1; i++)
            {
                maxIndex=i;
                for(int j=i+1; j<counter; j++)
                {
                    if(Data[j].Gender.compare(Data[maxIndex].Gender)>0)
                    maxIndex=j;
                }
                swap(Data[maxIndex], Data[i]);
            }
        }
        color(2);
        cout<<setw(9)<<left<<"StuNo."<<" "<<setw(13)<<left<<"Name"<<setw(7)<<left<<"Gender"<<" "<<setw(12)<<left<<"  Phone"<<" "<<setw(10)<<left<<"WeChat"<<" "<<setw(10)<<left<<"Dormitory"<<" "<<setw(5)<<left<<"Score"<<"\n";
        color(15);
        for(int i=0; i<counter; i++)
        {
            cout<<setw(9)<<left<<Data[i].StuNo<<" "<<setw(13)<<left<<Data[i].Name<<setw(7)<<left<<Data[i].Gender<<" "<<setw(12)<<left<<Data[i].PhoneNumber<<" "<<setw(10)<<left<< Data[i].Wechat<<" "<<setw(10)<<left<<Data[i].Dorm<<" "<<setw(5)<<left<<Data[i].score<<"\n";
        }
    }
}

void sortPhone()
{
    cin.get();
    if(flag==0)
    {
        ifstream my_file;
        string filename;
        string mumble;
        color(4);
        cout<<"\n\tNOTCE: Input 000 to Return to the Menu."<<endl;
        color(15);
        cout<<"\n\tThere is no data in the Students Management Information System.";
        cout<<"\n\tPress ENTER to load default file(stu.txt), or input a file name:";
        while(!my_file.is_open())
        {
            getline(cin, filename);
            if(filename=="000")
                break;
            if(filename=="")
                {
                    my_file.open("stu.txt");
                    cout<<"\n\tFile stu.txt opened successfully."<<endl;
                }
            else
                {
                my_file.open(filename);
                if(!my_file.is_open())
                    cout<<"\n\tFile "<<filename<<" couldn't open.\n\n\tPress ENTER to load default file(stu.txt), or input a file name:";
                else cout<<"\n\tFile "<<filename<<" opened successfully."<<endl;
                }
        }
        if(my_file.is_open())
        {
            counter=0;
            flag=1;
            getline(my_file, mumble);
            while(my_file >> Data[counter].StuNo >> Data[counter].Name >> Data[counter].Gender >> Data[counter].PhoneNumber >> Data[counter].Wechat >> Data[counter].Dorm >> Data[counter].score)
            {
                counter++;
                my_file.get();

            }
            cout<<"\n\tThere are "<<counter<<" students imported"<<endl;
        }
    }
    if(flag==1)
    {
        string choice;
        cout<<"\n\tTo sort the students by their Phone Number.\n";
        cout<<"\n\tPress ENTER to sort in ASC order, others in DESC order:";
        getline(cin,choice);
        if(choice=="")
        {
            int minIndex;
            for(int i=0; i<counter-1; i++)
            {
                minIndex=i;
                for(int j=i+1; j<counter; j++)
                {
                    if(Data[j].PhoneNumber.compare(Data[minIndex].PhoneNumber)<0)
                    minIndex=j;
                }
                swap(Data[minIndex], Data[i]);
            }
        }
        else
        {
            int maxIndex;
            for(int i=0; i<counter-1; i++)
            {
                maxIndex=i;
                for(int j=i+1; j<counter; j++)
                {
                    if(Data[j].PhoneNumber.compare(Data[maxIndex].PhoneNumber)>0)
                    maxIndex=j;
                }
                swap(Data[maxIndex], Data[i]);
            }
        }
        color(2);
        cout<<setw(9)<<left<<"StuNo."<<" "<<setw(13)<<left<<"Name"<<setw(7)<<left<<"Gender"<<" "<<setw(12)<<left<<"  Phone"<<" "<<setw(10)<<left<<"WeChat"<<" "<<setw(10)<<left<<"Dormitory"<<" "<<setw(5)<<left<<"Score"<<"\n";
        color(15);
        for(int i=0; i<counter; i++)
        {
            cout<<setw(9)<<left<<Data[i].StuNo<<" "<<setw(13)<<left<<Data[i].Name<<setw(7)<<left<<Data[i].Gender<<" "<<setw(12)<<left<<Data[i].PhoneNumber<<" "<<setw(10)<<left<< Data[i].Wechat<<" "<<setw(10)<<left<<Data[i].Dorm<<" "<<setw(5)<<left<<Data[i].score<<"\n";
        }
    }
}

void sortWechat()
{
    cin.get();
    if(flag==0)
    {
        ifstream my_file;
        string filename;
        string mumble;
        color(4);
        cout<<"\n\tNOTCE: Input 000 to Return to the Menu."<<endl;
        color(15);
        cout<<"\n\tThere is no data in the Students Management Information System.";
        cout<<"\n\tPress ENTER to load default file(stu.txt), or input a file name:";
        while(!my_file.is_open())
        {
            getline(cin, filename);
            if(filename=="000")
                break;
            if(filename=="")
                {
                    my_file.open("stu.txt");
                    cout<<"\n\tFile stu.txt opened successfully."<<endl;
                }
            else
                {
                my_file.open(filename);
                if(!my_file.is_open())
                    cout<<"\n\tFile "<<filename<<" couldn't open.\n\n\tPress ENTER to load default file(stu.txt), or input a file name:";
                else cout<<"\n\tFile "<<filename<<" opened successfully."<<endl;
                }
        }
        if(my_file.is_open())
        {
            counter=0;
            flag=1;
            getline(my_file, mumble);
            while(my_file >> Data[counter].StuNo >> Data[counter].Name >> Data[counter].Gender >> Data[counter].PhoneNumber >> Data[counter].Wechat >> Data[counter].Dorm >> Data[counter].score)
            {
                counter++;
                my_file.get();

            }
            cout<<"\n\tThere are "<<counter<<" students imported"<<endl;
        }
    }
    if(flag==1)
    {
        string choice;
        cout<<"\n\tTo sort the students by their Wechat.\n";
        cout<<"\n\tPress ENTER to sort in ASC order, others in DESC order:";
        getline(cin,choice);
        if(choice=="")
        {
            int minIndex;
            for(int i=0; i<counter-1; i++)
            {
                minIndex=i;
                for(int j=i+1; j<counter; j++)
                {
                    if(Data[j].Wechat.compare(Data[minIndex].Wechat)<0)
                    minIndex=j;
                }
                swap(Data[minIndex], Data[i]);
            }
        }
        else
        {
            int maxIndex;
            for(int i=0; i<counter-1; i++)
            {
                maxIndex=i;
                for(int j=i+1; j<counter; j++)
                {
                    if(Data[j].Wechat.compare(Data[maxIndex].Wechat)>0)
                    maxIndex=j;
                }
                swap(Data[maxIndex], Data[i]);
            }
        }
        color(2);
        cout<<setw(9)<<left<<"StuNo."<<" "<<setw(13)<<left<<"Name"<<setw(7)<<left<<"Gender"<<" "<<setw(12)<<left<<"  Phone"<<" "<<setw(10)<<left<<"WeChat"<<" "<<setw(10)<<left<<"Dormitory"<<" "<<setw(5)<<left<<"Score"<<"\n";
        color(15);
        for(int i=0; i<counter; i++)
        {
            cout<<setw(9)<<left<<Data[i].StuNo<<" "<<setw(13)<<left<<Data[i].Name<<setw(7)<<left<<Data[i].Gender<<" "<<setw(12)<<left<<Data[i].PhoneNumber<<" "<<setw(10)<<left<< Data[i].Wechat<<" "<<setw(10)<<left<<Data[i].Dorm<<" "<<setw(5)<<left<<Data[i].score<<"\n";
        }
    }
}

void sortDorm()
{
    cin.get();
    if(flag==0)
    {
        ifstream my_file;
        string filename;
        string mumble;
        color(4);
        cout<<"\n\tNOTCE: Input 000 to Return to the Menu."<<endl;
        color(15);
        cout<<"\n\tThere is no data in the Students Management Information System.";
        cout<<"\n\tPress ENTER to load default file(stu.txt), or input a file name:";
        while(!my_file.is_open())
        {
            getline(cin, filename);
            if(filename=="000")
                break;
            if(filename=="")
                {
                    my_file.open("stu.txt");
                    cout<<"\n\tFile stu.txt opened successfully."<<endl;
                }
            else
                {
                my_file.open(filename);
                if(!my_file.is_open())
                    cout<<"\n\tFile "<<filename<<" couldn't open.\n\n\tPress ENTER to load default file(stu.txt), or input a file name:";
                else cout<<"\n\tFile "<<filename<<" opened successfully."<<endl;
                }
        }
        if(my_file.is_open())
        {
            counter=0;
            flag=1;
            getline(my_file, mumble);
            while(my_file >> Data[counter].StuNo >> Data[counter].Name >> Data[counter].Gender >> Data[counter].PhoneNumber >> Data[counter].Wechat >> Data[counter].Dorm >> Data[counter].score)
            {
                counter++;
                my_file.get();

            }
            cout<<"\n\tThere are "<<counter<<" students imported"<<endl;
        }
    }
    if(flag==1)
    {
        string choice;
        cout<<"\n\tTo sort the students by their Dorms.\n";
        cout<<"\n\tPress ENTER to sort in ASC order, others in DESC order:";
        getline(cin,choice);
        if(choice=="")
        {
            int minIndex;
            for(int i=0; i<counter-1; i++)
            {
                minIndex=i;
                for(int j=i+1; j<counter; j++)
                {
                    if(Data[j].Dorm.compare(Data[minIndex].Dorm)<0)
                    minIndex=j;
                }
                swap(Data[minIndex], Data[i]);
            }
        }
        else
        {
            int maxIndex;
            for(int i=0; i<counter-1; i++)
            {
                maxIndex=i;
                for(int j=i+1; j<counter; j++)
                {
                    if(Data[j].Dorm.compare(Data[maxIndex].Dorm)>0)
                    maxIndex=j;
                }
                swap(Data[maxIndex], Data[i]);
            }
        }
        color(2);
        cout<<setw(9)<<left<<"StuNo."<<" "<<setw(13)<<left<<"Name"<<setw(7)<<left<<"Gender"<<" "<<setw(12)<<left<<"  Phone"<<" "<<setw(10)<<left<<"WeChat"<<" "<<setw(10)<<left<<"Dormitory"<<" "<<setw(5)<<left<<"Score"<<"\n";
        color(15);
        for(int i=0; i<counter; i++)
        {
            cout<<setw(9)<<left<<Data[i].StuNo<<" "<<setw(13)<<left<<Data[i].Name<<setw(7)<<left<<Data[i].Gender<<" "<<setw(12)<<left<<Data[i].PhoneNumber<<" "<<setw(10)<<left<< Data[i].Wechat<<" "<<setw(10)<<left<<Data[i].Dorm<<" "<<setw(5)<<left<<Data[i].score<<"\n";
        }
    }
}

void sortScore()
{
    cin.get();
    if(flag==0)
    {
        ifstream my_file;
        string filename;
        string mumble;
        color(4);
        cout<<"\n\tNOTCE: Input 000 to Return to the Menu."<<endl;
        color(15);
        cout<<"\n\tThere is no data in the Students Management Information System.";
        cout<<"\n\tPress ENTER to load default file(stu.txt), or input a file name:";
        while(!my_file.is_open())
        {
            getline(cin, filename);
            if(filename=="000")
                break;
            if(filename=="")
                {
                    my_file.open("stu.txt");
                    cout<<"\n\tFile stu.txt opened successfully."<<endl;
                }
            else
                {
                my_file.open(filename);
                if(!my_file.is_open())
                    cout<<"\n\tFile "<<filename<<" couldn't open.\n\n\tPress ENTER to load default file(stu.txt), or input a file name:";
                else cout<<"\n\tFile "<<filename<<" opened successfully."<<endl;
                }
        }
        if(my_file.is_open())
        {
            counter=0;
            flag=1;
            getline(my_file, mumble);
            while(my_file >> Data[counter].StuNo >> Data[counter].Name >> Data[counter].Gender >> Data[counter].PhoneNumber >> Data[counter].Wechat >> Data[counter].Dorm >> Data[counter].score)
            {
                counter++;
                my_file.get();

            }
            cout<<"\n\tThere are "<<counter<<" students imported"<<endl;
        }
    }
    if(flag==1)
    {
        string choice;
        cout<<"\n\tTo sort the students by their scores.\n";
        cout<<"\n\tPress ENTER to sort in ASC order, others in DESC order:";
        getline(cin,choice);
        if(choice=="")
        {
            int minIndex;
            for(int i=0; i<counter-1; i++)
            {
                minIndex=i;
                for(int j=i+1; j<counter; j++)
                {
                    if(Data[j].score - Data[minIndex].score<0)
                    minIndex=j;
                }
                swap(Data[minIndex], Data[i]);
            }
        }
        else
        {
            int maxIndex;
            for(int i=0; i<counter-1; i++)
            {
                maxIndex=i;
                for(int j=i+1; j<counter; j++)
                {
                    if(Data[j].score - Data[maxIndex].score>0)
                    maxIndex=j;
                }
                swap(Data[maxIndex], Data[i]);
            }
        }
        color(2);
        cout<<setw(9)<<left<<"StuNo."<<" "<<setw(13)<<left<<"Name"<<setw(7)<<left<<"Gender"<<" "<<setw(12)<<left<<"  Phone"<<" "<<setw(10)<<left<<"WeChat"<<" "<<setw(10)<<left<<"Dormitory"<<" "<<setw(5)<<left<<"Score"<<"\n";
        color(15);
        for(int i=0; i<counter; i++)
        {
            cout<<setw(9)<<left<<Data[i].StuNo<<" "<<setw(13)<<left<<Data[i].Name<<setw(7)<<left<<Data[i].Gender<<" "<<setw(12)<<left<<Data[i].PhoneNumber<<" "<<setw(10)<<left<< Data[i].Wechat<<" "<<setw(10)<<left<<Data[i].Dorm<<" "<<setw(5)<<left<<Data[i].score<<"\n";
        }
    }
}

void statistics()
{
    cin.get();
    if(flag==0)
    {
        ifstream my_file;
        string filename;
        string mumble;
        color(4);
        cout<<"\n\tNOTCE: Input 000 to Return to the Menu."<<endl;
        color(15);
        cout<<"\n\tThere is no data in the Students Management Information System.";
        cout<<"\n\tPress ENTER to load default file(stu.txt), or input a file name:";
        while(!my_file.is_open())
        {
            getline(cin, filename);
            if(filename=="000")
                break;
            if(filename=="")
                {
                    my_file.open("stu.txt");
                    cout<<"\n\tFile stu.txt opened successfully."<<endl;
                }
            else
                {
                my_file.open(filename);
                if(!my_file.is_open())
                    cout<<"\n\tFile "<<filename<<" couldn't open.\n\n\tPress ENTER to load default file(stu.txt), or input a file name:";
                else cout<<"\n\tFile "<<filename<<" opened successfully."<<endl;
                }
        }
        if(my_file.is_open())
        {
            counter=0;
            flag=1;
            getline(my_file, mumble);
            while(my_file >> Data[counter].StuNo >> Data[counter].Name >> Data[counter].Gender >> Data[counter].PhoneNumber >> Data[counter].Wechat >> Data[counter].Dorm >> Data[counter].score)
            {
                counter++;
                my_file.get();

            }
            cout<<"\n\tThere are "<<counter<<" students imported"<<endl;
        }
    }
    if(flag==1)
    {
        int minIndex=0;
        int maxIndex=0;
        int males=0;
        int females=0;
        float average=0.0;
        for(int i=0; i<counter; i++)
        {
            average+=Data[i].score;
            if(Data[i].Gender=="M") males++;
            else if(Data[i].Gender=="F") females++;
            if(Data[i].score - Data[minIndex].score<0)
            minIndex=i;
            if(Data[i].score - Data[maxIndex].score>0)
            maxIndex=i;
        }
        cout<<"\n\tThe Statistics Data of the Students are as follow: "<<endl;
        cout<<"\n\t"<<setw(9)<<right<<"Students: "<<right<<counter;
        cout<<"\n\t"<<setw(9)<<right<<"Male: "<<right<<males;
        cout<<"\n\t"<<setw(9)<<right<<"MaxScore: "<<right<<Data[maxIndex].score;
        cout<<"\n\t"<<setw(9)<<right<<"MinScore: "<<right<<Data[minIndex].score;
        cout<<"\n\t"<<setw(9)<<right<<"AvgScore: "<<right<<average/counter<<endl;
        cout<<"\n\tThe Information of the MaxScore Students is : "<<endl;
        int i=maxIndex;
        color(2);
        cout<<setw(9)<<left<<"StuNo."<<" "<<setw(13)<<left<<"Name"<<setw(7)<<left<<"Gender"<<" "<<setw(12)<<left<<"  Phone"<<" "<<setw(10)<<left<<"WeChat"<<" "<<setw(10)<<left<<"Dormitory"<<" "<<setw(5)<<left<<"Score"<<"\n";
        color(15);
        cout<<setw(9)<<left<<Data[i].StuNo<<" "<<setw(13)<<left<<Data[i].Name<<setw(7)<<left<<Data[i].Gender<<" "<<setw(12)<<left<<Data[i].PhoneNumber<<" "<<setw(10)<<left<< Data[i].Wechat<<" "<<setw(10)<<left<<Data[i].Dorm<<" "<<setw(5)<<left<<Data[i].score<<"\n";
        cout<<"\n\tThe Information of the MinScore Students is : "<<endl;
        i=minIndex;
        color(2);
        cout<<setw(9)<<left<<"StuNo."<<" "<<setw(13)<<left<<"Name"<<setw(7)<<left<<"Gender"<<" "<<setw(12)<<left<<"  Phone"<<" "<<setw(10)<<left<<"WeChat"<<" "<<setw(10)<<left<<"Dormitory"<<" "<<setw(5)<<left<<"Score"<<"\n";
        color(15);
        cout<<setw(9)<<left<<Data[i].StuNo<<" "<<setw(13)<<left<<Data[i].Name<<setw(7)<<left<<Data[i].Gender<<" "<<setw(12)<<left<<Data[i].PhoneNumber<<" "<<setw(10)<<left<< Data[i].Wechat<<" "<<setw(10)<<left<<Data[i].Dorm<<" "<<setw(5)<<left<<Data[i].score<<"\n";
    }
}

void clearData()
{
    cin.get();
    color(2);
    cout<<"\n\tThe "<<counter<<" Data has been cleared."<<endl;
    counter=0;
    flag=0;
    color(15);
}

void save()
{
    if(flag==0)
    {
        cout<<"\n\tThere is no data in the Students Management Information System.";
    }
    else
    {
    ofstream my_file;
    string filename;
    color(4);
    cout<<"\n\tNOTICE: Input 000 to Return to the Menu."<<endl;
    color(15);
    cout<<"\n\tPress ENTER to save data to stu_out.txt, or input a file name: ";
    cin.get();
    getline(cin,filename);
    if(filename!="000")
    {
    if(filename=="")
    {
        remove("stu_out.txt");
        my_file.open("stu_out.txt");
        cout<<"\n\tFile stu_out.txt opened successfully."<<endl;
    }
    else
    {
        stringstream s(filename);
        char* f=(char*)malloc(filename.length());
        s>>f;
        remove(f);
        my_file.open(filename);
        cout<<"\n\tFile "<<filename<<" opened successfully."<<endl;
    }

    my_file<<setw(9)<<left<<"StuNo."<<" "<<setw(13)<<left<<"Name"<<setw(7)<<left<<"Gender"<<" "<<setw(12)<<left<<"  Phone"<<" "<<setw(10)<<left<<"WeChat"<<" "<<setw(10)<<left<<"Dormitory"<<" "<<setw(5)<<left<<"Score"<<"\n";
    for(int i=0; i<counter; i++)
    {
        my_file<<setw(9)<<left<<Data[i].StuNo<<" "<<setw(13)<<left<<Data[i].Name<<setw(7)<<left<<Data[i].Gender<<" "<<setw(12)<<left<<Data[i].PhoneNumber<<" "<<setw(10)<<left<< Data[i].Wechat<<" "<<setw(10)<<left<<Data[i].Dorm<<" "<<setw(5)<<left<<Data[i].score<<"\n";
    }
    cout<<"\n\tThere are "<<counter<<" students saved to file: "<<filename<<".";
    }
    }
}

void showOrHide()
{
    cin.get();
    if(flag==0)
    {
        ifstream my_file;
        string filename;
        string mumble;
        color(4);
        cout<<"\n\tNOTCE: Input 000 to Return to the Menu."<<endl;
        color(15);
        cout<<"\n\tThere is no data in the Students Management Information System.";
        cout<<"\n\tPress ENTER to load default file(stu.txt), or input a file name:";
        while(!my_file.is_open())
        {
            getline(cin, filename);
            if(filename=="000")
                break;
            if(filename=="")
                {
                    my_file.open("stu.txt");
                    cout<<"\n\tFile stu.txt opened successfully."<<endl;
                }
            else
                {
                my_file.open(filename);
                if(!my_file.is_open())
                    cout<<"\n\tFile "<<filename<<" couldn't open.\n\n\tPress ENTER to load default file(stu.txt), or input a file name:";
                else cout<<"\n\tFile "<<filename<<" opened successfully."<<endl;
                }
        }
        if(my_file.is_open())
        {
            counter=0;
            flag=1;
            getline(my_file, mumble);
            while(my_file >> Data[counter].StuNo >> Data[counter].Name >> Data[counter].Gender >> Data[counter].PhoneNumber >> Data[counter].Wechat >> Data[counter].Dorm >> Data[counter].score)
            {
                counter++;
                my_file.get();

            }
            cout<<"\n\tThere are "<<counter<<" students imported"<<endl;
        }
    }
    if(flag==1)
    {
        color(2);
        cout<<"\n\tPress ENTER to SHOW the data field, other to HIDE it: "<<endl;
        color(15);
        string StudNo, Name, Gender, Phone, Wechat, Dorm, score;
        cout<<"\n\tShow or Hide the Student Number:";
        getline(cin,StudNo);
        cout<<"\n\tShow or Hide the Name:";
        getline(cin, Name);
        cout<<"\n\tShow or Hide the Gender:";
        getline(cin, Gender);
        cout<<"\n\tShow or Hide the Phone Number:";
        getline(cin, Phone);
        cout<<"\n\tShow or Hide the Wechat:";
        getline(cin, Wechat);
        cout<<"\n\tShow or Hide the Dormitory:";
        getline(cin, Dorm);
        cout<<"\n\tShow or Hide the Score:";
        getline(cin, score);
        color(2);
        if(StudNo=="") cout<<setw(9)<<left<<"StuNo."<<" ";
        if(Name=="") cout<<setw(13)<<left<<"Name"<<" ";
        if(Gender=="") cout<<setw(7)<<left<<"Gender"<<" ";
        if(Phone=="") cout<<setw(12)<<left<<"Phone"<<" ";
        if(Wechat=="") cout<<setw(10)<<left<<"WeChat"<<" ";
        if(Dorm=="") cout<<setw(10)<<left<<"Dormitory"<<" ";
        if(score=="") cout<<setw(5)<<left<<"Score";
        cout<<"\n";
        color(15);
        for(int i=0; i<counter; i++)
        {
        if(StudNo=="") cout<<setw(9)<<left<<Data[i].StuNo<<" ";
        if(Name=="") cout<<setw(13)<<left<<Data[i].Name<<" ";
        if(Gender=="") cout<<setw(7)<<left<<Data[i].Gender<<" ";
        if(Phone=="") cout<<setw(12)<<left<<Data[i].PhoneNumber<<" ";
        if(Wechat=="") cout<<setw(10)<<left<<Data[i].Wechat<<" ";
        if(Dorm=="") cout<<setw(10)<<left<<Data[i].Dorm<<" ";
        if(score=="") cout<<setw(5)<<left<<Data[i].score<<" ";
        cout<<"\n";
        }
    }
}


