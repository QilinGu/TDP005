#include "highScoreHandler.h"

#include <sstream>
#include <iostream>
#include <string>


highScoreHandler::highScoreHandler() : file("highScore.txt"), records(linesToIntVector()) {}

highScoreHandler::~highScoreHandler() {}

int highScoreHandler::getHighScore() const
{
	return records.at(0);
}

std::vector<int> highScoreHandler::linesToIntVector()
{
	std::vector<int> recs;

	for (std::string line : file.getLines())
	{
		std::istringstream iss (line);
		int points;

		// Get points from line
		iss >> points;

		recs.push_back(points);
	}

	return recs;
}

bool highScoreHandler::isRecord(const int& points) const
{
	return points > records.at(9);
}

void highScoreHandler::setNewRecord(const int& points)
{
	if (!isRecord(points))
	{
		std::cerr << points << " is not a record." << std::endl;
		exit(1);
	}

	for (unsigned int i = 0; i < records.size(); ++i)
	{
		if (points > records[i])
		{
			records.insert(records.begin()+i, points);
			records.pop_back();
			std::vector<std::string> lines;
			for (int point : records)
			{
				lines.push_back(std::to_string(point));
			}
			file.writeLines(lines);
			break;
		}
	}
}
