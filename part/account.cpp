#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>
#include <cctype>
#include <limits>
#include<conio.h>
using namespace std;
string currentAccount;
string lowercase(const string& str) {
    string result;
    for (char ch : str) {
        result += tolower(ch);
    }
    return result;
}
class Person {
private:
    string full_name;
    string cccd;
    string date_of_birth;
    string phone_number;
    string email;
    string account;
    string password;
public:
	string type;
    // Constructor
    Person() {
    	type = "User";
        full_name = "";
        cccd = "";
        date_of_birth = "";
        phone_number = "";
        email = "";
        account = "";
        password = "";
    }
	virtual ~Person() {}
    // Getter methods
    string getFullname() {
        return full_name;
    }
    string getCCCD() {
        return cccd;
    }
    string getDateOfBirth() {
        return date_of_birth;
    }
    string getPhoneNumber() {
        return phone_number;
    }
    string getEmail() {
        return email;
    }
    string getAccount() {
        return account;
    }
    string getPassword() {
        return password;
    }
    // Setter methods (if needed)
    void setFullname(string& name) {
        full_name = name;
    }
    void setCCCD(string& cccdNumber) {
        cccd = cccdNumber;
    }
    void setDateOfBirth(string& dob) {
        date_of_birth = dob;
    }
    void setPhoneNumber(string& phone) {
        phone_number = phone;
    }
    void setEmail(string& emailAddress) {
        email = emailAddress;
    }
    void setAccount(string& acc) {
        account = acc;
    }
    void setPassword(string& pass) {
        password = pass;
	}
    // Other member functions as needed
    virtual void print_info() {
    	cout << "----------------------------------------" << endl;
    	cout << setw(15) << left << "Account type: " << type << endl;
        cout << setw(15) << left << "Full Name: " << full_name << endl;
        cout << setw(15) << left << "CCCD: " << cccd << endl;
        cout << setw(15) << left << "Date of Birth: " << date_of_birth << endl;
        cout << setw(15) << left << "Phone Number: " << phone_number << endl;
        cout << setw(15) << left << "Email: " << email << endl;
        cout << setw(15) << left << "Username: " << account << endl;
    }
    virtual void input(vector<Person*> &people) {
		string temp;
		cout << "Enter full name: ";
	    getline(cin, temp);
	    setFullname(temp);
	    cout << "Enter CCCD: ";
	    getline(cin, temp);
	    setCCCD(temp);
	    cout << "Enter date of birth (yyyy.mm.dd): ";
	    getline(cin, temp);
	    setDateOfBirth(temp);
	    cout << "Enter phone number: ";
	    getline(cin, temp);
	    setPhoneNumber(temp);
	    cout << "Enter email: ";
	    getline(cin, temp);
	    setEmail(temp);
	    cout << "Enter username: ";
	    while(1) {
	    	bool found = false;
	    	getline(cin, temp);
	    	for (int i=0;i<people.size();i++) {
	    		if (temp == people[i]->getAccount()) found = true;
			}
			if (found == false) break;
			else cout << "Username already exist. Please enter another username: ";
		}
	    setAccount(temp);
	    cout << "Enter password: ";
	    getline(cin, temp);
	    setPassword(temp);
	}
};

class Student : public Person {
private:
    string student_id;
    string class_name;
    string cohort;
    string school;
public:
    // Constructor
    Student() {
        student_id = "";
        class_name = "";
        cohort = "";
        school = "";
		type = "Student";
    }
    // Getter
    string getStudentID() {
        return student_id;
    }
    string getClassName() {
        return class_name;
    }
    string getCohort() {
        return cohort;
    }
    string getSchool() {
        return school;
    }
    // Setter
    void setStudentID(string& id) {
        student_id = id;
    }
    void setClassName(string& className) {
        class_name = className;
    }
    void setCohort(string& cohortValue) {
        cohort = cohortValue;
    }
    void setSchool(string& schoolName) {
        school = schoolName;
    }
    void print_info() override {
        Person::print_info(); // Call the base class print_info first
        cout << setw(15) << left << "Student ID: " << student_id << endl;
        cout << setw(15) << left << "Class Name: " << class_name << endl;
        cout << setw(15) << left << "Cohort: " << cohort << endl;
        cout << setw(15) << left << "School: " << school << endl;
    }
    virtual void input(vector<Person*> &people) {
		string temp;
		Person::input(people);
		cout << "Enter StudentID: ";
	    getline(cin, temp);
	    setStudentID(temp);
		cout << "Enter class name: ";
	    getline(cin, temp);
	    setClassName(temp);
	    cout << "Enter cohort: ";
	    getline(cin, temp);
	    setCohort(temp);
	    cout << "Enter School: ";
	    getline(cin, temp);
	    setSchool(temp);	    
	}
};

