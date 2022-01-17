#include<iostream>
using namespace std;
#include<cstring>
#include<fstream>
#include<stdlib.h>
#include <string>
#include <unistd.h>
#include <algorithm>
#include <vector>
#include<time.h>










class menu
{
	public:
	virtual void options()=0;
};
class admin :public menu
{
	private:
		
	char name[100];
	char id[100];
	char pass[100];
	
	public:
		
	
    admin ()
    {
    	
    }

    void options();

    void store()
    {
        ofstream o;
        o.open("admin.txt",ios::binary|ios::app);
        

            o.write((char*)this,sizeof(*this));
            o.close();

    cout<<"Your account has been made!"<<endl;
    cout<<"We look forward to seeing you more "<<name<<endl;

    }	
    void read(char* uname,char* pass)
    {
      ifstream i;
      i.open("admin.txt",ios::binary);
      int flag=0;
      while(!i.eof())
      {
        if(i.read((char*)this,sizeof(*this)))
        {
         if(strcmp(this->id,uname)==0&&strcmp(this->pass,pass)==0)
         {
         cout<<"Welcome back "<<uname<<endl;
         flag=1;
         break;
         }
        }
      }
      if(flag==0)
	  {
         cout<<"No account found with that username and password ";
         cout<<"exiting....";
         sleep(4);
         exit(2);	  	
			}      
        }	
	
 // i.close();

 
	void display()
	{
	    cout<<"Name: "<<name<<endl;
		cout <<"\nID: x"<<id<<endl;
       

	}
};
class Plane{
    char announcements[100];
    int cid;
    // void sendannouncements(){
    //     cout << "Enter announcement: "<<endl;
    //     cin >> announcements;
    //     //read user ki file
    //     if (user.cid==this->cid){
    //         user.announcement=announcements;
                //update user ki file
    //     }
    // }
};


class BankAccount{
private:
    char bankname[100];
    int balance;
    int cardno;
    int pin;
public:
    BankAccount(); //nthng inside ie; account not made
    BankAccount(int card,int p){    //bankaccount only initialized if asked for
            
            this->cardno=card;
            this->pin=p;
            cout << "Enter Bank Name: ";
            cin >> bankname;
			srand((unsigned) time(0));
			
			
			balance = (rand() % 1000000000) + 10000000;
			cout<<"Your balance before payment was: "<<balance<<endl;
			
			


    } 
    void pay(int price){
        cout << "Congratulations!! Payment successfully made!\n"<<endl;
        balance-=price;  
    }
    void pay(double price){
        cout << "Congratulations!! Payment successfully made!\n"<<endl;
        balance-=price;  
    }    
    void getbalance(){
        cout << "Your current balance is : "<<balance<<endl<<endl;
    }
};

 


class Airline
{
 protected:
 //name of airline 
 char lname[10];
 public:
    Airline(){

    }
     void showflightcode();
    void registerannouncement();
     void registerannouncement(char* a);
    void makeannmt(){
       int choice;
       showflightcode();
       
  
   
       cout<<"1-Flight Cancel\n2-Change in date of Departure\n3-Any other annoucement\n";
       cin>>choice;
       if(choice==1)
       {
       	registerannouncement("Flight Cancel");
	   }
       else if(choice==2)
       {
       	registerannouncement("There is a change in Departure date.Kindly acknowledge");
	   }
	   else
       {
	   registerannouncement();}
        cout << "Announcement made successfully!\n\n";
    }

    
};
class Flight:public Airline
{
 private:
 int dof[3]={0};// 0th pe date 1th pe month 2nd pe year
 char mode; //I OR L
 float fcticket; //firstclass ticket
 float eticket; //economy ticket
 char flightcode[10];
 char destination[20];
 char departure[20];
 int seats;//total seats
 char modelno[10];
 int tcount[1000]={0};// booked seat no array
 int count=0;//total seats booked
 float time;
 char announcement[100];

 public:
 friend class Ticket;
 
 char* getflightcode(){
     return flightcode;
 }
 void setannmt(char* annmt){
        strcpy(announcement,annmt);
    }
    char* showannmt(){
        return announcement;
    }
 Flight()
 {
     
 }
 Flight(char m,float fc,float e,char *flig,char *dest,char *dept,char *model,float t,char *airline,int se,int D,int M,int Y)
 {
  mode=m;
  fcticket=fc;
  eticket=e;
  strcpy(flightcode,flig);
  strcpy(destination,dest);
  strcpy(departure,dept);
  strcpy(modelno,model);
  time=t;
  seats=se;
  strcpy(lname,airline);
  dof[0]=D;
  dof[1]=M;
  dof[2]=Y;
  
 }

