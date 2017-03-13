//
// Created by pily on 01/03/17.
//

#include "InputHandler.h"
#include "../Logger/Logger.h"
#include "../Logger/TextLogger/TextLogger.h"
#include "../Logger/DoubleLogger/DoubleLogger.h"
#include "../Exceptions/InvalidInputException.h"
#include "../Graphics/HelpScreen/HelpScreen.h"

#include "../Generator/GeneratorInerface.h"
#include "../Generator/bertofGenerator/Generator.h"

#include <regex>
#include <iostream>

std::string InputHandler::bssidInput = "";

void InputHandler::handle(int argc, char **argv) {

	try {
		/*** Default logger */
		std::shared_ptr<DoubleLogger> logger(DoubleLogger::getDoubleLogger());
		/*** bssid input from arguments */
		std::vector<std::string> bssid_arguments;
		/*** assid input from arguments */
		std::vector<std::string> assid_arguments;
		/*** switch to ask for a result based on the generator */
		bool useGenerator = false;
		/*** switch to ask for a result from the database */
		bool useDatabase = false;

		// Get arguments in c++ style string array
		/*** c++ string container of arguments */
		std::vector<std::string> args;
		for (int i = 0; i < argc; ++i) {
			args.push_back(std::string(argv[i]));
		}

		// Default behaviour: show help screen
		if (args.size() == 1) {
			std::cout << HelpScreen::getHelpScreen() << std::endl;
		}

		// Loop starts from 1 as args[0] allways contains the executable path
		for (int j = 1; j < args.size(); ++j) {
			// SWITCHES

			// Activate verbouse mode
			if (args[j] == "--verbouse" || args[j] == "-v") { Logger::setVerbouseLogActive(true); }

				// Activate debug mode
			else if (args[j] == "--debug") { Logger::setDebugLogActive(true); }

				// Activate write on log file
			else if (args[j] == "--logfile") {
				TextLogger::setWriteOnFileActive(true);

				// If a path is passed nex uses it as the log file path
				if (j + 1 < args.size() && !std::regex_match(args[j + 1], std::regex("^/-"))) {
					TextLogger::getTextLogger(args[j + 1]);
					++j;
				}
			}

				// Help dialog
			else if (args[j] == "--help" || args[j] == "-h") {
				std::cout << HelpScreen::getHelpScreen() << std::endl;
				break;
			}

				// BSSID input
			else if (args[j] == "-b" || args[j] == "--bssid") {

				// Listen for a BSSID as next argument
				// moves j to the first BSSID
				++j;

				// While i find arguments that match a BSSID format
				while (j < args.size() &&
					std::regex_match(args[j], std::regex("^(([0-9A-Fa-f]){2}:){5}([0-9a-fA-F]){2}$"))) {
					bssid_arguments.push_back(args[j]);
					++j;
				}
			}

				// ASSID input
			else if (args[j] == "-a" || args[j] == "--assid") {

				// Listen for ASSID as next argument
				// moves j to the first ASSID
				++j;

				// While i find arguments that match a ASSID format
				while (j < args.size() &&
					!std::regex_match(args[j], std::regex("^/-"))) {
					assid_arguments.push_back(args[j]);
					++j;
				}
			}

				// Switch to enable generator results
			else if (args[j] == "-g" || args[j] == "--generator") {
				useGenerator = true;
			}

				// Switch to enable database results
			else if (args[j] == "-d" || args[j] == "--database") {
				useDatabase = true;
			}

				// Case the argument is invalid
			else {
				throw InvalidInputException(args[j]);
			}

		} // End of for cycle

		// Output generation
		//TODO output generation

		if (useGenerator || useDatabase) {
			logger->log("Results:");
		}
		if (useGenerator) {
			GeneratorInterface *generator = new bertof::Generator();
			logger->logVerbouse("Results from generator by " + generator->author() + " version " + generator->version());
			for (int k = 0; k < bssid_arguments.size(); ++k) {
				std::vector<Pin> results = generator->generatePin(bssid_arguments[k]);
				logger->log(bssid_arguments[k] + " results:");
				for (int i = 0; i < results.size(); ++i) {
					logger->log(results[i].toString());
				}
			}
		}

		if (useDatabase) {
			/*

			 DatabaseInterface *database = new bertof::Database();
			logger->logVerbouse("Results from database by " + database->author() + " version " + database->version());

			for (int k = 0; k < bssid_arguments.size(); ++k) {
			 std::vector<Pin> results = generator.generatePin(bssid_arguments[k]);
			 logger->log(bssid_arguments[k] + " results:");
			 for (int i = 0; i < results.size(); ++i) {
				logger->log(results[i].toString());
			 }
			}

			for (int k = 0; k < assid_arguments.size(); ++k) {
			 std::vector<Pin> results = generator.generatePin(assid_arguments[k]);
			 logger->log(bssid_arguments[k] + " results:");
			 for (int i = 0; i < results.size(); ++i) {
				logger->log(results[i].toString());
			 }
			}

			*/

			logger->logError("Database is not implemented yet");
		}

	} catch (InvalidInputException e) {
		std::shared_ptr<DoubleLogger> logger(DoubleLogger::getDoubleLogger());
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
