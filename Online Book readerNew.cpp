#include <iostream>
#include<algorithm>
#include<vector>
#include<ctime> 
#include<map> 
#pragma warning(disable : 4996)
using namespace std;
const std::string currentDateTime() {
	time_t now = time(0);
	struct tm tstruct;
	char buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
	return buf;
}
int menu() {
	while (true) {
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
private:
	string ISBN;
	string Title;
	string Author_Name;
	int pages=0;
	int idBook=0;
public:
	static int LenBooks;
	string get_ISBN() {
		return ISBN;
	}
	void set_ISBN(string ISBN) {
		this->ISBN=ISBN;
	}
	string get_Title() {
		return Title;
	}
	void set_Title(string Title) {
		this->Title = Title;
	}
	string get_Author_Name() {
		return Title;
	}
	void set_Author_Name(string Author_Name) {
		this->Author_Name = Author_Name;
	}
	int get_pages() {
		return pages;
	}
	void set_pages(int pages) {
		this->pages = pages;
	}
	int get_idBook() {
		return idBook;
	}
	void set_idBook(int idBook) {
		this->idBook = idBook;
	}
};
int Book::LenBooks = 0;
struct All_Books {
	Book bk;
	map<string,pair<int,vector<string>>>contentBooks; //NameBook >>id  Content of each page
	map<string, Book>allbooks; //NameBook >>id  Content of each page
	void addBook() {
		string ISBN;
		string Title;
		string Author_Name;
		int pages;
		cout << "Enter ISBN:";
		cin >>ISBN;
		bk.set_ISBN(ISBN);
		cout << "Enter Title:";
		cin >> Title;
		bk.set_Title(Title);
		cout << "Enter Author Name:";
		cin >>Author_Name;
		bk.set_Author_Name (Author_Name);
		cout << "How Many Pages:";
		cin >> pages;
		bk.set_pages(pages);
		allbooks[bk.get_Title()]= bk;
		contentBooks[bk.get_Title()].first = Book::LenBooks;
		for (int i = 0; i < pages; i++) {
			cout << "Enter Content Of Page " << i + 1 << ": ";
			string cnt; cin >> cnt;
			contentBooks[bk.get_Title()].second.push_back(cnt);
		}
		++(Book::LenBooks);
	}
	void all_books() {
		for (auto& it : contentBooks) {
			cout << "Num of pages: " << contentBooks[it.first].second.size() << "\n";
			cout << contentBooks[it.first].first << ") Book Title: " << it.first << "\n";
		} 
	}
	void content_books(string name) {
		cout << "Num of pages: " << contentBooks[name].second.size() << "\n";
		for (auto& it : contentBooks[name].second) {
			int i = 1;
				cout << "Page " << i++ << " : " << it << "\n";
		}
	}
};
All_Books all;
struct admin {
private:
	int id_admin = 0;
	string admin_name;
	string pass;
	string name;
	string email;
public:
	static int adminLen;
	int get_id_admin() {
		return id_admin;
	}
	void set_id_admin(int id_admin) {
		this->id_admin = id_admin;
	}
	string get_admin_name() {
		return admin_name;
	}
	void set_admin_name(string admin_name) {
		this->admin_name = admin_name;
	}
	string get_pass() {
		return pass;
	}
	void set_pass(string pass) {
		this->pass = pass;
	}
	void set_name(string name) {
		this->name = name;
	}
	string get_name() {
		return name;
	}
	string get_email() {
		return email;
	}
	void set_email(string email) {
		this->email = email;
	}
	void print_admin() {
		cout << "admin:\n";
		cout << "Name :" << name << endl;
		cout << "Email :" << email << endl;
		cout << "admin_name :" << admin_name << endl;
	}
};	
int admin::adminLen = 0;
struct admin_process {
public:
	map <string,admin>alladmins;
	void sign_up_admin() {
		admin ad;
		cout << "*) admin name:\n";
		string adName; cin >> adName;
		 ad.set_admin_name(adName);
		cout << "*) Password:\n";
		string ps; cin >> ps;
		ad.set_pass(ps);
		cout << "*) Name:\n";
		string nm; cin >> nm;
		 ad.set_name(nm);
		cout << "*) email:\n";
		string mail; cin >> mail;
		 ad.set_email(mail);
		ad.set_id_admin( admin::adminLen);
		alladmins[adName] = ad;
		++(admin::adminLen);
	}
	void login_admin() {
		admin  ad;
		cout << "Enter admin_name: ";
		string admin_name; cin >> admin_name;
		cout << "Enter password: ";
		string pass; cin >> pass;
		if (checker_admins(admin_name, pass)) {
			 ad =alladmins[admin_name] ;
			menu_login_admin(ad);
		}
		else {
			cout << "Not Correct\n";
		}
	}
	void menu_login_admin(admin &ad) {
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
					ad.print_admin();
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
		for (auto& it : alladmins) {
			if (it.first == admin_name && alladmins[it.first].get_pass() == pass) {
				cout << "ADMIN:\n";
				cout << "Hello " <<it.first << endl;
				return true;
			}
		}
		return false;
	}
};
struct user {
private:
int id_user = 0;
	string user_name;
	string pass;
	string name;
	string email;
public:
	int get_id_user() {
		return id_user;
	}
	void set_id_user(int id_user) {
		this->id_user = id_user;
	}
	string get_user_name() {
		return user_name;
	}
	void set_user_name(string user_name) {
		this->user_name = user_name;
	}
	string get_pass() {
		return pass;
	}
	void set_pass(string pass) {
		this->pass = pass;
	}
	void set_name(string name) {
		this->name = name;
	}
	string get_name() {
		return name;
	}
	string get_email() {
		return email;
	}
	void set_email(string email) {
		this->email = email;
	}
	static int userLen;
	map<string, pair<int, string>>reading_list;//name Book and markStop and date
	void print_user() {
		cout << "User:\n";
		cout << "Name :" << name << endl;
		cout << "Email :" << email << endl;
		cout << "user_name :" << user_name << endl;
	}
	void history() {
		for (auto& it : reading_list) {
			cout << it.first << " Page: " << it.second.first << " " << it.second.second << endl;
		}
	}
	pair<string, int>choose_book(int _choose) {
		for (auto& it : all.contentBooks) {
			if (all.contentBooks[it.first].first == _choose) {
				cout << "Number of Pages : " << all.contentBooks[it.first].second.size() << "\n";
				pair<string, int>temp = { it.first, all.contentBooks[it.first].second.size() };
				return temp;//name & tot pages
			}
		}
		return make_pair("null", -1);
	}
	void content_page(int _id, int page) {
		for (auto& it : all.contentBooks) {
			if (all.contentBooks[it.first].first == _id) {
				int tracker = 1;
				for (auto& it2 : all.contentBooks[it.first].second) {
					if (tracker == page) {
						cout << "Current Page: " << page << " of " << all.contentBooks[it.first].second.size() << "\n";
						cout << "Content: \n" << it2 << "\n";
						return;
					}
					++tracker;
				}
			}
		}
	}
};	
int user::userLen = 0;
struct user_process {
public:
	map<string, user>allusers;
	bool checker_user(string user_name, string pass) {
		for (auto& it : allusers) {
			if (it.first == user_name && allusers[it.first].get_pass() == pass) {
				cout << "USER:\n";
				cout << "Hello " << it.first << endl;
				//CurrentId = allusers[it.first].get_id_user();
				return true;
			}
		}
		return false;
	}
	void sign_up_user() {
		user usr;
		cout << "*) user name:\n";
		string us; cin >> us;
		usr.set_user_name(us);
		cout << "*) Password:\n";
		string ps; cin >> ps;
		usr.set_pass(ps);
		cout << "*) Name:\n";
		string nm; cin >> nm;
		 usr.set_name(nm);
		cout << "*) email:\n";
		string mail; cin >> mail;
		 usr.set_email(mail);
		usr.set_id_user (user::userLen);
		allusers[us] = usr;
		++(user::userLen);
	}
	void menu_login_user(user& usr) {
		while (true) {
			cout << "1)View Profile: \n";
			cout << "2)Reading History: \n";
			cout << "3)Choose a Book \n";
			cout << "4)LogOut \n";
			cout << "5)Content of a Book \n";
			int choose; cin >> choose;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Only numeric input  \n";
			}
			else {
				if (choose == 1) {
					usr.print_user();
				}
				else if (choose == 2) {
					usr.history();
				}
				else if (choose == 3) {
					all.all_books();
					cout << "Choose a Book ID : ";
					int _choose; cin >> _choose;
					pair<string, int> bk_info = usr.choose_book(_choose);//name and pages tot
					if (bk_info.first == "null") {
						cout << "NOT FOUND\n";
					}
					else {
						usr.content_page(_choose, usr.reading_list[bk_info.first].first);
						if (usr.reading_list[bk_info.first].first)cout << "Current Page: " << usr.reading_list[bk_info.first].first << "\n";
						while (true) {
							int ch = menu_ReadingBook();
							if (ch == 1) {//next
								if (usr.reading_list[bk_info.first].first < bk_info.second) {
									usr.reading_list[bk_info.first].first++;//name and tot pages
									usr.content_page(_choose, usr.reading_list[bk_info.first].first);
								}
								else {
									cout << "No found \n";
								}
							}
							else if (ch == 2) {//prev
								if (usr.reading_list[bk_info.first].first > 1) {
									usr.reading_list[bk_info.first].first--;//name and tot pages
									usr.content_page(_choose, usr.reading_list[bk_info.first].first);
								}
								else {
									cout << "No found \n";
								}
							}
							else if (ch == 3) {
								usr.reading_list[bk_info.first].second = currentDateTime();
								break;
							}
						}
					}
				}
				else if (choose == 4) {
					break;
				}
				else if (choose == 5) {
					all.all_books();
					cout << "enter book name: ";
					string name; cin >> name;
					all.content_books(name);
				}
				else {
					cout << "Not valid input \n";
				}
			}
		}
	}
	void login_user() {
		user usr;
		cout << "Enter user_name: ";
		string user_name; cin >> user_name;
		cout << "Enter password: ";
		string pass; cin >> pass;
		if (checker_user(user_name, pass)) {
			
			menu_login_user(allusers[user_name]);
		}
		else {
			cout << "Not Correct\n";
		}
	}
};
int main() {
	admin_process admin;
	user_process user;
	while (true) {
		int choice = system();
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
