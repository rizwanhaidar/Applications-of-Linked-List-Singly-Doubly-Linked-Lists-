/*
Implementation of Singly
Doubly And Cylic Linked list
Based on The Emploee of some firm
*/
//******************Including Libraries*************************
#include<iostream>

#include<stdio.h>

#include<string>

using namespace std;
//*********************User Defined Class as Date**********************
//******************that will be keeping track of***********************
//******************date of joining of the employee**********************
//*************Variables Having month day and year**********************
//****************With Different Geters ans Setters*********************
//**************And a specialized function to print the date************ 
class Date {
	int day = 0;
	int month = 0;
	int year = 0;

public:
	//default constructor
	Date();
	//overloaded constructor
	Date(int a, int b, int c);
	//setter of day
	void setDay(int d);
	//setter of month
	void setMonth(int m);
	//setter of year
	void setYear(int y);
	//getter of day
	int getDay() const;
	//getter of month
	int getMonth() const;
	//getter of year
	int getYear() const;
	//specialized function to print date
	string getDate() const;
	//destructor
	virtual~Date();
};
Date::Date() {
	day = 0;
	month = 0;
	year = 0;
}
Date::Date(int d, int m, int y) {
	day = d;
	month = m;
	year = y;
}
void Date::setDay(int d) {
	if (d > 0 && d < 32) {
		day = d;
	}
}
void Date::setMonth(int m) {
	if (m > 0 && m < 13) {
		month = m;
	}
}
void Date::setYear(int y) {

	year = y;
}
int Date::getDay() const {
	return day;
}
int Date::getMonth() const {
	return month;
}
int Date::getYear() const {
	return year;
}
string Date::getDate() const {
	string to_ret;

	to_ret = to_string(getDay());
	to_ret = to_ret + "/";
	to_ret = to_ret + to_string(getMonth());
	to_ret = to_ret + "/";
	to_ret = to_ret + to_string(getYear());
	return to_ret;

}
Date::~Date() {

}
//**************Another Used Defined Class named as EMployee**************
//****************Having variables ID, NIC, Date, Salary, Bonus************
//******************that will be keeping track of***********************
//******************Important Details of the employee**********************
//****************With Different Geters ans Setters*********************
//**************And a specialized function to print the date************ 
class Employee {
private:
	//Variables
	string id;
	string NIC;
	Date date;
	int salary;
	int bonus;
public:
	//A default constructor
	Employee() {
		id = "";
		NIC = "";
		date.setDay(0);
		date.setMonth(0);
		date.setYear(0);

		salary = 0;
		bonus = 0;
	}
	//Overloaded constructor
	Employee(string id_, string nic_, int m_, int d_, int y_, int salary_ = 0, int bonus_ = 0) :
		id(id_),
		NIC(nic_),
		date(d_, m_, y_),
		salary(salary_),
		bonus(bonus_) {

		//nothing to be written here
		//As alll the variables have been initialized with
		//in initializor list
	}
	/*
	//a copy constructor
		Employee(Employee& copy_) :
			id(copy_.id),
			NIC(copy_.NIC),
			date(copy_.date),
			salary(copy_.salary),
			bonus(copy_.bonus) {}

			*/
			//setter
	void setid(string ID_) {
		id = ID_;
	}
	//setter
	void setNIC(string nic_) {
		NIC = nic_;
	}
	//setter
	void setdate(Date date_) {

		date.setDay(date_.getDay());
		date.setMonth(date_.getMonth());
		date.setYear(date_.getYear());
	}
	//setter
	void setsalary(int salary_) {
		salary = salary_;
	}
	//setter
	void setbonus(int bonus_) {
		bonus = bonus_;
	}
	//getter
	string getid() {
		return this->id;
	}
	//getter
	string getNic() {
		return this->NIC;
	}
	//getter
	string getdate() {
		return this->date.getDate();
	}
	//getter
	int getsalary() {
		return this->salary;
	}
	//getter
	int getbonus() {
		return this->bonus;
	}
	//A specialized function to print the Employee Details
	void display() {
		cout << "ID Of EMployee: " << id << endl <<
			"NIC of EMployee: " << id << " is \t" << NIC << endl <<
			"Date of joining for employe: " << id << "\t is " << date.getDate() << endl <<
			"Salary of Employee: " << id << "\t is " << salary << endl <<
			"Bonus of EMployee: " << id << "\t is " << bonus << endl << endl;
	}
};

class Node {
public:
	Employee data;
	Node* nextptr;

	Node(Employee data_) {
		data = data_;
		nextptr = NULL;
	}

};