class Staff : public Person {
private:
    string staff_id;
    string school;
    string department;
public:
    Staff() {
        staff_id = "";
        school = "";
        department = "";
		type = "Staff";
    }
    // Getter
    string getStaffID() {
        return staff_id;
    }
    string getSchool() {
        return school;
    }
    string getDepartment() {
        return department;
    }
    // Setter
    void setStaffID(string& id) {
        staff_id = id;
    }
    void setSchool(string& schoolName) {
        school = schoolName;
    }
    void setDepartment(string& departmentName) {
        department = departmentName;
    }
    //
    void print_info() override {
        Person::print_info();
        cout << setw(15) << left << "Staff ID: " << staff_id << endl;
        cout << setw(15) << left << "Department: " << department << endl;
        cout << setw(15) << left << "School: " << school << endl;
    }
    virtual void input(vector<Person*> &people) {
		string temp;
		Person::input(people);
		cout << "Enter StaffID: ";
	    getline(cin, temp);
	    setStaffID(temp);
	    cout << "Enter Department: ";
	    getline(cin, temp);
	    setDepartment(temp);
		cout << "Enter School: ";
	    getline(cin, temp);
	    setSchool(temp);
	}
	//
	void createAdminAccount(vector<Person*> &people) {
		cout << "Enter account type (U for User | S for Student | F for Staff | C for cancel): ";
		while(1) {
		string c; getline(cin,c);
		if (lowercase(c) == "u") {
			Person* ptr = new Person();
			ptr->input(people);
			people.push_back(ptr);
			cout << "Successful!" << endl;
			return;
		}
		else if (lowercase(c) == "s") {
			Student* ptr = new Student();
			ptr->input(people);
			people.push_back(ptr);
			cout << "Successful!" << endl;
			return;
		}
		else if (lowercase(c) == "f") {
			Staff* ptr = new Staff();
			ptr->input(people);
			people.push_back(ptr);
			cout << "Successful!" << endl;
			return;
		}
		else if (lowercase(c) == "c") {
			cout << "Cancel!" << endl;
			return;
		} else {
			cout << "Invalid input. Try again: ";
		}
	}
	}
	void listUser(vector<Person*> &people) {
		cout << "---------------Existed account--------------- " << endl;
		for (int i=0;i<people.size();i++) {
			if (people[i]->type == "User") {
				cout << setw(20) << left << "\033[33mUser\033[0m" << people[i]->getAccount() << endl;
				cout << people[i]->getFullname() << endl;
			}
			if (people[i]->type == "Student") {
				auto student = dynamic_cast<Student*>(people[i]);
				cout << setw(20) << left << "\033[32mStudent\033[0m" << student->getAccount() << endl;
				cout << student->getFullname() << endl;
				cout << student->getStudentID() << endl;
				cout << student->getClassName() << endl;
				cout << student->getCohort() << endl;
				cout << student->getSchool() << endl;
			}
			if (people[i]->type == "Staff") {
				auto staff = dynamic_cast<Staff*>(people[i]);
				cout << setw(20) << left << "\033[31mStaff\033[0m" << staff->getAccount() << endl;
				cout << staff->getFullname() << endl;
				cout << staff->getStaffID() << endl;
				cout << staff->getDepartment() << endl;
				cout << staff->getSchool() << endl;
			}
			cout << "---------------------------------------------" << endl;
		}
	}
};

// Function to save data to a text file
void saveDataToFile(vector<Person*>& people) {
    ofstream outFile("account_list.txt");
    if (!outFile.is_open()) {
        cerr << "Error: Unable to open file for writing." << endl;
        return;
    }

    for (auto& person : people) {
        outFile << person->type << ",";
        outFile << person->getFullname() << ",";
        outFile << person->getCCCD() << ",";
        outFile << person->getDateOfBirth() << ",";
        outFile << person->getPhoneNumber() << ",";
        outFile << person->getEmail() << ",";
        outFile << person->getAccount() << ",";
        outFile << person->getPassword();

        if (person->type == "Student") {
            auto student = dynamic_cast<Student*>(person);
            outFile << "," << student->getStudentID() << ",";
            outFile << student->getClassName() << ",";
            outFile << student->getCohort() << ",";
            outFile << student->getSchool();
        } else if (person->type == "Staff") {
            auto staff = dynamic_cast<Staff*>(person);
            outFile << "," << staff->getStaffID() << ",";
            outFile << staff->getSchool() << ",";
            outFile << staff->getDepartment();
        }
        outFile << endl;
    }
    outFile.close();
}

