#include<iostream>
#include<string>		
#include<vector>		// vector
#include<iomanip>		// for std::setw(n), std::setfill(ch), std::left, std::right
#include<sstream>		// stringstrean
#include<fstream>		// file operations
#include<cctype>		// using tolower() function
#include<limits>
#include<conio.h>		// for _kbhit() and _getch() functions
#include <cstdlib> 		// for exit function

using namespace std;
// Support functions
string lowercase(const string& str) {
    string result;
    for (char ch : str) {
        result += tolower(ch);
    }
    return result;
}
void clearScreen() {
    cout << "\033[2J\033[1;1H";  // ANSI escape sequence to clear screen
}

// Person class
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
    	cout << "\033[33m-------------------------------------\033[0m" << endl;
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
	    cout << "Enter date of birth (dd.mm.yyyy): ";
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
	void changePassword(vector<Person*> &people) {
		cout << "Username you want to change password: ";
		string temp; getline(cin,temp);
		for (int i=0;i<people.size();i++) {
			if(people[i]->getAccount()==temp && people[i]->type != "Staff") {
				cout << "Set new password: ";
				getline(cin,temp);
				people[i]->setPassword(temp);
				cout << "Success!" << endl;
				return;
			}
		}
		cout << "Can't find any user or student with that username." << endl;
	}
};

Person* current = nullptr; // Global

vector<Person*> people; // Vector to store Person* objects // Global

// Function to save data to a text file
void writeToFile(const vector<Person*>& people) {
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
void readfile(vector<Person*>& people) {
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
    cout << "Account list loaded!" << endl;
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
	string u, pass;
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
				current = people[i];
			}
		}
		if (access == true) {
			clearScreen();
			cout << "\033[32mLogged in successfully.\033[0m | Welcome \033[34m" << current->getAccount() << "\033[0m" << endl;
			cout << "Account type: " << "\033[31m" << current->type << "\033[0m" << endl;
			cout << endl;
			return;
		}
		else {
			cout << endl;
			cout << setw(40) << left << "" << "\033[33mInvalid username or password. Please try again.\033[0m" << endl;
			cout << setw(40) << left << "" << "\033[36m----------------------------------------------------------\033[0m" << endl;
		}
	}
}

// Manga class and relevant functions
class Manga {
	public:
		string name;
		vector<string> tag;
		string author;
		string date;
		double rate;
};

vector<Manga> list;		// Vector to store Manga objects // Global

