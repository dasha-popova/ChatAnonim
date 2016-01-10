#include <iostream>
#include "Database.h"
#include "Room.h"
using namespace std;

int main()
{
	Database database;
	database.generate_users_rooms();

	string user_id = "";
	user_id = "12";
	queue<Message> msg_to_user = database.rooms[database.user_room[user_id]].get_messages_to_sent();
	while (!msg_to_user.empty())
	{
		string msg_user_nick = msg_to_user.front().get_user_nick();
		string content = msg_to_user.front().get_msg_content();
		cout << msg_user_nick << ":\t " << content << endl;
		msg_to_user.pop();
	}
	system("pause");
	return 0;

}