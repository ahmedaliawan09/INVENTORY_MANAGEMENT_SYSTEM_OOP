#include"Header.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

extern int TShopkeeper;
extern int TCustomer;
extern int TProduct;


Color c;

//////////////////////////                 Product          ////////////////////////////////////

void Product::DisplayProduct(Product arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Product Name : " << arr[i].name << endl;
		cout << "Category : " << arr[i].categoryName << endl;
		cout << "Description : " << arr[i].description << endl;
		cout << "Product ID : " << arr[i].pID << endl;
		cout << "Product Size : " << arr[i].size << endl;
		cout << "Product Color : " << arr[i].color << endl;
		cout << "Product Quantity : " << arr[i].quantity << endl;
	}
}
void Product::ProductArrayFromFile(Product arr[], int size)
{
	string line;
	fstream file;
	//Getting data from file
	file.open("product.txt", ios::in);
	for (int i = 0; i < size; i++)
	{
		getline(file, arr[i].name);
		getline(file, arr[i].categoryName);
		getline(file, arr[i].description);
		getline(file, arr[i].pID);
		getline(file, arr[i].size);
		getline(file, arr[i].color);
		getline(file, arr[i].quantity);
	}
	file.close();
}
void Product::ProductArrayIntoFile(Product arr[], int size)
{
	string line;
	fstream file;
	file.open("product.txt", ios::out);
	for (int i = 0; i < size; i++)
	{
		file << arr[i].name << endl << arr[i].categoryName << endl << arr[i].description << endl;
		file << arr[i].pID << endl << arr[i].size << endl;
		file << arr[i].color << endl << arr[i].quantity << endl;
	}
	file.close();
}
void Product::AddProduct()
{
	cout << "Enter Product Name : ";
	cin >> name;
	cout << "Enter Category Name : ";
	cin >> categoryName;
	cout << "\n\n";
	for (int i = 0; i < 5; i++)
	{
		cout << i + 1 << " )\t" << CatName[i] << endl;
	}
	cout << "\nSelect Category : ";
	cin >> category;
	cout << "\nEnter Description : ";
	cin >> description;
	pID = to_string(++TProduct);
	int n = pID.length();
	if (n == 1)
		pID = "0" + category + "000" + pID;
	else if (n == 2)
		pID = "0" + category + "00" + pID;
	else if (n == 3)
		pID = "0" + category + "0" + pID;
	else
		pID = "0" + category + pID;
	cout << "Enter Size : ";
	cin >> size;
	cout << "Enter color : ";
	cin >> color;
	cout << "Enter Quantity : ";
	cin >> quantity;

	//Storing in file
	fstream file;
	file.open("product.txt", ios::app);
	file << name << endl << categoryName << endl << description << endl;
	file << pID << endl << size << endl << color << endl << quantity << endl;
	file.close();
	cout << "Product Added\n";
}
int Product::SearchProduct(Product arr[], int size)
{
	string id;
	cout << "Enter Product ID : ";
	cin >> id;
	for (int i = 0; i < size; i++)
	{
		if (id == arr[i].pID)
			return i;
	}
	cout << "No Such Product Exist\n\n";
	return -1;
}
void Product::EditProduct()
{
	int index = -1;
	Product* arr;
	arr = new Product[TProduct];
	ProductArrayFromFile(arr, TProduct);
	DisplayProduct(arr, TProduct);
	//Editing Data
	while (index == -1)
	{
		index = SearchProduct(arr, TProduct);
		if (index != -1)
		{
			cout << "Enter Name : ";
			cin >> arr[index].name;
			cout << "Enter description : ";
			cin >> arr[index].description;
			cout << "Enter Quantity : ";
			cin >> arr[index].quantity;
			cout << "Enter Size : ";
			cin >> arr[index].size;
			cout << "Enter color : ";
			cin >> arr[index].color;
			cout << "\nProduct Information Updated\n";
			break;
		}
		else
		{
			int ch;
			cout << "1.) Exit\n2.) ReSearch \nEnter : ";
			cin >> ch;
			if (ch == 1)
				break;
		}
	}
	ProductArrayIntoFile(arr, TProduct);
}

//////////////////////////                 Admin          ////////////////////////////////////

