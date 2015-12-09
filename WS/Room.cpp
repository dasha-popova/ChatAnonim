#include "Room.h"
using namespace std;

int Room::get_room_id()
{
	return room_id;
}

int Room::get_last_msg_id(int uid)
{
	return users[uid];
}

set<Message> Room::get_messages_to_sent(int uid)
{

	return messages_to_sent;
}

set<int> Room::get_users()
{
	set<int> uids;
	for (auto it = users.begin(); it != users.end(); ++it)
	{
		uids.insert(it->first);
	}

	return uids;
}

void Room::generate_db()
{
	for (int i = 0; i < max_count_users; ++i)
	{
		int uid = room_id * 1000 + i + 1;
		users.insert(uid, 0);
	}
}