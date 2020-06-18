#include <iostream>
#include "Files.h"

std::string fileToRead = "../testing.txt";
std::string tasks;
int selection;

int main() {
	tasks = files::readTasks(fileToRead);
	for (;;) {
		std::cout << "Tasks: \n" << tasks;
		std::cout << "Enter 1 to add a task. Enter 2 to remove a task. Anything else to end the program.";
		std::cin >> selection;
		std::cin.ignore();
		if (selection == 1) {
			std::cout << "Enter the task.";
			std::string newTask = std::string();
			std::getline(std::cin, newTask);
			tasks.append(newTask + "\n");
		}
		else if (selection == 2) {
			std::cout << "Enter a number of the line you wish to remove.";
			int line;
			std::cin >> line;
			tasks = files::removeTask(tasks, line);
		}
		else { // program over, successfully return 1
			return 1;
		}
		files::writeTasks(fileToRead, tasks);
	}
	std::cin.get();
	return -1;
}