class singlyList {
public:

	Node* head;
	Node* tail;
	Node* cursor;

	int count;
	singlyList() {
		head = NULL;
		tail = NULL;
		cursor = NULL;
		count = 0;
	}

	~singlyList() {
//		Node* temp;
//		while (head->nextptr != nullptr) {
//			temp = head;
//			head = head->nextptr;
//			delete temp;
//		}
//		delete tail;
		//		delete cursor;
		//		delete head;
	}

	void insert(Employee& newdata) {
		Node* temp = new Node(newdata);
		if (head == NULL) {
			head = temp;
			tail = temp;
		}
		else {
			Node* curr = new Node(newdata);
			curr = head;
			while (curr->nextptr != NULL) {
				curr = curr->nextptr;

			}
			curr->nextptr = temp;
			tail = temp;
		}
		count++;

	}

	void remove(string id) {
		if (head) {

			Node* current = head;
			Node* prev = current;
			Node* temp;
			while (current != NULL && current->data.getid() != id) {
				prev = current;
				current = current->nextptr;

			}

			if (current->nextptr != NULL) {
				temp = current;
				prev->nextptr = current->nextptr;
				delete temp;
				count--;
			}
			else {
				prev->nextptr = NULL;
				delete current;
			}
		}

	}

	void updateSalary(int salary, string id) {
		Node* current = head;
		while (current != NULL && current->data.getid() != id) {
			current = current->nextptr;
		}
		if (current != NULL)
			current->data.setsalary(salary);

	}

	void updateBonus(int Bonus, string id) {
		Node* current = head;
		while (current != NULL && current->data.getid() != id) {
			current = current->nextptr;
		}

		if (current) {
			current->data.setbonus(Bonus);
		}
	}

	void clear() {
		Node* current = head;
		Node* temp = current;
		while (current) {
			temp = current;
			current = current->nextptr;
			delete temp;
		}
		if (current) {
			delete current;
		}
		head = NULL;
		tail = NULL;
	}

	bool isEmpty() {
		if (head == NULL) {
			return true;
		}
		return false;
	}

	void sort() {
		if (!isEmpty()) {
			Node* ptr, * s;
			if (head == NULL) {
				cout << "The List is empty" << endl;
				return;
			}
			ptr = head;
			while (ptr != NULL) {
				for (s = ptr->nextptr; s != NULL; s = s->nextptr) {
					if (ptr->data.getsalary() < s->data.getsalary()) {
						swap(ptr->data, s->data);
						//if swap doesnot work you can modify it as
						//value = ptr->data;
						//ptr->data = s->data;
						//s->data = value;
					}
				}
				ptr = ptr->nextptr;
			}
		}
	}

	void display() {
		if (!isEmpty()) {
			Node* temp = head;
			while (temp != NULL) {
				temp->data.display();
				temp = temp->nextptr;
			}

		}
		else {
			cout << "\nError\n";
		}
	}

};

class Noded {
public:
	Employee data;
	Noded* nextptr;

	Noded* preptr;

	Noded(Employee data_) {
		data = data_;
		nextptr = NULL;
		preptr = NULL;

	}

};

class doublyList {
public:

	Noded* head;
	Noded* tail;
	Noded* cursor;

	int count;
	doublyList() {
		head = NULL;
		tail = NULL;
		cursor = NULL;
		count = 0;
	}

	~doublyList() {
//		Noded* temp;
//		while (head->nextptr != nullptr) {
//			temp = head;
//			head = head->nextptr;
//			delete temp;
//		}
//		delete tail;
	}

	void insert(Employee& newdata) {
		Noded* temp = new Noded(newdata);
		if (head == NULL) {
			head = temp;
			tail = temp;
		}
		else {
			Noded* curr = new Noded(newdata);
			curr = head;
			while (curr->nextptr != NULL) {
				curr = curr->nextptr;

			}
			curr->nextptr = temp;
			tail = temp;
			temp->preptr = curr;
			tail->nextptr = NULL;
		}
		count++;

	}

	void remove(string id) {
		if (head) {

			Noded* current = head;
			Noded* prev = current;
			Noded* temp;
			while (current != NULL && current->data.getid() != id) {
				prev = current;
				current = current->nextptr;

			}

			if (current->nextptr != NULL) {
				temp = current;
				prev->nextptr = current->nextptr;
				current->nextptr->preptr = prev;
				delete temp;
				count--;
			}
			else {
				prev->nextptr = NULL;
				current->preptr = NULL;
				delete current;

			}
		}

	}

