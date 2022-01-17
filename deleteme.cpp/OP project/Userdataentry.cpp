#include<iostream>
using namespace std;
#include<cstring>
#include<fstream>
#include<stdlib.h>
#include <string>
#include <unistd.h>

class user{
    protected:
	static int Tot;
	int ID;
	char name[100];
    char contact_num[11];
	int age;
	char gender[10];
	char username[100];
	char pass[50];
	
    public:
    friend class Ticket;
    user(char *name,char* cont,double age,char *gend,char *username,char *pass)
	{
	// ID=Tot++;
	strcpy(this->name,name);
	strcpy(this->username,username);
	strcpy(gender,gend);
	strcpy(this->pass,pass);
	this->age=age;
	strcpy(contact_num,cont);
    ifstream i;
    i.open("User.txt");
    if(Tot==0)
        {
        i.read((char*)this,sizeof(*this));
        while(!i.eof())
        {
        if( i.read((char*)this,sizeof(*this)))
        {
            Tot++;
        }
        else 
        break;
        }
        Tot++;
        ID=Tot;
        }
        else
        {
        Tot++;
        ID=Tot;
        }	
	
  i.close();
	}
	

	user(int num)
	{
		cout<<"Enter your name please: ";
		cin>>name;
		fflush(stdin);
		cout<<"Enter your contact number: ";
		cin>>contact_num;
		cout<<"Enter your age: ";
		cin>>age;
		cout<<"Enter you gender: ";
		cin>>gender;
		cout<<"Enter your username(spaces are not allowed and will lead to error): ";
		cin>>username;
		cout<<"Enter your password";
		cin>>pass;

        ifstream i;
        i.open("user.txt",ios::binary);
        //accountaccess s1;
        int count=0;
        if(Tot==0)
        {
        i.read((char*)this,sizeof(*this));
        if (!i.is_open()){cout <<"no record\nexitting\n"; exit(0);}
        while(!i.eof())
        {
            Tot++;
            
            i.read((char*)this,sizeof(*this));
        }
        Tot++;
        ID=Tot;
        }
        else
        {
        Tot++;
        ID=Tot;
        }	
	
  i.close();
	}

	user()
	{
  
	}
  //login
    user (char *uname,char *pass)
    {
      ifstream i;
      i.open("user.txt",ios::binary);
      while(!i.eof())
      {
        if(i.read((char*)this,sizeof(*this)))
        {
         if(strcmp(this->username,uname)==0&&strcmp(this->pass,pass)==0)
         {
         cout<<"Welcome back "<<this->name;
         break;
         }
        }
        else
        {
         cout<<"No account found with that username and password ";
         cout<<"exiting....";
         sleep(4);
         exit(2);
        }

      }
    }

    
    void store()
    {
        ofstream o;
        o.open("user.txt",ios::binary|ios::app);
        

            o.write((char*)this,sizeof(*this));
            o.close();

    cout<<"Your account has been made!"<<endl;
    cout<<"We look forward to seeing you more "<<name<<endl;

    }	
    void read()
    {
  ifstream i;
        i.open("user.txt",ios::binary);
        //accountaccess s1;
        int count=0;
        i.read((char*)this,sizeof(*this));
        if (!i.is_open()){cout <<"no record\nexitting\n"; exit(0);}
        while(!i.eof())
        {
                cout << "test";
            this->display();
            count++;
            
            i.read((char*)this,sizeof(*this));
        }	
	
  i.close();
 }
	void display()
	{
		cout <<"\nID: x"<<ID<<endl;
        cout<<"Name: "<<name<<endl;
		cout<<"Contact Number: "<<contact_num<<endl;
		cout<<"Age: "<<age<<endl;
		cout<<"Gender: "<<gender<<endl;
		cout<<endl;
	}
	
    // void getannouncements(){
    //     //read plane file
    //     if (this->cid=plane.cid){
    //         //cout plane.annoucement
    //     }
    // }

    void receipt(){
        cout<<"\n\t\t\t\tPassenger Information:\n";
	cout<< "\t\t---------------------------------------------\n";
	
	cout<<"\t\t| Name of Customer:--------------------------";

	cout<<"\t\t| Mode of Booking :------------ ";
	
	cout<<"\t\t| Origin:------ ";

		cout<<"\t\t| Destination:------ ";
        cout<<"\t\t| Ticket Number:------ ";
    cout<<"\t\t| Date of Departure:----- ";
    cout<<"\t\t---------------------------------------------\n";
	
	cout<<"\t\t| Payment Preference:--------- \n";
    cout<<"\t\t| Amount Paid:------ ";
	cout<<"\t\t| Hotel of Choice:------ ";
	cout<<"\t\t---------------------------------------------\n";
    }


    void complaints(){
        char complain[100];
        int choice;
        cout << "Select the department you want to register a complaint: "<<endl;
        cout << "\n1.Airport Staff\n2.Passenger Security\n3.Flight Delays\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Welcome to Airport Staff Complaint Section"<<endl;
            break;
        case 2:
            cout << "Welcome to Security Complaint Section"<<endl;
            break;
        case 3:
            cout << "Welcome to Flight Delay Complaint Section"<<endl;
            break;
        
        default:
            break;
        }
        cout << "Enter your complaint: "<<endl;
        cin >> complain;
        cout << "Dear Mr/Ms."<<name<< " your complaint has been registered!"<<endl;
        cout << "You will be contacted at "<<contact_num<<" for further enquiry!"<<endl;
    }


    void payment(int price){

        int choice;
        cout << "\t\tWelcome to Payments section";
        cout << "\n\nHow would you like to pay?:\n";
        cout << "\n\1.Pay by Debit Card \n\2.Pay by cash\n";
        cout << "\n\nEnter your preference: ";
        cin >> choice;
        if (choice==1 /* and user has not made an bankaccount*/){
            //debit card
            //BankAccount b1(choice);
            //b1.pay(price);
        }
         if (choice==1 /* and user has already made an bankaccount(thru previous signup)*/){
            //debit card
            //BankAccount b1; //will get data from file reading 
            //b1.pay(price);
            
        }
        if (choice==2){
            cout << "Amount to be paid: "<<price<<endl;
            cout << "Enter amount of cash: ";
            int cash;
            cin >> cash;
            if(cash>=price)
	  	 {
	  	  cout << "Change returned: "<<cash-price<<endl;
		   }
		else {
		cout << "Insufficient cash entered";
            
             }     }
    }
};

    


int user::Tot=0;

int main()
{
 user obj("Ahmed","32124533",double(21),"Male","Ahmed22","pass");
 obj.store();
 user obj2("Faiza","032145512",double(25),"Female","Faiza23","pass");
 obj2.store();
 user obj3("Taimur","0321456234",double(20),"Male","Taimur24","pass");
 obj3.store();
 user obj4("Hasan","03451234521",double(45),"Male","Hasan25","pass");
 obj4.store();
 
}
