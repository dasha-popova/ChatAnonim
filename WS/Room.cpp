#include "Room.h"
using namespace std;

string Room::get_room_id()
{
	return room_id;
}


queue<Message> Room::get_messages_to_sent(int last)
{

	return messages_to_sent;
}


void Room::generate_msgs()
{
	for (int i = 0; i < 20; ++i){
		stringstream ss1;
		ss1 << room_id << (i % 7 + 1);
		stringstream ss2;
		ss2 << i;
		messages_to_sent.push(Message(i, ss1.str(), "Message " + ss2.str()));
	}
}
