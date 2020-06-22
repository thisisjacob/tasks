#include <iostream>
#include "Files.h"


const std::string fileToRead = "../tasks.txt";

int main(void) {
	std::string tasks;
	int selection;

	tasks = files::readTasks(fileToRead);
	for (;;) {
		std::cout << "Tasks:\n" << tasks;
		std::cout << "\nEnter 1 to add a task\nEnter 2 to remove a task\nAnything else to end the program and save the list:";
		std::cin >> selection;
		std::cin.ignore();
		// add a task to tasks
		if (selection == 1) {
			std::cout << "Enter the task: ";
			std::string newTask;
			std::getline(std::cin, newTask);
			tasks = files::addTask(tasks, newTask, files::numberOfTasks(tasks) + 1);
		}
		// remove a task from tasks
		else if (selection == 2) {
			std::cout << "Enter a number of the line you wish to remove: ";
			int line;
			std::cin >> line;
			tasks = files::removeTask(tasks, line);
		}
		// program over, successfully return 0
		else { 
			return 0;
		}
		// update the fileToRead file with every addition or removal
		files::writeTasks(fileToRead, tasks);
		std::cout << "\n";
	}
	// should not reach here, return 1 to signify abnoraml exit
	return 1;
}