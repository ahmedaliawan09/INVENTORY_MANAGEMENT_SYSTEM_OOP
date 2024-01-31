#include"Header.h"
#include<iostream>
#include<fstream>
#include<string>
#include<Windows.h>
using namespace std;
int TShopkeeper;
int TCustomer;
int TProduct;
void setConsoleColor(WORD c)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
int main(){
	AdminModule AdminObj;
	ShopkeeperModule* ShopKeeperObj;
	CustomerModule* CustomerObj;
	AbstractClass* ptr;
	B obj;
	int choice, index = -1, ch;
	bool flag;
    TShopkeeper = obj.ShopKeeperCount();
	ShopKeeperObj = new ShopkeeperModule[TShopkeeper];
	obj.ShopkeeperArray(ShopKeeperObj, TShopkeeper);
    TCustomer = obj.CustomerCount();
	CustomerObj = new CustomerModule[TCustomer];
	obj.CustomerArray(CustomerObj, TCustomer);
    setConsoleColor(FOREGROUND_RED);
	cout << "////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n";
	cout << "------------------------------------------------------------------------------------------------------------------------\n";
	cout << "------------------------------------------------------------------------------------------------------------------------\n";
	setConsoleColor(FOREGROUND_GREEN);
	cout << "\t\t\t-------->>>>>>INVENTORY<<<<<<<----------------\t\t\t\t\n";
	setConsoleColor(FOREGROUND_RED);
	cout << "------------------------------------------------------------------------------------------------------------------------\n";
	setConsoleColor(FOREGROUND_GREEN);
	cout << "\t\t\t--------->>>>>>MANAGEMENT<<<<<<<----------------\t\t\t\t\n";
	setConsoleColor(FOREGROUND_RED);
	cout << "------------------------------------------------------------------------------------------------------------------------\n";
	setConsoleColor(FOREGROUND_GREEN);
	cout << "\t\t\t-------->>>>>>SYSTEM<<<<<<<<<<<-----------------\t\t\t\t\n";
	setConsoleColor(FOREGROUND_RED);
	cout << "------------------------------------------------------------------------------------------------------------------------\n";
	cout << "////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n";
	TProduct = obj.ProductCount();
	setConsoleColor(FOREGROUND_GREEN);
	while (true){
		cout << "\n\t\t1.) Admin\n\t\t2.) ShopKeeper\n\t\t3.) Customer\n\t\t4.) Exit\n\n\t   Enter : ";
		setConsoleColor(FOREGROUND_RED);
		while (true){
			cin >> choice;
			if (!cin)
			{
				cout << "Enter Integer Only\nReEnter : ";
				cin.clear();
				cin.ignore();
				continue;
			}
			else
				break;
		}
		switch (choice)
		{
		case 1:
			system("cls");
			ptr = new AdminModule;
			ptr->Display();
			setConsoleColor(FOREGROUND_GREEN);
			while (true)
			{
				cout << "\n\n1.) SignIn \n2.) Exit\n\nEnter : ";
				while (true)
				{
					setConsoleColor(FOREGROUND_RED);
					cin >> choice;
					if (!cin)
					{
						cout << "Enter Integer\nEnter again " << endl;
						cin.clear();
						cin.ignore();
						continue;
					}
					else break;
				}
				setConsoleColor(FOREGROUND_GREEN);
				if (choice == 1)
				{
					if (!AdminObj.SignIn())
						continue;
					else
					{
						flag = true;
						while (flag)
						{
							setConsoleColor(FOREGROUND_GREEN);
							cout << "\n1.) Add Shopkeeper \n2.) Add Customer \n3.) Add Product \n4.) Edit Shopkeeper";
							cout << "\n5.) Edit Customer\n6.) Edit Product\n7.) Delete Shopkeeper ";
							cout << "\n8.) Delete Customer\n9.) Delete Product \n10.) Exit\n";
							while (true)
							{
								setConsoleColor(FOREGROUND_RED);
								cin >> ch;
								if (!cin)
								{
									cout << "Enter Integer\nEnter again " << endl;
									cin.clear();
									cin.ignore();
									continue;
								}
								else {
									setConsoleColor(FOREGROUND_GREEN);
									break;
								}
							}
							cout << endl << endl;
							switch (ch)
							{
							case 1:
								AdminObj.AddShopkeeper();
								break;
							case 2:
								AdminObj.AddCustomer();
								break;
							case 3:
								AdminObj.AddProduct();
								break;
							case 4:
								AdminObj.EditShopkeeper();
								break;
							case 5:
								AdminObj.EditCustomer();
								break;
							case 6:
								AdminObj.EditProduct();
								break;
							case 7:
								AdminObj.DeleteShopkeeper();
								break;
							case 8:
								AdminObj.DeleteCustomer();
								break;
							case 9:
								AdminObj.DeleteProduct();
								break;
							case 10:
								flag = false;
								break;
							default:
								setConsoleColor(FOREGROUND_RED);
								cout << "InCorrect Input\n\n";
								setConsoleColor(FOREGROUND_GREEN);
								break;
							}
						}
					}
				}
				else if (choice == 2)
					break;
				else {
					setConsoleColor(FOREGROUND_RED);
					cout << "Enter Correct Input\n";
					setConsoleColor(FOREGROUND_GREEN);
				}
			}
			break;
		case 2:
			system("cls");
			ptr = new ShopkeeperModule;
			ptr->Display();
			while (true)
			{
				setConsoleColor(FOREGROUND_GREEN);
				cout << "1.) Sign Up\n2.) SignIn \n3.) Exit \n\nEnter : ";
				while (true)
				{
					setConsoleColor(FOREGROUND_RED);
					cin >> choice;
					if (!cin)
					{
						cout << "Enter Integer\nEnter again " << endl;
						cin.clear();
						cin.ignore();
						continue;
					}
					else {
						break;
					}

					setConsoleColor(FOREGROUND_GREEN);
				}
				if (choice == 1)
				{
					ptr->SignUp();
					cout << "ShopKeeper Registered Successfully\n";
					TShopkeeper = obj.ShopKeeperCount();
					ShopKeeperObj = new ShopkeeperModule[TShopkeeper];
					obj.ShopkeeperArray(ShopKeeperObj, TShopkeeper);
				}
				else if (choice == 2)
				{
					index = ShopKeeperObj->SignIn(ShopKeeperObj, TShopkeeper);
					if (index == -1)
						continue;
					else
					{
						flag = true;
						while (flag)
						{
							cout << "1.) Add Product \n2.) Edit Product \n3.) View Product \n4.) Exit \nEnter : ";
							while (true)
							{
								cin >> ch;
								if (!cin)
								{
									cout << "Enter Integer\nEnter again " << endl;
									cin.clear();
									cin.ignore();
									continue;
								}
								else break;
							}
							cout << endl << endl;
							switch (ch)
							{
							case 1:
								ShopKeeperObj[index].AddProduct();
								break;
							case 2:
								ShopKeeperObj[index].EditProduct();
								obj.ShopkeeperArray(ShopKeeperObj, TShopkeeper);
								break;
							case 3:
								ShopKeeperObj[index].ViewProduct();
								break;
							case 4:
								flag = false;
								break;
							default:
								cout << "Enter Valid Input\n";
								break;
							}
						}
					}
				}
				else if (choice == 3)
					break;
				else
					cout << "Enter correct Input\n";
			}
			break;
		case 3:
			system("cls");
			ptr = new CustomerModule();
			ptr->Display();
			while (true)
			{
				cout << "1.) Sign Up\n2.) SignIn \n3.) Exit \n\nEnter : ";
				while (true)
				{
					cin >> choice;
					if (!cin)
					{
						cout << "Enter Integer\nEnter again " << endl;
						cin.clear();
						cin.ignore();
						continue;
					}
					else break;
				}
				if (choice == 1)
				{
					ptr->SignUp();
					cout << "Customer Registered Successfully\n";
					TCustomer = obj.CustomerCount();
					CustomerObj = new CustomerModule[TCustomer];
					obj.CustomerArray(CustomerObj, TCustomer);
				}
				else if (choice == 2)
				{
					index = CustomerObj->SignIn(CustomerObj, TCustomer);
					if (index == -1)
						continue;
					else
					{
						flag = true;
						while (flag)
						{
							cout << "\n1.) Purchase a Product \n2.) Add to cart \n3.) Check Out \n4.) Exit \n\nEnter : ";
							while (true)
							{
								cin >> ch;
								if (!cin)
								{
									cout << "Enter Integer\nEnter again " << endl;
									cin.clear();
									cin.ignore();
									continue;
								}
								else break;
							}
							cout << endl << endl;
							switch (ch)
							{
							case 1:
								CustomerObj[index].Purchase(CustomerObj[index].cID);
								break;
							case 2:
								CustomerObj[index].AddtoCart(CustomerObj[index].cID);
								break;
							case 3:
								CustomerObj[index].CheckOut(CustomerObj[index].cID);
								break;
							case 4:
								flag = false;
								break;
							default:
								cout << "Enter Correct Input\n\n";
								break;
							}
						}
					}
				}
				else if (choice == 3)
					break;
				else
				{
					cout << "Enter correct Input\n";
					break;
				}
			}
			break;
		case 4:
			return 0;
		default:
			cout << "Enter Correct Input\n";
			break;
		}
	}
}