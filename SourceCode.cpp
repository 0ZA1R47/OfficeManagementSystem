#include<iostream>
#include<string>
#include<Windows.h>
#include<conio.h>
#include<iomanip>

using namespace std;
#define max 20

class employee
{
public:
	char name[30];
	long int jic;
	char jp[20];
	int ye;
	int age;
};
void Display_employee_info();
int x;
employee pqr[max], tempemp[max];
class admin
{
private:
	int account_balance;
	int monthly_expenses;
	int orderrecived;
	int orderdelevierd;
	int profit;
public:
	void setdata(int x, int y, int z, int w, int d) {
		account_balance = x;
		monthly_expenses = y;
		orderdelevierd = w;
		orderrecived = z;
		profit = d;
	}
	int getaccountbalance()
	{
		return account_balance;
	}
	int getmonthlyexpense()
	{
		return monthly_expenses;
	}
	int getorderdelevired()
	{
		return orderdelevierd;
	}
	int getorderrecived()
	{
		return orderrecived;
	}
	int getprofit()
	{
		return profit;
	}
	void display()
	{
		system("cls");
		cout << "\n\n\n\n\n\n\n\n" << endl;
		cout << "\n\n\t\tCurrent account Balance of the company is : " << setw(7) << account_balance << endl;
		cout << "\n\n\t\tCurrent Monthly expense of the company is : " << setw(7) << monthly_expenses << endl;
		cout << "\n\n\t\tCurrent order recived of the company is   : " << setw(7) << orderrecived << endl;
		cout << "\n\n\t\tCurrent order deleivered of the company is: " << setw(7) << orderdelevierd << endl;
		cout << "\n\n\t\tCurrent profit of the company is          : " << setw(7) << profit << endl;
	}
};

class store : public admin
{
private:
	int storeitem;
	int statics;
public:
	string name;
	int code;
	float price;
	store()
	{

	}
	void material()
	{
		cout << endl;
		cout << endl;
		int c;
		cout << " \n\n\t\tPress 1 If you are having greater than 25% of manufacturing material\n\n\t\tPress 2 if you having less than 25% of the manufacting material" << endl;
		cin >> c;
		if (c == 1)
		{
			cout << "\n\n\t\tThat's Good .Continue your work" << endl;
		}
		else if (c == 2)
		{
			cout << "\n\n\t\tYour Report has been recived and Order team is on the way to take order from you" << endl;

		}
		else
			cout << "\n\n\t\tMake sure you are entering correct option" << endl << "please pay attention " << endl;
	}

	void order()
	{
		cout << endl;
		cout << endl;
		int a;
		cout << "\n\n\t\tPress 1 if all the orders are completed and Target has been achieved";
		cin >> a;
		if (a == 1)
		{
			cout << "\n\n\t\tWe are sastified from your performance" << endl;
		}
		if (a != 1)
		{
			cout << "\n\n\t\tKindly list out the Orders which are pending and problem you are facing and Report it to admin" << endl;

		}

	}
};
store lm[max];
void add()
{
	system("cls");
	cout << "Enter the Number of the items you want to add in Inventory :" << endl;
	cin >> x;
	cout << endl;
	cout << "Enter The Information of the Articles" << endl;
	for (int i = 0; i <= x - 1; i++)
	{
		cout << "Enter the data for " << i + 1 << " Article" << endl;
		cout << "\nEnter the item category  : ";
		cin >> lm[i].name;
		cout << "Enter the item code        : ";
		cin >> lm[i].code;
		cout << "Enter the price of the item: ";
		cin >> lm[i].price;
		cout << endl << endl;
	}
}
void sell_()
{
	char a;
	int i, j;
	float total_price = 0;
	system("cls");
	cout << "\nEnter the item code:";
	cin >> i;
	for (j = 0; j < x; j++)
	{
		if (lm[j].code == i)
		{
			if (lm[j].price == 0)
			{
				cout << "\nSorry.There is no item left in this category.";
				cout << "\nDo you want to buy another item? y\\n" << endl;
				cin >> a;
				if (a == 'y')
				{
					cout << "\nEnter the item code:";
					cin >> i;
					j = -1;
				}
				else if (a == 'Y')
				{
					cout << "\nEnter the item code:";
					cin >> i;
					j = -1;
				}
				else
				{
					if (total_price != 0)
					{
						cout << "\nYour total price is: ";
						cout << total_price << " Rupees" << "\nThank You.";
					}
					cout << "Bye...Bye...";
					break;
				}
			}
			else
			{
				cout << " Item category is: " << lm[j].name;
				cout << "\nItem price is  : " << lm[j].price << "Rupees" << endl;
				total_price += lm[j].price;
				lm[j].price = 0;
				cout << "\nDo you want to buy another item(Y/N):\\n";
				cin >> a;
				if (a == 'y'|| a=='Y')
				{
					cout << "\nEnter the item code:";
					cin >> i;
					j = -1;
				}
				else if (a == 'Y')
				{
					cout << "\nEnter the item code:";
					cin >> i;
					j = -1;
				}
				else
				{
					system("cls");
					cout << "\nYour total price is: ";
					cout << total_price << "Rupees" << "\nThank You.";
					break;
				}
			}
		}
	}
	_getch();
}

