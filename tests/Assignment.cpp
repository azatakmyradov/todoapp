#include "../catch.hpp"
#include "../src/Assignment.h"
#include "../src/Subject.cpp"
#include "../src/Date.cpp"

TEST_CASE("TESTING SETTERS AND GETTERS") {
	Assignment assignment;
	assignment.setTitle("Task");
	assignment.setDescription("Task Description");
	Subject subject;
	subject.name = "Computer Science";
	subject.instructor = "Adam Teichert";
	assignment.setSubject(subject);
	assignment.setDifficulty(4);
	Date date;
	date.month = 5;
	date.day = 23
	date.year = 2019;
	assignment.setDueDate(date);

	REQUIRE(assignment.getTitle() == "Task");
	REQUIRE(assignment.getDescription() == "Task Description");
	REQUIRE(assignment.getSubject().name == "Computer Science");
	REQUIRE(assignment.getSubject().instructor == "Adam Teichert");
	REQUIRE(assignment.getDifficulty == 4);
	REQUIRE(assignment.getDate().month == 5);
	REQUIRE(assignment.getDate().day == 23);
	REQUIRE(assignment.getDate().year == 2019);
}
