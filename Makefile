app.o: src/Assignment.cpp src/SimpleTask.cpp src/Assignment.h src/SimpleTask.h main.cpp
	g++ src/Assignment.cpp src/SimpleTask.cpp main.cpp --std=c++11 -l sqlite3 -o app.o
