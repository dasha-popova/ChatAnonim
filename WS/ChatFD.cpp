#include <fastcgi2/component.h>
#include <fastcgi2/component_factory.h>
#include <fastcgi2/handler.h>
#include <fastcgi2/request.h>
#include "fastcgi2/stream.h"
#include <fastcgi2/data_buffer.h>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include "Database.h"

class ChatFD : virtual public fastcgi::Component, virtual public fastcgi::Handler
{
	
    public:
		Database database;
        ChatFD(fastcgi::ComponentContext *context) :
                fastcgi::Component(context)
        {
			database.generate_users_rooms();
        }

        virtual void onLoad()
        {
	
        }

        virtual void onUnload()
        {

        }

          virtual void handleRequest(fastcgi::Request *req, fastcgi::HandlerContext *context)
        {
			fastcgi::RequestStream stream(req);
			
			std::string requestMethod = req->getRequestMethod();
			if (requestMethod == "GET")
			{
				string user_id = "";

				if (req->hasArg("user_id"))
				{
					user_id = req->getArg("user_id");
					/// проверить есть ли юзер внутри мапы, если нет то добавить его в комнату и вывести все текущие сообщения
					queue<Message> msg_to_user = database.rooms[database.user_room[user_id]].get_messages_to_sent();
					stream << "{ msgs:\n\t[\n";
					while (!msg_to_user.empty())
					{
						string msg_user_nick = msg_to_user.front().get_user_nick();
						string content = msg_to_user.front().get_msg_content();
						stream << "\t\t{ " << "user_id: \"" << msg_user_nick << "\",\t msg_content: \"" << content << "\"}\n";
						msg_to_user.pop();
					}
					stream << "\t]\n}\n";
				}
				else
				{
					sendError(req, stream, 400);
				}
			}
			if (requestMethod == "POST")
			{
				if (req->hasArg("nick"))
				{
					string nick = req->getArg("nick");
					if (!nick.empty())
					{
						string user_id = database.add_new_user(nick);
						stream << "{ user_id: \"" << user_id << "\" }\n";
					}
					else
					{
						sendError(req, stream, 400);
					}
					
				}
			}

				
        }

		void sendError(fastcgi::Request *req, fastcgi::RequestStream &stream, int status)
		{
			string message = "Incorrect request body";
			sendError(req, stream, message, status);
		}
		void sendError(fastcgi::Request *req, fastcgi::RequestStream &stream, string &message, int status)
		{
			stream << "{ \"error\" : \"" + message + "\" }";
			req->setStatus(status);
		}

};

FCGIDAEMON_REGISTER_FACTORIES_BEGIN()
FCGIDAEMON_ADD_DEFAULT_FACTORY("ChatFDFactory", ChatFD)
FCGIDAEMON_REGISTER_FACTORIES_END()