	void updateSalary(int salary, string id) {
		Noded* current = head;
		while (current != NULL && current->data.getid() != id) {
			current = current->nextptr;
		}
		if (current != NULL)
			current->data.setsalary(salary);

	}

	void updateBonus(int Bonus, string id) {
		Noded* current = head;
		while (current != NULL && current->data.getid() != id) {
			current = current->nextptr;
		}

		if (current) {
			current->data.setbonus(Bonus);
		}
	}

	void clear() {

		Noded* current = head;
		Noded* temp = current;
		while (current) {
			temp = current;
			current = current->nextptr;
			delete temp;

		}
		if (current) {
			delete current;
		}
		head = NULL;
		tail = NULL;
	}
	bool isEmpty() {
		if (head == NULL) {
			return true;
		}
		return false;
	}

	void sort() {
		if (!isEmpty()) {
			Noded* ptr, * s;
			if (head == NULL) {
				cout << "The List is empty" << endl;
				return;
			}
			ptr = head;
			while (ptr != NULL) {
				for (s = ptr->nextptr; s != NULL; s = s->nextptr) {
					if (ptr->data.getsalary() < s->data.getsalary()) {
						swap(ptr->data, s->data);
						//if swap doesnot work you can modify it as
						//value = ptr->data;
						//ptr->data = s->data;
						//s->data = value;
					}
				}
				ptr = ptr->nextptr;
			}
		}
	}

	void display() {
		if (!isEmpty()) {
			Noded* temp = head;
			while (temp != NULL) {
				temp->data.display();
				temp = temp->nextptr;
			}

		}
		else {
			cout << "\nError\n";
		}
	}

};

int main() {

	Employee input1("18i-0001", "012345", 2, 3, 4, 9000, 100);
	Employee input2("18i-0002", "012347", 6, 5, 4, 2500, 700);
	Employee input3("18i-0003", "012349", 12, 23, 4, 300, 600);
	Employee input4("18i-0004", "012351", 4, 5, 6, 5000, 20);

	singlyList mylist;
	mylist.insert(input1);
	mylist.insert(input2);
	mylist.insert(input3);
	mylist.insert(input4);

	cout << endl << "Displaying list..." << endl;
	mylist.display();
	cout << endl;

	mylist.updateSalary(10000, "18i-0002");
	cout << "Updating salary of 18i-0002...." << endl;
	mylist.display();
	cout << endl;

	mylist.updateBonus(500, "18i-0004");
	cout << "Updating bonus of 18i-0004...." << endl;
	mylist.display();
	cout << endl;

	mylist.remove("18i-0003");
	cout << "Removing 18i-0003...." << endl;
	mylist.display();
	cout << endl;

	cout << "Sorting...." << endl;
	mylist.sort();
	mylist.display();

	cout << mylist.isEmpty() << endl;
	cout << "Clearing list..." << endl;
	mylist.clear();
	cout << mylist.isEmpty() << endl;
	cout << endl;
	//**************************************************************
	//***************************Doubly*******************************
	//***************************linked*********************************
	//***************************List*************************************
	cout << "\nDOUBLY stars here\n";
	Employee input5("18i-0005", "012353", 1, 2, 3, 2000, 500);
	Employee input6("18i-0006", "012355", 4, 5, 6, 500, 90);
	Employee input7("18i-0007", "012357", 7, 8, 9, 10, 20);
	Employee input8("18i-0008", "012359", 10, 11, 12, 3000, 560);

	doublyList mylist1;
	mylist1.insert(input5);
	mylist1.insert(input6);
	mylist1.insert(input7);
	mylist1.insert(input8);

	cout << endl << "Displaying list of employee" << endl;
	mylist1.display();
	cout << endl;

	mylist1.updateSalary(10000, "18i-0007");
	cout << "Updating salary of employee 18i-0007...." << endl;
	mylist1.display();
	cout << endl;

	mylist1.updateBonus(65400, "18i-0005");
	cout << "Updating bonus of 18i-0005 employee" << endl;
	mylist1.display();
	cout << endl;

	mylist1.remove("18i-0008");
	cout << "Removing employee 18i-0008 from the list" << endl;
	mylist1.display();
	cout << endl;

	cout << "Sorting the list entered by user" << endl;
	mylist1.sort();
	mylist1.display();

	cout << mylist1.isEmpty() << endl;
	cout << "Clearing list...\n1 output for cleared\n0 output for non cleared " << endl;
	mylist1.clear();
	cout << mylist1.isEmpty() << endl;
	cout << endl;

	return 0;

}