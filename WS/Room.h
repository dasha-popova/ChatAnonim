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
	Room() : max_count_users(10), room_id("") {}
	Room(const string rid) : max_count_users(10), room_id(rid) {}
	string get_room_id();
	queue<Message> get_messages_to_sent(int last);
	void generate_msgs();
	Room& operator=(const Room& right);
	~Room(){}
};