void AdminModule::Display()
{
	fstream file;
	string line;
	file.open("Admin.txt", ios::in);
	getline(file, email);
	getline(file, password);
	getline(file, username);
	file.close();

	c.setConsoleColor(FOREGROUND_RED);
	cout << "Admin \n";
	cout << "Email : " << email << endl;
	cout << "Password : " << password << endl;
	cout << "User Name : " << username << endl;
}
void AdminModule::SignUp()
{
	cout << "Admin Can't have more than 1 profile\n";
}
bool AdminModule::SignIn()
{
	string un, ps;
	cout << "Enter UserName : ";
	c.setConsoleColor(FOREGROUND_RED);
	cin >> un;
	c.setConsoleColor(FOREGROUND_GREEN);
	cout << "Enter Password : ";
	c.setConsoleColor(FOREGROUND_RED);
	cin >> ps;
	if (un == username && ps == password) {
		c.setConsoleColor(FOREGROUND_GREEN);
		return true;
	}
	cout << "\nIncorrect UserName or Password\n\n";
	c.setConsoleColor(FOREGROUND_GREEN);
	return false;
}
void AdminModule::AddShopkeeper()
{
	cout << "Enter First Name : ";
	c.setConsoleColor(FOREGROUND_RED);
	cin >> firstName;
	c.setConsoleColor(FOREGROUND_GREEN);
	cout << "Enter Last Name : ";
	c.setConsoleColor(FOREGROUND_RED);
	cin >> LastName;
	sId = to_string(++TShopkeeper);
	c.setConsoleColor(FOREGROUND_GREEN);
	cout << "Id : ";
	c.setConsoleColor(FOREGROUND_RED);
	cout << sId << endl;
	c.setConsoleColor(FOREGROUND_GREEN);
	cout << "Enter User Name : ";
	c.setConsoleColor(FOREGROUND_RED);
	cin >> Username;
	c.setConsoleColor(FOREGROUND_GREEN);
	cout << "Enter Email : ";
	c.setConsoleColor(FOREGROUND_RED);
	cin >> Email;
	c.setConsoleColor(FOREGROUND_GREEN);
	cout << "Enter Password : ";
	c.setConsoleColor(FOREGROUND_RED);
	cin >> Password;
	c.setConsoleColor(FOREGROUND_GREEN);
	cout << "Enter Date of Registration : ";
	c.setConsoleColor(FOREGROUND_RED);
	cin >> RegDate;
	c.setConsoleColor(FOREGROUND_GREEN);
	cout << "Enter Gender : ";
	c.setConsoleColor(FOREGROUND_RED);
	cin >> Gender;
	c.setConsoleColor(FOREGROUND_GREEN);
	cout << "Enter Blood Group : ";
	c.setConsoleColor(FOREGROUND_RED);
	cin >> BG;
	c.setConsoleColor(FOREGROUND_GREEN);
	cout << "Enter Contact Number : ";
	c.setConsoleColor(FOREGROUND_RED);
	cin >> ContactNo;
	c.setConsoleColor(FOREGROUND_GREEN);
	cout << "Enter Address : ";
	c.setConsoleColor(FOREGROUND_RED);
	cin >> Address;
	c.setConsoleColor(FOREGROUND_GREEN);

	//storing to File
	fstream file;
	file.open("shopkeeper.txt", ios::app);
	file << firstName << endl << LastName << endl << sId << endl << Username << endl;
	file << Email << endl << Password << endl << RegDate << endl;
	file << Gender << endl << BG << endl << ContactNo << endl << Address << endl;
	file.close();
	c.setConsoleColor(FOREGROUND_RED);
	cout << "ShopKeeper Added\n";
	c.setConsoleColor(FOREGROUND_GREEN);
}
void AdminModule::AddCustomer()
{
	cout << "Enter First Name : ";
	c.setConsoleColor(FOREGROUND_RED);
	cin >> fName;
	c.setConsoleColor(FOREGROUND_GREEN);
	cout << "Enter Last Name : ";
	c.setConsoleColor(FOREGROUND_RED);
	cin >> lName;
	cID = to_string(++TCustomer);
	c.setConsoleColor(FOREGROUND_GREEN);
	cout << "Enter User Name : ";
	c.setConsoleColor(FOREGROUND_RED);
	cin >> cUserName;
	c.setConsoleColor(FOREGROUND_GREEN);
	cout << "Enter Email : ";
	c.setConsoleColor(FOREGROUND_RED);
	cin >> cEmail;
	c.setConsoleColor(FOREGROUND_GREEN);
	cout << "Enter Password : ";
	c.setConsoleColor(FOREGROUND_RED);
	cin >> cPass;
	c.setConsoleColor(FOREGROUND_GREEN);
	cout << "Enter Registration D : ";
	c.setConsoleColor(FOREGROUND_RED);
	cin >> cregDate;
	c.setConsoleColor(FOREGROUND_GREEN);
	cout << "Enter Gender : ";
	c.setConsoleColor(FOREGROUND_RED);
	cin >> gen;
	c.setConsoleColor(FOREGROUND_GREEN);
	cout << "Enter Blood Group : ";
	c.setConsoleColor(FOREGROUND_RED);
	cin >> bloodGroup;
	c.setConsoleColor(FOREGROUND_GREEN);
	cout << "Enter Contact Number : ";
	c.setConsoleColor(FOREGROUND_RED);
	cin >> phoneNo;
	c.setConsoleColor(FOREGROUND_GREEN);
	cout << "Enter Address : ";
	c.setConsoleColor(FOREGROUND_RED);
	cin >> customerAddress;
	c.setConsoleColor(FOREGROUND_GREEN);
	cout << "Enter Category of Products : ";
	c.setConsoleColor(FOREGROUND_RED);
	cin >> Category;
	c.setConsoleColor(FOREGROUND_GREEN);
	cout << "Enetr Number of Products : ";
	c.setConsoleColor(FOREGROUND_RED);
	cin >> noOfProducts;
	//storing to File

	fstream file;
	file.open("customer.txt", ios::app);
	file << fName << endl << lName << endl << cID << endl << cUserName << endl;
	file << cEmail << endl << cPass << endl << cregDate << endl;
	file << gen << endl << bloodGroup << endl << phoneNo << endl << customerAddress << endl;
	file.close();
	cout << "Customer Added\n";
	c.setConsoleColor(FOREGROUND_GREEN);
}
void AdminModule::EditShopkeeper()
{
	int index = -1;
	Shopkeeper* arr;
	arr = new Shopkeeper[TShopkeeper];

	ShopArrayFromFile(arr, TShopkeeper);
	DisplayShopkeeper(arr, TShopkeeper);
	while (index == -1)
	{
		index = SearchShopkeeper(arr, TShopkeeper);
		if (index != -1)
		{
			c.setConsoleColor(FOREGROUND_GREEN);
			cout << "Enter First Name : ";
			c.setConsoleColor(FOREGROUND_RED);
			cin >> arr[index].firstName;
			c.setConsoleColor(FOREGROUND_GREEN);
			cout << "Enter Last Name : ";
			c.setConsoleColor(FOREGROUND_RED);
			cin >> arr[index].LastName;
			c.setConsoleColor(FOREGROUND_GREEN);
			cout << "Enter Address : ";
			c.setConsoleColor(FOREGROUND_RED);
			cin >> arr[index].Address;
			c.setConsoleColor(FOREGROUND_GREEN);
			cout << "Enter Contact No. : ";
			c.setConsoleColor(FOREGROUND_RED);
			cin >> arr[index].ContactNo;
			c.setConsoleColor(FOREGROUND_GREEN);
			cout << "Enter UserName : ";
			c.setConsoleColor(FOREGROUND_RED);
			cin >> arr[index].Username;
			c.setConsoleColor(FOREGROUND_GREEN);
			cout << "Enter Email : ";
			c.setConsoleColor(FOREGROUND_RED);
			cin >> arr[index].Email;
			c.setConsoleColor(FOREGROUND_GREEN);
			cout << "Enter Password : ";
			c.setConsoleColor(FOREGROUND_RED);
			cin >> arr[index].Password;
			c.setConsoleColor(FOREGROUND_GREEN);
		}
		else
		{
			c.setConsoleColor(FOREGROUND_GREEN);
			int ch;
			cout << "\n1.) Exit\n2.) ReSearch \nEnter : ";
			c.setConsoleColor(FOREGROUND_RED);
			cin >> ch;
			c.setConsoleColor(FOREGROUND_GREEN);
			if (ch == 1)
				break;
		}
	}
	ShopArrayIntoFile(arr, TShopkeeper);
}
void AdminModule::EditCustomer()
{
	int index = -1;
	Customer* arr;
	arr = new Customer[TCustomer];

	CustomerArrayFromFile(arr, TCustomer);
	DisplayCustomer(arr, TCustomer);

	while (index == -1)
	{
		index = SearchCustomer(arr, TCustomer);
		if (index != -1)
		{
			c.setConsoleColor(FOREGROUND_GREEN);
			cout << "Enter First Name : ";
			c.setConsoleColor(FOREGROUND_RED);
			cin >> arr[index].fName;
			c.setConsoleColor(FOREGROUND_GREEN);
			cout << "Enter Last Name : ";
			c.setConsoleColor(FOREGROUND_RED);
			cin >> arr[index].lName;
			c.setConsoleColor(FOREGROUND_GREEN);
			cout << "Enter Address : ";
			c.setConsoleColor(FOREGROUND_RED);
			cin >> arr[index].customerAddress;
			c.setConsoleColor(FOREGROUND_GREEN);
			cout << "Enter Contact No. : ";
			c.setConsoleColor(FOREGROUND_RED);
			cin >> arr[index].phoneNo;
			c.setConsoleColor(FOREGROUND_GREEN);
			cout << "Enter UserName : ";
			c.setConsoleColor(FOREGROUND_RED);
			cin >> arr[index].cUserName;
			c.setConsoleColor(FOREGROUND_GREEN);
			cout << "Enter Email : ";
			c.setConsoleColor(FOREGROUND_RED);
			cin >> arr[index].cEmail;
			c.setConsoleColor(FOREGROUND_GREEN);
			cout << "Enter Password : ";
			c.setConsoleColor(FOREGROUND_RED);
			cin >> arr[index].cPass;
			c.setConsoleColor(FOREGROUND_GREEN);
			cout << "\nCustomer Information Updated\n";
			break;
		}
		else
		{
			int ch;
			c.setConsoleColor(FOREGROUND_GREEN);
			cout << "\n1.) Exit\n2.) ReSearch \nEnter : ";
			c.setConsoleColor(FOREGROUND_RED);
			cin >> ch;
			if (ch == 1)
				break;
		}

		c.setConsoleColor(FOREGROUND_GREEN);
	}
	CustomerArrayIntoFile(arr, TCustomer);
}
void AdminModule::DeleteShopkeeper()
{
	int index = -1;
	Shopkeeper* arr;
	arr = new Shopkeeper[TShopkeeper];

	ShopArrayFromFile(arr, TShopkeeper);
	DisplayShopkeeper(arr, TShopkeeper);

	while (index == -1)
	{
		index = SearchShopkeeper(arr, TShopkeeper);
		if (index != -1)
		{
			for (int i = index; i < TShopkeeper - 1; i++)
			{
				swap(arr[i], arr[i + 1]);
			}
			c.setConsoleColor(FOREGROUND_RED);
			cout << "Shopkeeper Deleted\n";
			c.setConsoleColor(FOREGROUND_GREEN);
			TShopkeeper--;
			break;
		}
		else
		{
			int ch;
			c.setConsoleColor(FOREGROUND_GREEN);
			cout << "\n1.) Exit\n2.) ReSearch \nEnter : ";
			c.setConsoleColor(FOREGROUND_RED);
			cin >> ch;
			if (ch == 1)
				break;
		}

		c.setConsoleColor(FOREGROUND_GREEN);
	}
	ShopArrayIntoFile(arr, TShopkeeper);
}
void AdminModule::DeleteCustomer()
{
	int index = -1, cont = -1;
	Customer* arr;
	arr = new Customer[TCustomer];
	CustomerArrayFromFile(arr, TCustomer);
	DisplayCustomer(arr, TCustomer);

	while (index == -1)
	{
		cont = index = SearchCustomer(arr, TCustomer);
		if (index != -1)
		{
			TCustomer--;
			c.setConsoleColor(FOREGROUND_RED);
			cout << "\nCustomer Deleted\n";
			c.setConsoleColor(FOREGROUND_GREEN);
			break;
		}
		else
		{
			int ch;
			c.setConsoleColor(FOREGROUND_GREEN);
			cout << "1.) Exit\n2.) ReSearch \nEnter : ";
			cin >> ch;
			if (ch == 1)
				break;
		}
	}
	CustomerArrayIntoFile(arr, TCustomer);
}
void AdminModule::DeleteProduct()
{
	int index = -1;
	Product* arr;
	arr = new Product[TProduct];

	ProductArrayFromFile(arr, TProduct);
	DisplayProduct(arr, TProduct);
	while (index == -1)
	{
		index = SearchProduct(arr, TProduct);
		if (index != -1)
		{
			for (int i = index; i < TProduct - 1; i++)
			{
				swap(arr[i], arr[i + 1]);
			}
			TProduct--;
			c.setConsoleColor(FOREGROUND_RED);
			cout << "\nProduct Deleted\n";
			c.setConsoleColor(FOREGROUND_GREEN);
			break;
		}
		else
		{
			int ch;
			c.setConsoleColor(FOREGROUND_GREEN);
			cout << "1.) Exit\n2.) ReSearch \nEnter : ";
			c.setConsoleColor(FOREGROUND_RED);
			cin >> ch;
			c.setConsoleColor(FOREGROUND_GREEN);
			if (ch == 1)
				break;
		}
	}
	ProductArrayIntoFile(arr, TProduct);
}

