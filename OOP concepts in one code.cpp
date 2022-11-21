#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

int main();
int issuedBooks, returnedBooks, due;
#define max 50

//constructor
class user{
	public:
		char pass[50], name[50];
		user(){
			cout<<"please enter an username and password for signing up to library-> "<<endl;
			cout<<"enter username: "<<endl;
			cin.getline(name, 50);
			cout<<"enter the password: "<<endl;
			cin.getline(pass, 50);
			cout<<"thank you for signing up!";
			cout<<"now you can get access to all the books!"<<endl;
			
		}
};

class info{
	public:
		info(int issuedb, int returnb, int fine){
			issuedBooks=issuedb;
			returnedBooks=returnb;
			due=fine;
		}
};

class issueBook{
	public:
		issueBook(int issuedBooks){
			if(issuedBooks > max)
			    get();
			else{
				returnedBooks= issuedBooks;
				cout<<endl<<"You have issued a book!"<<endl;
				cout<<"You can issue only 5 books at a time so you still can issue "<<(5-issuedBooks)<<" more books."<<endl;
				cout<<"At the moment you have issued "<<issuedBooks<<" books"<<endl;
				cout<<"You have to return "<<returnedBooks<<" books."<<endl;
				cout<<"Due amount is Rs "<<due<<endl;
				
				
			}
		}
		
		issueBook(){
			if(issuedBooks > max){
				issuedBooks=5;
				cout<<"You have issued "<<issuedBooks<<" books."<<endl;
				cout<<"You have to return "<<returnedBooks<<" books."<<endl
				cout<<"Due amount is Rs "<<due<<endl;
				
			}
		}
		friend int get();
};

class accountinfo{
	public:
		accountinfo(){
			cout<<"Thank you, return soon!"<<endl;
		}
};

int get(){
	cout<<"You reached thr limit! Return books to issue more."<<endl;
}

class returnB{
	public:
		int display(){
			try{
				if(returnedBooks==0)
				    throw 0;
				else{
					cout<<"You have returned the book!"<<endl;
					returnedBooks = --issuedBooks;
					cout<<"You currently have "<<returnedBooks<<" books in your account."<<endl;
					
				}    
			}
			catch(int a){
				cout<<"Error :/    "<<"There are "<<a<<" books to be returned!"<<endl;
				
			}
		}
};


int main(){
	int menu;
	login s1;
	info obj(0,0,100);
	while(1){
		cout<<"Menu Driven: "<<endl;
		cout<<"1. Issue a book."<<endl;
		cout<<"2. Return a book."<<endl;
		cout<<"3. User info."<<endl;
		cout<<"4. Exit."<<endl;
		cout<<"Your choice: "<<endl;
		switch(menu){
			case 1:{
				if(issuedBooks> max)
				    issuedBooks = 5;
				else
				    issuedBooks++;
				    issueBook  user(issuedBooks);
				break;
			}
			
			case 2:{
				returnB user;
				user.display();
				break;
			}
			
			case 3:{
				info obj1;
				break;
			}
			
			case 4:{
				cout<<"Exiting library..........."<<endl;
				cout<<"Thank you for using the library! "<<endl;
				break;
			}
			exit(0);
		}
	}
}









