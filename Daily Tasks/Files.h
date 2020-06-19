#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

const int TASK_TAG_LENGTH = 10;

namespace files 
{
	// reads tasks from file, returns as a std::string with each task separated by a new line
	std::string readTasks(std::string file);
	// returns a string with the task associated with line removed
	std::string removeTask(std::string tasks, int line);
	// writes the tasks to file, with each task on a separate line
	void writeTasks(std::string file, std::string tasks);
	// returns a string with the new tasks list after the tasks are updated
	std::string addTask(std::string tasks, std::string task, int currentNumberOfTasks);
	// utilities
	// returns the number of tasks
	int numberOfTasks(std::string tasks);
	// removes task tag/number from a task
	std::string strippedTask(std::string task);
	// adds the task tag and number to the task
	std::string filledTask(std::string task, int currentTaskNum);
}