void display_()
{
	int i, j = 1;
	system("cls");

	for (i = 0; i < x; i++)
	{
		cout << j << ".Item category is: " << lm[i].name;
		cout << "\n  Item code is    : " << lm[i].code;
		cout << "\n  Item price is   : " << lm[i].price << "Rupees" << endl << endl;
		j++;
	}
	_getch();
};

void storeportal()
{
	int i;
	while (1)
	{
		cout << "\n   What do you want to do?" << endl;
		cout << "\n1: Add items to Inventory.";
		cout << "\n2: Sale an item.";
		cout << "\n3: Display all items.";
		cout << "\n4: Exit" << endl;
		cout << "\n\n Choose a number:";
		cin >> i;

		switch (i)
		{
		case 1:
		{
			add();
			break;
		}
		case 2:
		{
			sell_();
			break;
		}
		case 3:
		{
			display_();
			break;
		}

		case 4:
		{
			cout << "Good Bye! Thank you.";
			break;
		}
		}
		if (i == 4)
			break;
	}
	_getch();

}

class transport : public admin
{
private:
	string Driver_name;
	int id;
	int vechile;
	int inspection;
	int dutyhours;
public:
	transport()
	{
	};
	void driver_input()
	{
		cout << "Enter Driver name : ";
		cin >> Driver_name;
		cout << "Enter Driver Identity Number : ";
		cin >> id;
		cout << "Enter your number of vechile : ";
		cin >> vechile;
		cout << "Enter Inspected Months Passed : ";
		cin >> inspection;
		cout << "Enter Duty Hours : ";
		cin >> dutyhours;
		cout << endl;
	}

	string getOName()
	{
		return Driver_name;
	}
	int getvechile()
	{
		return vechile;
	}
	int getinspection()
	{
		if (inspection > 12)
		{
			cout << "\n\n\t\tThe cars are not more to be used for driving they need to be inspected" << endl;
			cout << "\n\n\t\t Our inspection team is on the way" << endl;
		}
		return inspection;
	}

	int getOID()
	{
		return id;
	}
	int getdutyhours()
	{
		if (dutyhours > 12)
		{
			cout << "\n\n\t\tlife is precious.No more driiving \n\n\t\t shift reffered to second driver" << endl;
		}
		return dutyhours;
	}

	void display()
	{
		system("cls");
		cout << "\n\n\n\n";
		cout << "\n\n\t\tDriver name :                   :" << getOName() << endl;
		cout << "\n\n\t\tDriver ID :                     :" << getOID() << endl;
		cout << "\n\n\t\tTotal vechiles                  :" << getvechile() << endl;
		cout << "\n\n\t\tinspected months for vechile is :" << getinspection() << endl;
		cout << "\n\n\t\tDuty hours are                  :" << getdutyhours() << endl;
	}
};

class Security
{
private:
	int guards;
	string name;
	int id;
	int duty_hours;
	int gate_number;

protected:
	string name2;
	string vehicle;
	string timein;
	string IDcardNo;

public:
	Security()
	{
	}

	void guest_input()
	{
		cout << "Enter your name : ";
		cin >> name2;
		cout << "Enter vehicle registration number  : ";
		cin >> vehicle;
		cout << "Enter your ID card number : ";
		cin >> IDcardNo;
		cout << "Enter going in time : ";
		cin >> timein;
	}

	void setguarddata()
	{
		cout << "Enter Name of Guard" << endl;
		cin >> name;
		cout << "Enter Id of Guard" << endl;
		cin >> id;
		cout << "Enter Duty hours of Guard" << endl;
		cin >> duty_hours;
		cout << "Enter Gate number  of Guard" << endl;
		cin >> gate_number;
		cout << "Enter Number of guards on duty" << endl;
		cin >> guards;
	}

