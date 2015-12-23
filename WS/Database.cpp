#include "Database.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
Database::Database()
{
}

Database::~Database()
{
}

void Database::generate_users_rooms()
{
	for (int i = 1; i <= 5; ++i)
	{
		stringstream ss1;
		ss1 << i;
		string id = ss1.str();
		rooms.insert(make_pair(id, Room(id)));
		rooms[id].generate_msgs();
		for (int j = 0; j <= 7; ++j){
			stringstream ss2;
			ss2 << i * 10 + j;
			user_room.insert(make_pair(ss2.str(), id));
		}
	}
}