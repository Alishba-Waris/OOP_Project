#include<iostream>
#include<fstream>
#include<ctime>
#include<cstdlib>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<windows.h>

using namespace std;

double Dollar = 0.0044;
double Pound = 0.0037;
class Customer
{
	private:
		char ch;
		string pin;
		string name ;
		double amount;
		double totalamount;
	
	public:	
		void Signin()
		{
			system("cls");
			string pin;
			string name ;
		  	p:
			cout << endl << "\n\n\n\n   \t welcome to Customer login page ";
		    cout << endl << " Enter your name : ";
		    cin >> name;
			cout << " Enter you pin : ";
			for(int i=1;i<=5;i++)
			{
				ch = getch();
				pin += ch;
				cout << "*";	
			}
			if(pin == "12345" && name == "qwerty")
			{
				cout << endl << " You are login successfully \n";
			}		
			else
			{
				getch();
				goto p;
			}
			totalamount = 100000;
		    amount = 0;
		}
	
		void Signup()
		{
			system("cls");
			char choice;
			fstream file;
			string n,pi,a;
			P:
			cout << "\n\n\n\n   \t Welcome to Customer signup page "
			<< endl << " you are here to create your account ";
			cout << endl << "\tEnter your name : ";
		    cin >> name;
			cout << endl << "\tEnter your Pin code containing 5 charachers : ";
			cin >> pin;
			cout << " Enter amount you want to deposit :  ";
			cin >> amount;
			totalamount = totalamount + amount;
			cout << " Your total amount is : " << totalamount;	
		
		
			file.open(" ATM.txt",ios::in);
			if(!file)
			{
				file.open("ATM.txt",ios::app|ios::out);
				file << " " << name << " " << pin << " " << totalamount;
				file.close();
			}
			else 
			{
				file >> n >> pi >> a;
				while(!file.eof())
				{
					if( n == name)
					{
						cout << endl << " user ID already exist ";
						getch();
						goto P;
					}
					file >> n >> pi >> a;
				}
				file.close();
				file.open("ATM.txt",ios::app|ios::out);
				file << " " << name << " " << pin << " " << totalamount;
				file.close();
				
			}
			cout<<endl<<" New user is added successfully ";
		}	
			
		void WithdrawCash()
		{
			fstream file,file1;
			system("cls");
			int choice;
				
			double PKR , DOLLAR ,POUNDS;
			cout << "\n\n\n\n\n How many amount to want to Withdraw : ";
			cin >> amount;
			cout << " In which currency you want to Withdraw ";
			cout << "\n press 1 for Rupee "
			<< "\n press 2 for Dollar" 
			<< "\n press 3 for UK Sterling Pound ";
			cout << "\n  select : ";
			cin >> choice;		
			switch (choice)
			{
				case 1:
					{
						totalamount = totalamount - amount;
						cout << endl << " Your cash is Withdraw successfully in PKR "
						<< " \n Your total amount is : " << totalamount;
						break;
					}
				case 2:
					{
						DOLLAR = amount * Dollar;
						if(DOLLAR <= totalamount)
						{
							totalamount = totalamount - amount;
							cout << endl << " Total Dollar after conversion : " << DOLLAR;
						cout << endl << " Your cash is Withdraw successfully in DOLLARS "
						<< " \n Your total amount is : " << totalamount;
						}
						else 
							cout << endl << " You have less balance in your account ";								
							break;
						}
					case 3:
						{
							POUNDS = amount * Pound;
							if(POUNDS <= totalamount)
							{
								cout << endl << " Total Pounds after conversion : " << Pound;
								totalamount = totalamount - amount;
								cout << endl << " Your cash is Withdraw successfully in POUNDS "
							<< " \n Your total amount is : " << totalamount;
							}
							else
							{
								cout << endl << " You have less balance in your account ";
							}								
							break;
						}
						default:
							cout << endl << " You Enter invslid no \n ";		
				}
					
			}
		    void CheckBalance()
			{
		    	system("cls");
		    	char choice;
		    	cout << "\n\n\n\n Your total amount is : " << totalamount;
		    	cout << "\n press 1 to return the home screen "
				<< "\npress 2 to eject the card.";
				cin >> choice;
				if (choice =='2')
					exit(0);
				
			}
			
