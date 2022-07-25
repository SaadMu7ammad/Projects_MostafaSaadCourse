#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int LenUser = 0;
int IDQuesALL = 0;
string CurrentUser = "";
int CurrentUserID = 0;
int menu_sec()  {
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
			cin.ignore(256,'\n');
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
	string user_name, pass, name, Email;
	int ID;
public:
	users() {
		ID = 0;
	}
	 void set_user_name(string &name) {
		user_name = name;
	}
	 void set_pass(string &pass) {
		this->pass = pass;
	}
	 void set_name(string &name) {
		this->name = name;
	}
	 void set_email(string &mail) {
		Email = mail;
	}
	 void set_id(int id) {
		ID = id;
	}
	 string get_user_name() {
		 return user_name ;
	}
	 string get_pass() {
		return pass;
	}
	 string get_name() {
		return name;
	}
	 string get_email() {
		return Email ;
	}
	 int get_id() {
		return ID;
	}
};
vector<users>allusers(1000);  
struct user_info
{
	void sign_up() {
		cout << "sign\n";
		string _usname, _pass, _name, _Email;
		cout << "enter username: "; cin >> _usname;
		cout << "enter pass: "; cin >> _pass;
		cout << "enter name: "; cin >> _name;
		cout << "enter email: "; cin >> _Email;
		allusers[LenUser].set_user_name(_usname);
		allusers[LenUser].set_pass(_pass);
		allusers[LenUser].set_name(_name);
		allusers[LenUser].set_email(_Email);
		allusers[LenUser].set_id(LenUser);
		++LenUser;
	}
	 int login(string name, string _pass) {//string usname, string password
		cout << "Profile: \n";
		for (int i = 0; i < LenUser; i++) {
			if (allusers[i].get_user_name() == name && allusers[i].get_pass() == _pass) {
				CurrentUser = name;
				CurrentUserID = allusers[i].get_id();
				return  i;
			}
		}
		return -1;
	}
	void print_user() {
		for (int i = 0; i < LenUser; i++) {
			cout << allusers[i].get_id() << "    " << allusers[i].get_name() << "\n";
		}
	}
}; 
map<int, vector<string>>mpFrom;//from -> to user
void _del(int _q) {
	for (int i = 0; i < LenUser; i++) {
		for (auto& it : mpFrom[i]) {
			if (it!=""&&it.substr(9, 1) == to_string(_q)) {
				it = "";
				cout << "deleted\n";
			}
			else if (it != "" && it.substr(7, 1) == to_string(_q)  ) {
				it = "";
				cout << "deleted\n";

			}
		}
	}
}
struct question {//each user
private:
	int user_id=0;
	public:
		int q_id = 0;
	vector<pair<int,pair<string, string>>>Question;//q id with Q and ANS
	 void set_user_id(int id) {
		user_id = id;
	}
	 int get_user_id() {
		return user_id;
	}
};
question q[1000];//q[ userID ]
struct Threadquestion {//each question
private:
	 int q_id=0;
public:
	vector<pair<int, pair<string, string>>>TQuestion;//Qid
	void set_q_id(int q_id) {
		this->q_id = q_id;
	}
	int get_q_id() {
		return q_id;
	}
};
Threadquestion Tq[1000];//Tq[ questionIDParent ]
 void TdispQ(int q_id) {
	for (auto& it2 : Tq[q_id].TQuestion) {
		cout <<"\t" << it2.second.first << "\t\t " << it2.second.second << "\n";
	}
}
 void dispQ(int user) {
	for (auto& it : q[user].Question) {
			cout   << it.second.first << "\t\t" << it.second.second << "\n";
			TdispQ(it.first);
	}
}
 struct question_info {
 public:
	 void ask() {
		 cout << "Enter user_id or -1 to cancel: ";
		 int user_id; cin >> user_id;
		 if (user_id == -1) {
			 return;
		 }
		 else {
			 if (user_id >= 0 && user_id < LenUser) {
				 cout << "Enter Question id for Thread or -1 to a New question: ";
				 int in; cin >> in;
				 if (in == -1) {
					 cout << "Enter the qustion: ";
					 string Quest; cin >> Quest;
					 string extra = "Question(" + to_string(IDQuesALL) + ") from user (" + to_string(CurrentUserID) + ") To User (" + to_string(user_id) + ")  :";
					 extra += Quest;
					 pair<int, pair<string, string>>temp;
					 temp.first = IDQuesALL;
					 temp.second.first = extra;
					 temp.second.second = "NOT ANSWERED";
					 q[user_id].Question.push_back(temp);
					 q[user_id].set_user_id(user_id);
					mpFrom[CurrentUserID].push_back(extra + "\t" + temp.second.second);
					 ++IDQuesALL;
				 }
				 else if (in >= 0 && in < IDQuesALL) {
					 cout << "Enter the qustion: ";
					 string Quest; cin >> Quest;
					 pair<int, pair<string, string>>temp;
					 string extra = "Thread(" + to_string(IDQuesALL) + ") from user (" + to_string(CurrentUserID) + ") To User (" + to_string(user_id) + "): ";
					 extra += Quest;
					 temp.first = IDQuesALL;
					 temp.second.first = extra;
					 temp.second.second = "NOT ANSWERED";
					 Tq[in].set_q_id(in);//in>> parent
					 Tq[in].TQuestion.push_back(temp);  //in >> IDQuestion For the Parent q
					 mpFrom[CurrentUserID].push_back(extra + "\t" + temp.second.second);
					 ++IDQuesALL;
				 }
				 else {
					 cout << "Invalid \n";
				 }
			 }
			 else {
				 cout << "NO such a user with id \n";
			 }
		 }
	 }
	 void answer() {
		 cout << "Enter Question ID or -1 to cancel: ";
		 int id; cin >> id;
		 if (id == -1) {
			 return;
		 }
		 else if (id >= 0 && id < IDQuesALL) {
			 for (int i = 0; i < LenUser; i++) {
				 for (auto& it : q[i].Question) {
					 if (it.first == id) {
						 cout << "Answer the Q: ";
						 string ans; cin >> ans;
						 it.second.second = ans;
						 break;
					 }
					 for (auto& it2 : Tq[it.first].TQuestion) {
						 if (it2.first == id) {
							 cout << "Answer the Q: ";
							 string ans; cin >> ans;
							 it2.second.second = ans;
						 }
					 }
				 }
			 }
		 }
		 else {
			 cout << "Invalid\n";
		 }
	 }
	 void feed() {
		 for (int i = 0; i < LenUser; i++) {
			 dispQ(i);
		 }
	 }
	 void to_me() {
		 dispQ(CurrentUserID);
	 }
	 void from_me() {
			 for (auto& it : mpFrom[CurrentUserID]) {
				 if(it!="" && it.substr(23, 1) == to_string(CurrentUserID))
				 cout << it << "\n";
				 if (it != "" && it.substr(21, 1) == to_string(CurrentUserID))
					 cout << it << "\n";
			 }
	 }
	void del() {
		cout << "Enter Question ID or -1 to cancel: ";
		int id; cin >> id;
		if (id == -1) {
			return;
		}
		else if (id >= 0 && id < IDQuesALL) {
			bool br = false;
			for (int i = 0; i < LenUser; i++) {
				int tr = 0;
				for (auto& it : q[i].Question) {//question to each user			
					if (it.first == id) {
						q[i].Question.erase(q[i].Question.begin()+tr);
						_del(id);
						for (auto& it2 : Tq[it.first].TQuestion) {
						_del(it2.first);
						}
						Tq[it.first].TQuestion.clear();
						br = true;
						break;
					}
					int tracker = 0;
					for (auto& it2 : Tq[it.first].TQuestion) {
						if (it2.first == id) {
							Tq[it.first].TQuestion.erase(Tq[it.first].TQuestion.begin() + tracker);
							_del(id);
						}
						++tracker;
					}
					++tr;
				}
				if (br) {
					break;
				}
			}
		}
		else {
			cout << "Invalid\n";
		}
	}	
};
int main() {
	users u;
	user_info uinfo;
	question_info q_info;
	while (true){
		int choose = menu_first();
		if (choose == 1) {
			cout << "login\nEnter username and pass: \n";
			string user_name, password;
			cin >> user_name >> password;
			int output = uinfo.login(user_name, password);
			if (output == -1) {
				cout << "NOT FOUNDED\n";
			}
			else {
				while (true) {
					int choose2 = menu_sec();
					if (choose2 == 1) {		
					q_info.to_me();
					}
					else if (choose2 == 2) {
						q_info.from_me();
					}
					else if (choose2 == 3) {
						q_info.answer();
					}
					else if (choose2 == 4) {
						q_info.del();
					}
					else if (choose2 == 5) {
						q_info.ask();
					}
					else if (choose2 == 6) {
						uinfo.print_user();
					}
					else if (choose2 == 7) {
						q_info.feed();
					}
					else if (choose2 == 8) {
						break;
					}
				}
			}
		}
		else if (choose == 2) {
			uinfo.sign_up();
		}
	}
	return 0;
}
