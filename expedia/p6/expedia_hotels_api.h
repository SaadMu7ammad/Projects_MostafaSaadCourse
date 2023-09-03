/*
 * expedia_hotels_api.h
 *
 *  Created on: Sep 22, 2020
 *      Author: moustafa
 */

#ifndef EXPEDIA_HOTELS_API_H_
#define EXPEDIA_HOTELS_API_H_
using namespace std;
#include<string>
#include<vector>
struct HiltonRoom {
public:
	int id;
	string room_type;
	int available;
	double price_per_night;
	string date_from;
	string date_to;
	int tempavail;
	int childs;
	int adults;
	int infants;
	int tot = 0;
	int iterns = 0;

};
vector<HiltonRoom>HiltonInfo{
	{0,"Interior View", 6, 200.0, "29-01-2022", "10-02-2022" ,6},
	{1, "City View", 3, 300.0, "29-01-2022", "10-02-2022" ,3},
	{2,"green View", 4, 500, "29-05-2022", "03-06-2022",4 }
};
struct HiltonHotelAPI {
public:
	/*static vector<HiltonRoom> SearchRooms(string country, string city, string from_date, string to_date, int adults, int children, int needed_rooms) {
		vector<HiltonRoom> rooms;
		rooms.push_back({ "Interior View", 6, 200.0, "29-01-2022", "10-02-2022" });
		rooms.push_back({ "City View", 3, 300.0, "29-01-2022", "10-02-2022" });
		rooms.push_back({ "City View", 3, 300.0, "29-01-2022", "10-02-2022" });
		return rooms;
	}*/
	//HiltonRoom obj;

	// HiltonHotelAPI() {
	//	//cout << "Hilton \n";
	//	for (auto& it : HiltonInfo) {
	//	//	it.available = it.tempavail;
	//		//cout << "id " << it.id << " RoomType: " << it.room_type << " price/night: " << it.price_per_night << " From: " << it.date_from << " To " << it.date_to << " Available " << it.available << "\n";
	//	}
	//}
	void printrooms() {
		cout << "Hilton \n";
		for (auto& it : HiltonInfo) {
			//it.available = it.tempavail;
			cout << "id " << it.id << " RoomType: " << it.room_type << " price/night: " << it.price_per_night << " From: " << it.date_from << " To " << it.date_to << " Available " << it.available << "\n";
		}
	}
};

struct MarriotRoom {
public:
	//int tempavail = 0;
	int id;
	string room_type;
	int available;
	double price_per_night;
	string date_from;
	string date_to;
	int tempavail;
	int childs;
	int adults;
	int infants;
	int tot = 0;
	int iterns = 0;

};
vector<MarriotRoom>MarriotInfo{
	{3, "City View", 8, 320.0, "29-01-2022", "10-02-2022" ,8},
	{ 4,"Interior View", 8, 220.0, "29-01-2022", "10-02-2022" ,8},
	{ 5,"Private View", 3, 600.0, "29-01-2022", "10-02-2022" ,3}
};

struct MarriottHotelAPI {
public:
	/*static vector<MarriottFoundRoom> FindRooms(string from_date, string to_date, string country, string city, int needed_rooms, int adults, int children) {
		vector<MarriottFoundRoom> rooms;

		rooms.push_back({ "City View", 8, 320.0, "29-01-2022", "10-02-2022" });
		rooms.push_back({ "Interior View", 8, 220.0, "29-01-2022", "10-02-2022" });
		rooms.push_back({ "Private View", 5, 600.0, "29-01-2022", "10-02-2022" });

		return rooms;
	}*/
	//MarriotRoom obj;

	// MarriottHotelAPI() {
	//	//cout << "Marriot \n";
	//	for (auto& it : MarriotInfo) {
	//	//	it.available = it.tempavail;
	//		//cout << "id " << it.id << " RoomType: " << it.room_type << " price/night: " << it.price_per_night << " From: " << it.date_from<<" To "<<it.date_to <<" Available "<<it.available << "\n";
	//	}
	//}
	void printrooms() {
		cout << "Marriot \n";
		for (auto& it : MarriotInfo) {
			//it.available = it.tempavail;
			cout << "id " << it.id << " RoomType: " << it.room_type << " price/night: " << it.price_per_night << " From: " << it.date_from << " To " << it.date_to << " Available " << it.available << "\n";
		}
	}
};

#endif /* EXPEDIA_HOTELS_API_H_ */
