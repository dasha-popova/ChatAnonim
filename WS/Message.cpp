#include "Message.h"
using namespace std;

int Message::get_msg_id()
{
	return msg_id;
}

string Message::get_user_nick()
{
	return user_nick;
}

string Message::get_msg_content()
{
	return msg_content;
}
