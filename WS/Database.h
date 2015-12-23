#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "Room.h"
#include <map>
using namespace std;

class Database
{
private:
	
public:
	map<string, Room> rooms;
	map<string, string> user_room;
	map<string, int> user_last_msg;
	Database();
	~Database();
	void generate_users_rooms();
};

