#pragma once

#include<iostream>
#include<fstream>
#include<string>
#include<Windows.h>
using namespace std;

extern int TShopkeeper;
extern int TCustomer;
extern int TProduct;

class Color {
public:
	void setConsoleColor(WORD c)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
	}
};

class AbstractClass
{
public:
	virtual void SignUp() = 0;
	virtual void Display() = 0;
};

class Shopkeeper
{
public:
	string firstName, LastName, sId;
	string Username, Email, Password, RegDate, Gender, BG, ContactNo, Address;

	void DisplayShopkeeper(Shopkeeper shopObj[], int size);
	int SearchShopkeeper(Shopkeeper arr[], int size);
	void ShopArrayFromFile(Shopkeeper arr[], int size);
	void ShopArrayIntoFile(Shopkeeper arr[], int size);
};
/////////////////////////////////////////////////////////////////////////////////////////////////////

class Customer
{
public:
	string fName, lName, cID, cregDate, gen, phoneNo, bloodGroup, customerAddress;
	string  noOfProducts, Category, cUserName, cEmail, cPass;

	void DisplayCustomer(Customer cusObj[], int size);
	int SearchCustomer(Customer arr[], int size);
	void CustomerArrayFromFile(Customer arr[], int size);
	void CustomerArrayIntoFile(Customer arr[], int size);
};

/////////////////////////////////////////////////////////////////////////////////////////////
class Product
{
public:
	string name, categoryName, category, description, quantity, size, color, pID;
	string CatName[5] = { "Sports", "Garments","Eatables", "Medicines", "Fashion" };

	void DisplayProduct(Product ProObj[], int size);
	void ProductArrayFromFile(Product arr[], int size);
	void ProductArrayIntoFile(Product arr[], int size);
	void AddProduct();
	int SearchProduct(Product arr[], int size);
	void EditProduct();
};



class AdminModule :public AbstractClass, public Shopkeeper, public Customer, public Product
{
public:
	AdminModule()
	{
		fstream file;
		string line;
		file.open("Admin.txt", ios::in);
		getline(file, email);
		getline(file, password);
		getline(file, username);
		file.close();
	}
	string username, email, password;
	AdminModule operator =(AdminModule& ob)
	{
		return ob;
	}
	virtual void Display();
	virtual void SignUp();

	bool SignIn();
	void AddShopkeeper();
	void AddCustomer();
	void EditShopkeeper();
	void EditCustomer();
	void DeleteShopkeeper();
	void DeleteCustomer();
	void DeleteProduct();
};

/////////////////////////////////////////////////////////////////////////////////////////////////////

class ShopkeeperModule :public AbstractClass, public Shopkeeper, public Product
{
public:
	virtual void Display();
	virtual void SignUp();

	int SignIn(ShopkeeperModule arr[], int size);
	void ViewProduct();
};
/////////////////////////////////////////////////////////////////////////////

class CustomerModule : public AbstractClass, public Customer, public Product
{
public:
	virtual void SignUp();
	virtual void Display();

	int SignIn(CustomerModule arr[], int size);
	int searchforPurchasing(Product arr[], int size);
	void Purchase(string id);
	void AddtoCart(string id);
	void CheckOut(string id);
};

class B
{
public:
	int ProductCount();
	int CustomerCount();
	int ShopKeeperCount();

	void CustomerArray(CustomerModule CusObj[], int count);
	void ShopkeeperArray(ShopkeeperModule ShopObj[], int count);
};