 float get_eticket()
 {
 	return eticket;
 }
 
 float get_fcticket()
 {
 	return  fcticket;
 }
 void write()
 {
  ofstream o;
  o.open("Flights.txt",ios::app);
  o.write((char*)this,sizeof(*this));
  o.close();
 }
 void display()
 {
  cout<<"Date of flight: "<<dof[0]<<"/"<<dof[1]<<"/"<<dof[2]<<endl;
  cout<<"Airline name is "<<lname<<endl;
  cout<<"Flight code is "<<flightcode<<endl;
  cout<<"Departure from "<<departure<<endl;
  cout<<"Destination is "<<destination<<endl;
  cout<<"First class ticket price "<<fcticket<<endl;
  cout<<"Economy class ticket price "<<eticket<<endl;
  cout<<"Estimated Time of flight is "<<time<<" hour(s)."<<endl;
  cout << "Announcement: "<<announcement<<endl;
  cout<<endl<<endl<<endl;
 }

 void update(char *IDD)
{
 fstream i ;//read
 i.open("Flights.txt",ios::binary|ios::in|ios::out);
 int pos;
 Flight s1;
 while(!i.eof())
 {
     pos=i.tellg();
     if(i.read((char*)&s1,sizeof(s1)))
     {
      if(strcmp(s1.flightcode,IDD)==0)
      {
       i.seekp(pos);
       i.write((char*)this,sizeof(*this));
       break;
      }
     }
     else 
     break;
 }
}
int change(char *IDD)
{
 fstream i ;//read
 i.open("Flights.txt",ios::binary|ios::in|ios::out);
 int pos;
 Flight s1;
 int f;
 cout<<"What would you like to update ?\nPress 1 for updating destination\nPress 2 for updating departure";
 int choice;
 while(1)
 {
 cin>>choice;
 if(choice==1)
 {
 cout<<"Enter new destination: ";
 cin>>destination;
 f=1;
 }
 else if(choice ==2)
 {
 cout<<"Enter new departure: ";
 cin>>departure;
 f=1;
 }
 else
 {
cout<<"Not an appropriate choice ";
f=0;
 
 }
 if(f==1)
 {
 while(!i.eof())
 {
     pos=i.tellg();
     if(i.read((char*)&s1,sizeof(s1)))
     {
      if(strcmp(s1.flightcode,IDD)==0)
      {
       i.seekp(pos);
       i.write((char*)this,sizeof(*this));
       break;
      }
     }
     else 
     break;
 }
 }
 cout<<"If you want to change anything else press 1 or press anything else to exit ";
 char ch;
 cin>>ch;
 if(ch=='1')
 {
 continue;
 }
 else 
 break;
}
}
 void cancelflight(char *Code)
     {
      Flight s1;
      ifstream i;
      ofstream  o;
      i.open("Flights.txt",ios::binary);
      o.open("Temp.txt",ios::binary);
      while(!i.eof())
      {
      
     if(i.read((char*)&s1,sizeof(s1)))
     {
      if(strcmp(s1.flightcode,Code)==0)
      {
       continue;
      }
      else 
      o.write((char*)&s1,sizeof(s1));
     }
     else 
     break;
      }
     delete("Flights.txt");
     rename("Temp.txt","Flights.txt");
     }
 void read()
 {
   ifstream i;
	i.open("Flights.txt", ios::binary);
    
	while(!i.eof()){
		if ((i.read((char*)this,sizeof(*this)))){
            cout << "Records\n";
			this->display();

		}
		else break; 
	}
  i.close();
 }
 
