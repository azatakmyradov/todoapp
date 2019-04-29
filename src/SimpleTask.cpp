#include <string>
#include <iostream>
#include "SimpleTask.h"

/**
 *	Gives done_ a default value
 */
SimpleTask::SimpleTask() {
	done_ = false;
}

/**
 *	Returns the title
 * 
 * 	@return std::string
 */
std::string SimpleTask::getTitle() {
	return title;
}

/**
 *	Returns the description
 * 
 * 	@return std::string
 */
std::string SimpleTask::getDescription() {
	return description;
}

/**
 *	Returns the Estimated Time
 * 
 * 	@return int
 */
int SimpleTask::getEstimatedTime() {
	return estimatedTime;
}

/**
 *	Returns the type of task
 * 
 * 	@return string
 */
std::string SimpleTask::getType() {
	return "SimpleTask";
}

/**
 *	Changes the value of title
 * 
 * 	@param std::string value
 */
void SimpleTask::setTitle(std::string value) {
	title = value;
}

/**
 *	Changes the value of description
 * 
 * 	@param std::string value
 */
void SimpleTask::setDescription(std::string value) {
	description = value;
}

/**
 *	Changes the value of estimated time
 * 
 * 	@param int value
 */
void SimpleTask::setEstimatedTime(int value) {
	estimatedTime = value;
}

/**
 * Gets input from user to set the values
 */
void SimpleTask::setValues() {
	std::cout << "Title: ";
	std::cin.clear();
	std::cin.ignore(10000, '\n');
	getline(std::cin, title);
	std::cout << "Description: ";
	getline(std::cin, description);
	std::cout << "Estimated Time (Minutes): ";
	std::cin >> estimatedTime;
}
