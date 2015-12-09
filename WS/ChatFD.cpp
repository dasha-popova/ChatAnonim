#include <fastcgi2/component.h>
#include <fastcgi2/component_factory.h>
#include <fastcgi2/handler.h>
#include <fastcgi2/request.h>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Room.h"

class ChatFD : virtual public fastcgi::Component, virtual public fastcgi::Handler
{
	
    public:
        ChatFD(fastcgi::ComponentContext *context) :
                fastcgi::Component(context)
        {
			
        }

        virtual void onLoad()
        {
	
        }

        virtual void onUnload()
        {

        }

        virtual void handleRequest(fastcgi::Request *request, fastcgi::HandlerContext *context)
        {
                request->setContentType("text/plain");
				Room room11(11); 
				
				string room_id = "0";
				string user_id = "-1";
				if (request->hasArg("user_id"))
				{
					user_id = request->getArg("user_id");
					room_id = user_id.substr(0, 2);
				}
				std::stringbuf buffer(user_id + " Hello\nChatFD World!\n");
				std::stringbuf buff2("You are in room" + room_id + "\n");
                request->write(&buffer);
				request->write(&buff2);
        }
};

FCGIDAEMON_REGISTER_FACTORIES_BEGIN()
FCGIDAEMON_ADD_DEFAULT_FACTORY("ChatFDFactory", ChatFD)
FCGIDAEMON_REGISTER_FACTORIES_END()