		    void MiniStatement()
			{
		    	system("cls");
		    	cout << "\n\n This offer is not available\n ";
			}
		    void UtilityBill()
			{
		    	char choice ;
		   		system("cls");
		    	cout << " \n\n\n\n Pres  1 to pay Electricity Bill \n"
		        << "Press 2 to pay PTCL Bill\n"
		        << "Press 3 to pay Water Bill\n"
		        << "press 4 to pay GAS Bill ";
	            cin >> choice;
	            amount = 1000 + rand() % 10000;
	            cout << "\n Your Bill is " << amount;
	            cout << endl << " Do you wanna pay bill Y/N ";
	            cin >> choice;
	            if(choice == 'y'|| choice == 'Y')
				{
	            	if (totalamount >= amount )
		        	{
						totalamount = totalamount - amount;
						cout << endl << " Your Bill is paid successfully \n"
						<< " Now your total amount is " << totalamount;
					}
				else
					cout << endl << " Your Total Amount is less then bill you have to pay ";
				}					
			}
			
		    void Topup()
			{		    	
		    	system("cls");
		    	char choice;
		    	cout << "\n\n\n\n Which network company you are using \n"
				<< "Press 1 for Mobilink\n"
				<< "Press 2 for Ufone\n"
				<< "Press 3 for Telenor\n"
				<< "Press 4 for Zong" ;
				cin >> choice;
				cout << endl << " Press 1 for Pre Paid Payment\n"
		        << "Press 2 for Post Paid Payment ";
		        cin >> choice;
		        switch(choice)
				{
		            case 1:
					{
		                cout << "How many Amount you want to pay : ";
		                cin >> amount;
		                break;
		            }
		            case 2:
					{
		                amount = 500 + rand() % 1500;
		                cout << " You have to pay " << amount << " PRs";
		                break;
		            }
		        }
				if (totalamount >= amount)
				{
				    totalamount = totalamount - amount;
				    cout << endl << " Your Payment is done successfully";
				}
				else
				cout << endl << " your total amount is less then amount you havr to pay";
		
			}
		    void CardPayment()
			{
		    	system("cls");
		    	char choice ;
		   		double creditno;
		   		cout << endl << " \n\n\n\nEnter credit card no : ";
		   		cin >> creditno;
		   		amount = 1000 + rand() % 10000;
	    		cout << endl << " Your bill abount is : " << amount ;
	    		cout << " \nDo you wanna pay this bill Y/N ";
	    		cin >> choice;
	    		if(choice=='Y' || choice == 'y')
				{
		    		if (amount<=totalamount)
					{
		    			cout << " \n You Bill is paid successfully ";
		    			totalamount = totalamount - amount;
					}
				}	
			}
			
		    void FundsTransfer()
			{
		    	system("cls");
		    	string trans_account;
		    	cout << " \n\n\n\nEnter the Account you want to Transfer : ";
		    	cin >> trans_account;
		    	cout << " Enter the Amount tou want Transfer : ";
		    	cin >> amount;
		    	if (totalamount>=amount )
		        {
					totalamount = totalamount - amount;
					cout << "\n Your Amount is successfully Transfered \n"
					<< "\n Now your total amount is " << totalamount;
				}
				else
					cout << endl << " Your Total Amount is less then the Amount you want to Transfer ";
		    	
			}	

};

class Admin
{
private:
		int choice;
		int ch, select;
		int password = 1234;
		int pound = 500;
		int rupee = 500;
		int dollar = 500;
		int rupee_notes;
		int dollar_notes;
		int pound_notes;
	public:
		void Cur_Status()
		{
			cout << " \n Check currency notes in ATM. \n";
			cout << " \n For Dollar:  Press 1 \n For Rupee:  Press 2 \n For Pound:  Press 3 ";
			cin >> choice;
			switch(choice)
			{
				case 1:
					cout << "\n Dollar Notes:   " << dollar;
					break;
				case 2:
					cout << "\n Rupee Notes:   " << rupee;  
					break;
				case 3:
					cout << "\n Pound Notes:   " << pound;
					break;
				default:
					cout << "\n This currency is not available.\n ";	
							
			}
			
			
		}
		void Cur_Add()
		{
			cout << "\n\n Do you want to add Currency notes? \n If Yes :   Press 1\n If No :   Press 2\n ";
			cin >> ch;
			if(ch == 1)
			{
				cout << "\n Which currency notes you want to add?\n";
				cout << " \n For Dollar:  Press 1 \n For Rupee:  Press 2 \n For Pound:  Press 3 ";
				cin >> select;
				if ( select == 1)
				{
				
					cout << "\n How many Dollar notes you want to add? ";
					cin >> dollar_notes;
					cout << "\n Now Dollar notes are : " << dollar + dollar_notes;
				}
				else if(select == 2)
				{
				
					cout << "\n How many Rupee notes you want to add? ";
					cin >> rupee_notes;
					cout << "\n Now Rupee notes are : " << rupee + rupee_notes;
					
				}
				else if(select == 3)
				{
				
					cout << "\n How many Pound notes you want to add? ";
					cin >> pound_notes;
					cout << "\n Now Pound notes are : " << pound + pound_notes;
					
				}
			} 
			
		}
		void  exchangerate()
		{
			int choice;
			cout << " \n\n Press 1 to change the rate of Dollar \n"
			<< " Pres  2 to change the the rate of Pounds ";
			cin >> choice;
			switch(choice)
			{
				case 1:
					{
						cout << " Enter the rate of Dollar : ";
						cin >> Dollar;
						break;
					}
				case 2:
					{
						cout << " Enter the rate of Pound : ";
						cin >> Pound;
						break;
					}		
			}	
		}
		
