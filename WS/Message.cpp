#include "Message.h"
using namespace std;

unsigned Message::get_msg_id()
{
	return msg_id;
}

unsigned Message::get_user_id()
{
	return user_id;
}

unsigned Message::get_room_id()
{
	return room_id;
}

string Message::get_msg_content()
{
	return msg_content;
}