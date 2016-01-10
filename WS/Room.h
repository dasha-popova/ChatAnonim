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
	int curr_count_users;
	int last_msg_id;
	Room() : max_count_users(10), last_msg_id(0), curr_count_users(0), room_id("") {}
	Room(const string rid) : max_count_users(10), last_msg_id(0), curr_count_users(0), room_id(rid) {}
	string get_room_id();
	queue<Message> get_messages_to_sent();
	int get_first_mid_in_queue();
	void generate_msgs();
	Room& operator=(const Room& right);
	bool is_available_to_add();
	void add_new_msg(string);
	~Room(){}
};