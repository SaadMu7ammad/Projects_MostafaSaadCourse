#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int menu() {
	while (true) {
		cout << "1)Add new Patient\n";
		cout << "2)Print All Patient\n";
		cout << "3)Get Next Patient\n";
		cout << "4)Exit\n";
		int choose; cin >> choose;
		if (choose < 1 || choose>4) {
			cout << "Invalid Try Again\n";
			continue;
			//return -1;
		}
		else {
			return choose;
		}
	}
}
struct Data {
	deque<string>name;
	deque<int>status;

	void display(int _i) {
		if (name.size() > 0)cout << "Specialization :" << _i << "\n";
		for (int i = 0; i < name.size(); i++) {
			cout << name[i] << " ";
			
			if (status[i] == 1)cout << "Urgent\n";
			else cout << "Regular\n";
		}
	}
};
struct hospital {
	Data specs[20];
	void add() {
		cout << "Enter Specs, Name, Status :\n";

		int spec; cin >> spec;
		string name; cin >> name;
		int status; cin >> status;
		if (specs[spec].name.size() >= 5) {
			cout << "sorry cant take an appointment now ! \n";
		}
		else {
			if (status == 0) {  
			specs[spec].name.push_back(name);
			specs[spec].status.push_back(status);
			}
			else if (status == 1) {
				specs[spec].name.push_front(name);
				specs[spec].status.push_front(status);
			}	
		}
	}
	void print() {
		for (int i = 0; i < 20; i++) {
			specs[i].display(i);
		}
	}
	void next() {
		cout << "choose a specialization : ";
		int _spec; cin >> _spec;
		if (_spec >= 0 && _spec < 20) {
			if (specs[_spec].name.size() > 0) {
				cout << "Mr-Ms " << specs[_spec].name.front()<<" go to Dr please \n";
				specs[_spec].name.pop_front();
				specs[_spec].status.pop_front();
			}
			else {
				cout << "No one for this specs \n Take a rest Dr \n";
			}
		}
	}
};
int main() {
	hospital obj;
	while (true) {
		int ch = menu();
		if (ch == 1) {
			obj.add();
		}
		else if (ch == 2) {
			obj.print();
		}
		else if (ch == 3) {
			obj.next();
		}
		else if (ch == 4) {
			break;
		}
	}
	return 0;
}
