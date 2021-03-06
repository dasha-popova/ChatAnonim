#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include "Room.h"
#include <map>
#include <mutex>
using namespace std;

class Database
{
private:
	static set<string> avaiable_rooms;
	static mutex mtx;
	static mutex mtx_rooms;
	static mutex mtx_user_room;
	static mutex mtx_user;
public:
	static int last_room_id;
	static int last_user_id;
	static map<string, Room> rooms;
	static map<string, string> user_room;
	static map<string, int> user_last_msg;
	static map<string, string> user_nick;
	Database(){}
	~Database() {}
	static void generate_users_rooms();
	static string find_available_room();
	static void clear_rooms();
	static string add_new_user(string);
	static bool add_new_message(string, string);
	static bool have_such_user(string);
	static string messages_json(string);
};

