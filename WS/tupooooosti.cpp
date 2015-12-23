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
	queue<Message> msg_to_user = database.rooms[database.user_room[user_id]].get_messages_to_sent(database.user_last_msg[user_id]);
	for (int i = 0; i < msg_to_user.size(); ++i)
	{
		string msg_user_id = msg_to_user.front().get_user_id();
		string content = msg_to_user.front().get_msg_content();
		cout << msg_user_id << ":\t " << content << endl;
		msg_to_user.pop();
	}
	system("pause");
	return 0;

}