// Function to check the input number
template <typename T>
void inputNumber (T& i) {
	while (1) {
        if (cin >> i) {
        	cin.ignore();
			break;
        } else {
            // Input failed
            cout << "Invalid input. Please enter an integer: ";
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cin.ignore();
        }
    }
}
void input(Manga &m) {
	cout << "Title: ";
	getline(cin, m.name);
	cout << "Tags: ";
	string tt;
	getline(cin, tt);
	stringstream ss(tt);
	string t;
	while(ss >> t) m.tag.push_back(t);
	cout << "Author: ";
	getline(cin, m.author);
	cout << "Date released: ";
	getline(cin, m.date);
	cout << "Rating: ";
	inputNumber(m.rate);
}
void show(const Manga &m) {
	cout << setfill(' ');
	cout << setw(45) << left << m.name;
	string allTags = m.tag[0];
	for (int i=1;i<m.tag.size();i++) {
		allTags+=", ";
		allTags+=m.tag[i];
	}
	cout << setw(50) << left << allTags;
	cout << setw(22) << left << m.author;
	cout << setw(20) << left << m.date;
	cout << setw(5) << right << m.rate << endl;
}
void showList(const vector<Manga> &list) {
	if(list.size()==0) {
		cout << "Empty list!" << endl;
		return;
	}
	cout << setfill(' ');
	cout << setw(2) << left << "" << "| ";
	cout <<"\033[31m"<< setw(45) << left << "Title";
	cout <<"\033[32m"<< setw(50) << left << "Tags";
	cout <<"\033[33m"<< setw(22) << left << "Author";
	cout <<"\033[34m"<< setw(20) << left << "Date released";
	cout <<"\033[35m"<< setw(5) << right << "Rating" << endl << "\033[0m";
	cout << setfill('-') << setw(147) << "-" << endl;
	for (int i = 0; i < list.size(); i++) {
		cout << setfill(' ') << setw(2)<< left << i+1 <<"| ";
    	show(list[i]);
    	cout << setfill('-') << setw(147) << "-" << endl;
    }
}
void add(vector<Manga> &list) {
	cout << "Adding new manga..." << endl;
	Manga newManga;
	input(newManga);
	list.push_back(newManga);
}
void remove(vector<Manga> &list) {
	cout << "Index of the manga that you want to delete: ";
	int n; inputNumber(n);
	if (n>0 && n<list.size()+1) {
		list.erase(list.begin()+n-1);
		cout << "Manga index = " << n << " has been removed." << endl;
	}
	else cout << "Invalid index." << endl;
}
void update(vector<Manga> &list) {
	cout << "Choose index: ";
	int choice; inputNumber(choice);
	if(choice<1 || choice>list.size()) {
		cout << "Invalid index." << endl;
		return;
	} else {
		cout << "Updating manga [" << choice << "] " << list[choice-1].name << endl;
		list[choice-1].tag.clear();
		list[choice-1].tag.shrink_to_fit();
		input(list[choice-1]);
	}
}

