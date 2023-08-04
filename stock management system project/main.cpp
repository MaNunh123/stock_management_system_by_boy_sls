#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
using namespace std;

// project : Stock Management System

/*Feature :
1. Supplier Management
2. Category Management
3. Product Management
4. Stock Management (Stock In and Out)
5. User Management (admin/normal)*/

// abstract base class
class IFeature
{
	// pure virtual function
public:
	virtual void Insert() = 0;
	virtual void Show() = 0;
	virtual int Search() = 0;
	virtual void Update() = 0;
	virtual void Delete() = 0;
	virtual void Sort() = 0;
};

class User : public IFeature
{
private:
	int userId;
	char username[50];
	char email[50];
	char password[50];
	char gender;
	char role[10];

public:
	// constructor
	User(int userId = 0, const char *username = "Unknown", const char *email = "Unknown",
		 const char *password = "Unknown", const char *role = "Unknown");
	// destructor
	~User();
	// implementors & accessors
	void SetUsername(char *username);
	int GetUserId();
	// operator overloading
	// insertion (output)
	friend ostream &operator<<(ostream &out, User &obj);
	// extraction (input)
	friend istream &operator>>(istream &in, User &obj);
	// assignment (swap object)
	void operator=(User obj);
	// comparison (== & >) (search & sort)
	int operator==(User obj);
	int operator>(User obj);
};

// definition of class User
User::User(int userId, const char *username, const char *email,
		   const char *password, const char *role) : userId(userId)
{
	strcpy(this->username, username);
	strcpy(this->email, email);
	strcpy(this->password, password);
	strcpy(this->role, role);
}

~User::User()
{
}

void User::SetUsername(char *username)
{
	this->username = username;
}

int User::GetUserId()
{
	return userId;
}

ostream &operator<<(ostream &out, User &obj)
{
	out << obj.userId << "\t" << obj.username << "\t" << obj.email << "\t" << obj.password << "\t" << obj.role << endl;
	return out;
}

istream &operator>>(istream &in, User &obj)
{
	cout << "Enter User ID : ";
	in >> obj.userId;
	cout << "Enter Username : ";
	in >> obj.username;
	cout << "Enter Email : ";
	in >> obj.email;
	cout << "Enter Password : ";
	in >> obj.password;
	cout << "Enter Role : ";
	in >> obj.role;
	return in;
}

int User::operator==(User obj)
{
	return userId == obj.userId;
}

int User::operator>(User obj)
{
	return userId > obj.userId;
}

void User::operator=(User obj)
{
	this->userId = obj.userId;
	strcpy(this->username, obj.username);
	strcpy(this->email, obj.email);
	strcpy(this->password, obj.password);
	strcpy(this->role, obj.role);
}

class Supplier : public IFeature
{
private:
	int supId;
	char name[50];
	char description[100];
	char address[50];
	char license[50];

public:
	// constructors
	Supplier();
	// constructors with parameter
	Supplier(int supId, char *name, char *description, char *address, char *license);
	// destructor
	~Supplier();
	// implementors & accessors
	void SetName(char *name);
	int GetSupId();
	friend ostream &operator<<(ostream &out, Supplier &obj);
	// extraction (input)
	friend istream &operator>>(istream &in, Supplier &obj);
	// assignment (swap object)
	void operator=(Supplier obj);
	// comparison (== & >) (search & sort)
	int operator==(Supplier obj);
	int operator>(Supplier obj);
};

Supplier::Supplier(int supId, char *name, char *description, char *address, char *license) : supId(supId)
{
	strcpy(this->name, name);
	strcpy(this->description, description);
	strcpy(this->address, address);
	strcpy(this->license, license);
}

~Supplier::Supplier()
{
}

Supplier::SetName(char *name)
{
	this->name = name;
}

Supplier::GetSupId()
{
	return subId;
}

ostream &operator<<(ostream &out, Supplier &obj)
{
	out << obj.subId << "\t" << obj.name << "\t" << obj.description << "\t" << obj.address << "\t" << obj.license << endl;
	return out;
}

istream &operator>>(istream &in, Supplier &obj)
{
	cout << "Enter Supplier ID : ";
	in >> obj.supId;
	cout << "Enter Supplier Name : ";
	in >> obj.name;
	cout << "Enter Supplier Description : ";
	in >> obj.description;
	cout << "Enter Supplier Address : ";
	in >> obj.address;
	cout << "Enter Supplier License : ";
	in >> obj.license;
	return in;
}

