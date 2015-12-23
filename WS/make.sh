 g++ Message.cpp -pthread -lboost_thread -lboost_system-mt -lboost_regex -lrt -Wall -c 
 g++ Room.cpp -pthread -lboost_thread -lboost_system-mt -lboost_regex -lrt -Wall -c
 g++ Database.cpp -pthread -lboost_thread -lboost_system-mt -lboost_regex -lrt -Wall -c
 g++ Message.o Room.o Database.o ChatFD.cpp  -O2 -fPIC -lfastcgi-daemon2 -pthread -lboost_thread -lboost_system-mt -lboost_regex -lrt -shared -o libchat.so