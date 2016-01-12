#include "Database.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int Database::last_room_id = 0;
int Database::last_user_id = 0;
mutex Database::mtx;
mutex Database::mtx_rooms;
mutex Database::mtx_user_room;
mutex Database::mtx_user;
set<string> Database::avaiable_rooms;
map<string, Room> Database::rooms;
map<string, string> Database::user_room;
map<string, int> Database::user_last_msg;
map<string, string> Database::user_nick;

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
		mtx.lock(); ///
		ss1 << ++last_room_id;
		mtx.unlock(); ///
		string id = ss1.str();
		mtx_rooms.lock(); ///
		rooms.insert(make_pair(id, Room(id)));
		avaiable_rooms.insert(id);
		mtx_rooms.unlock(); ///
		return id;
	}
}

void Database::clear_rooms()
{
	mtx_user_room.lock();
	for (map<string, string>::iterator it = user_room.begin(); it != user_room.end(); ++it)
	{
		string uid = it->first;
		string rid = it->second;
		if (rooms[rid].get_first_mid_in_queue() > user_last_msg[uid] + 100)
			// выкидываем юзера, если он не получал уже больше чем 100 новых сообщений 
		{
			if (!rooms[rid].is_available_to_add()) 
				avaiable_rooms.insert(rid);  
			rooms[rid].curr_count_users--;
			user_room.erase(uid);
			user_last_msg.erase(uid);
		}
	}
	mtx_user_room.unlock();
}

string Database::add_new_user(string nickname)
{
	//clear_rooms();
	string rid = find_available_room();
	stringstream ss2;
	mtx.lock(); ///
	ss2 << ++last_user_id;
	mtx.unlock(); ///
	string uid = ss2.str(); 
	mtx_user_room.lock(); ///
	user_room.insert(make_pair(uid, rid));
	mtx_user_room.unlock(); ///
	mtx_user.lock(); ///
	user_last_msg.insert(make_pair(uid, rooms[rid].get_first_mid_in_queue() - 1));
	rooms[rid].curr_count_users++;
	user_nick.insert(make_pair(uid, nickname));
	mtx_user.unlock(); ///
	mtx_rooms.lock(); ///
	if (!rooms[rid].is_available_to_add()) //убираем комнату из списка доступных, при полном заполнении
		avaiable_rooms.erase(rid);
	mtx_rooms.unlock(); ///
	//rooms[rid].generate_msgs();
	return ss2.str();
}

bool Database::add_new_message(string uid, string msg_cntnt)
{
	if (!have_such_user(uid))
		return false;
	mtx_user.lock(); ///
	string rid = user_room[uid];
	string nick = user_nick[uid];
	mtx_user.unlock(); ///
	mtx_rooms.lock(); ///
	rooms[rid].add_new_msg(nick, msg_cntnt);
	mtx_rooms.unlock(); ///
	return true;
}

bool Database::have_such_user(string uid)
{
	mtx_user_room.lock();
	bool flag = !user_room[uid].empty();
	mtx_user_room.unlock();
	return flag;
}

string Database::messages_json(string uid)
{
	string result = "";
	mtx_rooms.lock(); ///
	mtx_user_room.lock(); /// 
	mtx_user.lock(); ///
	//queue<Message> msg_to_user = rooms[user_room[uid]].get_messages_to_sent();
	queue<Message> msg_to_user = rooms[user_room[uid]].get_messages_to_sent(user_last_msg[uid]);
	mtx_user.unlock(); ///
	mtx_rooms.unlock(); ///
	mtx_user_room.unlock(); ///
	result.append("{ msgs:\n\t[\n");
	while (!msg_to_user.empty())
	{
		string msg_user_nick = msg_to_user.front().get_user_nick();
		string content = msg_to_user.front().get_msg_content();
		result.append("\t\t{ \"nick\": \"");
		result.append(msg_user_nick);
		result.append("\",\t \"content\": \"");
		result.append(content);
		result.append("\"}\n");
		//cout << msg_user_nick << ":\t " << content << endl;
		mtx_user.lock(); ///
		if (msg_to_user.size() == 1)
			user_last_msg[uid] = msg_to_user.front().get_msg_id();
		mtx_user.unlock(); ///
		msg_to_user.pop();
	}
	result.append("\t]\n}\n");
	return result;
}