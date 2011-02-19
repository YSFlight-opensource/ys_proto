g++ -Wall -O2 -c apps/activity_message.cpp -o obj/Release/apps/activity_message.o
g++ -Wall -O2 -c apps/apps.cpp -o obj/Release/apps/apps.o
g++ -Wall -O2 -c apps/ysclient.cpp -o obj/Release/apps/ysclient.o
g++ -Wall -O2 -c apps/ysclientActions.cpp -o obj/Release/apps/ysclientActions.o
g++ -Wall -O2 -c debug.cpp -o obj/Release/debug.o
g++ -Wall -O2 -c main.cpp -o obj/Release/main.o
g++ -Wall -O2 -c serialization/ackowledge.cpp -o obj/Release/serialization/ackowledge.o
g++ -Wall -O2 -c serialization/airDisplayOpt.cpp -o obj/Release/serialization/airDisplayOpt.o
g++ -Wall -O2 -c serialization/airList.cpp -o obj/Release/serialization/airList.o
g++ -Wall -O2 -c serialization/damage.cpp -o obj/Release/serialization/damage.o
g++ -Wall -O2 -c serialization/endianess.cpp -o obj/Release/serialization/endianess.o
g++ -Wall -O2 -c serialization/flight.cpp -o obj/Release/serialization/flight.o
g++ -Wall -O2 -c serialization/ground.cpp -o obj/Release/serialization/ground.o
g++ -Wall -O2 -c serialization/header.cpp -o obj/Release/serialization/header.o
g++ -Wall -O2 -c serialization/includeAll.cpp -o obj/Release/serialization/includeAll.o
g++ -Wall -O2 -c serialization/int.cpp -o obj/Release/serialization/int.o
g++ -Wall -O2 -c serialization/login.cpp -o obj/Release/serialization/login.o
g++ -Wall -O2 -c serialization/map.cpp -o obj/Release/serialization/map.o
g++ -Wall -O2 -c serialization/message.cpp -o obj/Release/serialization/message.o
g++ -Wall -O2 -c serialization/missileOpt.cpp -o obj/Release/serialization/missileOpt.o
g++ -Wall -O2 -c serialization/unpack.cpp -o obj/Release/serialization/unpack.o
g++ -Wall -O2 -c serialization/userlist.cpp -o obj/Release/serialization/userlist.o
g++ -Wall -O2 -c serialization/weather.cpp -o obj/Release/serialization/weather.o
g++ -Wall -O2 -c sockets/linux.cpp -o obj/Release/sockets/linux.o
g++ -Wall -O2 -c sockets/socketYS.cpp -o obj/Release/sockets/socketYS.o
g++ -Wall -O2 -c sockets/windows.cpp -o obj/Release/sockets/windows.o
g++ -Wall -O2 -c types/includeall.cpp -o obj/Release/types/includeall.o
g++ -Wall -O2 -c types/stringarray.cpp -o obj/Release/types/stringarray.o
g++ -Wall -O2 -c types/ys/includeAll.cpp -o obj/Release/types/ys/includeAll.o
g++ -Wall -O2 -c types/ys/tacknowledge.cpp -o obj/Release/types/ys/tacknowledge.o
g++ -Wall -O2 -c types/ys/tairDisplayOpt.cpp -o obj/Release/types/ys/tairDisplayOpt.o
g++ -Wall -O2 -c types/ys/tairList.cpp -o obj/Release/types/ys/tairList.o
g++ -Wall -O2 -c types/ys/tdamage.cpp -o obj/Release/types/ys/tdamage.o
g++ -Wall -O2 -c types/ys/tflight.cpp -o obj/Release/types/ys/tflight.o
g++ -Wall -O2 -c types/ys/tground.cpp -o obj/Release/types/ys/tground.o
g++ -Wall -O2 -c types/ys/theader.cpp -o obj/Release/types/ys/theader.o
g++ -Wall -O2 -c types/ys/tint.cpp -o obj/Release/types/ys/tint.o
g++ -Wall -O2 -c types/ys/tleft.cpp -o obj/Release/types/ys/tleft.o
g++ -Wall -O2 -c types/ys/tlogin.cpp -o obj/Release/types/ys/tlogin.o
g++ -Wall -O2 -c types/ys/tmap.cpp -o obj/Release/types/ys/tmap.o
g++ -Wall -O2 -c types/ys/tmessage.cpp -o obj/Release/types/ys/tmessage.o
g++ -Wall -O2 -c types/ys/tmissileOpt.cpp -o obj/Release/types/ys/tmissileOpt.o
g++ -Wall -O2 -c types/ys/tuserlist.cpp -o obj/Release/types/ys/tuserlist.o
g++ -Wall -O2 -c types/ys/tweather.cpp -o obj/Release/types/ys/tweather.o
g++ -o bin/Release/ys_proto obj/Release/apps/activity_message.o obj/Release/apps/apps.o obj/Release/apps/ysclient.o obj/Release/apps/ysclientActions.o obj/Release/debug.o obj/Release/main.o obj/Release/serialization/ackowledge.o obj/Release/serialization/airDisplayOpt.o obj/Release/serialization/airList.o obj/Release/serialization/damage.o obj/Release/serialization/endianess.o obj/Release/serialization/flight.o obj/Release/serialization/ground.o obj/Release/serialization/header.o obj/Release/serialization/includeAll.o obj/Release/serialization/int.o obj/Release/serialization/login.o obj/Release/serialization/map.o obj/Release/serialization/message.o obj/Release/serialization/missileOpt.o obj/Release/serialization/unpack.o obj/Release/serialization/userlist.o obj/Release/serialization/weather.o obj/Release/sockets/linux.o obj/Release/sockets/socketYS.o obj/Release/sockets/windows.o obj/Release/types/includeall.o obj/Release/types/stringarray.o obj/Release/types/ys/includeAll.o obj/Release/types/ys/tacknowledge.o obj/Release/types/ys/tairDisplayOpt.o obj/Release/types/ys/tairList.o obj/Release/types/ys/tdamage.o obj/Release/types/ys/tflight.o obj/Release/types/ys/tground.o obj/Release/types/ys/theader.o obj/Release/types/ys/tint.o obj/Release/types/ys/tleft.o obj/Release/types/ys/tlogin.o obj/Release/types/ys/tmap.o obj/Release/types/ys/tmessage.o obj/Release/types/ys/tmissileOpt.o obj/Release/types/ys/tuserlist.o obj/Release/types/ys/tweather.o -s -lpthread
