#include<iostream>
using namespace std;
#include<cstring>
#include<fstream>
#include<stdlib.h>
#include <string>
#include <unistd.h>

class accountaccess
{
    protected:
	static int Tot;
	int ID;
	char name[100];
    double contact_num;
	int age;
	char gender[10];
	char username[100];
	char pass[50];
	
	public:
    
	accountaccess(char *name,int cont,double age,char *gend,char *username,char *pass)
	{
	ID=Tot++;
	strcpy(this->name,name);
	strcpy(this->username,username);
	strcpy(gender,gend);
	strcpy(this->pass,pass);
	this->age=age;
	contact_num=cont;
	}

	accountaccess(int num)
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
	}
	accountaccess()
	{

	}
    void store()
    {
        ofstream o;
        o.open("accountaccess.txt",ios::app);
        
        if(o.is_open())
        {
            cout<<"File opened"<<endl;	
            o.write((char*)this,sizeof(*this));
            o.close();
        }	
    cout<<"Your account has been made!"<<endl;
    cout<<"We look forward to seeing you more "<<name<<endl;

    }	
    void loginread()
    {
        ifstream i;
        i.open("accountaccess.txt");
        //accountaccess s1;
        while(!i.eof())
        {
            i.read((char*)this,sizeof(*this));
            this->display();
                
        }	

    }
	void display()
	{
		cout<<"Name: "<<name<<endl;
		cout<<"Contact Number: "<<contact_num<<endl;
		cout<<"Age: "<<age<<endl;
		cout<<"Gender: "<<gender<<endl;
		cout<<endl<<endl;
	}
	
};
int accountaccess::Tot=0;

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
    BankAccount(){}; //nthng inside ie; account not made
    BankAccount(int num){    //bankaccount only initialized if asked for
            
            cout << "Enter Bank Name: ";
            cin >> bankname;
            balance= (rand() % 1000) + 10000;
            cout << "\nEnter your card no.:";
            cin >> cardno;
            cout << "\nEnter your pin no.:";
            cin >> pin;

    } 
    void pay(int price){
        cout << "Congratulations!! Payment successfully made!\n";
        balance-=price;
    }
    void getbalance(){
        cout << "Your current balance is : "<<balance<<endl;
    }
};


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
    char announcements[100];
	
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
        ID=Tot++;
	}
	user()
	{

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
            BankAccount b1(choice);
            b1.pay(price);
        }
         if (choice==1 /* and user has already made an bankaccount(thru previous signup)*/){
            //debit card
            BankAccount b1; //will get data from file reading 
            b1.pay(price);
            
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

class Airline
{
 protected:
 //name of airline 
 char lname[10];
 
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
 void write()
 {
  ofstream o;
  o.open("Flights.txt",ios::binary|ios::app);
  o.write((char*)this,sizeof(*this));
  o.close();
 }
 void display()
 {
  cout<<"Airline name is "<<lname<<endl;
  cout<<"Flight code is "<<flightcode<<endl;
  cout<<"Departure from "<<departure<<endl;
  cout<<"Destination is "<<destination<<endl;
  cout<<"First class ticket price "<<fcticket<<endl;
  cout<<"Economy class ticket price "<<eticket<<endl;
  cout<<"Estimated Time of flight is "<<time<<" hour(s)."<<endl;
  cout<<endl<<endl<<endl;
 }
 void read()
 {
   ifstream i;
	i.open("Flights.txt", ios::in);
    
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
  o.open("Flights.txt");
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
 }
  void International()
    {
     ifstream o;
     o.open("Flights.txt");
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
     ifstream o;
     o.open("Flights.txt");
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

class Ticket
{

    protected:
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
    void copyinfo(Flight &f,user &u){
        ID=u.ID;
        strcpy(name,u.name);
        strcpy(contact_num,u.contact_num);
        strcpy(gender,u.gender);
        modeIL=f.mode;
        strcpy(destination,f.destination);
        strcpy(departure,f.departure);
        strcpy(flightcode,f.flightcode);
    }
    void showticket(){
        cout << "ID:"<<ID<<endl;
        cout << "Flightcode: "<<flightcode<<endl;
        cout << "Name: "<<name<<endl;
        cout << "Destination: \n"<<destination<<endl;
    }
    void write(){
        ofstream o;
        o.open("booking.txt",ios::app);
        o.write((char*)this,sizeof(*this));
        o.close();
    }
   void read(){
        ifstream i;
        i.open("booking.txt");
        //accountaccess s1;
        while(!i.eof())
        {
            if(i.read((char*)this,sizeof(*this))){
            this->showticket();}
            else{
                break;
            }
                
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
//   int x=0;
//   int f=0;
//   for(int i=1;i<=obj.seats;i++)
//   {
//     for(int j=0;j<obj.seats;j++)
//     {
//      if(i==obj.tcount[j])
//      {
//       f=1;
//       break;
//      }
//     }
//     if(f==0)
//     {
//      cout<<"Seat no: "<<i;
//      cout<<"     ";
//      x++;
//     }
//     if(x==5)
//     {
//     cout<<endl;
//      x=0;
//     }
//     f=0;
   
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
     int meal;
     cout << "Welcome to In-Flight Meal Section\n";
     cout << "Please Select your Meal from the following\n";
     cout << "1.Chicken Curry\n2.Chicken Salad\n3.Sandwitches\n";
     cin >> meal;
     if (meal<1&&meal>3){
         cout << "Invalid meal\nPlease select again!!\n";
     }
     else {
         if (meal==1) cout << "Pakistani-Style Chicken Curry will be served to you!!\n";
         if (meal==2) cout << "Box-Filled Salad will be served to you!!\n";
         if (meal==3) cout << "Hearty-Sandwitches will be served to you!!\n";
     }
    }

    void selecthotel(){
        int choice;
        char type[10];
        char model[7]={"Resort"};
        char model1[8]={"Motel"};
        char model2[10]={"StarHotel"};
        cout << "Welcome to Hotel Purchase Section!";
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
    }


    void Buy(user &userobj)
    {
     char flightco[10];
     Flight obj;
     cout << "\nWelcome to Flight Booking Section.\n";
     cout << "1.International\n2.Local flight\n";
     int mode;
     cin >> mode;
     if (mode==1){
          cout << "i\n";
         obj.International();
     }
     else if (mode==2) {
         cout << "L\n";
         obj.Local();
     }
     cout<<endl<<"Enter flight code of flight you want to select ";
     fflush(stdin);
     cin>>flightco;
     Flight obj1=obj.select(flightco);
     seat(obj1);
     modeselect(obj1);
     food();
     selecthotel();
     copyinfo(obj1,userobj);
     write();
    }

   
};






int main()
{
    int choice;
//   system("cls");
//   cout<<"\t\t\t\tWelcome to l0ra 4 l0ra!....\n";
	
// 	cout<<"\t\t\t\tLoading App.....\n";
	
//    cout<<"\t\t\t\t\t----------------\n";
// 	cout<<"\t\t\t\t1- Signup\n";
// 	cout<<"\t\t\t\t2- Login\n";	
//     cout << "\t\t\t\t3- View bookings\n";
       // cout << "2-view flighs\n";
//      cout << "\t\t\t\t4- View Registered users\n";
     //cin>>choice;
    //   if (choice==2){
    //     Flight f;
    //     cout << "Welcome to Routes!\n";
    //      f.read();
    //      sleep(5);
    //     cout << "Returning to main menu for bookings!\n";
    //     main();
    // }
  //   user u;
     
//     if (choice==1){
//         user u1(choice);
//         u=u1;
//         u.store();
//         u.read();
         
//     }
//     else if (choice==2){
//         // fck it
//         cout << "maa chudae\n";
//         exit(0);
//     }
//     else if (choice==3){
//         Ticket t;
//         t.read();
//         sleep(4);
//         main();
//     }
//     else if (choice==4){
//        u.read();
//        exit(0);
    
//     }
//     else exit(0);
//     cout << "1. Make Reservation\n";
//     cout << "2. View Flights\n";
//     cout << "4. Change Reservation\n";
//     cout << "5. File Complain\n";
//     cin >> choice;

//     if (choice==1){

//          Ticket t;
//          t.Buy(u);
//          sleep(5);
//          cout << "congrats re-directing to menu\n";
//          main();
//     }
//     if (choice==2){
//         Flight f;
//         cout << "Welcome to Routes!\n";
//          f.read();
//          sleep(5);
//         cout << "Returning to main menu for bookings!\n";
//         main();
//     }
//     if (choice==3){
//         Ticket t;
//         t.read();
//         sleep(4);
//         main();
//     }
//     if (choice==6){
//        //sds
//     }
    
    



















  Flight obj('L',float(25000),float(15000),"PKR-265","Karachi","Islamabad","Boeing-747",float(2.5),"PIA",80,25,7,2021);
  obj.write();
  Flight obj1('I',float(250000),float(150000),"PK-20X","Tokyo","Lahore","Boeing-747",float(12),"Emirates",200,23,6,2021);
  obj1.write();
  Flight obj2('L',float(14000),float(7000),"PKR-194","Nawabshah","Karachi","Boeing-777",float(0.5),"Serene",50,24,5,2021);
  obj2.write();




}
