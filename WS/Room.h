#pragma once
#include <stdio.h>
#include "Message.h"
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <sstream>
using namespace std;

class Room
{
private:
	const int max_count_users;
	string room_id;
	queue<Message> messages_to_sent;

public:
	Room() : room_id(""), max_count_users(10){}
	Room(const string rid) : room_id(rid), max_count_users(10){}
	string get_room_id();
	queue<Message> get_messages_to_sent(int last);
	void generate_msgs();
	Room& operator=(const Room& right);
	~Room(){}
};