////////////////////////////////         Shopkeeper     //////////////////////////////////////////

void Shopkeeper::DisplayShopkeeper(Shopkeeper arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		c.setConsoleColor(FOREGROUND_GREEN);
		cout << "\nShopKeeper : ";
		c.setConsoleColor(FOREGROUND_RED);
		cout << i + 1 << endl << endl;
		c.setConsoleColor(FOREGROUND_GREEN);
		cout << "First Name : ";
		c.setConsoleColor(FOREGROUND_RED);
		cout << arr[i].firstName << endl;
		c.setConsoleColor(FOREGROUND_GREEN);
		cout << "Last Name : ";
		c.setConsoleColor(FOREGROUND_RED);
		cout << arr[i].LastName << endl;
		c.setConsoleColor(FOREGROUND_GREEN);
		cout << "Shopkeeper ID : ";
		c.setConsoleColor(FOREGROUND_RED);
		cout << arr[i].sId << endl;
		c.setConsoleColor(FOREGROUND_GREEN);
		cout << "UserName : ";
		c.setConsoleColor(FOREGROUND_RED);
		cout << arr[i].Username << endl;
		c.setConsoleColor(FOREGROUND_GREEN);
		cout << "Email : ";
		c.setConsoleColor(FOREGROUND_RED);
		cout << arr[i].Email << endl;
		c.setConsoleColor(FOREGROUND_GREEN);
		cout << "Password : ";
		c.setConsoleColor(FOREGROUND_RED);
		cout << arr[i].Password << endl;
		c.setConsoleColor(FOREGROUND_GREEN);
		cout << "Registration Date : ";
		c.setConsoleColor(FOREGROUND_RED);
		cout << arr[i].RegDate << endl;
		c.setConsoleColor(FOREGROUND_GREEN);
		cout << "Gender : ";
		c.setConsoleColor(FOREGROUND_RED);
		cout << arr[i].Gender << endl;
		c.setConsoleColor(FOREGROUND_GREEN);
		cout << "Blood Group ";
		c.setConsoleColor(FOREGROUND_RED);
		cout << arr[i].BG << endl;
		c.setConsoleColor(FOREGROUND_GREEN);
		cout << "Contact Number : ";
		c.setConsoleColor(FOREGROUND_RED);
		cout << arr[i].ContactNo << endl;
		c.setConsoleColor(FOREGROUND_GREEN);
		cout << "Address : ";
		c.setConsoleColor(FOREGROUND_RED);
		cout << arr[i].Address << endl;
		c.setConsoleColor(FOREGROUND_GREEN);
	}
}
int Shopkeeper::SearchShopkeeper(Shopkeeper arr[], int size)
{
	string id;
	c.setConsoleColor(FOREGROUND_GREEN);
	cout << "Enter Shopkeeper ID : ";
	c.setConsoleColor(FOREGROUND_RED);
	cin >> id;
	for (int i = 0; i < size; i++)
	{
		if (arr[i].sId == id)
			return i;
	}
	cout << "No Such Profile Exist\n\nReTry\n";
	c.setConsoleColor(FOREGROUND_GREEN);
	return -1;
}
void Shopkeeper::ShopArrayFromFile(Shopkeeper arr[], int size)
{
	string line;
	fstream file;
	file.open("shopkeeper.txt", ios::in);
	for (int i = 0; i < size; i++)
	{
		getline(file, arr[i].firstName);
		getline(file, arr[i].LastName);
		getline(file, arr[i].sId);
		getline(file, arr[i].Username);
		getline(file, arr[i].Email);
		getline(file, arr[i].Password);
		getline(file, arr[i].RegDate);
		getline(file, arr[i].Gender);
		getline(file, arr[i].BG);
		getline(file, arr[i].ContactNo);
		getline(file, arr[i].Address);
	}
	file.close();
}
void Shopkeeper::ShopArrayIntoFile(Shopkeeper arr[], int size)
{
	string line;
	fstream file;
	file.open("shopkeeper.txt", ios::out);
	for (int i = 0; i < size; i++)
	{
		file << arr[i].firstName << endl << arr[i].LastName << endl << arr[i].sId << endl;
		file << arr[i].Username << endl << arr[i].Email << endl;
		file << arr[i].Password << endl << arr[i].RegDate << endl << arr[i].Gender << endl;
		file << arr[i].BG << endl << arr[i].ContactNo << endl << arr[i].Address << endl;
	}
	file.close();
}

