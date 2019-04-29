#include "../catch.hpp"
#include "../src/SimpleTask.h"

TEST_CASE("TESTING SETTERS AND GETTERS") {
	Assignment assignment;
	assignment.setTitle("Task");
	assignment.setDescription("Task Description");
	assignment.setEstimatedTime(45);

	REQUIRE(assignment.getTitle() == "Task");
	REQUIRE(assignment.getDescription() == "Task Description");
	REQUIRE(assignment.getEstimatedTime() == 45);
}