int Supplier::operator==(Supplier obj)
{
	return supId == obj.supId;
}

int Supplier::operator>(Supplier obj)
{
	return supId > obj.supId;
}

void Supplier::operator=(Supplier obj)
{
	this->supId = obj.supId;
	strcpy(this->name, obj.name);
	strcpy(this->description, obj.description);
	strcpy(this->address, obj.address);
	strcpy(this->license, obj.license);
}
// definition of class Supplier

class Category : public IFeature
{
private:
	int catId;
	char name[50];
	char description[100];

public:
	// constructors
	Category();
	Category(int catId, char *name, char *description);
	// destructor
	~Category();
	// implementors & accessors
	void SetName(char *name);
	int GetCatId();
	friend ostream &operator<<(ostream &out, Category &obj);
	// extraction (input)
	friend istream &operator>>(istream &in, Category &obj);
	// assignment (swap object)
	void operator=(Category obj);
	// comparison (== & >) (search & sort)
	int operator==(Category obj);
	int operator>(Category obj);
};

Category::Category(int catId, char *name, char *description) : catId(catId)
{
	strcpy(this->name, name);
	strcpy(this->description, description);
}

~Category::Category()
{
}

Category::SetName(char *name)
{
	this->name = name;
}

Category::GetCatId()
{
	return catId;
}

ostream &operator<<(ostream &out, Category &obj)
{
	out << obj.catId << "\t" << obj.name << "\t" << obj.description << endl;
	return out;
}

istream &operator>>(istream &in, Category &obj)
{
	cout << "Enter Category ID : ";
	in >> obj.catId;
	cout << "Enter Category Name : ";
	in >> obj.name;
	cout << "Enter Category Description : ";
	in >> obj.description;
	return in;
}

int Category::operator==(Category obj)
{
	return catId == obj.catId;
}

int Category::operator>(Category obj)
{
	return catId > obj.catId;
}

void Category::operator=(Category obj)
{
	this->catId = obj.catId;
	strcpy(this->name, obj.name);
	strcpy(this->description, obj.description);
}

// definition of class Category

class Product : public IFeature
{
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
	// constructors
	Product();
	Product(int proId, char *name, char *description,
			double price, char *madeAtDate, char *expirationDate,
			int supId, char *supName, int catId, char *catName);
	// destructor
	~Product();
	// implementors & accessors
	void SetName(char *name);
	int GetProId();
	friend ostream &operator<<(ostream &out, Product &obj);
	// extraction (input)
	friend istream &operator>>(istream &in, Product &obj);
	// assignment (swap object)
	void operator=(Product obj);
	// comparison (== & >) (search & sort)
	int operator==(Product obj);
	int operator>(Product obj);
};

Product::Product(int proId, char *name, char *description,
				 double price, char *madeAtDate, char *expirationDate,
				 int supId, char *supName, int catId, char *catName) : proId(proId)
{
	strcpy(this->proId, proId);
	strcpy(this->name, name);
	strcpy(this->description, description);
	strcpy(this->price, price);
	strcpy(this->madeAtDate, madeAtDate);
	strcpy(this->expirationDate, expirationDate);
	strcpy(this->supId, supId);
	strcpy(this->supName, supName);
	strcpy(this->catId, catId);
	strcpy(this->catName, catName);
}

~Product::Product();

Product::SetName(char *name)
{
	this->name = name;
}

Product::GetProId()
{
	return proId;
}

ostream &operator<<(ostream &out, Product &obj)
{
	out << obj.proId << "\t" << obj.name << "\t" << obj.description << "\t" << obj.price << "\t" << obj.madeAtDate << "\t" << obj.expirationDate
		<< "\t" << obj.supId << "\t" << obj.supName << "\t" << obj.catId << "\t" << obj.catName << endl;
	return out;
}

istream &operator>>(istream &in, Product &obj)
{
	cout << "Enter Product ID : ";
	in >> obj.catId;
	cout << "Enter Product Name : ";
	in >> obj.name;
	cout << "Enter Product Description : ";
	in >> obj.description;
	cout << "Enter Product Price : ";
	in >> obj.price;
	cout << "Enter Product MadeDate : ";
	in >> obj.madeAtDate;
	cout << "Enter Product ExpirationDate : ";
	in >> obj.expirationDate;
	cout << "Enter Supplier Id : ";
	in >> obj.supId;
	cout << "Enter Supplier Name : ";
	in >> obj.supName;
	cout << "Enter Category Id : ";
	in >> obj.catId;
	cout << "Enter Category Name : ";
	in >> obj.catName;
	return in;
}

