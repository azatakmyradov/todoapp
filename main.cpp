#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "src/Assignment.h"
#include "src/SimpleTask.h"
#include "src/Database.cpp"
#include "src/Task.cpp"

int main() {

	// Initiates the the database and sets it up
	char* databaseFile = "tasks.db";
	Database database(databaseFile);
	database.setup();

	// Choice input for actions to take
	int choice;

	// It will keep the application running so the user doesn't have to open the app again
	while(true) {
		// Displays the Tasks table
		Task::show(database);

		// Shows the available actions to take
		Task::showOptions();		

		std::cout << "Choose: ";
		std::cin >> choice;

		// Decides which action to take for users input
		switch (choice) {
			case 0:
				// Action to remove a task from the list
				Task::remove(database);
				break;
			case 1:
				int task;
				std::cout << "Choose the type of task: (0: Simple Task, 1: Assignment): ";
				std::cin >> task;

				// adds a simple task to the list
				if (task == 0) Task::addSimple(database);

				//adds a assignment type task to the list
				else if (task == 1) Task::addAssignment(database);
				break;
			case 2:
				// finishes the task
				Task::finish(database);
				break;
			case 3: 
				// unfinishes the task
				Task::unFinish(database);
				break;
			case 4:
				// gives the user option to order tasks
				Task::changeOrder();
				break;
		}
	}

	// closes the database
	database.stop();
	return 0;
}
