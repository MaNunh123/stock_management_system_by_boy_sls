#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
using namespace std; 

//project : Stock Management System 

/*Feature : 
1. Supplier Management
2. Category Management 
3. Product Management
4. Stock Management (Stock In and Out)
5. User Management (admin/normal)*/

//abstract base class 
class IFeature {
	//pure virtual function 
	public:
		virtual void Insert() = 0;
		virtual void Show() = 0;
		virtual int Search() = 0; 
		virtual void Update() = 0;
		virtual void Delete() = 0;	
		virtual void Sort() = 0;
};

class User:public IFeature {
	private:
		int userId; 
		char username[50];
		char email[50];
		char password[50]; 
		char gender; 
		char role[10];
	public:
		//constructor
		User(int userId = 0, const char *username = "Unknown", const char *email = "Unknown", 
			const char *password = "Unknown", const char *role = "Unknown");
		//destructor 
		~User();
		//implementors & accessors
		void SetUsername(char *username);
		int GetUserId();
		//operator overloading
		//insertion (output)
		friend ostream &operator << (ostream &out, User &obj); 
		//extraction (input)
		friend istream &operator >> (istream &in, User &obj); 
		//assignment (swap object)
		void operator = (User obj); 
		//comparison (== & >) (search & sort) 
		int operator == (User obj); 
		int operator > (User obj); 
};

//definition of class User
User::User(int userId, const char *username, const char *email, 
		   const char *password, const char *role):
		   	userId(userId){
	strcpy(this->username, username);
	strcpy(this->email, email); 
	strcpy(this->password, password); 
	strcpy(this->role, role); 
}

~User::User(){
}

void User::SetUsername(char *username){
	this->username = username; 
}

int User::GetUserId(){
	return userId;
}

ostream &operator << (ostream &out, User &obj){
	out<<obj.userId<<"\t"<<obj.username<<"\t"<<obj.email<<"\t"<<obj.password<<"\t"<<obj.role<<endl;
	return out; 
}

istream &operator >> (istream &in, User &obj){
	cout<<"Enter User ID : "; in>>obj.userId; 
	cout<<"Enter Username : "; in>>obj.username; 
	cout<<"Enter Email : "; in>>obj.email; 
	cout<<"Enter Password : "; in>>obj.password; 
	cout<<"Enter Role : "; in>>obj.role; 
	return in; 
}

int User::operator == (User obj){
	return userId == obj.userId;
}

int User::operator > (User obj){
	return userId > obj.userId; 
}

void User::operator = (User obj){
	this->userId = obj.userId; 
	strcpy(this->username, obj.username); 
	strcpy(this->email, obj.email); 
	strcpy(this->password, obj.password); 
	strcpy(this->role, obj.role);
}
 
class Supplier:public IFeature {
	private:
		int supId; 
		char name[50]; 
		char description[100];
		char address[50]; 
		char license[50];
	public:
		//constructors
		Supplier();
		Supplier(int supId, char *name, char *description, char *address, char *license);
		//destructor 
		~Supplier();
		//implementors & accessors
		void SetName(char *name);
		int GetSupId();
};

//definition of class Supplier

class Category:public IFeature {
	private:
		int catId; 
		char name[50]; 
		char description[100];
	public:
		//constructors
		Category();
		Category(int catId, char *name, char *description);
		//destructor 
		~Category();
		//implementors & accessors
		void SetName(char *name);
		int GetCatId();
};

//definition of class Category

class Product:public IFeature {
	private:
		int proId; 
		char name[50]; 
		char description[100];
		double price; 
		char madeAtDate[50]; 
		char expirationDate[50];
		int supId;
		char supName[50];
		int catId;
		char catName[50];
	public:
		//constructors
		Product();
		Product(int proId, char *name, char *description, 
		double price, char *madeAtDate, char *expirationDate, 
		int supId, char *supName, int catId, char *catName);
		//destructor 
		~Product();
		//implementors & accessors
		void SetName(char *name);
		int GetProId();
};

//definition of class Product

class Stock:public IFeature {
	private:
		int stockId; 
		int qty; 
		int proId; 
		char proName[50];
		int userId;
		char username[50];
	public:
		//constructors
		Stock();
		Stock(int stockId, int qty, int proId, char *proName, int userId, char *username);
		//destructor 
		~Stock();
		//implementors & accessors
		void SetQty(int qty);
		int GetStockId();
		//operator overloading 
};

//definition of class Stock

//template function
template <class Type>
void Insert(Type obj){
	cin>>obj;
}

template <class Type>
void Show(Type obj[], int n){
	for(int i = 0; i < n; i++){
		cout<<obj[i];
	}
}

template <class Type, class Type1>
int Search(Type obj[], int n, Type1 keyItem){
	int i; 
	int found = 0;
	for(i = 0; i < n; i++)
		if(obj[i] == keyItem){
			found++;
			break;
		}
	return found == 1 ? i : -1;
}

template <class Type, class Type1>
bool Update(Type obj[], int n, Type1 keyItem){
	int found = 0;
	for(int i = 0; i < n; i++)
		if(obj[i] == keyItem){
			found++;
			cout<<obj[i];
			cin>>obj[i];
			break;
		}
	return found == 1;
}

template <class Type, class Type1>
bool Delete(Type obj[], int n, Type1 keyItem){
	int found = 0; 
	for(int i = 0; i < n; i++){
		if(obj[i] == keyItem){
			found++; 
			for(int k = i; k < n; k++)
				obj[k] = obj[k+1];
			break; 
		}
	}
	//n--;
	return found == 1; 
}

template <class Type>
void Sort(Type obj[], int n){
	Type temp; 
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			if(obj[i] > obj[j]){
				temp = obj[i]; 
				obj[i] = obj[j]; 
				obj[j] = temp;
			}
		}
	}
}

int main(){
	cout<<"Stock Management System"<<endl; 
	getch(); 
	return 0;
}