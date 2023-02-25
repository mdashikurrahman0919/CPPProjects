/*
Name           : Md Ashikur Rahman
ID             : 20170919
Frameworke     : Framework for project 08
Projecert name : Tickets System
Date           : 12 November 2021
Aouthor        : MD ASHIKUR RAHMNA
Copyright      : @ashikurrahman
Description    : A Framework that includes Menu and user choices
*/




#include<iostream>
#include<string.h>
#include <windows.h>
#include <cstdlib>
using namespace std;
void changeColor(int desiredColor){
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), desiredColor);
}
#define MAX 50
bool check= false;
int row,counter=0;
int col,Seat,sell=0,booking=0;
string seat[MAX][MAX];

class TicketsTheater{
	public:
		void showmenu()
		{
		changeColor(15);

            cout<<"\n\n\t\t%%%%%%%%%%%%%%%%%%%%% Project 8 Tickets System %%%%%%%%%%%%%%%%%%%%%%%%%%\n"<<endl;


			cout<<"\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&"<<endl;
		    cout<<"\t\t============================ Tickets Menu ==============================="<<endl;
		    cout<<"\t\t========================================================================="<<endl;
		    cout<<"\t\t=                                                                       ="<<endl;
			cout<<"\t\t=                                                                       ="<<endl;
		    cout<<"\t\t=             1.Create Theater                  2.Show Theater          ="<<endl;
		    cout<<"\t\t=                                                                       ="<<endl;
		    cout<<"\t\t=                                                                       ="<<endl;
		    cout<<"\t\t=             3.Sell Ticket                     4.Refund                ="<<endl;
		    cout<<"\t\t=                                                                       ="<<endl;
		    cout<<"\t\t=                                                                       ="<<endl;
		    cout<<"\t\t=             5.Booking Ticket                  6.Cancel Ticket         ="<<endl;
		    cout<<"\t\t=                                                                       ="<<endl;
		    cout<<"\t\t=                                                                       ="<<endl;
		    cout<<"\t\t=             7.Search                          8.Exit                  ="<<endl;
		    cout<<"\t\t=                                                                       ="<<endl;
		    cout<<"\t\t=                                                                       ="<<endl;
		    cout<<"\t\t========================================================================="<<endl;
		    cout<<"\t\t============================ Copyright@ashikurrahman ===================="<<endl;
		    cout<<"\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&"<<endl;
		Controller();
		}
	public:
		void creatTheater()
		{check=true;
			cout<<"\n\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%Create a Theater%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
			cout<<"\n\n\t\tinput the Rows of the theater :";
			cin>>row;
			cout<<"\n\n\t\tinput the Columes of the theater :";
			cin>>col;
			Seat=col*row;
			for(int i = 0; i < row; ++i)
		       {
			    for(int j = 0; j < col; ++j)
			       {
			           seat[i][j]="0";
			       }
			   }
			   cout<<"\n\t\t%%%%%%%%%%%%%%%%%%Theater Tickets Create Success%%%%%%%%%%%%%%%%%%%%%\n"<<endl;
			   showTheater();
		}
	public:
		void mainmenu(){
			cout<<"\n\n\t\tPress any key to return to the Main menu.";
			cin.sync();
			cin.clear();
			getchar();
			showmenu();
		}
	public:
		void showTheater()
		{
			cout<<"\n\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%Show Status%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
			cout<<"\n\t\t0:"<<Seat
			<<" seat available\t\t";
			changeColor(14);
			cout<<"1: ";
			changeColor(15);
			cout<<sell<<" sold\t";
			changeColor(12);
			cout<<"2: ";
			changeColor(15);
			cout<<booking<<" reserved\n\n\n"<<endl;
			cout<<"\t\t    ";
			for(int i=1;i<=col;i++){
				if(i<9)
					cout<<i<<"   ";
				else
					cout<<i<<"  ";
			}
			cout<<"\n";
			for(int i = 0; i < row; ++i)
			{
				if(i<9){
					cout<<"\t\t"<<i+1;
				}else
				cout<<"\t       "<<i+1;
				for(int j = 0; j < col; ++j)
			        {
			        	if(seat[i][j]=="1"){
			        		changeColor(14);
						}else if(seat[i][j]=="2"){
							changeColor(12);
						}
					cout<<"   "<< seat[i][j];
						changeColor(15);
						if(j == col - 1)
			                cout << endl;
       				 }
			}
		mainmenu();
		}
	public:
		void update()
		{
		cout<<"\n\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%Show Status%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
			cout<<"\n\t\t0:"<<Seat
			<<" seat available\t\t";
			changeColor(14);
			cout<<"1: ";
			changeColor(15);
			cout<<sell<<" sold\t";
			changeColor(12);
			cout<<"2: ";
			changeColor(15);
			cout<<booking<<" reserved\n\n\n"<<endl;
			cout<<"\t\t    ";
			for(int i=1;i<=col;i++){
				if(i<9)
					cout<<i<<"   ";
				else
					cout<<i<<"  ";
			}
			cout<<"\n";
			for(int i = 0; i < row; ++i)
			{

				if(i<9){
					cout<<"\t\t"<<i+1;
				}else
				cout<<"\t       "<<i+1;

				for(int j = 0; j < col; ++j)
			        {
			        	if(seat[i][j]=="1"){
			        		changeColor(14);
						}else if(seat[i][j]=="2"){
							changeColor(12);
						}
					cout<<"   "<< seat[i][j];
						changeColor(15);
						if(j == col - 1)
			                cout << endl;
       				 }
			}

		}
	public:
		void sellingTickets()
		{
		update();
			int num1,num2;

				cout<<"\n\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%Selling Tickets%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;

				cout<<"\n\t\tplease input the row :";
				cin>>num1;
				if(num1==888){
					showmenu();
				}

				if(num1>row){
					changeColor(12);
					cout<<"\n\t\tInvalid input!!!"<<endl;
					changeColor(15);
				}

				cout<<"\n\t\tplease input the colume :";
				cin>>num2;
				if(num2==888)showmenu();
				if(num2>col){
					changeColor(12);
					cout<<"\n\t\tInvalid input!!!"<<endl;
					changeColor(15);
				}
				changeColor(11);
				cout<<"\n\n\t\t\tTicket:<"<<num1<<","<<num2<<"> sold success."<<endl;
				changeColor(15);
				seat[num1-1][num2-1]="1";
				sell++;
				Seat--;
				update();
			mainmenu();

		}
	public:
		void refundTickets()
		{

				cin.clear();
				cin.sync();

			int num1,num2;
				update();
					cout<<"\n\t\t%%%%%%%%%%%%%%%%%%%%%%%%%Refunding Tickets%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
					cout<<"\n\t\tinput the row :";

				cin>>num1;
				if(num1==888)showmenu();
				if(num1>row){
					changeColor(12);
						cout<<"\n\t\tInvalid input!!!"<<endl;
							changeColor(15);
					}
				cout<<"\n\t\tinput the colume :";
				cin>>num2;

				if(num1==888)showmenu();

				if(num2>col){
						changeColor(12);
						cout<<"\n\t\tInvalid input!!!"<<endl;
							changeColor(15);
					}
						num2-=1;
						num1-=1;
						if( seat[num1][num2]=="0"){
							changeColor(12);
							cout<<"\n\t\tThis seat not Sold yet, you can't Refund it"<<endl;
							changeColor(15);
						}else if(seat[num1][num2]=="2"){
							changeColor(12);
							cout<<"\n\t\tThis seat already Reserved, you can't Refund it"<<endl;
							changeColor(15);
						}else if(seat[num1][num2]=="1"){
							seat[num1][num2]="0";
							sell--;
							Seat++;
							changeColor(11);
							cout<<"\n\n\t\t\tTicket:<"<<num1+1<<","<<num2+1<<"> Refund success."<<endl;
							changeColor(15);
						}
		update();
		mainmenu();

		}
	public:
		void bookingTickets()
		{
				int num1,num2;
			update();
			cout<<"\n\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%Booking Tickets%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;

			cout<<"\n\t\tinput the row :";
			cin>>num1;
			if(num1==888)showmenu();
			if(num1>row){
				changeColor(12);
					cout<<"\n\t\tInvalid input!!!"<<endl;
					changeColor(15);
				}
			cout<<"\n\t\tinput the colume :";
			cin>>num2;
			if(num2==888)showmenu();
			if(num2>col){
				changeColor(12);
					cout<<"\n\t\tInvalid input!!!"<<endl;
					changeColor(15);
				}
			if(seat[num1-1][num2-1]=="1"){
				changeColor(12);
				cout<<"\n\t\tThis seat already Sold"<<endl;
				changeColor(15);
			}
			else if(seat[num1-1][num2-1]=="2"){
				changeColor(12);
				cout<<"\n\t\tThis seat already Reserved"<<endl;
				changeColor(15);
			}else{
				changeColor(11);
				cout<<"\n\n\t\t\tTicket:<"<<num1<<","<<num2<<"> Booking success."<<endl;
				changeColor(15);
				seat[num1-1][num2-1]="2";
				counter=2;
				Seat--;
				booking++;

			}
		update();
			mainmenu();
		}
		public:
		void cancelTickets()
		{

				int num1,num2;
				update();
				cout<<"\n\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%Cancelling Tickets%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;

				cout<<"\n\t\tinput the row :";
				cin>>num1;
				if(num1==888)showmenu();
				if(num1>row){
					changeColor(12);
						cout<<"\n\t\tInvalid input!!!"<<endl;
							changeColor(15);
					}
				cout<<"\n\t\tinput the colume :";
				cin>>num2;

				if(num1==888)showmenu();

				if(num2>col){
						changeColor(12);
						cout<<"\n\t\tInvalid input!!!"<<endl;
							changeColor(15);
					}
						num2-=1;num1-=1;
						if(seat[num1][num2]=="0"){
							changeColor(12);
							cout<<"\n\t\tThis seat not Reserved yet, you can't cancel it"<<endl;
							changeColor(15);
						}else if(seat[num1][num2]=="1"){
							changeColor(12);
							cout<<"\n\t\tThis seat already sold, you can't cancel it"<<endl;
							changeColor(15);
						}else if(seat[num1][num2]=="2"){
							seat[num1][num2]="0";
							booking--;
							Seat++;
							changeColor(11);
							cout<<"\n\n\t\t\tTicket:<"<<num1+1<<","<<num2+1<<"> Cencel success."<<endl;
							changeColor(15);
						}


			update();
			mainmenu();
		}
	public:
		void searchTickets()
		{
			while(check){
				int num1,num2;
			cout<<"\n\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%Search Tickets%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
				changeColor(12);
				cout<<"\n\n\t\tInput 888 to return to the menu."<<endl;
				changeColor(15);
			cout<<"\n\t\tinput the row :";
			cin>>num1;
			if(num1==888)mainmenu();


			if(num1>row){
				changeColor(12);
					cout<<"\n\t\tInvalid input!!!"<<endl;
						changeColor(15);
							continue;
			}



			cout<<"\n\t\tinput the colume :";
			cin>>num2;

				if(num2==888)mainmenu();


				if(num1>col){
					changeColor(12);
						cout<<"\n\t\tInvalid input!!!"<<endl;
							changeColor(15);
								continue;
			}



			if(seat[num1-1][num2-1]=="1"){
				changeColor(11);
					cout<<"\n\n\t\t\tTicket:<"<<num1<<","<<num2<<"> is sold"<<endl;
						changeColor(15);
							continue;

			}else if(seat[num1-1][num2-1]=="2"){
				changeColor(11);
					cout<<"\n\n\t\t\tTicket:<"<<num1<<","<<num2<<"> is reserved"<<endl;
						changeColor(15);
							continue;
			}else{
				changeColor(11);
					cout<<"\n\n\t\t\tSeat:<"<<num1<<","<<num2<<"> is Empty"<<endl;
						changeColor(15);
							continue;
			}
			cin.sync();
			cin.clear();
			}
			cout<<"\n\n\t\tCreate theater first!!!"<<endl;
		}


