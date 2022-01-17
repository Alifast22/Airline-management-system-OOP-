#include<iostream>
using namespace std;
#include<cstring>
#include<fstream>
#include<stdlib.h>
#include <string>
#include <unistd.h>

class admin
{
	char name[100];
	char id[100];
	char pass[100];
	
	public:
		
	
    admin (char* name,char *uname,char *pass)
    {
        strcpy(this->id,uname);
        strcpy(this->pass,pass);
        strcpy(this->name,name);

    }

    
    void store()
    {
        ofstream o;
        o.open("admin.txt",ios::binary|ios::app);
        

            o.write((char*)this,sizeof(*this));
            o.close();

    cout<<"Your account has been made!"<<endl;
    cout<<"We look forward to seeing you more "<<name<<endl;

    }	
    void read(char* name,char* uname,char* pass)
    {
      ifstream i;
      i.open("admin.txt",ios::binary);
      while(!i.eof())
      {
        if(i.read((char*)this,sizeof(*this)))
        {
         if(strcmp(this->id,uname)==0&&strcmp(this->pass,pass)==0)
         {
         cout<<"Welcome back "<<name;
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
	
 // i.close();

 
	void display()
	{
		cout <<"\nID: x"<<id<<endl;
        cout<<"Name: "<<name<<endl;

	}
};
int main() {
	

	admin a("Ali","ali22","pass");
	admin b("Ibad","Ibad23","pass");
	admin c("Khuwaja","Khuwaja24","pass");
	a.store();
    a.read("Ali","ali22","pass");
    cout<<endl;
    b.store();
    b.read("Ibad","Ibad23","pass");
    cout<<endl;
    c.store();
    c.read("Khuwaja","Khuwaja24","pass");
	
}
