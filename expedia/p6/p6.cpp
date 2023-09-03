#include <iostream>
#include<map>
#include"expedia_flights_api.h"
#include"expedia_hotels_api.h"
using namespace std;
string Currentuser;
int menu() {
    while (true) {
        cout << "1:Login \n";
        cout << "2:SignUp \n";
        int ch; cin >> ch;
        if (cin.fail()) {
            cout << "Enter 1 or 2(Numeric Input)\n";
            cin.clear();
            cin.ignore(256, '\n');
            continue;
        }
        if (ch != 1 && ch != 2) {
            cout << "Enter 1 or 2\n";
            continue;
        }
        return ch;
    }
}
int menu_2() {
    while (true) {
        cout << "1: View Profile\n";
        cout << "2: Make Itinerary\n";
        cout << "3: List My Itineraries\n";
        cout << "4: Logout\n";
        int ch; cin >> ch;
        if (cin.fail()) {
            cout << "Enter 1 or 2(Numeric Input)\n";
            cin.clear();
            cin.ignore(256, '\n');
            continue;
        }
        if (ch > 4 || ch < 1) {
            cout << "Enter 1 to 4\n";
            continue;
        }
        return ch;
    }
}
int menu_3() {
    while (true) {
        cout << "1: Add flight \n";
        cout << "2: Add hotel \n";
        cout << "3: Done\n";
        cout << "4: Cancel\n";
        int ch; cin >> ch;
        if (cin.fail()) {
            cout << "Enter 1 or 2(Numeric Input)\n";
            cin.clear();
            cin.ignore(256, '\n');
            continue;
        }
        if (ch > 4 || ch < 1) {
            cout << "Enter 1 to 4\n";
            continue;
        }
        return ch;
    }
}

struct user {
private:
    int iduser = 0;
    string user_name;
    string email;
    string pass;
    string name;
    // int total = 0;

   //  vector<flight*>allflights;
public:
    map<string, vector <AirCanadaFlightcustomer>>name_canadaobject;
    map<string, vector <TurkishFlightcustomer>>name_Turkishobject;

    map<string, vector <AirCanadaFlightcustomer>>Tempname_canadaobject;
    map<string, vector <TurkishFlightcustomer>>Tempname_Turkishobject;

    map<string, vector <AirCanadaFlightcustomer>>Fixedname_canadaobject;
    map<string, vector <TurkishFlightcustomer>>Fixedname_Turkishobject;


    map<string, vector <HiltonRoom>>name_hiltonbject;
    map<string, vector <MarriotRoom>>name_mariotobject;

    map<string, vector <HiltonRoom>>Tempname_hiltonbject;
    map<string, vector <MarriotRoom>>Tempname_mariotobject;

    map<string, vector <HiltonRoom>>Fixedname_hiltonbject;
    map<string, vector <MarriotRoom>>Fixedname_mariotobject;








    map<string, int>creditcard;
    map<string, int>debitcard;
    static int iternslen;
    static int id;

