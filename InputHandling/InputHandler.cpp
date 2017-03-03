//
// Created by pily on 01/03/17.
//

#include "InputHandler.h"
#include "../Logger/Logger.h"
#include "../Logger/TextLogger/TextLogger.h"
#include "../Logger/DoubleLogger/DoubleLogger.h"
#include "../Exceptions/InvalidInputException.h"

#include <regex>

void InputHandler::handle(int argc, char **argv) {

	Logger *logger = new DoubleLogger();

	// Get arguments in c++ style string array
	auto args = std::vector<std::string>();
	for (int i = 0; i < argc; ++i) {
		args.push_back(argv[i]);
	}

	// Loop starts from 1 as args[0] contains the executable path
	for (int j = 1; j < args.size(); ++j) {

		// Activate verbouse mode
		if (args[j] == "--verbouse" || args[j] == "-v") {
			Logger::setVerbouseLogActive(true);
		}

			// Activate debug mode
		else if (args[j] == "--debug") {
			Logger::setDebugLogActive(true);
		}

			// Activate write on log file
		else if (args[j] == "--logfile") {
			TextLogger::setWriteOnLogFileActive(true);

			// If a path is passed nex uses it as the log file path
			if (j + 1 < args.size() && !std::regex_match(args[j + 1], std::regex("^/-"))) {
				TextLogger::setFilePath(args[j + 1]);
				++j;
			}
		}

			// Case the argument is invalid
		else {
			logger->logError("Argument passed is invalid:\t" + args[j]);
			throw InvalidInputException("Argument passed is invalid:\t\"" + args[j] + "\"");
		}
	}
}