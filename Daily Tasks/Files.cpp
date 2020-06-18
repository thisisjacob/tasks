#include "Files.h"

std::string files::readTasks(std::string file)
{
	std::string tasks = std::string();
	std::ifstream input = std::ifstream();
	input.open(file);
	// returns an empty std::string
	if (!input) { 
		std::cerr << "File not recognized or unable to be opened." << std::endl;
		return tasks;
	}

	std::string line;
	while (std::getline(input, line)) {
		tasks.append(line + "\n");
	}
	return tasks;
}

void files::writeTasks(std::string file, std::string tasks) {
	std::ofstream output = std::ofstream();
	output.open(file);

	if (!output) {
		std::cerr << "File not recognized or unable to be opened.";
		return;
	}

	output << tasks;
}

std::string files::removeTask(std::string tasks, int line) {
	std::istringstream istream(tasks);
	std::string lineString;
	std::string newTasks = std::string();

	// appends any lines in istream to newTasks, excepting the the line-th line
	int i = 0;
	while (std::getline(istream, lineString)) {
		if (i + 1 != line) {
			newTasks.append(lineString + "\n");
		}
		i++;
	}
	return newTasks;
}

int files::numberOfTasks(std::string tasks) {
	int position = 0;
	int lines = 0;
	while (tasks.find("\n", position) != std::string::npos) {
		position = tasks.find("\n", position) + 1;
		lines++;
	}
	return lines;
}