    int get_iduser() {
        return iduser;
    }
    void set_iduser(int iduser) {
        this->iduser = iduser;
    }
    void set_user_name(string user_name) {
        this->user_name = user_name;
    }
    string get_user_name() {
        return user_name;
    }
    void set_pass(string pass) {
        this->pass = pass;
    }
    string get_pass() {
        return pass;
    }
    string get_name() {
        return name;
    }
    void set_name(string name) {
        this->name = name;
    }
    string get_email() {
        return email;
    }
    void set_email(string email) {
        this->email = email;
    }
    void print() {
        cout << "User View:\n";
        cout << "\tuser Name : " << user_name << endl;
        cout << "\tName : " << name << endl;
        cout << "\tEmail : " << email << endl;
    }
    void addflight() {
        AirCanadaFlightcustomer objcan;
        TurkishFlightcustomer objturk;
        cout << "Country From : ";
        string countryfrom; cin >> countryfrom;
        cout << "from date: (dd-mm-yy): ";
        string datefrom; cin >> datefrom;
        cout << "Country To:";
        string countryto; cin >> countryto;
        cout << "To date: (dd-mm-yy): ";
        string dateto; cin >> dateto;
        int adultnum, childnum, infantnum;

        cout << "Enter num of adults  ";  cin >> adultnum;
        cout << "enter num of childs: "; cin >> childnum;
        cout << "enter num of infants: "; cin >> infantnum;
        AirCanadaOnlineAPI obj;
        obj.printFlights();
        TurkishAirlinesOnlineAPI obj2;
        obj2.printFlights();

        cout << "Choose a flight : ";
        int choose; cin >> choose;
        if (choose < 0) {
            cout << "Invalid id\n";
        }
        else {

            for (auto& it : obj2.TurkishFlightInfo) {
                if (it.id == choose) {
                    objturk.id = it.id;
                    objturk.childs = childnum;
                    objturk.adults = adultnum;
                    objturk.date_time_from = datefrom;
                    objturk.date_time_to = dateto;
                    objturk.infants = infantnum;
                    objturk.price = it.price;
                    objturk.tot = (it.price * (objturk.childs + objturk.adults));
                    objturk.iterns = user::iternslen;
                    Tempname_Turkishobject[user_name].push_back(objturk);

                }
            }
            for (auto& it : obj.CanadaFlightInfo) {
                if (it.id == choose) {
                    objcan.id = it.id;
                    objcan.childs = childnum;
                    objcan.adults = adultnum;
                    objcan.date_time_from = datefrom;
                    objcan.date_time_to = dateto;
                    objcan.infants = infantnum;
                    objcan.price = it.price;
                    objcan.tot = (it.price * (objcan.childs + objcan.adults));
                    objcan.iterns = user::iternslen;

                    Tempname_canadaobject[user_name].push_back(objcan);

                }
            }
        }
    }
    void flightconfirm() {
        AirCanadaFlightcustomer objcan;
        TurkishFlightcustomer objturk;
        vector< AirCanadaFlightcustomer>arrcan = Tempname_canadaobject[user_name];
        vector< TurkishFlightcustomer>arrturk = Tempname_Turkishobject[user_name];

        for (auto it : arrcan)Fixedname_canadaobject[user_name].push_back(it);
        for (auto it2 : arrturk)Fixedname_Turkishobject[user_name].push_back(it2);


        //name_canadaobject[user_name]=arrcan;
       // name_Turkishobject[user_name] = arrturk;
        Tempname_canadaobject[user_name].clear();
        Tempname_Turkishobject[user_name].clear();
        name_canadaobject[user_name].clear();
        name_Turkishobject[user_name].clear();

        user::iternslen++;
    }
    void flightcancel() {
        Tempname_canadaobject[user_name].clear();
        Tempname_Turkishobject[user_name].clear();
        name_canadaobject[user_name].clear();
        name_Turkishobject[user_name].clear();
    }

    /*void flightfixed() {
        AirCanadaFlightcustomer objcan;
        TurkishFlightcustomer objturk;
        vector< AirCanadaFlightcustomer>arrcan = name_canadaobject[user_name];
        vector< TurkishFlightcustomer>arrturk = name_Turkishobject[user_name];

        Fixedname_canadaobject[user_name] = arrcan;
        Fixedname_Turkishobject[user_name] = arrturk;

        name_canadaobject[user_name].clear();
        name_Turkishobject[user_name].clear();

    }*/




