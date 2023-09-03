/*
 * expedia_flights_api.h
 *
 *  Created on: Sep 18, 2020
 *      Author: moustafa
 */
#ifndef EXPEDIA_FLIGHTS_API_H_
#define EXPEDIA_FLIGHTS_API_H_
#include<vector>
#include<string>
#include<map>
using namespace std;
//
//struct flight {
//	virtual vector<flight*> GetAvailableFlights() = 0;
//	virtual void printFlights() = 0;
//public:
//	static int id;
//};
//int idflights = 0;

struct AirCanadaFlightcustomer {
public:
	int id = 0;
	double price;
	string date_time_from;
	string date_time_to;
	int childs;
	int adults;
	int infants;
	int tot = 0;
	int iterns = 0;
};

struct AirCanadaOnlineAPI {

public:
	AirCanadaFlightcustomer obj;
	vector<AirCanadaFlightcustomer>CanadaFlightInfo{
	{0,200, "25-01-2022", "10-02-2022" ,2,4,5},
	{ 1,250, "29-01-2022", "10-02-2022" ,5,5,5}
	};
	// vector<AirCanadaFlightcustomer> GetFlights(string from, string from_date, string to, string to_date, int adults, int childern) {
	//	vector<AirCanadaFlightcustomer> flights;
	////flights.push_back({ 0,200, "25-01-2022", "10-02-2022" ,2,4,5 });
	////	flights.push_back({ 1,250, "29-01-2022", "10-02-2022" ,5,5,5 });
	//	return flights;
	//}
	void printFlights() {
		cout << "Canada flight\n";
		for (auto& it : CanadaFlightInfo) {
			cout << "id " << it.id << " From: " << it.date_time_from << " To: " << it.date_time_to << " cost: " << it.price << "\n";
		}
	}
	/*static bool ReserveFlight(const AirCanadaFlightcustomer& flight, const AirCanadaFlightcustomer& info) {
		return true;
	}*/
};
class TurkishFlightcustomer {


public:
	int id = 0;
	double price;
	string date_time_from;
	string date_time_to;
	int childs;
	int adults;
	int infants;
	int tot = 0;//total costs
	int iterns = 0;
};


struct TurkishAirlinesOnlineAPI {

public:
	vector<TurkishFlightcustomer>TurkishFlightInfo{
	{2, 300, "10-01-2022", "10-02-2022" },
	{ 3,320, "12-01-2022", "10-02-2022" }
	};
	/*void SetFromToInfo(string datetime_from, string from, string datetime_to, string to) {
	}
	void SetPassengersInfo(int infants, int childern, int adults) {
	}*/
	// vector<TurkishFlightcustomer> GetAvailableFlights() const {
	//	vector<TurkishFlightcustomer> flights;
	////	flights.push_back({ 0,300, "10-01-2022", "10-02-2022",7,5,3 });
	////flights.push_back({ 1, 320, "12-01-2022", "10-02-2022",6,3,2 });
	//	return flights;
	//}
	void printFlights() {
		cout << "Turkish flight\n";
		for (auto& it : TurkishFlightInfo) {
			cout << "id " << it.id << " From: " << it.date_time_from << " To: " << it.date_time_to << " Cost: " << it.price << "\n";
		}
	}
	/*static bool ReserveFlight(const TurkishFlightcustomer& info, const TurkishFlightcustomer& flight) {
		return false;
	}*/
};
#endif /* EXPEDIA_FLIGHTS_API_H_ */