int Product::operator==(Product obj)
{
	return proId == obj.proId;
}

int Product::operator>(Product obj)
{
	return proID > obj.proId;
}

void Product::operator=(Product obj)
{
	this->proId = proId;
	strcpy(this->name, obj.name);
	strcpy(this->description, obj.description);
	strcpy(this->price, obj.price);
	strcpy(this->madeAtDate, obj.madeAtDate);
	strcpy(this->expirationDate, obj.expirationDate);
	strcpy(this->supId, obj.supId);
	strcpy(this->supName, obj.supName);
	strcpy(this->catId, obj.catId);
	strcpy(this->catName, obj.catName);
}
// definition of class Product

class Stock : public IFeature
{
private:
	int stockId;
	int qty;
	int proId;
	char proName[50];
	int userId;
	char username[50];

public:
	// constructors
	Stock();
	Stock(int stockId, int qty, int proId, char *proName, int userId, char *username);
	// destructor
	~Stock();
	// implementors & accessors
	void SetQty(int qty);
	int GetStockId();
	// operator overloading
};
Stock::Stock(int stockId, int qty, int proId, char *proName, int userId, char *username) : stockId(stockId)
{
	strcpy(this->stockId, stockId);
	strcpy(this->qty, qty);
	strcpy(this->proId, proId);
	strcpy(this->proName, proName);
	strcpy(this->userId, userId);
	strcpy(this->username, username);
}

~Stock::Stock();

Stock::SetQty(int qty)
{
	return qty;
}

Stock::GetStockId()
{
	return StockId;
}

ostream &operator<<(ostream &out, Stock &obj)
{
	out << obj.stockID << "\t" << obj.qty << "\t" << obj.proId << "\t" << obj.proName << "\t" << obj.userId << "\t" << obj.username << endl;
	return out;
}

instream &operator>>(instream &in, Stock &obj)
{
	cout << "Enter Stock ID :";
	in >> obj.stockId;
	cout << "Enter Stock QTY :";
	in >> obj.qty;
	cout << "Enter Product ID :";
	in >> obj.proId;
	cout << "Enter Product Name :";
	in >> obj.proName;
	cout << "Enter User ID :";
	in >> obj.userId;
	cout << "Enter UserName :";
	in >> obj.userName;
	return in;
}

int Stock::operator==(Stock obj)
{
	return stockId == obj.stockId;
}

int Stock::operator>(Stock obj)
{
	return stockId > obj.stockId;
}

int Stock::operator=(Stock obj)
{
	this->stockId = stockId;
	strcpy(this->qty, obj.qty);
	strcpy(this->proId, obj.proId);
	strcpy(this->proName, obj.proName);
	strcpy(this->userId, obj.userId);
	strcpy(this->username, obj.username);
}
// definition of class Stock

// template function
template <class Type>
void Insert(Type obj)
{
	cin >> obj;
}

template <class Type>
void Show(Type obj[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << obj[i];
	}
}

template <class Type, class Type1>
int Search(Type obj[], int n, Type1 keyItem)
{
	int i;
	int found = 0;
	for (i = 0; i < n; i++)
		if (obj[i] == keyItem)
		{
			found++;
			break;
		}
	return found == 1 ? i : -1;
}

template <class Type, class Type1>
bool Update(Type obj[], int n, Type1 keyItem)
{
	int found = 0;
	for (int i = 0; i < n; i++)
		if (obj[i] == keyItem)
		{
			found++;
			cout << obj[i];
			cin >> obj[i];
			break;
		}
	return found == 1;
}

template <class Type, class Type1>
bool Delete(Type obj[], int n, Type1 keyItem)
{
	int found = 0;
	for (int i = 0; i < n; i++)
	{
		if (obj[i] == keyItem)
		{
			found++;
			for (int k = i; k < n; k++)
				obj[k] = obj[k + 1];
			break;
		}
	}
	// n--;
	return found == 1;
}

template <class Type>
void Sort(Type obj[], int n)
{
	Type temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (obj[i] > obj[j])
			{
				temp = obj[i];
				obj[i] = obj[j];
				obj[j] = temp;
			}
		}
	}
}

int main()
{
	cout << "Stock Management System" << endl;
	getch();
	return 0;
}