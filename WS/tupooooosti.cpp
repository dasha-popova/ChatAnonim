#include <iostream>
#include "Database.h"
#include "Room.h"
using namespace std;

int main()
{
	Database database;
	database.generate_users_rooms();

	string user_id = "";

	user_id = database.add_new_user("blabla");
	cout << "New user: " << user_id << endl;
	cout << "New user: " << database.add_new_user("blabla") << endl; // add new user

		//add new msg
	if (database.have_such_user(user_id)) // get all msg in the room
	{
		cout << database.messages_json(user_id);
	}
	else
		cout << "no such user. need registration" << endl;
	database.add_new_message(user_id, "MY NEW MESSAGE");
	if (!database.add_new_message("23", "MY NEW MESSAGE13"))
		cout << "23" << " oops" << endl;
	if (!database.add_new_message("22", "MY NEW MESSAGE22"))
		cout << "22" << " oops" << endl;
	if (database.have_such_user(user_id)) // get all msg in the room
	{
		cout << database.messages_json(user_id);
	}
	else
		cout << "no such user. need registration" << endl;

	system("pause");
	return 0;

}