void ShopkeeperModule::Display()
{
	Shopkeeper* arr;
	arr = new Shopkeeper[TShopkeeper];
	ShopArrayFromFile(arr, TShopkeeper);
	DisplayShopkeeper(arr, TShopkeeper);
}
void ShopkeeperModule::SignUp()
{
	sId = to_string(++TShopkeeper);
	string firstName, LastName, sId;
	string Username, Email, Password, RegDate, Gender, BG, ContactNo, Address;
	c.setConsoleColor(FOREGROUND_GREEN);
	cout << "Enter First Name : ";
	c.setConsoleColor(FOREGROUND_RED);
	cin >> firstName;
	c.setConsoleColor(FOREGROUND_GREEN);
	cout << "Enter Last Name : ";
	c.setConsoleColor(FOREGROUND_RED);
	cin >> LastName;
	c.setConsoleColor(FOREGROUND_GREEN);
	cout << "Id : ";
	c.setConsoleColor(FOREGROUND_RED);
	cout << sId << endl;
	c.setConsoleColor(FOREGROUND_GREEN);
	cout << "Enter User Name : ";
	c.setConsoleColor(FOREGROUND_RED);
	cin >> Username;
	c.setConsoleColor(FOREGROUND_GREEN);
	cout << "Enter Email : ";
	c.setConsoleColor(FOREGROUND_RED);
	cin >> Email;
	c.setConsoleColor(FOREGROUND_GREEN);
	cout << "Enter Password : ";
	c.setConsoleColor(FOREGROUND_RED);
	cin >> Password;
	c.setConsoleColor(FOREGROUND_GREEN);
	cout << "Enter Date of Registration : ";
	c.setConsoleColor(FOREGROUND_RED);
	cin >> RegDate;
	c.setConsoleColor(FOREGROUND_GREEN);
	cout << "Enter Gender : ";
	c.setConsoleColor(FOREGROUND_RED);
	cin >> Gender;
	c.setConsoleColor(FOREGROUND_GREEN);
	cout << "Enter Blood Group : ";
	c.setConsoleColor(FOREGROUND_RED);
	cin >> BG;
	c.setConsoleColor(FOREGROUND_GREEN);
	cout << "Enter Contact Number : ";
	c.setConsoleColor(FOREGROUND_RED);
	cin >> ContactNo;
	c.setConsoleColor(FOREGROUND_GREEN);
	cout << "Enter Address : ";
	c.setConsoleColor(FOREGROUND_RED);
	cin >> Address;

	fstream file;
	file.open("shopkeeper.txt", ios::app);
	file << firstName << endl << LastName << endl << sId << endl << Username << endl;
	file << Email << endl << Password << endl << RegDate << endl;
	file << Gender << endl << BG << endl << ContactNo << endl << Address << endl;
	file.close();
	cout << "\nShopKeeper Added\n";
	c.setConsoleColor(FOREGROUND_GREEN);
}
int ShopkeeperModule::SignIn(ShopkeeperModule arr[], int size)
{
	string un, ps;
	c.setConsoleColor(FOREGROUND_GREEN);
	cout << "Enter UserName : ";
	c.setConsoleColor(FOREGROUND_RED);
	cin >> un;
	c.setConsoleColor(FOREGROUND_GREEN);
	cout << "Enter Password : ";
	c.setConsoleColor(FOREGROUND_RED);
	cin >> ps;
	for (int i = 0; i < size; i++)
	{
		if (un == arr[i].Username && ps == arr[i].Password)
			return i;
	}
	c.setConsoleColor(FOREGROUND_RED);
	cout << "No Such Profile for ShopKeeper Exist\n\n";
	c.setConsoleColor(FOREGROUND_GREEN);
	return -1;
}
void ShopkeeperModule::ViewProduct()
{
	Product* arr;
	arr = new Product[TProduct];
	ProductArrayFromFile(arr, TProduct);
	DisplayProduct(arr, TProduct);
}

