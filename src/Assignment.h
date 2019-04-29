#include <string>
#include "Subject.cpp"
#include "Date.cpp"

class Assignment {

	private:
		std::string title;
		std::string description;
		Subject subject;
		int difficulty;
		Date dueDate;
		bool done_;

	public:
		Assignment();
		std::string getTitle();

		std::string getDescription();

		Subject getSubject();

		int getDifficulty();

		Date getDueDate();

		std::string getType();

		void setTitle(std::string);

		void setDescription(std::string);

		void setSubject(Subject value);

		void setDifficulty(int value);

		void setDueDate(Date value);

		void setValues();

};
