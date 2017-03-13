//
// Created by pily on 06/03/17.
//

#ifndef WPS_PIN_GENERATOR_VERSION_H
#define WPS_PIN_GENERATOR_VERSION_H

#include <string>

class Info {
public:
	static std::string getVersion();
	static std::string getProjectName();
	static std::string getExecutableName();
};

#endif //WPS_PIN_GENERATOR_VERSION_H