	int getguards()
	{
		return guards;
	}

	string getName()
	{
		return name;
	}

	int getID()
	{
		return id;
	}

	int getHours()
	{
		return duty_hours;
	}

	int getGateNumber()
	{
		return gate_number;
	}

	void display()
	{
		cout << "Gurad on Duty Are : " << getguards() << endl;
		cout << "Name : " << getName() << endl;
		cout << "ID Number : " << getID() << endl;
		cout << "Duty Hours : " << getHours() << endl;
		cout << "Currently on gate " << getGateNumber() << endl;
	}

	void guestslip()
	{
		cout << "Name : " << name2 << endl;
		cout << "Vehicle number : " << vehicle << endl;
		cout << "ID Card Number : " << IDcardNo << endl;
		cout << "Entering Time : " << timein << endl;
		cout << "Allowed by Guard : " << getName() << endl;
	}
};

class CCTV : public Security
{
private:
	int Number_of_Cameras;

public:
	CCTV()
	{
	}

	void setData(int n)
	{
		Number_of_Cameras = n;
	}

	void Cameras()
	{
		int c;
		cout << " Press 1 if all Cameras are working\n Press 2 if any of the Cameras is not working\n";
		cin >> c;
		if (c == 1)
		{
			cout << "OKAY Good... Now keep a close eye and report in case of any unusual activity\n";

		}
		else if (c == 2)
		{
			cout << "Report has been sent to admin. Wait for further orders\n";

		}
		else
			cout << "You are not entering the appropriate number. Kindly recheck\n";
	}

	void activity()
	{
		int a;
		cout << "Press 1 if there is any unusual movement\n";
		cin >> a;
		if (a == 1)
		{
			cout << "Report sent to admin. Keep close eye until further orders\n";

		}
	}
};

class Patrol : public Security
{
private:
	string officer_name;
	int id;
	int guard;
public:
	Patrol()
	{
	}

	void setdata()
	{
		cout << "Enter the name of the patrolling officer" << endl;
		cin >> officer_name;
		cout << "Enter the Id of the patrolling officer " << endl;
		cin >> id;
		cout << "Enter the Number of the patrolling officer" << endl;
		cin >> guard;
	}

	string getOName()
	{
		return officer_name;
	}

	int getOID()
	{
		return id;
	}
	int getguards()
	{
		return guard;
	}

	void display()
	{
		cout << "Patrolling officer name : " << getOName() << endl;
		cout << "Officer ID : " << getOID() << endl;
		cout << "Guards on Duty : " << getguards() + 4 << endl;
		cout << "Guards on patrol : " << getguards() << endl;
	}
};
void adminportal(admin a, transport t, store s)
{
	int j;
	cout << "\n\n\n\n\n\n\n\n\n\n\n \t\t\t|============ WELCOME TO Admin Section ============|";
	_getch();
	do
	{
		system("cls");
		cout << "\n\n\t\t   1. TO VIEW STATISTICS\n\n\t\t   2. STORE MENU\n\n\t\t   3. TRANSPORT MENU";
		cout << "\n\n\t\t   4. To Return To Main Menu" << endl;
		cout << "\n\n=============================================================\n";
		cout << "\n\nEnter Your Choice:";
		cin >> j;
		system("cls");
		switch (j) {
		case 1:
			cout << "Welcome To view statics" << endl;
			cout << "PLEASE WAIT WHILE WE ARE GETTING RECORD READY FOR YOU" << endl;
			cout << endl;
			_getch();
			system("cls");
			a.display();
			_getch();
			break;
		case 2:
			cout << "Welcome To Store menu " << endl;
			cout << "PLEASE WAIT WHILE WE ARE GETTING Things READY FOR YOU" << endl;
			_getch();
			system("cls");
			s.material();
			_getch();
			system("cls");
			s.order();
			_getch();
			system("cls");
			storeportal();
			break;
		case 3:
			cout << "Welcome To Transport menu" << endl;
			t.driver_input();
			_getch();
			system("cls");
			cout << "PLEASE WAIT WHILE WE ARE GETTING Things READY FOR YOU" << endl;
			_getch();
			system("cls");
			t.display();
			_getch();
			break;
		}
	} while (j != 4);
}

void menu()

