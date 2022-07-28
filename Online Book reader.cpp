#include <iostream>
#include<algorithm>
#include<vector>
#include<bits/stdc++.h>
#include<ctime> 
#pragma warning(disable : 4996)
using namespace std;
int CurrentId;
string CurrentName;
const std::string currentDateTime() {
	time_t now = time(0);
	struct tm tstruct;
	char buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
	return buf;
}
int menu() {
	while(true) {
		cout << "1) Login:\n";
		cout << "2) Sign Up:\n";
		int choose; cin >> choose;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Only numeric input  \n";
		}
		else {
			if (choose == 1 || choose == 2) {
				return choose;
			}
			else {
				cout << "Not valid input \n";
			}
		}
	}
}
int menu_ReadingBook() {
	while (true) {
		cout << "1) Next Page:\n";
		cout << "2) Prev Page:\n";
		cout << "3) Stop Reading:\n";
		int choose; cin >> choose;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Only numeric input  \n";
		}
		else {
			if (choose == 1 || choose == 2 || choose == 3) {
				return choose;
			}
			else {
				cout << "Not valid input \n";
			}
		}
	}
}
int system() {
	while (true) {
		cout << "1)Admin\n";
		cout << "2)User\n";
		int choose; cin >> choose;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Only numeric input  \n";
		}
		else {
			if (choose == 1 || choose == 2) {
				return choose;
			}
			else {
				cout << "Not valid input \n";
			}
		}
	}
}
struct Book {
	string ISBN;
	string Title;
	string Author_Name;
	int pages=0;
	int idBook = 0;
static int LenBooks ;
};
int Book::LenBooks = 0;
struct All_Books {
	Book bk[1000];
	map<string, pair<int, vector<string>>>contentBooks; //NameBook >>id  Content of each page
	void addBook() {
	string ISBN;
	string Title;
	string Author_Name;
	int pages;
	cout << "Enter ISBN:";
	cin >> ISBN;
	bk[bk->LenBooks].ISBN = ISBN;
	cout << "Enter Title:";
	cin >> Title;
	bk[bk->LenBooks].Title = Title;
	cout << "Enter Author Name:";
	cin >> Author_Name;
	bk[bk->LenBooks].Author_Name = Author_Name;
	cout << "How Many Pages:";
	cin >> pages;
	bk[bk->LenBooks].pages = pages;
	contentBooks[Title].first = bk->LenBooks;
	for (int i = 0; i < pages; i++) {
		cout << "Enter Content Of Page " << i + 1 << ": ";
		string cnt; cin >> cnt;
		contentBooks[Title].second.push_back(cnt);
	}
++(bk->LenBooks);
}
void all_books() {
	for (auto& it : contentBooks) {
		cout << "Num of pages: " << contentBooks[it.first].second.size()<<"\n";
		cout << contentBooks[it.first].first << ") Book Title: " << it.first << "\n";
		int i = 1;
		for (auto& it2 : contentBooks[it.first].second) {
			cout <<"Page "<<i++ <<" : " << it2 << "\n";
		}
	}
}
};
struct admin {
	static int adminLen ;
	int id_admin = 0;
	string admin_name;
	string pass;
	string name;
	string email;
	void print_admin() {
		cout << "admin:\n";
		cout << "Name :" << name << endl;
		cout << "Email :" << email << endl;
		cout << "admin_name :" <<admin_name << endl;
	}
};
 int admin::adminLen = 0;
admin ad[1000];  //each admin has a 
All_Books all;
struct admin_process {
	void sign_up_admin() {
		cout << "*) admin name:\n";
		cin >> ad[ad->adminLen].admin_name;
		cout << "*) Password:\n";
		cin >> ad[ad->adminLen].pass;
		cout << "*) Name:\n";
		cin >> ad[ad->adminLen].name;
		cout << "*) email:\n";
		cin >> ad[ad->adminLen].email;
		CurrentId = ad->adminLen;
		CurrentName = ad[ad->adminLen].admin_name;
		ad[ad->adminLen].id_admin = ad->adminLen;
		++(ad->adminLen);
	}
	void login_admin() {
		cout << "Enter admin_name: ";
		string admin_name; cin >> admin_name;
		cout << "Enter password: ";
		string pass; cin >> pass;
		if (checker_admins(admin_name, pass)) {
			menu_login_admin();
		}
		else {
			cout << "Not Correct\n";
		}
	}
	void menu_login_admin() {
		while (true) {
			cout << "1)View Profile: \n";
			cout << "2)Add a Book \n";
			cout << "3)All Books \n";
			cout << "4)LogOut \n";
			int choose; cin >> choose;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Only numeric input  \n";
			}
			else {
				if (choose == 1) {
					ad[CurrentId].print_admin();
				}
				else if (choose == 2) {
					all.addBook();
				}
				else if (choose == 3) {
					all.all_books();
				}
				else if (choose == 4) {
					break;
				}
				else {
					cout << "Not valid input \n";
				}
			}
		}
	}
