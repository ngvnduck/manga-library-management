#include <iostream>
#include <string>		
#include <vector>		// vector
#include <iomanip>		// for std::setw(n), std::setfill(ch), std::left, std::right
#include <sstream>		// stringstrean
#include <fstream>		// file operations
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
	cout << "Nhap ten truyen: ";
	getline(cin, m.name);
	cout << "Nhap the loai: ";
	string tt;
	getline(cin, tt);
	stringstream ss(tt);
	string t;
	while(ss >> t) m.tag.push_back(t);
	cout << "Nhap tac gia: ";
	getline(cin, m.author);
	cout << "Nhap ngay ra mat: ";
	getline(cin, m.date);
	cout << "Nhap diem so: ";
	cin >> m.rate;
	cin.ignore();
}
void show(Manga m) {
	cout << m.name << endl;
	for (int i = 0; i < m.tag.size(); i++) cout << m.tag[i] << " ";
	cout << endl << m.author << endl;
	cout << m.date << endl;
	cout << m.rate << endl;
	cout << "------------------" << endl;

}
void showList(vector<Manga> list) {
	
}
void add(vector<Manga> &list) {
	Manga newManga;
	input(newManga);
	list.push_back(newManga);
}
void update(vector<Manga> &list) {
	for (int i=0;i<list.size();i++) show(list[i]);
	cout << "Chon STT truyen muon sua: ";
	int choice; cin >> choice; cin.ignore();
	if(choice<1 || choice>list.size()) {
		cout << "Khong hop le." << endl;
		return;
	} else {
		cout << "Dang sua truyen [" << choice << "] " << list[choice-1].name << endl;
		list[choice-1].tag.clear();
		list[choice-1].tag.shrink_to_fit();
		input(list[choice-1]);
	}
}
void searchbyName(vector<Manga> list) {
	string keyword;
	cout << "Nhap tu khoa can tim: ";
	getline(cin,keyword);
	bool found=false;
	for (int i=0; i<list.size(); i++) {
		if(list[i].name.find(keyword) != string::npos) {
			show(list[i]);
			found = true;
		}
	}
	if(!found) cout << "Khong tim thay truyen chua tu khoa.";
}
void searchbyTag(vector<Manga> list) {
	string keyword;
	cout << "Nhap the loai can tim: ";
	getline(cin,keyword);
	bool found=false;
	for (int i=0; i<list.size(); i++) {
		for(int j=0;j<list[i].tag.size();j++) {
			if(list[i].tag[j].find(keyword) != string::npos) {
				show(list[i]);
				found = true;
				break;
		}
		}
	}
	if(!found) cout << "Khong tim thay the loai.";
}
void searchbyAuthor(vector<Manga> list) {
	string keyword;
	cout << "Nhap tac gia can tim: ";
	getline(cin,keyword);
	bool found=false;
	for (int i=0; i<list.size(); i++) {
		if(list[i].author.find(keyword) != string::npos) {
			show(list[i]);
			found = true;
		}
	}
	if(!found) cout << "Khong tim thay tac gia.";
}
void searchbyYear(vector<Manga> list) {
	string keyword;
	cout << "Nhap nam can tim: ";
	getline(cin,keyword);
	bool found=false;
	for (int i=0; i<list.size(); i++) {
		if(list[i].date.find(keyword) != string::npos) {
			show(list[i]);
			found = true;
		}
	}
	if(!found) cout << "Khong tim thay truyen chua tu khoa.";
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
	} else cout << "Khong tai duoc danh sach truyen!" << endl;
}
int main() {
	vector<Manga> list;
	readfile(list);
	for (int i=0; i<list.size(); i++) show(list[i]);
	
	return 0;
}