	private:
		void Controller()
		{
			while(1)
			{cin.sync();
				cin.clear();
				int num;
			changeColor(15);
				cout<<"\n\n\t\tchoose number= ";
				cin>> num ;
					if(num==8){
							exitmenu();
					}else{
						switch(num)
							{	case 1:
										creatTheater();
										break;
								case 2:
										showTheater();
										break;
								case 3:
										sellingTickets();
										break;
								case 4:
										counter=2;
										refundTickets();
										break;
							 	case 5:
								 		bookingTickets();
										 break;
								case 6:
										counter=5;
										cancelTickets();
										break;
								case 7:
										searchTickets();
										break;
								default:
									changeColor(12);
									cout<<"\n\t\tInvalid input!!!"<<endl;
									changeColor(15);
							}
					}

			}
		}


		private:
			void exitmenu(){

				changeColor(11);

				cout<<"                          .-'-.                   "<<endl;
                cout<<"                         /   e >                  "<<endl;
                cout<<"                    _.-''';   /                   "<<endl;
                cout<<"     __________.-''-._.-'    /                    "<<endl;
                cout<<"    =======----:_''-'       /                     "<<endl;
                cout<<"                 '-=.  ...-'                      "<<endl;
                cout<<"                    :_\\_@Md Ashikur Rahman       "<<endl;

                cout<<"Now exiting. Goodbye."<<endl;
                        changeColor(10);
			exit(1);
			}
};
int main(){
TicketsTheater tt;
tt.showmenu();

}

