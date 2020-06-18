#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
namespace files 
{
	// reads tasks from file, returns as a std::string with each task separated by a new line
	std::string readTasks(std::string file);
	// returns a string with the task associated with line removed
	std::string removeTask(std::string tasks, int line);
	// writes the tasks to file, with each task on a separate line
	void writeTasks(std::string file, std::string tasks);
	// utilities
	// returns the number of tasks
	int numberOfTasks(std::string tasks);
}