{
	cout << "\n\n\n\n\n\n\n\n\n\n\n \t\t\t|============ WELCOME TO Employee Record Management Section ============|";
	_getch();
	system("cls");
	cout << "\n\n\t\t   1. TO Create all Employee Data\n\n\t\t   2. To See Employee Data \n\n\t\t   3. To Add New Employee Data\n\n\t\t";
	cout << "   4. TO Delete Employee Data\n\n\t\t   5. To Update Employee Data\n\n\t\t   6. To Search data of Employee\n\n\t\t";
	cout << "   7. To Quit the Employee Management system\n\n\t\t    " << endl;
}


void newentry()

{
	system("cls");
	cout << "        **WELCOME TO EMPLOYEE ENTRY TABLE*     ";
	cout << endl;
	cout << endl;
	cout << "The Maxium Limit of Employee in the Company is 15" << endl;
	cout << endl;
	cout << "Enter the Number of Employees you want to add(1-15)" << endl;
	cin >> x;
	cout << endl;
	cout << "Enter The Below Information of the Employees" << endl;
	for (int i = 0; i <= x - 1; i++)
	{
		cout << "Enter the data for" << i + 1 << "Employee" << endl;
		cout << endl << endl;
		cout << "Name  :";
		cin.getline(pqr[i].name, 30);
		cin.getline(pqr[i].name, 30);
		cout << "Job Identity Code : ";
		cin >> pqr[i].jic;
		cout << "Job Post :";
		cin >> pqr[i].jp;
		cout << "Years of Experience : ";
		cin >> pqr[i].ye;
		cout << "Age : ";
		cin >> pqr[i].age;
		cout << endl << endl << endl;
	}
	cout << "going to main menu";
	Sleep(500);
}


void  list()
{
	system("cls");
	cout << "       **Employee Record Table*" << endl;
	cout << "  Name             Job Identity Code      Job Post      Years(EXP)      Age " << endl;
	cout << "   ---------------------------------------------------------------- " << endl;
	for (int i = 0; i <= x - 1; i++)
	{
		cout << setw(15) << pqr[i].name;
		cout << "\t\t";
		cout << setw(4) << pqr[i].jic;
		cout << "\t\t      ";
		cout << setw(6) << pqr[i].jp;
		cout << "\t\t";
		cout << setw(4) << pqr[i].ye;
		cout << "\t   ";
		cout << setw(2) << pqr[i].age;
		cout << "\t";
		cout << endl;
	}
	cout << "going to main menu";
	_getch();
}

void insert()
{
	system("cls");
	int i = x;
	x += 1;
	cout << "Insert New Record";
	cout << endl;
	cout << endl;
	cout << "You Are Entering Data For " << x << "Employee " << endl;
	cout << "Name  :";
	cin >> pqr[i].name;
	cout << "Job Identity Code : ";
	cin >> pqr[i].jic;
	cout << "Job Post :";
	cin >> pqr[i].jp;
	cout << "Years of Experience : ";
	cin >> pqr[i].ye;
	cout << "Age : ";
	cin >> pqr[i].age;
	cout << endl << endl;
	cout << "going to main menu";
	Sleep(500);
}



void deletes()
{
	system("cls");
	int jic;
	int check = 0;
	cout << "You Want to Delete an Employee Record" << endl;
	cout << endl;
	cout << "Enter a JobCode To Delete That Entry  ";
	cin >> jic;
	int i;
	for (i = 0; i <= x - 1; i++)
	{
		if (pqr[i].jic == jic)
		{
			check = i;
		}
	}
	for (i = 0; i <= x - 1; i++)
	{
		if (i == check)
		{
			continue;
		}
		else
		{
			if (i > check)
			{
				tempemp[i - 1] = pqr[i];
			}
			else
			{
				tempemp[i] = pqr[i];
			}
		}
	}
	x--;
	for (i = 0; i <= x - 1; i++)
	{
		pqr[i] = tempemp[i];
	}
	cout << "Record Deleted sucessfully" << endl;
	_getch();
	system("cls");
}


void edit()
{
	system("cls");
	int jobcode;
	cout << "You Want to Update an Employee Entry Record ";
	cout << endl << endl;
	int i;
	void editmenu();
	void editname(int);
	void editcode(int);
	void editjp(int);
	void editexp(int);
	void editage(int);
	char option;
	cout << "Enter An jobcode To Edit An Entry----  ";
	cin >> jobcode;
	editmenu();
	for (i = 0; i <= x - 1; i++)
	{
		if (pqr[i].jic == jobcode)
		{
			while ((option = cin.get()) != 'q')
			{
				switch (option)
				{
				case 'N':
					editname(i);
					break;
				case 'C':
					editcode(i);
					break;
				case 'J':
					editjp(i);
					break;
				case 'E':
					editexp(i);
					break;
				case 'A':
					editage(i);
					break;
				}
				editmenu();
			}
		}
	}
	cout << "Record Updated SucessFully" << endl;
	_getch();
	system("cls");
}

