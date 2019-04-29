#include <string>
#include <iostream>
#include "Assignment.h"

/**
 *	Gives the done_ default value
 *
 *	@return boolean
 */
Assignment::Assignment() {
	done_ = false;
}

/**
 *	Returns the title
 * 
 *	@return std::string
 */
std::string Assignment::getTitle() {
	return title;
}

/**
 *	Returns the description
 * 
 *	@return std::string
 */
std::string Assignment::getDescription() {
	return description;
}

/**
 *	Returns the subject
 * 
 *	@return Subject
 */
Subject Assignment::getSubject() {
	return subject;
}

/**
 *	Returns the difficulty
 * 
 * 	@return int
 */
int Assignment::getDifficulty() {
	return difficulty;
}

/**
 *	Returns the Due Date
 * 
 * 	@return Date
 */
Date Assignment::getDueDate() {
	return dueDate;
}

/**
 *	Returns the type of Task
 * 
 * 	@return std::string
 */
std::string Assignment::getType() {
	return "Assignment";
}

/**
 * 	Changes the value of title
 * 	@param std::string value
 * 
 * 	@return std::string
 */
void Assignment::setTitle(std::string value) {
	title = value;
}

/**
 *	Changes the value of description
 * 
 * @param std::string value
 */
void Assignment::setDescription(std::string value) {
	description = value;
}

/**
 *	Changes the value of the Subject
 * 
 * 	@param Subject value
 */
void Assignment::setSubject(Subject value) {
	subject = value;
}

/**
 *	Changes the value of difficulty
 * 
 *	@param int value
 */
void Assignment::setDifficulty(int value) {
	difficulty = value;
}

/**
 *	Changes the value of Date
 * 
 * 	@param Date value
 */
void Assignment::setDueDate(Date value) {
	dueDate = value;
}

/**
 * Gets input from user to set the values
 */
void Assignment::setValues() {
	std::cout << "Title: ";
	std::cin.clear();
	std::cin.ignore(10000, '\n');
	getline(std::cin, title);
	std::cout << "Description: ";
	getline(std::cin, description);
	std::cout << "Difficulty (1-10): ";
	std::cin >> difficulty;
	std::cout << "Set the due date." << std::endl;
	std::cout << "Month (1-12): ";
	std::cin >> dueDate.month;
	std::cout << "Day (1-31): ";
	std::cin >> dueDate.day;
	std::cout << "Year: ";
	std::cin >> dueDate.year;
}