    void addroom() {
        MarriotRoom objmar;
        HiltonRoom objhil;
        //user  * u;
       // user_process up;
       // u =&(up.name_user_map[Currentuser]);
        cout << "from date: (dd-mm-yy): ";
        string datefrom; cin >> datefrom;
        cout << "Country:";
        string country; cin >> country;
        cout << "City:";
        string city; cin >> city;
        cout << "To date: (dd-mm-yy): ";
        string dateto; cin >> dateto;
        /* cout << "Enter num of availablity:  ";
         int av; cin >> av;*/
        int adultnum, childnum, infantnum;
        cout << "Enter num of adults  ";  cin >> adultnum;
        cout << "enter num of childs: "; cin >> childnum;
        cout << "enter num of infants: "; cin >> infantnum;


        MarriottHotelAPI obj;
        obj.printrooms();
        HiltonHotelAPI obj2;
        obj2.printrooms();


        //for (auto& it : HiltonInfo) {
        //      // if ( it.tot != 0) {
        //           cout << "Hilton "; cout << "id " << it.id << " RoomType: " << it.room_type << " price/night: " << it.price_per_night << " From: " << it.date_from << " To " << it.date_to << " Available " << it.available << "\n";
        //           
        //      // }
        //   }
        //   for (auto& it :MarriotInfo) {
        //      // if (it.tot != 0) {
        //           cout << "Marriot ";  cout << "id " << it.id << " RoomType: " << it.room_type << " price/night: " << it.price_per_night << " From: " << it.date_from << " To " << it.date_to << " Available " << it.available << "\n";
        //         
        //      /// }
        //   }

        cout << "Choose a room : ";
        int choose; cin >> choose;
        if (choose < 0) {
            cout << "Invalid id\n";
        }
        else {
            // int i = 0;
            for (auto& it : HiltonInfo) {

                if (it.id == choose) {
                    objhil.id = it.id;
                    objhil.childs = childnum;
                    objhil.adults = adultnum;
                    objhil.date_from = datefrom;
                    objhil.date_to = dateto;
                    objhil.infants = infantnum;
                    objhil.price_per_night = it.price_per_night;
                    objhil.available = it.available;
                    objhil.tempavail = it.tempavail;//temp

                    objhil.iterns = user::iternslen;
                    objhil.tot = (it.price_per_night * (objhil.childs + objhil.adults));
                    if (it.tempavail >= 1) {
                        //it.available--;
                        it.tempavail--;
                        objhil.tempavail = it.tempavail;
                        //  objhil.available--;

                    }
                    else
                    {
                        cout << "No more available rooms\n";
                        return;
                    }
                    Tempname_hiltonbject[user_name].push_back(objhil);
                }
                //  ++i;
            }
            // int i = 0;
            for (auto& it : MarriotInfo) {
                if (it.id == choose) {

                    objmar.id = it.id;
                    objmar.childs = childnum;
                    objmar.adults = adultnum;
                    objmar.date_from = datefrom;
                    objmar.date_to = dateto;
                    objmar.infants = infantnum;
                    objmar.price_per_night = it.price_per_night;
                    objmar.tot = (it.price_per_night * (objmar.adults + objmar.childs));
                    objmar.iterns = user::iternslen;
                    objmar.available = it.available;
                    if (it.tempavail >= 1) {
                        // it.available--;
                        it.tempavail--;
                        // objmar.available--;      
                        objmar.tempavail = it.tempavail;//temp

                    }
                    else {
                        cout << "No more available rooms\n";
                        return;
                    }
                    Tempname_mariotobject[user_name].push_back(objmar);
                }
                //  ++i;
            }
        }
    }
    void roomconfirm() {

        MarriotRoom objmar;
        HiltonRoom objhil;
        vector< MarriotRoom>arrmar = Tempname_mariotobject[user_name];
        vector< HiltonRoom>arrhil = Tempname_hiltonbject[user_name];


        for (auto& it : arrmar)Fixedname_mariotobject[user_name].push_back(it);
        for (auto& it2 : arrhil)Fixedname_hiltonbject[user_name].push_back(it2);


        for (auto& it : Fixedname_mariotobject[user_name]) {

            it.available = it.tempavail;

        }
        for (auto& it2 : Fixedname_hiltonbject[user_name]) {

            it2.available = it2.tempavail;

        }
        name_hiltonbject[user_name].clear();
        name_mariotobject[user_name].clear();
        Tempname_mariotobject[user_name].clear();
        Tempname_hiltonbject[user_name].clear();

        user::iternslen++;

    }
    void roomcancel() {
        Tempname_mariotobject[user_name].clear();
        Tempname_hiltonbject[user_name].clear();
        name_hiltonbject[user_name].clear();
        name_mariotobject[user_name].clear();
        for (auto& it : Fixedname_mariotobject[user_name]) {

            it.tempavail = it.available;

        }for (auto& it : Fixedname_hiltonbject[user_name]) {

            it.tempavail = it.available;

        }
    }
    void pay() {
        while (true) {
            cout << "select payment choice: \n";
            cout << "1: Debit Card " << ":Owner " << Currentuser << "Card Number " << creditcard[Currentuser] << endl;
            cout << "2: Credit Card " << ":Owner " << Currentuser << "Card Number " << debitcard[Currentuser] << endl;
            int ch; cin >> ch;
            if (cin.fail()) {
                cout << "Enter 1 or 2(Numeric Input)\n";
                cin.clear();
                cin.ignore(256, '\n');
                continue;
            }
            if (ch != 1 && ch != 2) {
                cout << "Enter 1 or 2\n";
                continue;

            }
            else if (ch == 1) {
                cout << "Debit Card\n";
                cout << "Money WithDraw Successfully \n";
                break;

            }
            else if (ch == 2) {
                cout << "Credit Card\n";
                cout << "Money WithDraw Successfully \n";
                break;

            }
        }

    }
    /*  void roomfixed() {
          MarriotRoom objmar;
          HiltonRoom objhil;
          vector< MarriotRoom>arrmar = name_mariotobject[user_name];
          vector< HiltonRoom>arrhil = name_hiltonbject[user_name];

          Fixedname_hiltonbject[user_name] = arrhil;
          Fixedname_mariotobject[user_name] = arrmar;

          name_mariotobject[user_name].clear();
          name_hiltonbject[user_name].clear();

      }*/
};
int user::id = 0;
int user::iternslen = 0;
struct user_process {

public:
    map<string, user>name_user_map;
    void sign_up() {
        user u;
        cout << "enter username: ";
        string us_name; cin >> us_name;
        cout << "enter name: ";
        string name; cin >> name;
        cout << "enter email: ";
        string email; cin >> email;
        cout << "enter password: ";
        string pass; cin >> pass;
        cout << "Enter number of your debit card ";
        int numdeb; cin >> numdeb;
        cout << "Enter number of your credit card ";
        int numcred; cin >> numcred;
        if (name_user_map.count(us_name)) {
            cout << "username is already used Another username\n ";
            return;
        }
        else {
            u.set_name(name);
            u.set_user_name(us_name);
            u.set_email(email);
            u.set_pass(pass);
            u.set_iduser(user::id);
            u.creditcard[us_name] = numcred;
            u.debitcard[us_name] = numdeb;
            name_user_map[us_name] = u;
            user::id++;
        }
    }
    void login() {
        user* u;
        cout << "Enter username: ";
        string usname; cin >> usname;
        cout << "Enter password: ";
        string pass; cin >> pass;
        if (name_user_map.count(usname)) {
            u = &name_user_map[usname];
            if (u->get_pass() == pass) {
                //getinside profile;
                cout << "Hello\n";
                Currentuser = usname;
                while (true) {
                    int ch = menu_2();
                    if (ch == 1) {
                        u->print();//view profile
                    }
                    else if (ch == 2) {// make itinerary
                        while (true) {


                            int choose = menu_3();
                            if (choose == 1) {
                                //Add Flight
                                u->addflight();
                            }
                            else if (choose == 2) {
                                //Add Hotel
                                u->addroom();
                            }
                            else if (choose == 3) {
                                u->flightconfirm();
                                //  u.flightfixed();

                                u->roomconfirm();
                                // u.roomfixed();
                                    //Done
                                //go to payment section
                                u->pay();
                                //  MarriottHotelAPI();
                                  //HiltonHotelAPI();

                            }
                            else if (choose == 4) {
                                u->flightcancel();
                                u->roomcancel();
                                break;//Cancel
                            }
                        }
                    }
                    else if (ch == 3) {//list itineraries
                        for (int i = 0; i < user::iternslen; i++) {
                            int tot = 0;
                            for (auto& it : u->Fixedname_canadaobject[Currentuser]) {
                                if (it.iterns == i && it.tot != 0) {
                                    cout << "canada :  id " << it.id << " From: " << it.date_time_from << " To: " << it.date_time_to << " cost: " << it.price << "\n";
                                    cout << "Cost: " << it.tot << "\n";
                                    tot += it.tot;
                                }
                            }
                            for (auto& it : u->Fixedname_Turkishobject[Currentuser]) {
                                if (it.iterns == i && it.tot != 0) {
                                    cout << "Turkish : id " << it.id << " From: " << it.date_time_from << " To: " << it.date_time_to << " cost: " << it.price << "\n";
                                    cout << "Cost: " << it.tot << "\n";
                                    tot += it.tot;
                                }
                            }
                            for (auto& it : u->Fixedname_hiltonbject[Currentuser]) {
                                if (it.iterns == i && it.tot != 0) {
                                    cout << "Hilton "; cout << "id " << it.id << " RoomType: " << it.room_type << " price/night: " << it.price_per_night << " From: " << it.date_from << " To " << it.date_to << " Available " << it.available << "\n";
                                    tot += it.tot;
                                    cout << "Cost: " << it.tot << "\n";
                                    for (int i = 0; i < HiltonInfo.size(); i++) {
                                        if (HiltonInfo[i].id == it.id) {
                                            HiltonInfo[i].available = it.available;
                                        }
                                    }
                                }
                            }
                            for (auto& it : u->Fixedname_mariotobject[Currentuser]) {
                                if (it.iterns == i && it.tot != 0) {
                                    cout << "Marriot ";  cout << "id " << it.id << " RoomType: " << it.room_type << " price/night: " << it.price_per_night << " From: " << it.date_from << " To " << it.date_to << " Available " << it.available << "\n";
                                    tot += it.tot;
                                    cout << "Cost: " << it.tot << "\n";
                                    for (int i = 0; i < MarriotInfo.size(); i++) {
                                        if (MarriotInfo[i].id == it.id) {
                                            MarriotInfo[i].available = it.available;
                                        }
                                    }
                                }
                            }
                            if (tot != 0) {
                                cout << "\nTOTAL= " << tot << endl;;
                                cout << "*********************************************************\n";
                            }
                        }
                    }
                    else if (ch == 4) {//logout
                        break;
                    }
                }
                return;
            }
        }
        cout << "No Such User \n";
        return;
    }
    void printusers() {
        for (auto& it : name_user_map)cout << it.first << "\n";
    }
    /* user_process * sendaddres() {
         return u->Fixedname_mariotobject[Currentuser];
     }*/

};
int main()
{
    user_process up;
    while (true) {
        int choose = menu();//login or signUp
        if (choose == 1) {
            up.login();
            //up.printusers();
        }
        else if (choose == 2) {
            up.sign_up();
        }
    }
    return 0;
}