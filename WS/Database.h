#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include "Room.h"
#include <map>
using namespace std;

class Database
{
private:
	set<string> avaiable_rooms;
	int last_room_id;
	int last_user_id;
public:
	map<string, Room> rooms;
	map<string, string> user_room;
	map<string, int> user_last_msg;
	map<string, string> user_nick;
	Database() : last_room_id(0), last_user_id(0) {}
	~Database() {}
	void generate_users_rooms();
	string find_available_room();
	void clear_rooms();
	string add_new_user(string);
};

