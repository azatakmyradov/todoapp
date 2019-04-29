#include <sqlite3.h>
#include <iomanip>

/**
 * Database wrapper to make the code cleaner and to not repeat the code
 */
class Database
{
private:
	char* databaseName;
	sqlite3 *db;
	char *zErrMsg;
	int connection;
	const char* data;

	// static method that works with the database returned data
	static int callback(void *NotUsed, int argc, char *argv[], char **azColName) {
		const char separator = ' ';
		const int width = 16;
		std::string task;
		std::cout << std::endl;
		std::string done = argv[8];
		if (stoi(done) == 1) {
			std::cout << "✔ ";
		}
		for (int i = 0; i < argc - 1; ++i)
		{
			task = argv[i] ? argv[i] : "";
		    std::cout << std::left << std::setw(width) << std::setfill(separator) << task;
		}
		std::cout << "\n------------------------------------------------------------------------------------------------------------------------------------";
		return 0;
	}

public:
	/**
	 * Opens the database
	 *
	 * @param char* databaseName_
	 */
	Database(char* databaseName_) {
		databaseName = databaseName_;
		connection = sqlite3_open(databaseName, &db);

		if(connection) {
			fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
			exit(0);
		}
	}
	~Database() {
		
	}

	/**
	 * 	Creates the Tasks table in the database
	 */
	void setup() {
		char* CREATE_TASKS_TABLE = "CREATE TABLE TASKS("  \
		"ID INTEGER PRIMARY KEY  AUTOINCREMENT," \
		"title                CHAR(50)    NOT NULL," \
		"description          TEXT        NOT NULL," \
		"subject_name         CHAR(50)," \
		"subject_instructor   CHAR(50)," \
		"difficulty           INT," \
		"due_date              CHAR(50)," \
		"estimated_time        CHAR(50)," \
		"done                 TINYINT(1)   NOT NULL );";
		execute(CREATE_TASKS_TABLE);
	}

	/**
	 * Closes the database
	 */
	void stop() {
		sqlite3_close(db);
	}

	/**
	 *	Runs the SQL Query
	 * 
	 * @param char* sql
	 */
	void execute(char* sql) {
		connection = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);

		if( connection != SQLITE_OK ) {
			sqlite3_free(zErrMsg);
		}
	}
};
