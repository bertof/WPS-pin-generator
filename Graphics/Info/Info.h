//
// Created by pily on 06/03/17.
//

#ifndef WPS_PIN_GENERATOR_VERSION_H
#define WPS_PIN_GENERATOR_VERSION_H

#include <string>

/*** Centralized information about this program
 */
class Info {
public:
	/*** Get a string with the version of the program
	 * @return version string
	 */
	static std::string getVersion();
	/*** Get the full name of the project
	 * @return project name string
	 */
	static std::string getProjectName();
	/*** Get the executable name
	 * @return executable name
	 */
	static std::string getExecutableName();
	/*** Get author name
	 * @return author string
	 */
	static std::string getAuthorNames();
	/*** Get some info about the author
	 * @return author info
	 */
	static std::string getAuthorInfos();
};

#endif //WPS_PIN_GENERATOR_VERSION_H
