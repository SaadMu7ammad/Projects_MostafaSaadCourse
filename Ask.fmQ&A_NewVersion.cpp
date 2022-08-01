#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;
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
private:
	int user_id=0;
	string user_name, pass, name, Email;
public:
	static int LenUser;
	int get_user_id() {
		return user_id;
	}
	void set_user_id(int usid) {
		 user_id=usid;
	}
	string get_user_name() {
		return user_name;
	}
	void set_user_name(string us) {
		user_name = us;
	}
	string get_pass() {
		return pass;
	}
	void set_pass(string pss) {
		pass = pss;
	}
	string get_name() {
		return name;
	}
	void set_name(string nm) {
		name = nm;
	}
	string get_Email() {
		return Email;
	}
	void set_Email(string mail) {
		Email = mail;
	}
};
int users::LenUser = 0;
struct usersProcess {
public:
	map<string, users>USERS_DATA;
	void sign_up() {
		users usr;
		cout << "sign\n";
		while (true) {
			cout << "enter username: "; 
			string usrname;
			cin >> usrname;
			 usr.set_user_name(usrname);
			if (USERS_DATA.count(usr.get_user_name()) != 0) {
				cout << "same username found Try Again ";
				continue;
			}
			else {
				break;
			}
		}
		cout << "enter pass: "; 
		string ps; cin >> ps;
		 usr.set_pass(ps);
		cout << "enter name: ";
		string nm; cin >> nm;
		usr.set_name(nm);
		cout << "enter email: "; string mail; cin >> mail;
		usr.set_Email(mail);
		usr.set_user_id(users::LenUser++);
		USERS_DATA[usr.get_user_name()] = usr;
	}
	void print_user() {
		for (auto& it : USERS_DATA) {
			cout << it.first << " " << it.second.get_user_id()<<"\n";
		}
	}
};
struct questions {
private:
	int q_id=0;
	int parent_id=0;
	int qfromusr=0;
	int qtousr=0;
	string q;
	string ans="NOT ANSWERED";
public:
	static int LenQ ;

	int get_q_id() {
		return  q_id;
	}
	void set_q_id(int qd) {
		q_id = qd;
	}
	int get_parent_id() {
		return  parent_id;
	}
	void set_parent_id(int pid) {
		parent_id = pid;
	}
	int get_qfromusr() {
		return  qfromusr;
	}
	void set_qfromusr(int qfrm) {
		qfromusr = qfrm;
	}
	int get_qtousr() {
		return  qtousr;
	}
	void set_qtousr(int qto) {
		qtousr = qto;
	}
	string get_q() {
		return q;
	}
	void set_q(string Q) {
		q = Q;
	}
	string get_ans() {
		return ans;
	}
	void set_ans(string Ans) {
		ans = Ans;
	}
};
 int questions::LenQ=0;
struct questionsprocess {
	map<int, questions>Q_DATA;//id and data about the question
	map<int,vector<int>>q2thread;//parent q linked with its q threads
	void ask() {
		questions qobj;
		cout << "enter user id or -1 to cancel: ";
		int in; cin >> in;//to user id
		if (in == -1)return;
		else {
			if (in>=0&&in<users::LenUser) {
				cout << "enter question id : or -1 to a new question: ";
				int qin; cin >> qin;
				if (qin == -1) {
					cout << "enter the question: ";
					string q; cin >> q;
					 qobj.set_q(q);
					qobj.set_parent_id ( questions::LenQ);
					qobj.set_qfromusr( CurrentUserID);
					qobj.set_qtousr ( in);
					qobj.set_q_id(questions::LenQ);
					Q_DATA[questions::LenQ] = qobj;
					q2thread[questions::LenQ].push_back(questions::LenQ);
					questions::LenQ++;
				}
				else if(qin>=0&&qin< questions::LenQ){
					cout << "enter the question: ";
					string q; cin >> q;
					 qobj.set_q(q);
					qobj.set_parent_id(qin) ;
					qobj.set_qfromusr( CurrentUserID);
					qobj.set_qtousr( in);
					qobj.set_q_id (questions::LenQ);
					Q_DATA[questions::LenQ] = qobj;
					q2thread[qobj.get_parent_id()].push_back(questions::LenQ);
					questions::LenQ++;
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
						cout << "question " << it2 << ": " << " from user " << Q_DATA[it2].get_qfromusr() << " to user " << Q_DATA[it2].get_qtousr() << " " <<Q_DATA[it2].get_q() << "\t" << Q_DATA[it2].get_ans() << " \n";
						++i;
					}
					else {
						cout << "\tThread "<< it2<< ": from user " << Q_DATA[it2].get_qfromusr() << " to user " << Q_DATA[it2].get_qtousr() <<" " << Q_DATA[it2].get_q() << "\t" << Q_DATA[it2].get_ans() << " \n";
					}
				}
		}
	}
	void answer() {
		questions q;
		cout << "enter question id or -1 to cancel: ";
		int qid; cin >> qid;
		q.set_q_id(qid);
		if (q.get_q_id() == -1) {
			return;
		}
		else if (q.get_q_id() >=0 &&q.get_q_id() < questions::LenQ) {
			cout << "enter the answer :";
			string ANS; cin >> ANS;
			 Q_DATA[q.get_q_id()].set_ans(ANS);
		}
		else {
			cout << "invalid input\n";
		}
	}
	void del() {
		questions q;
		cout << "enter a question id or -1 to cancel:";
		int qid; cin >> qid;
		 q.set_q_id(qid);
		if (q.get_q_id() == -1) {
			return;
		}
		else if (q.get_q_id() >= 0 && q.get_q_id() < questions::LenQ) {
			questions _q = Q_DATA[q.get_q_id()];
			Q_DATA.erase(_q.get_q_id());
			q2thread.erase(_q.get_q_id());
			vector<int>&v = q2thread[_q.get_parent_id()];
			int i = 0;
			for (auto& it : v) {
				if (it == _q.get_q_id()) {
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
			if (it.second.get_qtousr() == CurrentUserID) {
				cout << it.first << " from user "<<it.second.get_qfromusr()<<" to user "<<it.second.get_qtousr()<<" " << it.second.get_q() << " " << it.second.get_ans() << "\n";
			}
		}
	}
	void from_me() {//q are send from me
		for (auto& it : Q_DATA) {
			if (it.second.get_qfromusr()== CurrentUserID) {
				cout << it.first << " from user " << it.second.get_qfromusr() << " to user " << it.second.get_qtousr() << " " << it.second.get_q() << " " << it.second.get_ans() << "\n";
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
			if (upro.USERS_DATA.count(user_name) == 0|| upro.USERS_DATA[user_name].get_pass() != password) {
				cout << "NOT FOUNDED\n";
			}	
			else {
				CurrentUserID = upro.USERS_DATA[user_name].get_user_id();
				CurrentUser = upro.USERS_DATA[user_name].get_user_name();
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
