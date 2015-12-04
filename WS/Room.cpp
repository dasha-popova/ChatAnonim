#include "Room.h"
using namespace std;

unsigned Room::get_room_id()
{
	return room_id;
}

unsigned Room::get_last_msg_id()
{
	return last_msg_id;
}

set<Message> Room::get_messages_to_sent()
{
	return messages_to_sent;
}

set<unsigned> Room::get_users()
{
	return users;
}

void Room::add_user(unsigned uid)  //
{
	///	MTX
	if (max_count_users > users.size())
		users.insert(uid);
	/////////////////////////////////////???????????????????
}

void Room::delete_user(unsigned uid) //
{
	//MTX
	users.erase(uid);
}