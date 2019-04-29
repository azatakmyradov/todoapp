/**
 * Task class
 *
 * Helps to clean up the code
 */
class Task
{
private:
	/**
	 *	Helps to find and replace a piece of string
	 * 
	 * @param std::string &value
	 * @param const std::string toReplace
	 * @param const std::string& replaceWith
	 */
	static void replace(std::string &value, const std::string& toReplace, const std::string& replaceWith) {
		value.replace(value.find(toReplace), toReplace.length(), replaceWith);
	}

public:
	/**
	 *	Displays all the tasks from database
	 * 
	 * @param Database database
	 */
	static void show(Database database) {
		// Table seperators
		const char separator = ' ';
	    const int width = 16;

	    std::string order_column;
	    std::string order_type;

	    // File with order settings
	    std::ifstream infile(".settings");

	    // Checks if file exists. If not creates it and write order settings into it
	    if (! infile.good())
	    {
	    	std::ofstream myfile;
			myfile.open (".settings");
			// "ID" is the column to be ordered with. "ASC" is the type of order
			myfile << "ID\nASC";
			myfile.close();
	    }

	    // gets the order settings from the file and saves it into variables order_column and order_type
	    std::string line;
	    std::ifstream settings (".settings");
	    if (settings.is_open())
	    {
	    	int i = 0;
	    	while ( getline (settings,line) )
	    	{
	    		if (i == 0) order_column = line;
	    		if (i == 1) order_type = line;
	    		i++;
	    	}
	    	settings.close();
	    }

	    // SQL statement to get all the tasks from database with order
		std::string tasks = "SELECT * FROM TASKS ORDER BY :COLUMN :TYPE";
		replace(tasks, ":COLUMN", order_column);
		replace(tasks, ":TYPE", order_type);
		char tasks_c[1024];
		strcpy(tasks_c, tasks.c_str());
		std::cout << "------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
	    std::cout << std::left << std::setw(width) << std::setfill(separator) << "ID";
	    std::cout << std::left << std::setw(width) << std::setfill(separator) << "Title";
	    std::cout << std::left << std::setw(width) << std::setfill(separator) << "Description";
	    std::cout << std::left << std::setw(width) << std::setfill(separator) << "Subject";
	    std::cout << std::left << std::setw(width) << std::setfill(separator) << "Instructor";
	    std::cout << std::left << std::setw(width) << std::setfill(separator) << "Difficulty";
	    std::cout << std::left << std::setw(width) << std::setfill(separator) << "Due";
	    std::cout << std::left << std::setw(width) << std::setfill(separator) << "Estimated Time";
	    std::cout << "\n------------------------------------------------------------------------------------------------------------------------------------";
	    database.execute(tasks_c);
	    std::cout << std::endl;
	}

	/**
	 *	Asks for user input for task ID and deletes it from database
	 * 
	 * 	@param Database database
	 */
	static void remove(Database database) {
		int task_id;
		std::cout << "Enter the task ID: ";
		std::cin >> task_id;
		std::string tasks = "DELETE FROM TASKS WHERE ID = ";
		tasks.append(std::to_string(task_id));
		char tasks_c[1024];
		strcpy(tasks_c, tasks.c_str());
		database.execute(tasks_c);
	}

	/**
	 *	Adds a simple task to database with user input
	 * 
	 * 	@param Database database
	 */
	static void addSimple(Database database) {
		SimpleTask task;
		task.setValues();
		std::string tasks = "INSERT INTO TASKS(TITLE,DESCRIPTION,ESTIMATED_TIME,DONE) VALUES(':TITLE',':DESCRIPTION',':ESTIMATED_TIME',0);";
		replace(tasks, ":TITLE", task.getTitle());
		replace(tasks, ":DESCRIPTION", task.getDescription());
		replace(tasks, ":ESTIMATED_TIME", std::to_string(task.getEstimatedTime()));
		char tasks_c[1024];
		strcpy(tasks_c, tasks.c_str());
		database.execute(tasks_c);
	}

