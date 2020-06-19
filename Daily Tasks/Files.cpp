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
	int i = 0;
	while (std::getline(input, line)) {
		tasks.append(files::filledTask(line, i));
		i++;
	}
	return tasks;
}

void files::writeTasks(std::string file, std::string tasks) {
	std::ofstream output = std::ofstream();
	std::istringstream stringStream(tasks);
	std::string line;
	output.open(file);

	if (!output) {
		std::cerr << "File not recognized or unable to be opened.";
		return;
	}

	while (std::getline(stringStream, line)) {
		output << files::strippedTask(line) << "\n";
	}
}

std::string files::addTask(std::string tasks, std::string task, int currentNumberOfTasks) {
	std::string newTasks;
	newTasks.append(tasks);
	newTasks.append(files::filledTask(task, currentNumberOfTasks));

	return newTasks;
}

std::string files::removeTask(std::string tasks, int line) {
	std::istringstream istream(tasks);
	std::string lineString;
	std::string newTasks = std::string();

	// appends any lines in istream to newTasks, excepting the the line-th line
	int i = 0;
	while (std::getline(istream, lineString)) {
		// formats it to keep within the limit of TASK_TAG_LENGTH, so that parts of the task itself will not be removed during saving
		if ((i + 1) != line) 
		{ 
			newTasks.append(lineString);
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

std::string files::strippedTask(std::string task) {
	return task.substr(TASK_TAG_LENGTH, task.length());
}

std::string files::filledTask(std::string task, int currentTaskNum) {
	std::string newTask;
	if (currentTaskNum < 10) {
		newTask = "Task 00" + std::to_string(currentTaskNum + 1) + ": " + task + "\n";
	}
	else if (currentTaskNum < 100) {
		newTask = "Task 0" + std::to_string(currentTaskNum + 1) + ": " + task + "\n";
	}
	else {
		newTask = "Task " + std::to_string(currentTaskNum + 1) + ": " + task + "\n";
	}

	return newTask;
}