		void Signadmin()
		{
			system("cls");
			string pin;
		    string name ;
		    p:
			cout << endl << "\n\n\n\n   \t welcome to Admin login page ";
		    cout << endl << " Enter your ID : ";
		    cin >> name;
			cout << " Enter you pin : ";
			for(int i = 1; i <= 5; i++)
			{
				ch = getch();
				pin += ch;
				cout << "*";
			}
			if(pin == "54321" && name == "admin")
			{
				cout << endl << " You are login successfully \n";
			}		
			else
			{
				getch();
				goto p;
			}
		
		}
};

class Atm
{
	private:
		Customer customer;
		Admin admin;
	public:
		void CustomerMenu()
		{
			int select1,select2;	
			system("cls");
			cout << "\n\t\t\tWelcome to Customers screen  " << endl;
	
			cout << "\n1.Account Signup ";
			cout << "\n2.Account Signin ";
			cout << "\nSelect :";
			cin >> select1;
			if (select1 == 1)
			customer.Signup();
			if (select1 == 2)
			customer.Signin();
			p:
			cout << "\n\tMAin Menu" << endl;
			cout << "\n1.Withdrway Cash";
			cout << "\n2.Check Balance";
			cout << "\n3.Get Mini Statement";
			cout << "\n4.Pay Utility Bill";
			cout << "\n5. Mobile Top-up";
			cout << "\n6. Credit Card Payment";
			cout << "\n7.Funds Transfer";
			cout << "\n8.Exit";
			cout << "\nSelect :";
			cin >> select2;
			system("cls");
			switch(select2)
			{
				case 1:
				    {
			            cout << "\n\tWITHDRWA CASH" << endl;
			            customer.WithdrawCash();
				      	break;
				    }	
				case 2:
				    {
				       	cout << "CHeck balance" << endl;
		                customer.CheckBalance();
				       	break;
					}		 
				case 3:
				    {
				     	cout << "GET MINI STATEMENT" << endl;
				        customer.MiniStatement();
				     	break;
				    }
				case 4:
				    {
				     	cout << "PAY UTILITY BILLS :" << endl;
				        customer.UtilityBill();
				     	break;
				     	
					}	
				case 5:
				    {
				    	cout << "MOBILE TOP_UP" << endl;
				        customer.Topup();
				        break;
				    }	
				case 6:
				    {
				      	cout << "CREDIT CARD PAYMENT" << endl;
				        customer.CardPayment();
				      	break;
					}
				case 7:
				    {
				      	cout << "FUNDS TRANDFER " << endl;
				        customer.FundsTransfer();
				      	break;
					}
				case 8:
					{
						exit(0);
						break;
					}	  
														   				 	   	  									 	 				   		    
					}//end of switch
					cout << "\nPress enter key to continue" << endl;
				    getch();
				    goto p;
					
	}	
	void AdminMenu()
	{
		int select1;
		admin.Signadmin();
		cout << "\n\tMAin Menu" << endl;
		cout << "\n1.View Status of Currency Notes ";
		cout << "\n2.Add Currency Notes ";
		cout << "\n3.set the exchange rate";
		cin >> select1;
		switch(select1)
		{
			case 1:
				{
					admin.Cur_Status();
					break;
				}
			case 2:
				{
					admin.Cur_Add();
					break;
				}
			case 3:
				{
					admin.exchangerate();
					break;
				}		
			}
	}
		

	
};



int main()
{
	//starting();
	system("Color 0B");
	Atm ATM;
	
	int choice ;
	cout << "Please select which screen you want to open" << endl;
	cout << " Press 1 for user screen" << endl;
	cout << " Press 2 for Admin screen" << endl;
	cout << " Select :";
	cin >> choice;
	if (choice == 1)
{
	ATM.CustomerMenu();
}
	if (choice == 2)
	{	
		ATM.AdminMenu();	
	}
	return 0;
}

