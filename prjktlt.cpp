#include<iostream>
#include<string>		
#include<vector>		// vector
#include<iomanip>		// for std::setw(n), std::setfill(ch), std::left, std::right
#include<sstream>		// stringstrean
#include<fstream>		// file operations
#include<cctype>		// using tolower() function

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
	cout << setfill(' ');
	cout << setw(2) << left << "" << "| ";
	cout << setw(45) << left << "Title";
	cout << setw(50) << left << "Tags";
	cout << setw(22) << left << "Author";
	cout << setw(20) << left << "Date released";
	cout << setw(5) << right << "Rating" << endl;
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
void searchbyName(const vector<Manga> &list) {
	string keyword;
	cout << "Finding keyword: ";
	getline(cin,keyword); keyword = lowercase(keyword);
	bool found=false;
	for (int i=0; i<list.size(); i++) {
		if(lowercase(list[i].name).find(keyword) != string::npos) {
			show(list[i]);
			found = true;
		}
	}
	if(!found) cout << "Can't find any manga with that keyword.";
}
void searchbyTag(const vector<Manga> &list) {
	string keyword; keyword = lowercase(keyword);
	cout << "Finding tags: ";
	getline(cin,keyword);
	bool found=false;
	for (int i=0; i<list.size(); i++) {
		for(int j=0;j<list[i].tag.size();j++) {
			if(lowercase(list[i].tag[j]).find(keyword) != string::npos) {
				show(list[i]);
				found = true;
				break;
		}
		}
	}
	if(!found) cout << "Can't find any manga with that tags.";
}
void searchbyAuthor(const vector<Manga> &list) {
	string keyword; keyword = lowercase(keyword);
	cout << "Finding author: ";
	getline(cin,keyword);
	bool found=false;
	for (int i=0; i<list.size(); i++) {
		if(lowercase(list[i].author).find(keyword) != string::npos) {
			show(list[i]);
			found = true;
		}
	}
	if(!found) cout << "Can't find any manga with that author.";
}
void searchbyYear(const vector<Manga> &list) {
	string keyword;
	cout << "Finding year released: ";
	getline(cin,keyword);
	bool found=false;
	for (int i=0; i<list.size(); i++) {
		if(list[i].date.find(keyword) != string::npos) {
			show(list[i]);
			found = true;
		}
	}
	if(!found) cout << "Can't find any manga released in that year.";
}
void searchbyRating(const vector<Manga> &list) {
	double r;
	cout << "Finding mangas with rating above: ";
	cin >> r;
	bool found=false;
	for (int i=0; i<list.size(); i++) {
		if(list[i].rate >= r) {
			show(list[i]);
			found = true;
		}
	}
	if(!found) cout << "Can't find any manga above that rating.";
}
void filter(const vector<Manga> &list) {
	
}
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
int main() {
	vector<Manga> list;
	readfile(list);
	showList(list);
	searchbyTag(list);
	return 0;
}
