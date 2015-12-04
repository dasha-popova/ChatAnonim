#include <iostream>
#include <stdio.h>
using namespace std;

class Message
{
private:
	unsigned msg_id;
	unsigned user_id;
	unsigned room_id;
	string msg_content;

public:
	Message(unsigned mid, unsigned uid, unsigned rid, string content) :
		msg_id(mid), user_id(uid), room_id(rid), msg_content(content){}
	unsigned get_msg_id();
	unsigned get_user_id();
	unsigned get_room_id();
	string get_msg_content();
	~Message(){};

};