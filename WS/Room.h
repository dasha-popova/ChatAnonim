#include <stdio.h>
#include "Message.h"
#include <iostream>
#include <set>
#include <mutex>
using namespace std;

class Room
{
private:
	const unsigned max_count_users = 10000;
	unsigned room_id;
	set<unsigned> users;
	set<Message> messages_to_sent;
	unsigned last_msg_id;
	mutex mtx_users;

public:
	Room(unsigned rid) : room_id(rid), last_msg_id(0){}
	unsigned get_room_id();
	set<unsigned> get_users();
	set<Message> get_messages_to_sent();
	unsigned get_last_msg_id();
	void add_user(unsigned uid); //// ??????????????????????????????????????
	void delete_user(unsigned uid);
	~Room(){}
};