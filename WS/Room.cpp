#include "Room.h"
using namespace std;

string Room::get_room_id()
{
	return room_id;
}


queue<Message> Room::get_messages_to_sent()
{
	return messages_to_sent;
}


void Room::generate_msgs()
{
	for (int i = 0; i < 20; ++i){
		stringstream ss1_nick;
		ss1_nick << room_id << "nick=" << (i % curr_count_users + 1);
		add_new_msg(ss1_nick.str());
	}
}

bool Room::is_available_to_add()
{
	return curr_count_users < max_count_users;
}

int Room::get_first_mid_in_queue()
{
	if (messages_to_sent.empty())
		return 0;
	else
		return messages_to_sent.front().get_msg_id();
}

void Room::add_new_msg(string nickname)
{
	stringstream ss2_content;
	ss2_content << last_msg_id + 1;
	messages_to_sent.push(Message(++last_msg_id, nickname, "Message " + ss2_content.str()));
}