///////////////////////////////////////          Customer            //////////////////////////////////

void Customer::DisplayCustomer(Customer arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		c.setConsoleColor(FOREGROUND_GREEN);
		cout << "First Name : ";
		c.setConsoleColor(FOREGROUND_RED);
		cout << arr[i].fName << endl;
		c.setConsoleColor(FOREGROUND_GREEN);
		cout << "Last Name : ";
		c.setConsoleColor(FOREGROUND_RED);
		cout << arr[i].lName << endl;
		c.setConsoleColor(FOREGROUND_GREEN);
		cout << "Customer ID : ";
		c.setConsoleColor(FOREGROUND_RED);
		cout << arr[i].cID << endl;
		c.setConsoleColor(FOREGROUND_GREEN);
		cout << "UserName : ";
		c.setConsoleColor(FOREGROUND_RED);
		cout << arr[i].cUserName << endl;
		c.setConsoleColor(FOREGROUND_GREEN);
		cout << "Email : ";
		c.setConsoleColor(FOREGROUND_RED);
		cout << arr[i].cEmail << endl;
		c.setConsoleColor(FOREGROUND_GREEN);
		cout << "Password : ";
		c.setConsoleColor(FOREGROUND_RED);
		cout << arr[i].cPass << endl;
		c.setConsoleColor(FOREGROUND_GREEN);
		cout << "Registration Date : ";
		c.setConsoleColor(FOREGROUND_RED);
		cout << arr[i].cregDate << endl;
		c.setConsoleColor(FOREGROUND_GREEN);
		cout << "Gender : ";
		c.setConsoleColor(FOREGROUND_RED);
		cout << arr[i].gen << endl;
		c.setConsoleColor(FOREGROUND_GREEN);
		cout << "Blood Group : ";
		c.setConsoleColor(FOREGROUND_RED);
		cout << arr[i].bloodGroup << endl;
		c.setConsoleColor(FOREGROUND_GREEN);
		cout << "Contact No. : ";
		c.setConsoleColor(FOREGROUND_RED);
		cout << arr[i].phoneNo << endl;
		c.setConsoleColor(FOREGROUND_GREEN);
		cout << "Address : ";
		c.setConsoleColor(FOREGROUND_RED);
		cout << arr[i].customerAddress << endl;
		c.setConsoleColor(FOREGROUND_GREEN);
	}
}
int Customer::SearchCustomer(Customer arr[], int size)
{
	string id;
	c.setConsoleColor(FOREGROUND_GREEN);
	cout << "Enter Customer ID : ";
	c.setConsoleColor(FOREGROUND_RED);
	cin >> id;
	for (int i = 0; i < size; i++)
	{
		if (id == arr[i].cID)
			return i;
	}
	c.setConsoleColor(FOREGROUND_GREEN);
	cout << "No Such Profile Exist\n\n";
	return -1;
}
void Customer::CustomerArrayFromFile(Customer arr[], int size)
{
	string line;
	fstream file;
	file.open("customer.txt", ios::in);
	for (int i = 0; i < size; i++)
	{
		getline(file, arr[i].fName);
		getline(file, arr[i].lName);
		getline(file, arr[i].cID);
		getline(file, arr[i].cUserName);
		getline(file, arr[i].cEmail);
		getline(file, arr[i].cPass);
		getline(file, arr[i].cregDate);
		getline(file, arr[i].gen);
		getline(file, arr[i].bloodGroup);
		getline(file, arr[i].phoneNo);
		getline(file, arr[i].customerAddress);
	}
	file.close();
}
void Customer::CustomerArrayIntoFile(Customer arr[], int size)
{
	string line;
	fstream file;
	file.open("customer.txt", ios::out);
	for (int i = 0; i < size; i++)
	{
		file << arr[i].fName << endl << arr[i].lName << endl << arr[i].cID << endl;
		file << arr[i].cUserName << endl << arr[i].cEmail << endl << arr[i].cPass << endl;
		file << arr[i].cregDate << endl << arr[i].gen << endl;
		file << arr[i].bloodGroup << endl << arr[i].phoneNo << endl << arr[i].customerAddress << endl;
	}
	file.close();
}