 Flight select(char *fligh)
 {
 ifstream o; 
  o.open("Flights.txt",ios::binary);
  while(!o.eof())
  {
   if(o.read((char*)this,sizeof(*this)))
   {
    if(strcmp(fligh,this->flightcode)==0)
    {
        cout << "Flight Selected\n";
        cout <<"Airline : " << this->lname<<endl;

     return *this;
    }
   }
   else 
   
   break;
  }
  cout<<"No flights found ";
  Flight obj('L',float(0),float(0),"XXX","XXX","XXX","XXX",float(0),"XXX",80,25,7,2021);
//Flight obj('L',float(25000),float(15000),"PKR-265","Karachi","Islamabad","Boeing-747",float(2.5),"PIA",80,25,7,2021);
  //Flight(char m,float fc,float e,char *flig,char *dest,char *dept,char *model,float t,char *airline,int se,int D,int M,int Y)
  return obj;
 }
  void International()
    {
         cout<<"\nInternational Flights list Displaying.";
		 sleep(1);
		 cout<<".";
		 sleep(1);
		 cout<<".";
		 system("cls");
		 cout<<"\n\n\n";     	
     ifstream o;
     o.open("Flights.txt",ios::binary);
     while(!o.eof())
     {
     if(o.read((char*)this,sizeof(*this)))
     {
      if(this->mode=='I'||this->mode=='i')
      {
        this->display();
      }
     }
     else
     break;
     }
     
    }
     void Local()
    {
         cout<<"\nLocal Flights list Displaying.";
		 sleep(1);
		 cout<<".";
		 sleep(1);
		 cout<<".";
		 system("cls");
		 cout<<"\n\n\n";      	
     ifstream o;
     o.open("Flights.txt",ios::binary);
     while(!o.eof())
     {
     if(o.read((char*)this,sizeof(*this)))
     {
      if(this->mode=='L'||this->mode=='l')
      {
        this->display();
      }
     }
     else
     break;
     }
     
    }
 };

class user: public menu
{
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
    	
