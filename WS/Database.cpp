#include "Database.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int Database::last_room_id = 0;
int Database::last_user_id = 0;
mutex Database::mtx;
set<string> Database::avaiable_rooms;
map<string, Room> Database::rooms;
map<string, string> Database::user_room;
map<string, int> Database::user_last_msg;
map<string, string> Database::user_nick;
Database::Database()
{
}
void Database::generate_users_rooms()
{
	for (int i = 0; i < 25; ++i)
	{
		stringstream ss1;
		ss1 << "nick" << i + 1;
		add_new_user(ss1.str());
	}
	for (map<string, Room>::iterator it = rooms.begin(); it != rooms.end(); ++it)
	{
		it->second.generate_msgs();
	}
}

string Database::find_available_room()
{
	if (!avaiable_rooms.empty())
		return *avaiable_rooms.begin();
	else
	{
		stringstream ss1;
		ss1 << ++last_room_id;
		string id = ss1.str();
		rooms.insert(make_pair(id, Room(id)));
		avaiable_rooms.insert(id);
		return id;
	}
}

void Database::clear_rooms()
{
	for (map<string, string>::iterator it = user_room.begin(); it != user_room.end(); ++it)
	{
		string uid = it->first;
		string rid = it->second;
		if (rooms[rid].get_first_mid_in_queue() > user_last_msg[uid] + 20)
			// выкидываем юзера, если он не получал уже больше чем 20 новых сообщений 
		{
			if (!rooms[rid].is_available_to_add()) 
				avaiable_rooms.insert(rid);  
			rooms[rid].curr_count_users--;
			user_room.erase(uid);
			user_last_msg.erase(uid);
		}

	}
}

string Database::add_new_user(string nickname)
{
	clear_rooms();
	string rid = find_available_room();
	stringstream ss2;
	mtx.lock(); ///
	ss2 << ++last_user_id;
	mtx.unlock(); ///
	string uid = ss2.str();
	user_room.insert(make_pair(uid, rid));
	user_last_msg.insert(make_pair(uid, rooms[rid].get_first_mid_in_queue() - 1));
	rooms[rid].curr_count_users++;
	user_nick.insert(make_pair(uid, nickname));
	if (!rooms[rid].is_available_to_add()) //убираем комнату из списка доступных, при полном заполнении
		avaiable_rooms.erase(rid);
	//rooms[rid].generate_msgs();
	return ss2.str();
}