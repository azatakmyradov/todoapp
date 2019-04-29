#include <string>

class SimpleTask {

	private:
		std::string title;
		std::string description;
		int estimatedTime;
		bool done_;

	public:
		SimpleTask();

		std::string getTitle();

		std::string getDescription();

		int getEstimatedTime();

		std::string getType();

		void setTitle(std::string);

		void setDescription(std::string);

		void setEstimatedTime(int);

		void setValues();

};
