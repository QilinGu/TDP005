#ifndef FILEHANDLER_H
#define FILEHANDLER_H

//!\cond
#include <vector>
#include <string>
//!\endcond

//! fileHandler class
/*!
 * A class that handles input/output to files
 */
class fileHandler
{
public:

	//! Constructor
	/*!
	 * The constructor initialize the filename variable
	 * \param filename The file to load
	 */
	fileHandler(const std::string& filename);

	//! Destructor
	/*!
	 * The destructor does not do anything.
	 */
	virtual ~fileHandler();

	//! getLines method
	/*!
	 * Returns all the lines in a vector, each line in its own index.
	 */
	std::vector<std::string> getLines();

	//! writeLines method
	/*!
	 * Writes every index from the vector on its own line
	 * \param lines The lines to write in a vector<string>
	 */
	void writeLines(std::vector<std::string>& lines);

	//! checkErr method
	/*!
	 * Checks if file could be opened and if not, outputs error and exits.
	 * \param fs The filestream.
	 */
	void checkErr(std::fstream& fs);

	//! changeFile method
	/*!
	 * Change the file to operate on.
	 * \param _filename The new file to work on.
	 */
	void changeFile(const std::string& _filename);


private:
	std::string filename;
};

#endif
