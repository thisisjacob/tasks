#include <iostream>
#include "Files.h"

std::string fileToRead = "../tasks.txt";
std::string tasks;
int selection;

int main(void) {
	tasks = files::readTasks(fileToRead);
	for (;;) {
		std::cout << "Tasks: \n" << tasks;
		std::cout << "Enter 1 to add a task. Enter 2 to remove a task. Anything else to end the program and save the list.\n";
		std::cin >> selection;
		std::cin.ignore();
		if (selection == 1) {
			std::cout << "Enter the task: ";
			std::string newTask;
			std::getline(std::cin, newTask);
			tasks = files::addTask(tasks, newTask, files::numberOfTasks(tasks));
		}
		else if (selection == 2) {
			std::cout << "Enter a number of the line you wish to remove: ";
			int line;
			std::cin >> line;
			tasks = files::removeTask(tasks, line);
		}
		else { // program over, successfully return 1
			return 0;
			
		}
		files::writeTasks(fileToRead, tasks);
	}
	std::cin.get();
	return 1;
}