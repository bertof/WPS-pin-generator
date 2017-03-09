//
// Created by pily on 01/03/17.
//

#include "InputHandler.h"
#include "../Logger/Logger.h"
#include "../Logger/TextLogger/TextLogger.h"
#include "../Logger/DoubleLogger/DoubleLogger.h"
#include "../Exceptions/InvalidInputException.h"
#include "../Graphics/HelpScreen/HelpScreen.h"

#include <regex>
#include <iostream>

std::string InputHandler::bssidInput = "";

void InputHandler::handle(int argc, char **argv) {

	try {

		std::unique_ptr<Logger> logger(new DoubleLogger());

//		Logger *logger = new DoubleLogger();

		// Get arguments in c++ style string array
		auto args = std::vector<std::string>();
		for (int i = 0; i < argc; ++i) {
			args.push_back(argv[i]);
		}

		// Loop starts from 1 as args[0] contains the executable path
		for (int j = 1; j < args.size(); ++j) {

			// SWITCHES

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

				// ARGUMENTS

				// BSSID input
			else if (args[j] == "-b" || args[j] == "--bssid") {
				// Listen for a BSSID as next argument
				if (j + 1 < args.size() &&
				    std::regex_match(args[j + 1], std::regex("^([0-9A-F][0-9A-F]:){5}[0-9A-F][0-9A-F]$"))) {
					InputHandler::setBssidInput(args[j + 1]);
					++j;
				} else throw InvalidInputException(args[j + 1]);
			}

				// Help dialog
			else if (args[j] == "--help" || args[j] == "-h") {
				std::cout << HelpScreen::getHelpScreen() << std::endl;
				break;
			}

				// Case the argument is invalid
			else {
				throw InvalidInputException(args[j]);
			}
		}

	} catch (InvalidInputException e) {
		Logger *logger = new DoubleLogger();
		logger->logError("Argument passed is invalid:\t" + std::string(e.what()));
		throw InvalidInputException("Argument passed is invalid:\t\"" + std::string(e.what()) + "\"");
	}

}

const std::string &InputHandler::getBssidInput() {
	return bssidInput;
}

void InputHandler::setBssidInput(const std::string &bssidInput) {
	InputHandler::bssidInput = bssidInput;
}