bool checker_admins(string admin_name, string pass) {
	for (int i = 0; i < ad->adminLen; i++) {
		if (ad[i].admin_name == admin_name && ad[i].pass == pass) {
			cout<<"ADMIN:\n";
			cout << "Hello " << ad[i].name << endl;
			return true;
		}
	}
	return false;
}
};
struct user {
	static int userLen ;
	map<string,pair<int, string>>reading_list ;//name Book and markStop and date
	int id_user = 0;
	string user_name;
	string pass;
	string name;
	string email;
	vector<pair<string, string>>history_user;
	map<string,pair<int, string>>mark;
	void print_user() {
		cout << "User:\n";
		cout << "Name :" << name << endl;
		cout << "Email :" << email << endl;
		cout << "user_name :" << user_name << endl;
	}
	void history() {
		for (auto& it : reading_list) {
				cout << it.first << " Page: " << it.second.first <<" " <<it.second.second<< endl;
		}
	}
pair<string,int>choose_book(int _choose) {
		for (auto& it : all.contentBooks) {
			if (all.contentBooks[it.first].first == _choose) {
				cout << "Number of Pages : " <<all. contentBooks[it.first].second.size() << "\n";
				pair<string, int>temp = { it.first, all.contentBooks[it.first].second.size() };
				return temp;//name & tot pages
			}
		}
		return make_pair("null",-1);
}
void content_page(int _id,int page) {
	for (auto& it : all.contentBooks) {
		if (all.contentBooks[it.first].first == _id) {
			int tracker = 1;
			for (auto& it2 : all.contentBooks[it.first].second) {
				if (tracker == page) {
					cout << "Current Page: "<<page<< " of "<< all.contentBooks[it.first].second.size()<<"\n";
					cout <<"Content: \n" << it2 << "\n";
					return;
				}
				++tracker;
			}
		}
	}
}
};
int user::userLen = 0;
user usr[1000];  //each admin has a 
struct user_process {
	void sign_up_user() {
		cout << "*) user name:\n";
		cin >> usr[usr->userLen].user_name;
		cout << "*) Password:\n";
		cin >> usr[usr->userLen].pass;
		cout << "*) Name:\n";
		cin >> usr[usr->userLen].name;
		cout << "*) email:\n";
		cin >> usr[usr->userLen].email;
		CurrentId = usr->userLen;
		CurrentName= usr[usr->userLen].user_name;
		usr[usr->userLen].id_user = usr->userLen;
		++(usr->userLen);
	}
	void login_user() {
		cout << "Enter user_name: ";
		string user_name; cin >> user_name;
		cout << "Enter password: ";
		string pass; cin >> pass;
		if (checker_user(user_name, pass)) {
			menu_login_user();
		}
		else {
			cout << "Not Correct\n";
		}
	}
	void menu_login_user() {
		while (true) {
			cout << "1)View Profile: \n";
			cout << "2)Reading History: \n";
			cout << "3)Choose a Book \n";
			cout << "4)LogOut \n";
			int choose; cin >> choose;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Only numeric input  \n";
			}
			else {
				if (choose == 1) {
					usr[CurrentId].print_user();
				}
				else if (choose == 2) {
					usr[CurrentId].history();
				}
				else if (choose == 3) {
					all.all_books();
					cout << "Choose a Book ID : ";
					int _choose; cin >> _choose;
					pair<string,int> bk_info=usr[CurrentId].choose_book(_choose);//name and pages tot
					if (bk_info.first == "null") {
						cout << "NOT FOUND\n";
					}
					else {
						usr[CurrentId].content_page(_choose, usr[CurrentId].reading_list[bk_info.first].first);
						if (usr[CurrentId].reading_list[bk_info.first].first)cout << "Current Page: " << usr[CurrentId].reading_list[bk_info.first].first << "\n";
						while (true) {
							int ch = menu_ReadingBook();
							if (ch == 1) {//next
								if (usr[CurrentId].reading_list[bk_info.first].first < bk_info.second) {
									usr[CurrentId].reading_list[bk_info.first].first++;//name and tot pages
									usr[CurrentId].content_page(_choose, usr[CurrentId].reading_list[bk_info.first].first);
								}
								else {
									cout << "No found \n";
								}
							}
							else if (ch == 2) {//prev
								if (usr[CurrentId].reading_list[bk_info.first].first > 1) {
									usr[CurrentId].reading_list[bk_info.first].first--;//name and tot pages
									usr[CurrentId].content_page(_choose, usr[CurrentId].reading_list[bk_info.first].first);
								}
								else {
									cout << "No found \n";
								}
							}
							else if (ch == 3) {		
								usr[CurrentId].reading_list[bk_info.first].second = currentDateTime();
								break;
							}
						}
					}
				}
				else if (choose == 4) {
					break;
				}
				else {
					cout << "Not valid input \n";
				}
			}
		}
	}
	bool checker_user(string user_name, string pass) {
		for (int i = 0; i < usr->userLen; i++) {
			if (usr[i].user_name == user_name && usr[i].pass == pass) {
				cout << "USER:\n";
				cout << "Hello " << usr[i].name << endl;
				CurrentId = usr[i].id_user;
				return true;
			}
		}
		return false;
	}
};
int main()
{
	admin_process admin;
	user_process user;
	while (true) {
		int choice=system();
		if (choice == 1) {
			int ch = menu();
			if (ch == 1) {
				admin.login_admin();
			}
			else if (ch == 2) {//sign Up admin
				admin.sign_up_admin();
			}
		}
		else if (choice == 2) {
			int ch = menu();
			if (ch == 1) {
				user.login_user();
			}
			else if (ch == 2) {//sign Up User
				user.sign_up_user();
			}
		}
	}
	return 0;
}
