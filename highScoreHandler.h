#ifndef HIGHSCOREHANDLER_H
#define HIGHSCOREHANDLER_H

#include "fileHandler.h"

class highScoreHandler
{
public:

	//! Constructor
	/*!
	 * The initialize the filehandler and records variable
	 */
	highScoreHandler();

	//! Destructor
	/*!
	 * The destructor doesn't do anything.
	 */
	virtual ~highScoreHandler();

	//! getHighScore method
	/*!
	 * Returns the current high score.
	 * \return Current high score
	 */
	int getHighScore() const;

	//! isRecord method
	/*!
	 * Returns true if parameter points is a new records, else returns false.
	 * \param points The points to check against.
	 */
	bool isRecord(const int& points) const;

	//! setNewRecord method
	/*!
	 * Sets the new records, if parameter is not a records, outputs an error and exits.
	 * \param points The points with the new record.
	 */
	void setNewRecord(const int& points);

private:
	//! linesToIntVector method
	/*!
	 * Returns all lines converted to integers with each line as its own index.
	 */
	std::vector<int> linesToIntVector();

	fileHandler file;
	std::vector<int> records;
};

#endif
