#include <fastcgi2/component.h>
#include <fastcgi2/component_factory.h>
#include <fastcgi2/handler.h>
#include <fastcgi2/request.h>
#include "fastcgi2/stream.h"
#include <fastcgi2/data_buffer.h>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include "Database.h"
namespace pt = boost::property_tree;
namespace jsp = pt::json_parser;

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
					if (database.have_such_user(user_id)) // get all msg in the room
					{
						stream << database.messages_json(user_id);
					}
					else 
					{
						string msg = "Need registration."; 
						sendError(req, stream, msg, 400);
					}
				}
				else
				{
					sendError(req, stream, 400);
				}
			}
			if (requestMethod == "POST" && req->countArgs() > 0)
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
				else
				{
					fastcgi :: DataBuffer buffer = req->requestBody();
					std :: string jsonString;
					buffer.toString(jsonString);
					
					string user_id;
					string content;
					try {
						std::stringstream ss(jsonString);
						   pt::ptree tree;
						   jsp::read_json(ss, tree);
						 
						for(auto &v: tree)
						{
							if (v.first == "user_id")
							{
								user_id = v.second.get<std::string>("");
							}
							if (v.first == "content")
							{
								content = v.second.get<std::string>("");
							}
						}
						//stream << "oooops" << "\n";
					} catch (boost::property_tree::json_parser_error &e) { // если json не валидный
						sendError(req, stream, 400);
					} 
					if(!database.add_new_message(user_id, content))
						sendError(req, stream, 400);
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
			stream << "{ \"error\" : \"" + message + "\" }\n";
			req->setStatus(status);
		}

};

FCGIDAEMON_REGISTER_FACTORIES_BEGIN()
FCGIDAEMON_ADD_DEFAULT_FACTORY("ChatFDFactory", ChatFD)
FCGIDAEMON_REGISTER_FACTORIES_END()