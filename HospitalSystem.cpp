#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int booklen = 0;
int userlen = 0;
int menu() {
	while (true) {
		cout << "1) add Book: \n";
		cout << "2) Search For a Book: \n";
		cout << "3) Print who borrowed a Book: \n";
		cout << "4) Print BooksByName  : \n";
		cout << "5) Print BooksById  : \n";
		cout << "6) Add User : \n";
		cout << "7) Borrow a Book : \n";
		cout << "8) Return a Book : \n";
		cout << "9) Print Users : \n";
		cout << "10) Exit : \n";
		int choose; cin >> choose;
		if (choose < 1 || choose > 9) {
			continue;
		}
		else {
			return choose;
		}
	}
}
struct User_info {
	string name;
	int id=0;
	void display() {
		cout << name << " " << id << "\n";
	}
};
User_info user[100];
struct Users {
	void add_user() {
		cout << "Enter Id & Name :\n";
		string _name; int _id;
		cin >> _id >> _name;
		user[userlen].id = _id;
		user[userlen].name = _name;
		++userlen;
	}
	void print_user() {
		for (int i = 0; i < userlen; i++) {
			user[i].display();
		}
	}
};
bool User_checker(string user_name) {
	for (int i = 0; i < userlen; i++) {
		if (user_name == user[i].name) {
			return true;
		}
	}
	return false;
}
struct  Book_info
{
	int Id=0;
	int quantity=0;
	 int _quantity=0;
	vector<string>borrow; //userName
	void display() {
		cout << Id << " " << quantity << "\n";
	}
};
bool cmpName(pair<string, Book_info> &a, pair<string, Book_info> &b){return a.first <= b.first;}
bool cmpId(pair<string, Book_info> &a, pair<string, Book_info> &b){return a.second.Id >= b.second.Id;}
struct Books {
	 pair<string, Book_info>p[100];// [ name & (Pair of -> id & quantity) ]
	void add_book() {
		cout << "Enter Id , Name, Total_Quantity: ";
		int _id; cin >> _id;
		string _name; cin >> _name;
		int _tot; cin >> _tot;
		p[booklen].first = _name;
		p[booklen].second.Id= _id;
		p[booklen].second.quantity= _tot;
		p[booklen].second._quantity = _tot;
		++booklen;
	}
	void printName() {
		for (int i = 0; i < booklen; i++) {
			sort(p, p+booklen, cmpName);
				cout << p[i].first <<" ";
				p[i].second.display();
		}
	}
	void printId() {
		for (int i = 0; i < booklen; i++) {
			sort(p, p + booklen, cmpId);
			cout << p[i].first << " ";
			p[i].second.display();
		}
	}
	void borrow(string us_name, string bk_name,int _id) {
		bool flag = false;
		for (int i = 0; i < booklen; i++) {
			if (p[i].first == bk_name&& p[i].second.Id == _id) {
				if (User_checker(us_name)) {
					if (p[i].second.quantity > 0) {
						p[i].second.borrow.push_back(us_name);
						flag = true;
						p[i].second.quantity--;
					}
					else {
						cout << "NO More Copies\n";
					}
				}
				else {
					cout<<"NO User Found\n";
				}
			}
		}
		if (flag == false) {
			cout << "NO Book Found\n";
		}
	}
void returnn(string us_name, string bk_name, int _id) {
		bool flag = false;
		for (int i = 0; i < booklen; i++) {
			if (p[i].first == bk_name && p[i].second.Id == _id && p[i].second.borrow.size() > 0) {
				//if (p[i].second._quantity == p[i].second.quantity) {
				if (User_checker(us_name)) {
					for (int j = 0; j < p[i].second._quantity; j++) {
						if (p[i].second.borrow[j] == us_name) {
							p[i].second.borrow.erase(p[i].second.borrow.begin() + j);
							p[i].second.borrow.shrink_to_fit();
							flag = true;
							p[i].second.quantity++;
							cout << "User returned the Book\n";
							break;
						}
					}
				}
				else {
					cout << "NO User Found\n";
				}
			}
		}
		if (flag == false) {
			cout << "NO Book Found\n";
		}
}
	void search(string prefix) {
		bool flag = false;
		for (int i = 0; i < booklen; i++) {
			string tmp = p[i].first.substr(0, prefix.length());
			if (tmp == prefix) {
				flag = true;
				cout << p[i].first << "\n";
			}
		}
		if (flag == false)cout << "NO Such a Book there\n";
	}
	void who_borrow(string namebk) {
		for (int i = 0; i < booklen; i++) {
			if (p[i].first == namebk) {
				for (auto& it : p[i].second.borrow) {
					cout << it << "\n";
				}
			}
		}
	}
};
int main()
{
	Books b;
	Users u;
	while (true) {
		int ch = menu();
		if (ch == 1) {
			b.add_book();
		}
		else if (ch == 2) {
			cout << "search for the book : ";
			string prefix; cin >> prefix;
			b.search(prefix);
		}
		else if (ch == 3) {
			cout << "Enter a book : ";
			string nameBk; cin >> nameBk;
			b.who_borrow(nameBk);
		}
		else if (ch == 4) {
			b.printName();
		}
		else if (ch == 5) {
			b.printId();
		}
		else if (ch == 6) {
			u.add_user();
		}
		else if (ch == 7) {
			cout << "Enter user name and book name and its Id: \n";
			string us_name, bk_name;
			cin >> us_name >> bk_name;
			int id; cin >> id;
			b.borrow( us_name, bk_name,id);
		}
		else if (ch == 8) {
			cout << "Enter user name and book name and its Id: \n";
			string us_name, bk_name;
			cin >> us_name >> bk_name;
			int id; cin >> id;
			b.returnn(us_name, bk_name, id);
		}
		else if (ch == 9) {
			u.print_user();
		}
		else if (ch == 10) {
			break;
		}
	}
	return 0;
}
