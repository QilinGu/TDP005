#include "fileHandler.h"

#include <iostream>
#include <fstream>


fileHandler::fileHandler(const std::string& _filename) : filename(_filename) {}

fileHandler::~fileHandler() {}

void fileHandler::checkErr(std::fstream& fs)
{
	if (!fs.is_open())
	{
		std::cerr << "Error: Could not open file '" << filename << "'." << std::endl;
		exit(1);
	}
}

std::vector<std::string> fileHandler::getLines()
{
	std::fstream ifs (filename, std::fstream::in);

	checkErr(ifs);

	std::vector<std::string> lines;

	std::string line;
	while (getline(ifs, line))
	{
		lines.push_back(line);
	}

	ifs.close();

	return lines;
}

void fileHandler::writeLines(std::vector<std::string>& lines)
{
	std::fstream ofs (filename, std::fstream::out | std::fstream::trunc);

	checkErr(ofs);

	for (std::string l : lines)
	{
		ofs << l << "\n";
	}

	ofs.close();
}

void fileHandler::changeFile(const std::string& _filename)
{
	filename = _filename;
}
