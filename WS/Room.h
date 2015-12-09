#include <stdio.h>
#include "Message.h"
#include <iostream>
#include <set>
#include <map>
using namespace std;

class Room
{
private:
	const int max_count_users;
	const int room_id;
	map<const int, int> users;
	set<Message> messages_to_sent;

public:
	Room(const int rid) : room_id(rid), max_count_users(10){}
	int get_room_id();
	set<int> get_users();
	set<Message> get_messages_to_sent(int uid);
	int get_last_msg_id(int uid);
	void generate_db();
	~Room(){}
};