	/**
	 *	Adds assignment to the database with user input
	 * 
	 * 	@param Database database
	 */
	static void addAssignment(Database database) {
		Assignment task;
		task.setValues();
		std::string tasks = "INSERT INTO TASKS(TITLE,DESCRIPTION,SUBJECT_NAME,SUBJECT_INSTRUCTOR,DIFFICULTY,DUE_DATE,DONE) VALUES(':TITLE',':DESCRIPTION',':SUBJECT_NAME', ':SUBJECT_INSTRUCTOR', ':DIFFICULTY', ':MONTH/:DAY/:YEAR',0);";
		replace(tasks, ":TITLE", task.getTitle());
		replace(tasks, ":DESCRIPTION", task.getDescription());
		replace(tasks, ":SUBJECT_NAME", task.getSubject().name);
		replace(tasks, ":SUBJECT_INSTRUCTOR", task.getSubject().instructor);
		replace(tasks, ":DIFFICULTY", std::to_string(task.getDifficulty()));
		replace(tasks, ":MONTH", std::to_string(task.getDueDate().month));
		replace(tasks, ":DAY", std::to_string(task.getDueDate().day));
		replace(tasks, ":YEAR", std::to_string(task.getDueDate().year));
		char tasks_c[1024];
		strcpy(tasks_c, tasks.c_str());
		database.execute(tasks_c);
	}

	/**
	 *	Finishes the task
	 * 
	 * 	@param Database database
	 */
	static void finish(Database database) {
		int task_id;
		std::cout << "Enter the task ID: ";
		std::cin >> task_id;
		std::string tasks = "UPDATE TASKS SET DONE = 1 WHERE ID = ";
		tasks.append(std::to_string(task_id));
		char tasks_c[1024];
		strcpy(tasks_c, tasks.c_str());
		database.execute(tasks_c);
	}

	/**
	 *	Unfinishes the task
	 * 
	 * 	@param Database database
	 */
	static void unFinish(Database database) {
		int task_id;
		std::cout << "Enter the task ID: ";
		std::cin >> task_id;
		std::string tasks = "UPDATE TASKS SET DONE = 0 WHERE ID = ";
		tasks.append(std::to_string(task_id));
		char tasks_c[1024];
		strcpy(tasks_c, tasks.c_str());
		database.execute(tasks_c);
	}

	/**
	 *	Changes the order of tasks displayed to the user and saves it to a file
	 */
	static void changeOrder() {
		int order_by_choice;
		int order_type_choice;
		std::string order_by;
		std::string order_type;

		std::cout << "0 - ID" << std::endl;
		std::cout << "1 - Title" << std::endl;
		std::cout << "2 - Description" << std::endl;
		std::cout << "3 - Subject" << std::endl;
		std::cout << "4 - Instructor" << std::endl;
		std::cout << "5 - Difficulty" << std::endl;
		std::cout << "6 - Due" << std::endl;
		std::cout << "7 - Estimated Time" << std::endl;
		std::cout << "Order by: ";
		std::cin >> order_by_choice;

		switch (order_by_choice) {
			case 0:
				order_by = "ID";
				break;
			case 1:
				order_by = "TITLE";
				break;
			case 2:
				order_by = "DESCRIPTION";
				break;
			case 3:
				order_by = "SUBJECT_NAME";
				break;
			case 4:
				order_by = "SUBJECT_INSTRUCTOR";
				break;
			case 5:
				order_by = "DIFFICULTY";
				break;
			case 6:
				order_by = "DUE_DATE";
				break;
			case 7:
				order_by = "ESTIMATED_TIME";
				break;
			case 8:
				order_by = "DONE";
				break;
		}

		std::cout << "0 - Ascending" << std::endl;
		std::cout << "1 - Descending" << std::endl;
		std::cout << "Order type: ";
		std::cin >> order_type_choice;

		switch (order_type_choice) {
			case 0:
				order_type = "ASC";
				break;
			case 1:
				order_type = "DESC";
				break;
		}

		std::ofstream myfile;
		myfile.open (".settings");
		myfile << order_by << "\n" << order_type;
		myfile.close();
	}

	/**
	 * Displays the available actions to the user
	 */
	static void showOptions() {
		std::cout << "0 - Delete Task" << std::endl;
		std::cout << "1 - Add Task" << std::endl;
		std::cout << "2 - Finish Task" << std::endl;
		std::cout << "3 - Unfinish Task" << std::endl;
		std::cout << "4 - Change Order" << std::endl;
	}
};
