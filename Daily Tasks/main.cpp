#include <iostream>
#include "Files.h"

std::string fileToRead = "../testing.txt";
std::string tasks;

int main() {
	std::cout << "Current tasks: " << std::endl;
	tasks = files::readTasks(fileToRead);
	std::cout << tasks << std::endl;
	std::cout << files::numberOfTasks(tasks);
	files::writeTasks("../secondTest.txt", tasks); // testing, remove
	tasks = files::removeTask(tasks, 2);
	std::cout << tasks;
	std::cout << std::endl;
	std::cin.get();
	return 0;
}