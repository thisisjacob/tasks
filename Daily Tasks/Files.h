#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

const int TASK_TAG_LENGTH = 10;

namespace files 
{
	// reads tasks from file, returns as a std::string with each task separated by a new line
	// std::string file is the name of the file to read from
	std::string readTasks(std::string file);
	// returns a string representing a list of lines of tasks, returns a string with a selected line of that string removed
	// std::string tasks is the current list of tasks, int line is the line to be removed from tasks
	std::string removeTask(std::string tasks, int line);
	// writes the tasks to file, with each task on a separate line
	// std::string file is the file to write to, std::string tasks are a list of tasks to write
	void writeTasks(std::string file, std::string tasks);
	// returns a string with a new std::string task at the end of the list of tasks
	// std::string tasks is the original list of tasks, std::string task is the new task, int currentNumberOfTasks is the number of tasks, before the new one is added
	std::string addTask(std::string tasks, std::string task, int currentNumberOfTasks);
	// utilities

	// returns the number of tasks
	// std::string is the list of tasks, where each task is separated by a \n
	int numberOfTasks(std::string tasks);
	// returns a std::string without a task tag
	// std::string is the task to strip the tag from, tag is in the form of Task xxx: 
	std::string stripTaskTag(std::string task);
	// returns a string with a task tag at the beginning
	// tag is in the form of Task currentTaskNum
	// std::string is the task to remove the tag from, currentTaskNum is the number of the current task receiving a tag
	std::string addTaskTag(std::string task, int currentTaskNum);
}