void editmenu()
{
	system("cls");
	cout << "          N=> To Edit Name " << endl;
	cout << "          C=> To Edit Job Identity Code " << endl;
	cout << "          J=> To Edit Job Post" << endl;
	cout << "          E=> To Edit Experience " << endl;
	cout << "          A=> To Edit Age        " << endl;
	cout << "          Q=> To  QUIT           " << endl;
	cout << " Select What You Want to Update and Enter Correct Option  : " << endl;
}

void editname(int i)

{

	cout << "Enter New Name  : " << endl;

	cin >> pqr[i].name;

}

void editcode(int i)

{

	cout << "Enter New Job Job Identity Code-  :" << endl;

	cin >> pqr[i].jic;

}

void editjp(int i)

{

	cout << "Enter new Job Post  :  " << endl;

	cin >> pqr[i].jp;

}

void editexp(int i)

{

	cout << "Enter new Years of Experience  : " << endl;

	cin >> pqr[i].ye;

}

void editage(int i)

{

	cout << "Enter new Age  :  " << endl;

	cin >> pqr[i].age;

}


void search()

{

	system("cls");
	cout << "Welcome To Search Of Employee ";
	cout << endl << endl;
	int jobcode;
	cout << "You Can Search Only By Jobcode Of An Employee" << endl << endl;

	cout << "Enter Job Identity Code Of An Employee" << endl;
	cin >> jobcode;
	for (int i = 0; i <= x - 1; i++)

	{

		if (pqr[i].jic == jobcode)

		{
			cout << "       **Employee Record Table*" << endl;
			cout << "  Name        Job Identity Code      Job Post      Years(EXP)      Age " << endl;
			cout << "   ---------------------------------------------------------------- " << endl;
			cout << pqr[i].name;
			cout << "\t\t";
			cout << setw(4) << pqr[i].jic;
			cout << "\t\t      ";
			cout << setw(6) << pqr[i].jp;
			cout << "\t\t";
			cout << setw(4) << pqr[i].ye;
			cout << "\t   ";
			cout << setw(2) << pqr[i].age;
			cout << "\t";
			cout << endl;

		}
	}

	cout << "going to main menu";

	_getch();



}
void portalemployee()
{
	int option;
	do

	{
		menu();
		cin >> option;
		switch (option)

		{

		case 1:

			newentry();

			break;

		case 2:

			list();

			break;

		case 3:

			insert();

			break;

		case 4:

			deletes();

			break;

		case 5:

			edit();

			break;

		case 6:

			search();

			break;



		}
		system("cls");
	}

	while (option != 7);
}
void adminportal()
{
	int option;
	do

	{
		menu();
		cin >> option;
		switch (option)

		{

		case 1:

			newentry();

			break;

		case 2:

			list();

			break;

		case 3:

			insert();

			break;

		case 4:

			deletes();

			break;

		case 5:

			edit();

			break;

		case 6:

			search();

			break;



		}
		system("cls");
	}

	while (option != 7);
}
void securityportal(Security sc, CCTV cv, Patrol pt)
{
	int j;
	cout << "\n\n\n\n\n\n\n\n\n\n\n \t\t\t|============ WELCOME TO Security Section ============|";
	_getch();
	do
	{
		system("cls");
		cout << "\n\n\t\t   1. TO VIEW Guards Status\n\n\t\t   2. To Go to CCtv Section\n\n\t\t   3.To Patrol section";
		cout << "\n\n\t\t   4. To Return To Main Menu" << endl;
		cout << "\n\n=============================================================\n";
		cout << "\n\nEnter Your Choice:";
		cin >> j;
		system("cls");
		switch (j) {
		case 1:
			cout << "Welcome To Guards section" << endl;
			sc.setguarddata();
			system("cls");
			cout << "PLEASE WAIT WHILE WE ARE GETTING RECORD READY FOR YOU" << endl;
			cout << endl;
			_getch();
			system("cls");

			sc.display();
			_getch();
			system("cls");
			cout << "Welcome To guest Entry Setup and slip generation Section" << endl;
			sc.guest_input();
			_getch();
			system("cls");
			sc.guestslip();
			_getch();
			system("cls");
			break;
		case 2:
			cout << "Welcome To CCTV menu " << endl;
			cout << "PLEASE WAIT WHILE WE ARE GETTING Things READY FOR YOU" << endl;
			_getch();
			system("cls");
			cv.setData(9);
			cv.Cameras();
			_getch();
			system("cls");
			cv.activity();
			_getch();
			break;
		case 3:
			cout << "Welcome To Security Patrol Section" << endl;
			cout << "PLEASE WAIT WHILE WE ARE GETTING Things READY FOR YOU" << endl;
			_getch();
			system("cls");
			pt.setdata();
			pt.display();
			_getch();
			break;
		}
	} 
	while (j != 4);
}
void Display_employee_info()
{
	int jobcode;
	cout << "Enter Job Identity Code Of An Employee" << endl;
	cin >> jobcode;
	for (int i = 0; i <= x - 1; i++)

	{

		if (pqr[i].jic == jobcode)

		{
			cout << "       **Employee Record Table*" << endl;
			cout << "  Name        Job Identity Code      Job Post      Years(EXP)      Age " << endl;
			cout << "   ---------------------------------------------------------------- " << endl;
			cout << pqr[i].name;
			cout << "\t\t";
			cout << setw(4) << pqr[i].jic;
			cout << "\t\t      ";
			cout << setw(6) << pqr[i].jp;
			cout << "\t\t";
			cout << setw(4) << pqr[i].ye;
			cout << "\t   ";
			cout << setw(2) << pqr[i].age;
			cout << "\t";
			cout << endl;

		}
	}

	cout << "going to main menu";

	_getch();



}





