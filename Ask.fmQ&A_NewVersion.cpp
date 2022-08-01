#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;
int LenUser = 0;
int LenQ = 0;
string CurrentUser = "";
int CurrentUserID = 0;
int menu_sec() {
	while (true) {
		cout << "1)Print Questions To Me \n";
		cout << "2)Print Questions From Me\n";
		cout << "3)Answer Question\n";
		cout << "4)Delete Question\n";
		cout << "5)Ask Question\n";
		cout << "6)List System Users\n";
		cout << "7)Feed\n";
		cout << "8)Logout\n";
		int choose; cin >> choose;
		if (cin.fail()) {  //if the type of input is not valid (not appropriate) 
			cin.clear();
			cin.ignore(256, '\n');
		}
		else {
			if (choose > 8 || choose < 1) {
				continue;
			}
			return choose;
		}
	}
}
int menu_first() {
	while (true) {
		cout << "Menu:\n";
		cout << "1:Login:\n";
		cout << "2:Sign Up:\n";
		int choose; cin >> choose;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(256, '\n');
		}
		else {
			if (choose > 2 || choose < 1) {
				continue;
			}
			return choose;
		}
	}
}
struct users {
	int user_id=0;
	string user_name, pass, name, Email;
};
struct usersProcess {
	
	map<string, users>USERS_DATA;
	void sign_up() {
		users usr;
		cout << "sign\n";
		while (true) {
			cout << "enter username: "; cin >> usr.user_name;
			if (USERS_DATA.count(usr.user_name) != 0) {
				cout << "same username found Try Again ";
				continue;
			}
			else {
				break;
			}
		}
		cout << "enter pass: "; cin >> usr.pass;
		cout << "enter name: "; cin >> usr.name;
		cout << "enter email: "; cin >> usr.Email;
		usr.user_id=LenUser++;
		USERS_DATA[usr.user_name] = usr;
	}
	void print_user() {
		for (auto& it : USERS_DATA) {
			cout << it.first << " " << it.second.user_id<<"\n";
		}
	}
};
struct questions {
	int q_id=0;
	int parent_id=0;
	int qfromusr=0;
	int qtousr=0;
	string q;
	string ans="NOT ANSWERED";
};
struct questionsprocess {
	map<int, questions>Q_DATA;//id and data about the question
	map<int,vector<int>>q2thread;//parent q linked with its q threads
	void ask() {
		questions qobj;
		usersProcess usrp;
		cout << "enter user id or -1 to cancel: ";
		int in; cin >> in;//to user id
		if (in == -1)return;
		else {
			if (in>=0&&in<LenUser) {
				cout << "enter question id : or -1 to a new question: ";
				int qin; cin >> qin;
				if (qin == -1) {
					cout << "enter the question: ";
					cin >> qobj.q;
					qobj.parent_id = LenQ;
					qobj.qfromusr = CurrentUserID;
					qobj.qtousr = in;
					qobj.q_id = LenQ;
					Q_DATA[LenQ] = qobj;
					q2thread[LenQ].push_back(LenQ);
					LenQ++;			
				}
				else if(qin>=0&&qin<LenQ){  
					cout << "enter the question: ";
					cin >> qobj.q;
					qobj.parent_id=qin ;
					qobj.qfromusr = CurrentUserID;
					qobj.qtousr = in;
					qobj.q_id = LenQ;
					Q_DATA[LenQ] = qobj;
					q2thread[qobj.parent_id].push_back(LenQ);
					LenQ++;
				}
				else {
					cout << "invalid question id\n";
				}
			}
			else {
				cout << "invalid user id\n";
			}
		}
	}
	void feed() {
		for (auto& it : Q_DATA){
				int i = 0;
				for (auto& it2 : q2thread[it.first]) {
					if (i == 0) {
						cout << "question " << it2 << ": " << " from user " << Q_DATA[it2].qfromusr << " to user " << Q_DATA[it2].qtousr << " " <<Q_DATA[it2].q << "\t" << Q_DATA[it2].ans << " \n";
						++i;
					}
					else {
						cout << "\tThread "<< it2<< ": from user " << Q_DATA[it2].qfromusr << " to user " << Q_DATA[it2].qtousr  <<" " << Q_DATA[it2].q << "\t" << Q_DATA[it2].ans << " \n";
					}
				}
		}
	}
	void answer() {
		questions q;
		cout << "enter question id or -1 to cancel: ";
		cin >> q.q_id;
		if (q.q_id == -1) {
			return;
		}
		else if (q.q_id >=0 &&q.q_id <LenQ) {
			cout << "enter the answer :";
			cin >> Q_DATA[q.q_id].ans;
		}
		else {
			cout << "invalid input\n";
		}
	}
	void del() {
		questions q;
		cout << "enter a question id or -1 to cancel:";
		cin >> q.q_id;
		if (q.q_id == -1) {
			return;
		}
		else if (q.q_id >= 0 && q.q_id < LenQ) {
			questions _q = Q_DATA[q.q_id];
			Q_DATA.erase(_q.q_id);
			q2thread.erase(_q.q_id);
			vector<int>&v = q2thread[_q.parent_id];
			int i = 0;
			for (auto& it : v) {
				if (it == _q.q_id) {
					v.erase(v.begin()+i);
					break;
				}
				++i;
			 }
		}
		else {
			cout << "invalid input\n";
		}
	}
	void to_me() {//q are send to me
		for (auto& it : Q_DATA) {
			if (it.second.qtousr == CurrentUserID) {
				cout << it.first << " from user "<<it.second.qfromusr<<" to user "<<it.second.qtousr<<" " << it.second.q << " " << it.second.ans << "\n";
			}
		}
	}
	void from_me() {//q are send from me
		for (auto& it : Q_DATA) {
			if (it.second.qfromusr== CurrentUserID) {
				cout << it.first << " from user " << it.second.qfromusr << " to user " << it.second.qtousr << " " << it.second.q << " " << it.second.ans << "\n";
			}
		}
	}
};
int main() {
	usersProcess upro;
	questionsprocess qpro;
	while (true) {
		int choose = menu_first();
		if (choose == 1) {
			cout << "login\nEnter username and pass: \n";
			string user_name, password;
			cin >> user_name >> password;
			if (upro.USERS_DATA.count(user_name) == 0|| upro.USERS_DATA[user_name].pass != password) {
				cout << "NOT FOUNDED\n";
			}	
			else {
				CurrentUserID = upro.USERS_DATA[user_name].user_id;
				CurrentUser = upro.USERS_DATA[user_name].user_name;
				while (true) {
					int choose2 = menu_sec();
					if (choose2 == 1) {
						qpro.to_me();
					}
					else if (choose2 == 2) {
					qpro.from_me();
					}
					else if (choose2 == 3) {
						qpro.answer();
					}
					else if (choose2 == 4) {
						qpro.del();
					}
					else if (choose2 == 5) {
						qpro.ask();
					}
					else if (choose2 == 6) {
						upro.print_user();
					}
					else if (choose2 == 7) {
						qpro.feed();
					}
					else if (choose2 == 8) {
						break;
					}
				}
			}
		}
		else if (choose == 2) {
			upro.sign_up();
		}
	}
	return 0;
}