// Function to read data from a text file and append to the vector
void readDataFromFile(vector<Person*>& people) {
    ifstream inFile("account_list.txt");
    if (!inFile.is_open()) {
        cout << "Error: Unable to open file for reading." << endl;
        return;
    }
	string line;
    while (getline(inFile, line)) {
        stringstream ss(line);
        string type, fullname, cccd, dob, phone, email, account, password;

        getline(ss, type, ',');
        getline(ss, fullname, ',');
        getline(ss, cccd, ',');
        getline(ss, dob, ',');
        getline(ss, phone, ',');
        getline(ss, email, ',');
        getline(ss, account, ',');
        getline(ss, password, ',');

        Person* person = nullptr;
		if (type == "User") {
            person = new Person();
            Student* student = new Student();
            person->setFullname(fullname);
            person->setCCCD(cccd);
            person->setDateOfBirth(dob);
            person->setPhoneNumber(phone);
            person->setEmail(email);
            person->setAccount(account);
            person->setPassword(password);
        } else if (type == "Student") {
            string studentID, className, school, cohort;

            getline(ss, studentID, ',');
            getline(ss, className, ',');
            getline(ss, cohort, ',');
            getline(ss, school);

            Student* student = new Student();
            student->setFullname(fullname);
            student->setCCCD(cccd);
            student->setDateOfBirth(dob);
            student->setPhoneNumber(phone);
            student->setEmail(email);
            student->setAccount(account);
            student->setPassword(password);
            student->setStudentID(studentID);
            student->setClassName(className);
            student->setCohort(cohort);
            student->setSchool(school);

            person = student;
        } else if (type == "Staff") {
            string staffID, school, department;

            getline(ss, staffID, ',');
            getline(ss, school, ',');
            getline(ss, department);

            Staff* staff = new Staff();
            staff->setFullname(fullname);
            staff->setCCCD(cccd);
            staff->setDateOfBirth(dob);
            staff->setPhoneNumber(phone);
            staff->setEmail(email);
            staff->setAccount(account);
            staff->setPassword(password);
            staff->setStaffID(staffID);
            staff->setSchool(school);
            staff->setDepartment(department);

            person = staff;
        }
        if (person != nullptr) {
            people.push_back(person);
        }
    }
    cout << "Loaded" << endl;
    inFile.close();
}

void createAccount(vector<Person*> &people) {
	cout << "Input account type (U for User | S for Student | C for Cancel): ";
	while(1) {
		string c; getline(cin,c);
		if (lowercase(c) == "u") {
			Person* ptr = new Person();
			ptr->input(people);
			people.push_back(ptr);
			cout << "Successful!" << endl;
			return;
		}
		else if (lowercase(c) == "s") {
			Student* ptr = new Student();
			ptr->input(people);
			people.push_back(ptr);
			cout << "Successful!" << endl;
			return;
		}
		else if (lowercase(c) == "c") {
			cout << "Cancel!" << endl;
			return;
		} else {
			cout << "Invalid input. Try again: ";
		}
	}
}
string asterisk (string &pass) {
	char ch;
	while (true) {
	    ch = _getch(); // Get a character without echoing it to the console
	
	    if (ch == 13) { // Check if the Enter key is pressed
	        break;
	    } else if (ch == 8 && !pass.empty()) { // Check if Backspace is pressed
	        cout << "\b \b"; // Move the cursor back, print a space, move back again
	        pass.pop_back();
	    } else if (isprint(ch)) { // Check if the character is printable
	        cout << '*';
	        pass += ch;
	    }
    }
    return pass;
}
void login(vector<Person*> &people) {
	string u, pass = ""; char ch;
	bool access = false;
	while(1) {
		cout << setw(40) << left << "" << "\033[36m----------------------------------------------------------\033[0m" << endl;
		cout << setw(66) << left << "" << "\033[32mLOG IN\033[0m" << endl;
		cout << setw(40) << left << "" << "\033[36m----------------------------------------------------------\033[0m" << endl;
		cout << setw(40) << left << "" << "Username: ";
		getline(cin,u);
		cout << setw(40) << left << "" << "Password: ";
		asterisk(pass);
		for (int i=0;i<people.size();i++) {
			if (people[i]->getAccount() == u && people[i]->getPassword() == pass) {
				access = true;
				currentAccount = people[i]->type;
				break;
			}
		}
		if (access == true) {
			cout << setw(40) << left << "" << "\033[32mLogged in successfully.\033[0m" << endl;
			cout << setw(40) << left << "" << "\033[36m----------------------------------------------------------\033[0m" << endl;
			return;
		}
		else {
			cout << setw(40) << left << "" << "\033[33mInvalid username or password. Please try again.\033[0m" << endl;
			cout << setw(40) << left << "" << "\033[36m----------------------------------------------------------\033[0m" << endl;
		}
	}
}

int main() {
    vector<Person*> people; // Vector to store Person objects
    // Load data from file at the start
    readDataFromFile(people);
    
//	Person* ptr = new Person();
//	people.push_back(ptr);
//	ptr->input();
//	ptr->print_info();
//	ptr = new Student();
//	people.push_back(ptr);
//	ptr->input();
//	ptr->print_info();
//	ptr = new Staff();
//	people.push_back(ptr);
//	ptr->input();
//	ptr->print_info();
//	saveDataToFile(people);
login(people);
cout << currentAccount;
    return 0;
}