void CustomerModule::SignUp()
{
	string fName, lName, cID, cregDate, gen, phoneNo, bloodGroup, customerAddress, noOfProducts, Category;
	string cUserName, cEmail, cPass, billStatus;


	c.setConsoleColor(FOREGROUND_GREEN);
	cout << "Enter First Name : ";
	c.setConsoleColor(FOREGROUND_RED);
	cin >> fName;
	c.setConsoleColor(FOREGROUND_GREEN);
	cout << "Enter Last Name : ";
	c.setConsoleColor(FOREGROUND_RED);
	cin >> lName;
	c.setConsoleColor(FOREGROUND_GREEN);
	cID = to_string(++TCustomer);
	c.setConsoleColor(FOREGROUND_GREEN);
	cout << "Enter User Name : ";
	c.setConsoleColor(FOREGROUND_RED);
	cin >> cUserName;
	c.setConsoleColor(FOREGROUND_GREEN);
	cout << "Enter Email : ";
	c.setConsoleColor(FOREGROUND_RED);
	cin >> cEmail;
	c.setConsoleColor(FOREGROUND_GREEN);
	cout << "Enter Password : ";
	c.setConsoleColor(FOREGROUND_RED);
	cin >> cPass;
	c.setConsoleColor(FOREGROUND_GREEN);
	cout << "Enter Registration D : ";
	c.setConsoleColor(FOREGROUND_RED);
	cin >> cregDate;
	c.setConsoleColor(FOREGROUND_GREEN);
	cout << "Enter Gender : ";
	c.setConsoleColor(FOREGROUND_RED);
	cin >> gen;
	c.setConsoleColor(FOREGROUND_GREEN);
	cout << "Enter Blood Group : ";
	c.setConsoleColor(FOREGROUND_RED);
	cin >> bloodGroup;
	c.setConsoleColor(FOREGROUND_GREEN);
	cout << "Enter Contact Number : ";
	c.setConsoleColor(FOREGROUND_RED);
	cin >> phoneNo;
	c.setConsoleColor(FOREGROUND_GREEN);
	cout << "Enter Address : ";
	c.setConsoleColor(FOREGROUND_RED);
	cin >> customerAddress;
	c.setConsoleColor(FOREGROUND_GREEN);
	cout << "Enter Category of Products : ";
	c.setConsoleColor(FOREGROUND_RED);
	cin >> Category;
	c.setConsoleColor(FOREGROUND_GREEN);
	cout << "Enetr Number of Products : ";
	c.setConsoleColor(FOREGROUND_RED);
	cin >> noOfProducts;
	c.setConsoleColor(FOREGROUND_GREEN);
	cout << "Bill Paid Status (Yes / No) : ";
	c.setConsoleColor(FOREGROUND_RED);
	cin >> billStatus;

	fstream file;
	file.open("customer.txt", ios::app);
	file << fName << endl << lName << endl << cID << endl << cUserName << endl;
	file << cEmail << endl << cPass << endl << cregDate << endl;
	file << gen << endl << bloodGroup << endl << phoneNo << endl << customerAddress << endl;
	file.close();
	cout << "\nCustomer Added\n\n";
	c.setConsoleColor(FOREGROUND_GREEN);
}
int CustomerModule::SignIn(CustomerModule arr[], int size)
{
	string u, p;
	bool found = false;
	c.setConsoleColor(FOREGROUND_GREEN);
	cout << "Enter UserName : ";
	c.setConsoleColor(FOREGROUND_RED);
	cin >> u;
	c.setConsoleColor(FOREGROUND_GREEN);
	cout << "Enter Password : ";
	c.setConsoleColor(FOREGROUND_RED);
	cin >> p;
	for (int i = 0; i < size; i++)
	{
		if (u == arr[i].cUserName && p == arr[i].cPass)
		{
			cout << "Condition SuccessFul\n";
			return i;
			found = true;
		}
	}
	if (!found)
		cout << "No Such Profile for Admin Exist\n\n";
	c.setConsoleColor(FOREGROUND_GREEN);
	return -1;
}
void CustomerModule::Display()
{
	Customer* arr;
	arr = new Customer[TCustomer];

	CustomerArrayFromFile(arr, TCustomer);
	DisplayCustomer(arr, TCustomer);
}
int CustomerModule::searchforPurchasing(Product arr[], int size)
{
	string id;
	c.setConsoleColor(FOREGROUND_GREEN);
	cout << "Enter Product ID to purchase : ";
	c.setConsoleColor(FOREGROUND_RED);
	cin >> id;
	for (int i = 0; i < size; i++)
	{
		if (id == arr[i].pID)
			return i;
	}
	cout << "No Such Product Exist\n\n";
	c.setConsoleColor(FOREGROUND_GREEN);
	return -1;
}
void CustomerModule::Purchase(string id)
{
	int index = -1, quant = 0;
	Product* arr;
	arr = new Product[TProduct];
	ProductArrayFromFile(arr, TProduct);
	DisplayProduct(arr, TProduct);
	int ch;
	while (index == -1)
	{
		index = searchforPurchasing(arr, TProduct);
		if (index != -1)
		{
			while (true)
			{
				c.setConsoleColor(FOREGROUND_GREEN);
				cout << "Enter Quantity : ";
				c.setConsoleColor(FOREGROUND_RED);
				cin >> quant;
				if (quant > stoi(arr[index].quantity))
				{
					c.setConsoleColor(FOREGROUND_RED);
					cout << "Sorry We don't have enough stock available\n";
					c.setConsoleColor(FOREGROUND_GREEN);
					cout << "1.) ReEnter Quantity \n2.) Skip\n3.) Enter : ";
					c.setConsoleColor(FOREGROUND_RED);
					cin >> ch;
					c.setConsoleColor(FOREGROUND_GREEN);
					if (ch == 2)
						break;
				}
				else
				{
					int q = stoi(arr[index].quantity);
					q -= quant;
					arr[index].quantity = to_string(q);
					fstream filecart;
					filecart.open("addToCart.txt", ios::app);
					if (filecart.is_open())
					{
						c.setConsoleColor(FOREGROUND_RED);
						cout << "Product Added to Cart\n";
						filecart << id << endl;
						filecart << arr[index].name << endl << arr[index].categoryName << endl << arr[index].description << endl;
						filecart << arr[index].pID << endl << arr[index].size << endl << arr[index].color << endl << quant << endl;
					}
					else {
						c.setConsoleColor(FOREGROUND_RED);
						cout << "File not open\n";
					}
					filecart.close();
					c.setConsoleColor(FOREGROUND_GREEN);
					break;
				}
			}
			cout << "\n1.) Continue Shopping \n2.) Exit\nEnter : ";
			c.setConsoleColor(FOREGROUND_RED);
			cin >> ch;
			if (ch == 1)
				index = -1;
			else
				index = 0;
			c.setConsoleColor(FOREGROUND_GREEN);
			break;
		}
		else
		{
			c.setConsoleColor(FOREGROUND_GREEN);
			cout << "\n1.) Exit\n2.) ReSearch \nEnter : ";
			c.setConsoleColor(FOREGROUND_RED);
			cin >> ch;
			c.setConsoleColor(FOREGROUND_GREEN);
			if (ch == 1)
				break;
		}
	}
	ProductArrayIntoFile(arr, TProduct);
}
void CustomerModule::AddtoCart(string id)
{
	int del = 0, ch, index = -1, count = 0;
	string line;
	fstream file;
	file.open("addToCart.txt", ios::in);
	while (getline(file, line))
		count++;
	file.close();
	count /= 8;
	class cart
	{
	public:
		string cid, nam, CatName, des, pid, siz, clr, quant;
	};
	cart* arr;
	arr = new cart[count];
	file.open("addToCart.txt", ios::in);
	for (int i = 0; i < count; i++)
	{
		getline(file, arr[i].cid);
		getline(file, arr[i].nam);
		getline(file, arr[i].CatName);
		getline(file, arr[i].des);
		getline(file, arr[i].pid);
		getline(file, arr[i].siz);
		getline(file, arr[i].clr);
		getline(file, arr[i].quant);
	}
	file.close();
	if (count > 0)
	{
		for (int i = 0; i < count; i++)
		{
			if (id == arr[i].cid)
			{
				c.setConsoleColor(FOREGROUND_GREEN);
				cout << "Product ID : ";
				c.setConsoleColor(FOREGROUND_RED);
				cout << arr[i].cid << endl;
				c.setConsoleColor(FOREGROUND_GREEN);
				cout << "Product Name : ";
				c.setConsoleColor(FOREGROUND_RED);
				cout << arr[i].nam << endl;
				c.setConsoleColor(FOREGROUND_GREEN);
				cout << "Category Name : ";
				c.setConsoleColor(FOREGROUND_RED);
				cout << arr[i].CatName << endl;
				c.setConsoleColor(FOREGROUND_GREEN);
				cout << "Description : ";
				c.setConsoleColor(FOREGROUND_RED);
				cout << arr[i].des << endl;
				c.setConsoleColor(FOREGROUND_GREEN);
				cout << "Product ID  : ";
				c.setConsoleColor(FOREGROUND_RED);
				cout << arr[i].pid << endl;
				c.setConsoleColor(FOREGROUND_GREEN);
				cout << "Size : ";
				c.setConsoleColor(FOREGROUND_RED);
				cout << arr[i].siz << endl;
				c.setConsoleColor(FOREGROUND_GREEN);
				cout << "Color : ";
				c.setConsoleColor(FOREGROUND_RED);
				cout << arr[i].clr << endl;
				c.setConsoleColor(FOREGROUND_GREEN);
				cout << "Quantity : ";
				c.setConsoleColor(FOREGROUND_RED);
				cout << arr[i].quant << endl;
				c.setConsoleColor(FOREGROUND_GREEN);

				cout << "\n1.) Change Quantity \n2.) Delete Product from Cart\n3.) No Changes\nEnter : ";
				c.setConsoleColor(FOREGROUND_RED);
				cin >> ch;
				if (ch == 1)
				{
					int q;
					c.setConsoleColor(FOREGROUND_GREEN);
					cout << "Enter new Quantity : ";
					c.setConsoleColor(FOREGROUND_RED);
					cin >> q;
					c.setConsoleColor(FOREGROUND_GREEN);
					arr[i].quant = to_string(q);
				}
				else if (ch == 2)
				{
					del++;
					for (int j = i; j < count - 1; j++)
					{
						swap(arr[i], arr[i + 1]);
					}
					count--;
					c.setConsoleColor(FOREGROUND_RED);
					cout << "Product Removed from Cart\n";
					c.setConsoleColor(FOREGROUND_GREEN);
				}
				if (ch == 3)
					continue;
			}
		}
		count -= del;
		file.open("addToCart.txt", ios::out);
		for (int i = 0; i < count; i++)
		{
			file << arr[i].cid << endl << arr[i].nam << endl;
			file << arr[i].CatName << endl << arr[i].des << endl << arr[i].pid << endl;
			file << arr[i].siz << endl << arr[i].clr << endl << arr[i].quant << endl;
		}
		file.close();
	}
	else {

		c.setConsoleColor(FOREGROUND_RED);
		cout << "No Product found in cart\n";
		c.setConsoleColor(FOREGROUND_GREEN);
	}
}
void CustomerModule::CheckOut(string id)
{
	int index = -1, count = 0;
	float Bill, amount = 0;
	fstream file;
	string line;
	file.open("addToCart.txt", ios::in);
	while (getline(file, line))
	{
		count++;
	}
	count /= 8;
	class addCart
	{
	public:
		string cid, nam, CatName, des, pid, siz, clr, quant;
	};
	addCart* arr;
	arr = new addCart[count];
	file.close();
	file.open("addToCart.txt", ios::in);
	for (int i = 0; i < count; i++)
	{
		getline(file, arr[i].cid);
		getline(file, arr[i].nam);
		getline(file, arr[i].CatName);
		getline(file, arr[i].des);
		getline(file, arr[i].pid);
		getline(file, arr[i].siz);
		getline(file, arr[i].clr);
		getline(file, arr[i].quant);
	}
	file.close();
	for (int i = 0; i < count; i++)
	{
		if (id == arr[i].cid)
			amount++;
	}
	amount *= 200;
	amount = amount + (0.02 * amount);
	while (true)
	{
		if (amount > 0)
		{
			c.setConsoleColor(FOREGROUND_GREEN);
			cout << "Payable Amount : ";
			c.setConsoleColor(FOREGROUND_RED);
			cout << amount << endl << endl;
			c.setConsoleColor(FOREGROUND_GREEN);
			cout << "Enter Your Amount : ";
			c.setConsoleColor(FOREGROUND_RED);
			cin >> Bill;
			c.setConsoleColor(FOREGROUND_GREEN);
			if (Bill >= amount)
			{
				c.setConsoleColor(FOREGROUND_GREEN);
				cout << "Change Returned : " << Bill - amount << endl;
				file.open("addToCart.txt", ios::out);
				for (int i = 0; i < count; i++)
				{
					if (arr[i].cid == id)
						continue;
					file << arr[i].cid << endl;
					file << arr[i].nam << endl << arr[i].CatName << endl << arr[i].des << endl;
					file << arr[i].pid << endl << arr[i].siz << endl << arr[i].clr << endl << arr[i].quant << endl;
				}
				file.close();
				break;
			}
			else {
				c.setConsoleColor(FOREGROUND_RED);
				cout << "Not Enough Amount\nReEnter \n";
				c.setConsoleColor(FOREGROUND_GREEN);
			}
		}
		else
		{
			c.setConsoleColor(FOREGROUND_RED);
			cout << "Nothing to pay\n";
			c.setConsoleColor(FOREGROUND_GREEN);
			break;
		}
	}
}

