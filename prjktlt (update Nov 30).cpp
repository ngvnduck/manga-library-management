/*#include<iostream>
#include<string>		
#include<vector>		// vector
#include<iomanip>		// for std::setw(n), std::setfill(ch), std::left, std::right
#include<sstream>		// stringstrean
#include<fstream>		// file operations
#include<cctype>		// using tolower() function
#include <chrono>
#include <thread>*/
#include <bits/stdc++.h>
using namespace std;
class Manga {
	public:
		string name;
		vector<string> tag;
		string author;
		string date;
		double rate;
};
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
	cin >> m.rate;
	cin.ignore();
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
	if(list.size()==0) return;
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
	int n; cin >> n;
	if (n>0 && n<list.size()+1) {
		list.erase(list.begin()+n-1);
		cout << "Manga index = " << n << " has been removed." << endl;
	}
	else cout << "Invalid index." << endl;
}
void update(vector<Manga> &list) {
	cout << "Choose index: ";
	int choice; cin >> choice; cin.ignore();
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
string lowercase(const string& str) {
    string result;
    for (char ch : str) {
        result += tolower(ch);
    }
    return result;
}
vector<Manga> searchbyName(const vector<Manga> &list) {
	vector<Manga> result;
	string keyword;
	cout << "Finding keyword: ";
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
	string keyword; keyword = lowercase(keyword);
	cout << "Finding tags: ";
	getline(cin,keyword);
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
	string keyword; keyword = lowercase(keyword);
	cout << "Finding author: ";
	getline(cin,keyword);
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
	cout << "Finding year released: ";
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
	cout << "Finding mangas with rating above: ";
	cin >> r;
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
	cout << "Criteria:" << endl;
	cout << "[1] Name" << endl << "[2] Tags" << endl << "[3] Author" << endl << "[4] Year" << endl << "[5] Rating" << endl << "[0] Cancel" << endl;
	while(1) {
	cout << "Search by: ";
	int choice; cin >> choice; cin.ignore();
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
	} else cout << "Failed to load manga list!" << endl;
	save.close();
}
void writeToFile(const vector<Manga> &list) {
    ofstream output("newMan.txt");
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
        cout << "Data has been saved." << endl;
    } else {
        cout << "Unable to open manga_list.txt for writing." << endl;
    }
    output.close();
}
void menu(vector<Manga> &list) {
	cout << "---------------Options---------------" << endl;
	cout << "[1] All manga titles" << endl;
	cout << "[2] Search" << endl;
	cout << "[3] Add new manga" << endl;
	cout << "[4] Delete" << endl;
	cout << "[5] Update manga" << endl;
	while(1) {
		cout << "Your choice: ";
		int choice; cin >> choice; cin.ignore();
		switch (choice) {
			case 1:
				showList(list);
				break;
			case 2:
				search(list);
				break;
			case 3:
				add(list);
				break;
			case 4:
				remove(list);
				break;
			case 5:
				update(list);
				break;
			case 0:
				return;
			default:
				cout << "Invalid choice." << endl;
		}
	}
}
int main() {
	vector<Manga> list;
	readfile(list);
	this_thread::sleep_for(chrono::seconds(2)); // Delay 2 seconds
	menu(list);
	return 0;
}