int main()

{
	Security sc;
	admin a;
	transport t;
	store l;
	CCTV cv;
	Patrol pt;
	int j;
	cout << "\n\n\n\n\n\n\n\n\n\n\n \t\t\t|============Office Management and Survillance System  ============|";
	_getch();
	system("cls");
	do
	{
		system("cls");
		cout << "\n\t\t   Welcome To Main Menu \n";
		cout << "=============================================================";
		cout << "\n\n\t\t   1. TO ADMIN SECTION\n\n\t\t   2. SECURITY SECTION\n\n\t\t   3. EMPLOYEE RECORD SECTION";
		cout << "\n\n\t\t   4. To Exit The Program" << endl;
		cout << "\n\n=============================================================\n";
		cout << "\n\nEnter Your Choice:";
		cin >> j;
		system("cls");
		if (j == 3)
		{
			string x = "";
			char p;
			cout << "Enter Secret login Password :\n";
			p = _getch();
			while (p != 13)
			{
				x.push_back(p);
				cout << '*';
				p = _getch();
			}
			if (x == "Employee1234") {
				cout << endl;
				cout << "\n\n\n\n\n";
				cout << "*Access granted*\n";
				_getch();
				system("cls");
				portalemployee();
			}
			else {
				cout << "**Access aborted**\n";
				cout << "---------Authorized Person only-----------\n";
			}
		}
		if (j == 1)
		{
			a.setdata(1200000, 12304, 98, 23, 200000);
			{string x = "";
			char p;
			cout << "Enter Secret login Password :\n";
			p = _getch();
			while (p != 13)
			{
				x.push_back(p);
				cout << '*';
				p = _getch();
			}
			if (x == "Admin1234") {
				cout << endl;
				cout << "\n\n\n\n\n";
				cout << "*Access granted*\n";
				_getch();
				system("cls");
				adminportal(a, t, l);
			}
			else 
			{
				cout << "**Access aborted**\n";
				cout << "---------Authorized Person only-----------\n";
			}
			}
		}
		if (j == 2)
		{
			string x = "";
			char p;
			cout << "Enter Secret login Password :\n";
			p = _getch();
			while (p != 13)
			{
				x.push_back(p);
				cout << '*';
				p = _getch();
			}
			if (x == "Security1234") {
				cout << endl;
				cout << "\n\n\n\n\n";
				cout << "*Access granted*\n";
				_getch();
				system("cls");
				securityportal(sc, cv, pt);
			}
			else {
				cout << "**Access aborted**\n";
				cout << "---------Authorized Person only-----------\n";
			}
		}
	} 
	while (j != 4);
	system("pause");
	return 0;
}