    	void options();
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
	}

	user(int num)
	{

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

       
	}
	user()
	{
  
	}
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
         cout<<"No account found with that username and password\n\n ";
         cout<<"Try again!!!\n\n";
         int x;
         for(x=0;x<3;x++)
         {
         	int flag=0;
         	char u[100];
			char p[50];
         	cout<<"Enter Username: ";
         	cin>>u;
         	cout<<"Enter password: ";
         	cin>>p;
			ifstream i;
			i.open("user.txt",ios::binary);
			while(!i.eof())
			{
			if(i.read((char*)this,sizeof(*this)))
			{
			if(strcmp(this->username,u)==0&&strcmp(this->pass,p)==0)
			{
			cout<<"Welcome back "<<this->name;
			flag=1;
			break;
			}
			}
			else
			{
         cout<<"\n\nNo account found with that username and password\n ";
         cout<<"Try again!!!\n\n";				
			}			         	
           }
          if(flag==1)
          {break;
		  }
		 }
		 if(x==3)
		 {
		 cout<<"You have tried three times!!";
		 cout<<"\nExiting program...";
         sleep(4);
         exit(2);
         
     }
        }

      }
    }

    void pastrecords();
    void viewannmt();
    int getID(){
        return ID;
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
        user s1;
        int count=0;
        i.read((char*)&s1,sizeof(s1));
        if (!i.is_open()){cout <<"no record\nexitting\n"; exit(0);}
        while(!i.eof())
        {
                cout << "test";
            s1.display();
            count++;
            
            i.read((char*)&s1,sizeof(s1));
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
        cout << "Username: "<<username<<endl;
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


    void payment(char mfe,int seat,Flight &f)
{
        int choice,price;
         system("cls");
         cout<<"\nPayment section opening.";
		 sleep(1);
		 cout<<".";
		 sleep(1);
		 cout<<".";
		 system("cls");
		         
        cout << "\t\t\t\t-----Welcome to Payments section-----\n";
        cout<<"\n\n\n"; 
        if(mfe==1)
        {
        	price=f.get_fcticket()*seat;
		}
		else if(mfe==2)
		{
			price=f.get_eticket()*seat;
		}
        cout<<"The amount you have to pay is: "<<price;
        cout << "\n\nHow would you like to pay?:\n";
        cout << "\n1.Pay by Debit Card \n2.Pay by cash\n";
        cout << "\n\nEnter your preference: ";
        cin >> choice;
        
        if (choice==1 /* and user has not made an bankaccount*/){
            //debit card
            cout<<"Enter credit card number: ";
            int card;
            cin>>card;
            cout<<"Enter pin number: ";
            int p;
            cin>>p;
            BankAccount b1(card,p);
            b1.pay(price);
            b1.getbalance();
        }
//         if (choice==1 /* and user has already made an bankaccount(thru previous signup)*/){
//            //debit card
//            BankAccount b1; //will get data from file reading 
//            b1.pay(price);
//            
//        }
        if (choice==2){
        	
            cout << "Enter amount of cash: ";
            int cash;
            cin >> cash;
            if(cash>=price)
	  	 {
	  	  cout << "\nChange returned: "<<cash-price<<endl<<endl;
	  	  cout<<"Payment successfully made";
		   }
		else {
		cout << "Insufficient cash entered";
            
             }     }
             
             cout<<"Exiting payment section.";
             sleep(1);
             cout<<".";
             sleep(1);
    }    


void update(int IDD)
{
 fstream i ;//read
 i.open("user.txt",ios::binary|ios::in|ios::out);
 int pos;
 user s1;
 while(!i.eof())
 {
     pos=i.tellg();
     if(i.read((char*)&s1,sizeof(s1)))
     {
      if(s1.ID==IDD)
      {
       i.seekp(pos);
       i.write((char*)this,sizeof(*this));
       break;
      }
     }
     else 
     break;
 }
}
void changestuff(int IDD)
{
int f=0;
 fstream i ;//read
 i.open("user.txt",ios::binary|ios::in|ios::out);
 int pos;
 user s1;
 cout<<"Press 1 if you want to change your username.\nPress 2 if you want to change your password\n Press 3 if you want to change your contact number ";
 int choice;
 while(1)
 {
 cin>>choice;
 if(choice==1)
 {
 cout<<"Enter new username ";
 cin>>username;
 f=1;
 }
 else if(choice==2)
 {
  char temp[50];
  cout<<"Enter old password to confirm it is you ";
  cin>>temp;
  fflush(stdin);
  if(strcmp(temp,pass)==0)
  {
   cout<<"Enter new password(without spaces)";
   cin>>pass;
   f=1;
  
}
  
  else
  {
   cout<<"Incorrect password nothing will be updated ";
  }
 }
 else if(choice==3)
 {
  cout<<"Enter new contact number ";
  cin>>contact_num;
  f=1;
 }
 else
 {
  cout<<"Invalid choice ";
 }
 if(f==1)
 {
 while(!i.eof())
   {
     pos=i.tellg();
     if(i.read((char*)&s1,sizeof(s1)))
     {
      if(s1.ID==IDD)
      {
       i.seekp(pos);
       i.write((char*)this,sizeof(*this));
       break;
      }
     }
     else 
     break;
 }
 }
 cout<<"If you want to change anything else press 1 or press anything else to exit ";
 char ch;
 cin>>ch;
 if(ch=='1')
 {
 continue;
 }
 else 
 break;
}
 }
 
 void canceluser(int ID)
     {
      user s1;
      ifstream i;
      ofstream  o;
      i.open("user.txt",ios::binary);
      o.open("Temp.txt",ios::binary);
      while(!i.eof())
      {
     if(i.read((char*)&s1,sizeof(s1)))
     {
      if(s1.ID==ID)
      {
       continue;
      }
      else 
      o.write((char*)&s1,sizeof(s1));
     }
     else 
     break;
      }
     delete("user.txt");
     rename("Temp.txt","user.txt");
     }   

};

int user::Tot=0;

class Ticket
{
    protected:
    int dof[3]={0}; //date of issuance;
    int today[3]={0}; //today's date
    int meals[10]={0};
    int ID;
    char name[100];
    char contact_num[11];
    char gender[10];
    char modeIL;
    char modeFE;
    int seats;
    char destination[20];
    char departure[20];
    char flightcode[10];
    public:
    Ticket()
    {

    }
    int getID(){ return ID;}

const int monthDays[12]
	= { 31, 28, 31, 30, 31, 30,
	31, 31, 30, 31, 30, 31 };


int countLeapYears(int y,int x)
{
	int years = y;


    if(x==1)
    {
	if (dof[1] <= 2)
    {
		years--;
    }
    }
    else if(x==2)
    {
     if (today[1] <= 2)
    {
		years--;
    }
    }
	
	return years / 4 - years / 100 + years / 400;
}


int getDifference()
{
	long int n1 = today[2]* 365 + today[0];

	
	for (int i = 0; i < today[1] - 1; i++)
		n1 += monthDays[i];

	n1 += countLeapYears(today[2],2);

	long int n2 = dof[2] * 365 + dof[0];
	for (int i = 0; i < dof[1] - 1; i++)
		n2 += monthDays[i];
	n2 += countLeapYears(dof[2],1);


	return (n2 - n1);
}
    void currenttime()
    {
     time_t t= time(NULL);
     tm*ptr=localtime(&t);
     today[0]=(ptr->tm_mday);
     today[1]=(ptr->tm_mon)+1;
     today[2]=(ptr->tm_year)+1900;
     
    }
    void copyinfo(Flight &f,user &u){
        ID=u.ID;
        strcpy(name,u.name);
        strcpy(contact_num,u.contact_num);
        strcpy(gender,u.gender);
        modeIL=f.mode;
        strcpy(destination,f.destination);
        strcpy(departure,f.departure);
        strcpy(flightcode,f.flightcode);
          u.update(u.ID);
        f.update(f.flightcode);
        int i;
        for(i=0;i<3;i++)
        {
         dof[i]=f.dof[i];
        }
        currenttime();

    }
    void showticket(){


        cout<<"Date issued: "<<today[0]<<"/"<<today[1]<<"/"<<today[2]<<endl;
        cout<<"Date of flight "<<dof[0]<<"/"<<dof[1]<<"/"<<dof[2]<<endl;
        cout<<"Time remaining till flight "<<getDifference()<<" days."<<endl;
        cout << "ID:"<<ID<<endl;
        cout << "Flightcode: "<<flightcode<<endl;
        cout << "Name: "<<"Ahmed"<<endl;
        cout << "Destination:  "<<destination<<endl;
        int y=seats;
        int x=0;
        while(y>0)
        {
         cout<<"For seat "<<x+1<<" Meal served ";
        if (meals[x]==1) cout << "Pakistani-Style Chicken Curry!!\n";
        if (meals[x]==2) cout << "Box-Filled Salad!!\n";
        if (meals[x]==3) cout << "Hearty-Sandwitches!!\n";
        y--;
        x++;
        }
    }
    void write(){
        ofstream o;
        o.open("booking.txt",ios::app);
        o.write((char*)this,sizeof(*this));
        o.close();
    }
    void read(){
        ifstream i;
        i.open("booking.txt",ios::binary);
        //accountaccess s1;
        while(!i.eof())
        {
            if(i.read((char*)this,sizeof(*this))){
            this->showticket();}
            else{
                break;
            }
           cout<<"\n\n";     
        }	
        i.close();

    }
    bool seat_no(int y,Flight& obj)
{
                if( obj.tcount[y-1] == -1 )
                {
  	                 cout << "The seat is taken already. \n";
                       return false;
                		}
		

            return true;
        
       
        
        
}

    void modeselect(Flight& obj)
    {
        int y,mode;
        cout << "\n1.First-Class\n2.Economy\n";
        cin >> mode;
        modeFE=mode;

        cout<<"Enter the number of seats you want to purchase ? "<<endl;
        cin>>y;
        seats=y;
        if ((obj.count+y)>obj.seats){
            cout << "Seats not available";
            cout << "\nOnly "<<obj.seats-obj.count<<"are available\nPlease Re-select your seats";

            modeselect(obj);
        }
      
     else{
      while(y>0)
      {
      int x;
      cout<<"Enter seat no(only from above displayed): " ;
      cin>>x;
      if(!(x>0&&x<=obj.seats))
      {
       cout<<"invalid seat no ";
       system("CLS");
       modeselect(obj);
      }

      if(seat_no(obj.tcount[x-1],obj)==0)
      {
        continue;
      }
      else
      {
       obj.tcount[x-1]=-1;
      }
      obj.count++;
      y--;
      }
       }
        }

void seat(Flight &obj)
 {
   
int j = 1;
				while ( j < obj.seats+1 )
				{
					if ( obj.tcount[j-1] == -1)
					j++;
					else
					{	
						cout <<"|" << j << "|";
						if ( j%10 == 0 )
						cout << endl;
						j++;	
					}	
 }
 }

    void food(){
    	 system("cls");
         cout<<"\nFood section opening.";
		 sleep(1);
		 cout<<".";
		 sleep(1);
		 cout<<".";
		 system("cls");
		 cout<<"\n\n\n"; 
     int meal;
     cout << "\t\t\t-----Welcome to In-Flight Meal Section-----\n\n\n\n";
     cout << "Please Select your Meal from the following\n";
     cout << "1.Chicken Curry\n2.Chicken Salad\n3.Sandwitches\n";
     int x=seats;
     int y=0;
     while(x>0)
     {
     cout<<"Enter meal for Seat: "<<y+1;
     cin >> meal;
     if (meal<1&&meal>3){
         cout << "Invalid meal\nPlease select again!!\n";
       continue;
     }
     else {
         if (meal==1) cout << "Pakistani-Style Chicken Curry!!\n";
         if (meal==2) cout << "Box-Filled Salad!!\n";
         if (meal==3) cout << "Hearty-Sandwitches!!\n";
         meals[y]=meal;
         x--;
         y++;
         
     }

     }
     
     cout<<"Food section Exiting.";
     sleep(1);
     cout<<".";
     sleep(1);
     cout<<".";
     system("cls");
    }

    void selecthotel(){
    	system("cls");
         cout<<"\nHotel section opening.";
		 sleep(1);
		 cout<<".";
		 sleep(1);
		 cout<<".";
		 system("cls");   	
        int choice;
        char type[10];
        char model[7]={"Resort"};
        char model1[8]={"Motel"};
        char model2[10]={"StarHotel"};
        cout << "\t\t\t-----Welcome to Hotel Purchase Section-----\n\n\n\n";
        cout << "Select any type of hotel!\n";
        cout << "1.Resorts\n2.Motel\n3.Star Hotel\n";
        cin >> choice;
        if (choice==1)
         {
             cout << "Resort has been purchased\n";
             strcpy(type,model);
             }
        
        if (choice==2){
            cout << "Motel has been purchased!!\n";
            strcpy(type,model1);
        }
        if (choice==3){
            cout << "Star Hotel has been purchased!!\n";
            strcpy(type,model2);
        }
        
      cout<<"Hotel section Exiting.";
	  sleep(1);
	  cout<<".";
	  sleep(1);
	  cout<<".";
	  system("cls");  
    }
    char* getflightcode(){
       return flightcode;
   }

    void Buy(user &userobj)
    {
     char flightco[10];
     Flight obj;
     system("cls");
     cout<<"Flight booking Section opening.";
     sleep(1);
     cout<<".";
     sleep(1);
     cout<<".";
     system("cls");
     cout << "\nWelcome to Flight Booking Section.\n";
     cout << "1.International\n2.Local flight\n";
     int mode;
     cin >> mode;
     if (mode==1){
         // cout << "i\n";
         obj.International();
     }
     else if (mode==2) {
       //  cout << "L\n";
         obj.Local();
     }
     cout<<endl<<"Enter flight code of flight you want to select ";
     fflush(stdin);
     cin>>flightco;
     
     
     Flight obj1=obj.select(flightco);
     if(strcmp(obj1.lname,"XXX")==0)
     {
     	while(strcmp(obj1.lname,"XXX")==0)
     	{
     	cout<<"\nPlease enter a valid flightcode: ";
     	cin>>flightco;
     	Flight obj1=obj.select(flightco);
     	if(strcmp(obj1.lname,"XXX")!=0)
     	{break;
		 }
      }
	 }
     seat(obj1);    
     modeselect(obj1);     
     user u;
     u.payment(modeFE,seats,obj1);
     food();
     selecthotel();
        
     copyinfo(obj1,u);
     write(); 
    	cout<<"Displaying Ticket.";
    	sleep(1);
    	cout<<".";
    	sleep(1);
    	cout<<".";
    	system("cls");
    	cout<<"\n\n";     
     showticket();
     
     
    }

   
};


void user::pastrecords(){
       
        ifstream i;
        i.open("booking.txt",ios::binary);
        Ticket s1;
        i.read((char*)&s1,sizeof(s1));
        if (!i.is_open()){cout <<"no record\nexitting\n";}
             while(!i.eof())
        {
            if (this->ID==s1.getID()){
                s1.showticket();
            }

            
            
            i.read((char*)&s1,sizeof(s1));
        }	
	
  i.close();        
    }

void Airline::showflightcode(){
        ifstream i;
	    i.open("Flights.txt", ios::binary|ios::in);
        cout << "List of Flightcodes\n";
        int count=1;
        Flight s1;
	    while(!i.eof()){
		if ((i.read((char*)&s1,sizeof(s1)))){
            
			cout <<count<<" "<<s1.getflightcode()<<endl;
            count++;
		}
		else break; 
	}
  i.close(); 
        
 }
void Airline::registerannouncement(){

        char flightcode[10];
       char annmt[100];
        cout << "Enter the flight-code to make an announcement!\n";
       cin >> flightcode;
       cout <<endl<< flightcode<<" Selected!\n\n";
       cout << "Write your announcement to the passengers of flight "<<flightcode<<"!\n";
       cin >> annmt;
        fstream i;
        
        Flight s1;
        i.open("Flights.txt",ios::binary|ios::in|ios::out);
        
        int pos;
        while (!i.eof()){
            
            
          pos=i.tellg();
        if(i.read((char*)&s1,sizeof(s1)))
        {
            
        if(strcmp(s1.getflightcode(),flightcode)==0)
        {
            cout << s1.getflightcode()<<endl;
        s1.setannmt(annmt);
        i.seekp(pos);
        i.write((char*)&s1,sizeof(s1));
        break;
        }
        }
        else 
        break;
        }
        i.close();



    }

void Airline::registerannouncement(char* a){

        char flightcode[10];
       char annmt[100];
        cout << "Enter the flight-code to make an announcement!\n";
       cin >> flightcode;
       cout <<endl<< flightcode<<" Selected!\n\n";
       cout << "Your announcement to the passengers of flight "<<flightcode<<" is "<<a<<endl;
       strcpy(annmt,a);
        fstream i;
        
        Flight s1;
        i.open("Flights.txt",ios::binary|ios::in|ios::out);
        
        int pos;
        while (!i.eof()){
            
            
          pos=i.tellg();
        if(i.read((char*)&s1,sizeof(s1)))
        {
            
        if(strcmp(s1.getflightcode(),flightcode)==0)
        {
            cout << s1.getflightcode()<<endl;
        s1.setannmt(annmt);
        i.seekp(pos);
        i.write((char*)&s1,sizeof(s1));
        break;
        }
        }
        else 
        break;
        }
        i.close();



    }    
void user::viewannmt()
{
      // vector <int> userid; //stores userID
        ifstream i;
        Ticket s1;
        i.open("booking.txt",ios::binary);
        i.read((char*)&s1,sizeof(s1));
        int count=0;
        ifstream o;
        o.open("Flights.txt",ios::binary);
        Flight s2;
        while (!i.eof()){
            
            if (ID==s1.getID()){
                    o.read((char*)&s2,sizeof(s2));
                    while(!o.eof()){      
                        // pos=o.tellg();   
                       // cout <<s2.getflightcode()<<"out"<<" "<<endl;
                        //cout <<s1.getflightcode()<<"out"<<" "<<endl;
                    if (strcmp(s2.getflightcode(),s1.getflightcode())==0){
                            cout <<"Announcement for Flight "<<s2.getflightcode()<<": "<< s2.showannmt()<<endl;
                        
                    }
                    o.read((char*)&s2,sizeof(s2));
                    }
                    o.close();
                    o.open("Flights.txt",ios::binary|ios::in|ios::out);
                                
            }
            
            i.read((char*)&s1,sizeof(s1));
        }
        i.close();
        //cout << count<<endl;
         //ifstream o;
// for (int id : userid)
//         {
//             cout <<id<<endl;
//         }
        // o.open("Flights.txt",ios::binary);
         //Flight s2;
        
        // int pos;
        
           //  for (int i=0;i<count;i++)
        // {o.read((char*)&s2,sizeof(s2));
        //          while(!o.eof()){      
        //             // pos=o.tellg();   
        //              cout <<s2.getflightcode()<<"out"<<" "<<endl;
        //              cout <<s1.getflightcode()<<"out"<<" "<<endl;
        //         if (strcmp(s2.getflightcode(),s1.getflightcode())==0){
        //                 cout << s2.showannmt()<<endl;
                    
        //         }
        //         o.read((char*)&s2,sizeof(s2));
        //         }
        //         o.close();
        //         o.open("Flights.txt",ios::binary|ios::in|ios::out);
        
    
}

void admin::options()
{
	user u;
   int choice;
	cout<<"\nMoving to Admin Menu\n\n";
    cout<<"Loading.";
    sleep(1);
    cout<<".";
    sleep(1);
    cout<<".";   
  system("cls");
  cout<<"\t\t\t\t-----Flight with pride!!-----\n";	
  cout<<"\t\t\t\t------Admin Menu Page-------\n\n\n";
  
   cout << "1- View Bookings\n";
   cout << "2- View Registered users\n";
   cout << "3- Make Announcement(admin)\n";
   cout << "4- Logout\n";
   
   cin>>choice;
    if (choice==1){
        Ticket t;
        t.read();
        cout<<"Press any key to continue(redirected to menu screen): ";
        char ch;
        cin>>ch;
        this->options();
    }
    else if (choice==2){
       u.read();
       cout<<"Press any key to continue(redirected to menu screen): ";
        char ch;
        cin>>ch;      
       	this->options();
    }
    else if (choice==3)
	{
    //    Airline *a;
    //    Flight f;
    //    a=&f;
    //     a->showflightcode();
        Airline a;
        
        a.makeannmt();
       cout<<"Press any key to continue(redirected to menu screen): ";
        char ch;
        cin>>ch;  
		this->options();            
        
    }
	else if(choice==4)
	
	{
		cout<<"\nLogging off.";
		sleep(1);
		cout<<".";
		sleep(1);
		cout<<".";
		exit(1);
		}	
}

void user::options()
{
	user u;
	int choice;
	cout<<"\nMoving to User Menu\n\n";
    cout<<"Loading.";
    sleep(1);
    cout<<".";
    sleep(1);
    cout<<".";
 
    system("cls");
    
    cout<<"\t\t\t\t------Flight with pride-----\n";
    cout<<"\t\t\t\t-----Welcome to User Page-----\n\n\n";	
    cout << "1. Make Reservation\n";
    cout << "2. View Flights\n";
    cout << "3. View Past Bookings\n";
    cout << "4. Change Reservation\n";
    cout << "5. File Complain\n";
    cout << "6. Change your data\n";
    cout << "7. View Announcements\n";
     cout << "8. logout\n";
    cin >> choice;


    if (choice==1){

         Ticket t;
         t.Buy(u);
	     cout<<"\n\nPress Any key to return to menu: ";
	     char ch;
	     cin>>ch;         
         this->options();
    }
    if (choice==2){
        Flight f;
        cout << "Welcome to Routes!\n";
         f.read();
	     cout<<"\n\nPress Any key to return to menu: ";
	     char ch;
	     cin>>ch;         
         this->options();
    }
    if (choice==3){
        this->pastrecords();
	     cout<<"\n\nPress Any key to return to menu: ";
	     char ch;
	     cin>>ch;         
         this->options();   
    }
     if (choice==6){
       this->changestuff(u.getID());
      }
    if (choice==7){
        this->viewannmt();
	     cout<<"\n\nPress Any key to return to menu: ";
	     char ch;
	     cin>>ch;         
         this->options();	
	
    }
	else if(choice==8)
	
	{
		cout<<"\nLogging off.";
		sleep(1);
		cout<<".";
		sleep(1);
		cout<<".";
		exit(1);
		}    
}
int main()
{
    int choice;
  system("cls");
  cout<<"\t\t\t\tWelcome to Flight with pride!!....\n";
	
	cout<<"\t\t\t\tLoading App.....\n";
	
   cout<<"\t\t\t\t\t----------------\n";
	cout<<"\t\t\t\t1- Signup\n";
	cout<<"\t\t\t\t2- Login\n";	
    cout << "\t\t\t\t3- Login as Admin\n";

    cin>>choice;
    user u;
    if (choice==1){
        user u1(choice);
        u=u1;
        u.store();
        u.read();
        
         
    }
    else if (choice==2){
        cout<<"Enter user name ";
        char name[100];
        fflush(stdin);
        cin>>name;
        cout<<"Enter pass word: ";
        char pass[50];
        fflush(stdin);
        cin>>pass;
        user u2(name,pass);
       u=u2;
       cout<<endl;
       u.options();
        



    }
    else if(choice==3)
    {
    	char uname[100];
    	char pass[100];
    	admin a;
    	cout<<"Enter Username: ";
    	fflush(stdin);
    	cin.getline(uname,100);
    	cout<<"Enter Password: ";
    	fflush(stdin);
    	cin.getline(pass,100);
		
		a.read(uname,pass); 
		a.options();	
	}

    else 
    {
		cout<<"Wrong option entered.\nProgram exiting!!!";
		cout<<"Loading.";
		sleep(1);
		cout<<".";
		sleep(1);
		cout<<".";
		sleep(1);
		cout<<".";
		sleep(1);
	    exit(0);   	
	}

       
    }
    
    




















//   Flight obj('L',float(25000),float(15000),"PKR-265","Karachi","Islamabad","Boeing-747",float(2.5),"PIA",80);
//   obj.write();
//   Flight obj1('I',float(250000),float(150000),"PK-20X","Tokyo","Lahore","Boeing-747",float(12),"Emirates",200);
//   obj1.write();
//   Flight obj2('L',float(14000),float(7000),"PKR-194","Nawabshah","Karachi","Boeing-777",float(0.5),"Serene",50);
//   obj2.write();