////////////////////////////////////////////////////////////////////////

int B::ProductCount()
{
	int count = 0;
	fstream file; string line;
	file.open("product.txt", ios::in);
	if (file.is_open())
		while (getline(file, line))
		{
			count++;
		}
	else {
		c.setConsoleColor(FOREGROUND_RED);
		cout << "File Not Open\n";
		c.setConsoleColor(FOREGROUND_GREEN);
	}
	return count / 7;
}
int B::CustomerCount()
{
	int count = 0;
	fstream file; string line;
	file.open("customer.txt", ios::in);
	if (file.is_open())
		while (getline(file, line))
		{
			count++;
		}
	else {
		c.setConsoleColor(FOREGROUND_RED);
		cout << "File Not Open\n";
		c.setConsoleColor(FOREGROUND_GREEN);
	}
	return count / 11;
}
int B::ShopKeeperCount()
{
	int count = 0;
	fstream file; string line;
	file.open("shopkeeper.txt", ios::in);
	if (file.is_open())
		while (getline(file, line))
		{
			count++;
		}
	else {
		c.setConsoleColor(FOREGROUND_RED);
		cout << "File Not Open\n";
		c.setConsoleColor(FOREGROUND_GREEN);
	}
	return count / 11;
}
void B::CustomerArray(CustomerModule CusObj[], int count)
{
	fstream file;
	string line;
	file.open("customer.txt", ios::in);
	for (int i = 0; i < TCustomer; i++)
	{
		getline(file, CusObj[i].fName);
		getline(file, CusObj[i].lName);
		getline(file, CusObj[i].cID);
		getline(file, CusObj[i].cUserName);
		getline(file, CusObj[i].cEmail);
		getline(file, CusObj[i].cPass);
		getline(file, CusObj[i].cregDate);
		getline(file, CusObj[i].gen);
		getline(file, CusObj[i].bloodGroup);
		getline(file, CusObj[i].phoneNo);
		getline(file, CusObj[i].customerAddress);
	}
	file.close();
}
void B::ShopkeeperArray(ShopkeeperModule ShopObj[], int count)
{
	fstream file;
	string line;
	file.open("shopkeeper.txt", ios::in);
	////  Getting Data from file
	for (int i = 0; i < TShopkeeper; i++)
	{
		getline(file, ShopObj[i].firstName);
		getline(file, ShopObj[i].LastName);
		getline(file, ShopObj[i].sId);
		getline(file, ShopObj[i].Username);
		getline(file, ShopObj[i].Email);
		getline(file, ShopObj[i].Password);
		getline(file, ShopObj[i].RegDate);
		getline(file, ShopObj[i].Gender);
		getline(file, ShopObj[i].BG);
		getline(file, ShopObj[i].ContactNo);
		getline(file, ShopObj[i].Address);
	}
	file.close();
	return;
}