vector<Manga> searchbyName(const vector<Manga> &list) {
	vector<Manga> result;
	string keyword;
	cout << "Searching for keyword: ";
	getline(cin,keyword); keyword = lowercase(keyword);
	for (int i=0; i<list.size(); i++) {
		if(lowercase(list[i].name).find(keyword) != string::npos) {
			result.push_back(list[i]);
		}
	}
	if(!result.size()) {
		cout << "Can't find any manga with that keyword." << endl;
		return list;
	}
	showList(result);
	return result;
}
vector<Manga> searchbyTag(const vector<Manga> &list) {
	vector<Manga> result;
	string keyword;
	cout << "Searching for tags: ";
	getline(cin,keyword); keyword = lowercase(keyword);
	for (int i=0; i<list.size(); i++) {
		for(int j=0;j<list[i].tag.size();j++) {
			if(lowercase(list[i].tag[j]).find(keyword) != string::npos) {
				result.push_back(list[i]);
				break;
		}
		}
	}
	if(!result.size()) {
		cout << "Can't find any manga with that tags." << endl;
		return list;
	}
	showList(result);
	return result;
}
vector<Manga> searchbyAuthor(const vector<Manga> &list) {
	vector<Manga> result;
	string keyword;
	cout << "Searching for author: ";
	getline(cin,keyword); keyword = lowercase(keyword);
	for (int i=0; i<list.size(); i++) {
		if(lowercase(list[i].author).find(keyword) != string::npos) {
			result.push_back(list[i]);
		}
	}
	if(!result.size()) {
		cout << "Can't find any manga with that author." << endl;
		return list;
	}
	showList(result);
	return result;
}
vector<Manga> searchbyYear(const vector<Manga> &list) {
	vector<Manga> result;
	string keyword;
	cout << "Searching for year released: ";
	getline(cin,keyword);
	for (int i=0; i<list.size(); i++) {
		if(list[i].date.find(keyword) != string::npos) {
			result.push_back(list[i]);
		}
	}
	if(!result.size()) {
		cout << "Can't find any manga released in that year." << endl;
		return list;
	}
	showList(result);
	return result;
}
vector<Manga> searchbyRating(const vector<Manga> &list) {
	vector<Manga> result;
	double r;
	cout << "Searching for mangas with rating above: ";
	inputNumber(r);
	for (int i=0; i<list.size(); i++) {
		if(list[i].rate >= r) {
			result.push_back(list[i]);
		}
	}
	if(!result.size()) {
		cout << "Can't find any manga above that rating." << endl;
		return list;
	}
	showList(result);
	return result;
}
void search(const vector<Manga> &list) {
	vector<Manga> result=list;
	while(1) {
	cout << "Criteria:" << endl;
	cout << "[1] Name" << endl << "[2] Tags" << endl << "[3] Author" << endl << "[4] Year" << endl << "[5] Rating" << endl << "[6] Refresh filter" << endl << "[0] Cancel" << endl;
	cout << "Search by: ";
	int choice; inputNumber(choice);
	switch (choice) {
		case 1:
			result=searchbyName(result);
			break;
		case 2:
			result=searchbyTag(result);
			break;
		case 3:
			result=searchbyAuthor(result);
			break;
		case 4:
			result=searchbyYear(result);
			break;
		case 5:
			result=searchbyRating(result);
			break;
		case 6:
			result=list;
			cout << "Filter refreshed." << endl;
			break;
		case 0:
			return;
			break;
		default:
			cout << "Invalid choice." << endl;
	}
}}
void readfile(vector<Manga> &list) {
	ifstream save("manga_list.txt");
	if(save.is_open()) {
		string line;
		while(getline(save, line)) {
			Manga m;
			m.name = line;
			if(getline(save, line)) {
				stringstream ss(line);
				string t;
				while(ss >> t) m.tag.push_back(t);
			}
			if(getline(save, line)) m.author=line;
			if(getline(save, line)) m.date=line;
			if(getline(save, line)) m.rate=stod(line);
			list.push_back(m);
		}
		cout << "Manga list loaded!" << endl;
	} else cout << "Failed to load manga list!" << endl;
	save.close();
}
void writeToFile(const vector<Manga> &list) {
    ofstream output("manga_list.txt");
    if (output.is_open()) {
        for (const Manga &m : list) {
            // Write each field of the Manga object to the file
            output << m.name << endl;
            // Write tags with spaces between them
            for (const string &tag : m.tag) {
                output << tag << ' ';
            }
            output << endl;
            output << m.author << endl;
            output << m.date << endl;
            output << m.rate << endl;
        }
        cout << endl << "Data has been saved." << endl;
    } else {
        cout << "Unable to open manga_list.txt for writing." << endl;
    }
    output.close();
}
void menuAdmin() {
	cout << "\033[33m---------------Options---------------\033[0m" << endl;
	cout << "[1] Display main functions" << endl;
	cout << "[2] All manga titles" << endl;
	cout << "[3] Search" << endl;
	cout << "[4] Add new manga" << endl;
	cout << "[5] Delete manga" << endl;
	cout << "[6] Update manga" << endl;
	cout << "[7] Create new account" << endl;
	cout << "[8] View registered accounts" << endl;
	cout << "[9] View/Edit account information" << endl;
	cout << "[0] Save & Log out" << endl;
}
void menu() {
	cout << "\033[33m---------------Options---------------\033[0m" << endl;
	cout << "[1] Display main functions" << endl;
	cout << "[2] All manga titles" << endl;
	cout << "[3] Search" << endl;
	cout << "[4] View/Edit account information" << endl;
	cout << "[5] Help" << endl;
	cout << "[6] About" << endl;
	cout << "[0] Save & Log out" << endl;
}
void help() {
	cout << "Help yourself" << endl;
}
void about() {
	cout << "Program written by Duke ..." << endl;
}
void printCapybara() {
	ifstream file("capybara.txt");
    if (file.is_open()) {
        cout << file.rdbuf();
        file.close();
    }
}
void start(vector<Person*> &people) {
    here:
    cout << "\033[25;40H" << ".....\033[32mEnter = Log In\033[0m || \033[36mSpace = Create new account\033[0m || \033[33mESC = Exit\033[0m.....";
    while (1) {
        if (_kbhit()) {
            char key = _getch(); // Read a single character
            if (key == '\r') {
                // Enter key was pressed
                clearScreen();
                login(people);
                break;
            } else if (key == ' ') {
                // Space bar was pressed
                clearScreen();
                cout << "\033[36mCreating new account...\033[0m" << endl;
                createAccount(people);
                goto here;
                break;
            } else if (key == 27) {
            	writeToFile(list);
				writeToFile(people);
				exit(0); // Exit program
			}
			else {
                // Do nothing for other keys
            }
        }
    }
}
int main() {
	begin:
	readfile(list);
	readfile(people);
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	clearScreen();
	printCapybara();
	start(people);
	int choice; string cf;
	if (current->type == "Staff") {
		menuAdmin();
		while(1) {
		cout << "\033[33m-------------------------------------\033[0m" << endl;
		cout << "Your choice: ";
		inputNumber(choice);
		Staff* st = nullptr;
		switch (choice) {
			case 1:
				menuAdmin();
				break;
			case 2:
				showList(list);
				break;
			case 3:
				search(list);
				break;
			case 4:
				add(list);
				break;
			case 5:
				remove(list);
				break;
			case 6:
				update(list);
				break;
			case 7:
				st = dynamic_cast<Staff*>(current);
				st->createAdminAccount(people);
				break;
			case 8:
				st = dynamic_cast<Staff*>(current);
				st->listUser(people);
				cout << "\033[33m-------------------------------------\033[0m" << endl;
				cout << "[0] Go back" << endl;
				cout << "[1] Change password of a non-Staff" << endl;
				while(1){
					cout << "Your choice: ";
					int c;
					inputNumber(c);
					if (c==0) break;
					else if (c==1) st->changePassword(people);
					else cout << "Invalid number." << endl;
				}
				break;
			case 9:
				current->print_info();
				cout << "\033[33m-------------------------------------\033[0m" << endl;
				cout << "[0] Go back" << endl;
				cout << "[1] Change password" << endl;
				cout << "[2] Change all informations" << endl;
				while(1){
					cout << "Your choice: ";
					int c;
					inputNumber(c);
					if (c==0) break;
					else if (c==1) {
						string newpass;
						getline(cin,newpass);
						current->setPassword(newpass);
					}
					else if (c==2) current->input(people);
					else cout << "Invalid number." << endl;
				}
				break;
			case 0:
				cout << "Confirm log out. [Y/N]: ";
				getline(cin,cf);
				if (lowercase(cf) == "y") {
					writeToFile(people);
					writeToFile(list);
					goto begin;
				}
				else break;
			default:
				cout << "Invalid choice." << endl;
		}
	}
	} else {
		menu();
		while(1) {
		cout << "\033[33m-------------------------------------\033[0m" << endl;
		cout << "Your choice: ";
		inputNumber(choice);
		switch (choice) {
			case 1:
				menu();
				break;
			case 2:
				showList(list);
				break;
			case 3:
				search(list);
				break;
			case 4:
				current->print_info();
				cout << "\033[33m-------------------------------------\033[0m" << endl;
				cout << "[0] Go back" << endl;
				cout << "[1] Change password" << endl;
				cout << "[2] Change all informations" << endl;
				while(1){
					cout << "Your choice: ";
					int c;
					inputNumber(c);
					if (c==0) break;
					else if (c==1) {
						string newpass;
						getline(cin,newpass);
						current->setPassword(newpass);
					}
					else if (c==2) current->input(people);
					else cout << "Invalid number." << endl;
				}
				break;
			case 5:
				help();
				break;
			case 6:
				about();
				break;
			case 0:
				cout << "Confirm log out. [Y/N]: ";
				getline(cin,cf);
				if (lowercase(cf) == "y") {
					writeToFile(list);
					goto begin;
				}
				else break;
			default:
				cout << "Invalid choice." << endl;
		}
	}
	}	
    return 0;
}
