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
#include "../Exceptions/NotImplementedException.h"
#include "../Exceptions/HelpScreenException.h"

#include <regex>
#include <iostream>

std::string InputHandler::bssidInput = "";

void InputHandler::handle(int argc, char **argv) {

	try {
		/*** Default logger */
		std::shared_ptr<DoubleLogger> logger(DoubleLogger::getDoubleLogger());

		/*** BSSID input from arguments */
		std::vector<std::string> bssid_arguments;
		/*** ESSID input from arguments */
		std::vector<std::string> essid_arguments;

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

		// Default behaviour when not using any aguments: show help screen
		if (args.size() == 1) {
			throw HelpScreenException();
		}

		// Loop starts from 1 as args[0] allways contains the executable path
		int i = 1;
		while (i < args.size()) {

			// SWITCHES

			// Activate verbouse mode
			if (args[i] == "--verbouse" || args[i] == "-v") {
				Logger::setVerbouseLogActive(true);
				++i;
			}

				// Activate debug mode
			else if (args[i] == "--debug") {
				Logger::setDebugLogActive(true);
				++i;
			}

				// Activate write on log file
			else if (args[i] == "--logfile") {
				TextLogger::setWriteOnFileActive(true);

				// If a path is passed nex uses it as the log file path
				if (i + 1 < args.size() && std::regex_match(args[i + 1], std::regex("^(^-)"))) {
					TextLogger::getTextLogger(args[i + 1]);
					++i;
				}

				++i;
			}

				// Help dialog
			else if (args[i] == "--help" || args[i] == "-h") {
				throw HelpScreenException();
			}

				// BSSID input
			else if (args[i] == "-b" || args[i] == "--bssid") {

				// Listen for a BSSID as next argument

				// While i find arguments that match a BSSID format
				while (i + 1 < args.size()
					&& std::regex_match(args[i + 1], std::regex("^(([0-9A-Fa-f]){2}:){5}([0-9a-fA-F]){2}$"))) {

					bssid_arguments.push_back(args[i + 1]);
					++i;
				}

				// Check if any BSSID is been given
				if (bssid_arguments.size() == 0) {
					throw InvalidInputException("No BSSID found");
				}

				++i;
			}

				// ESSID input
			else if (args[i] == "-e" || args[i] == "--essid") {

				// Listen for a ESSID as next argument

				// While i find arguments that match a BSSID format
				while (i + 1 < args.size() &&
					std::regex_match(args[i + 1], std::regex("^(^-)"))) {
					bssid_arguments.push_back(args[i + 1]);
					++i;
				}

				// Check if any ESSID is been given
				if (essid_arguments.size() == 0) {
					throw InvalidInputException("No ESSID found");
				}

				++i;
			}

				// Switch to enable generator results
			else if (args[i] == "-g" || args[i] == "--generator") {
				useGenerator = true;
				++i;
			}

				// Switch to enable database results
			else if (args[i] == "-d" || args[i] == "--database") {
				useDatabase = true;
				++i;
			}

				// Case the argument is invalid
			else {
				throw InvalidInputException(args[i]);
			}

		} // End of for cycle

		// Output generation
		//TODO output generation

		if (!useGenerator && !useDatabase) {
			throw InvalidInputException("-g or -d options not set.");
		}

		if (bssid_arguments.size() + essid_arguments.size() == 0) {
			throw InvalidInputException("No BSSID or ESSID argument given.");
		}

		if (useGenerator) {
			std::shared_ptr<GeneratorInterface> generator(new bertof::Generator());
			logger->logVerbouse(
				"Results from generator by " + generator->author() + " version " + generator->version());
			for (int k = 0; k < bssid_arguments.size(); ++k) {
				std::vector<Pin> results = generator->generatePin(bssid_arguments[k]);
				logger->log("BSSID:\t" + bssid_arguments[k]);
				logger->logVerbouse("Pins generated:");
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

			for (int k = 0; k < essid_arguments.size(); ++k) {
			 std::vector<Pin> results = generator.generatePin(essid_arguments[k]);
			 logger->log(bssid_arguments[k] + " results:");
			 for (int i = 0; i < results.size(); ++i) {
				logger->log(results[i].toString());
			 }
			}

			*/

			throw NotImplementedException("Database is not implemented yet");
		}

	} catch (InvalidInputException e) {
		std::shared_ptr<DoubleLogger> logger(DoubleLogger::getDoubleLogger());
		logger->logError(std::string(e.what()));
	} catch (HelpScreenException e) {
		std::cout << HelpScreen::getHelpScreen() << std::endl;
	} catch (NotImplementedException e) {
		std::shared_ptr<DoubleLogger> logger(DoubleLogger::getDoubleLogger());
		logger->logError(std::string(e.what()));
	}
}

const std::string &InputHandler::getBssidInput() {
	return bssidInput;
}

void InputHandler::setBssidInput(const std::string &bssidInput) {
	InputHandler::bssidInput = bssidInput;
}
