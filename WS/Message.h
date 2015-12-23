#pragma once
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

class Message
{
private:
	int msg_id;
	string user_id;
	string msg_content;

public:
	Message(unsigned mid, string uid, string content) :
		msg_id(mid), user_id(uid), msg_content(content){}
	int get_msg_id();
	string get_user_id();
	string get_msg_content();
	~Message(){};

};