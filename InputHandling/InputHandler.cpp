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

	std::shared_ptr<Logger> logger(new DoubleLogger);

//		Logger *logger = new DoubleLogger();

	// Get arguments in c++ style string array
	std::vector<std::string> args;

	for (int i = 0; i < argc; ++i) {
	  args.push_back(std::string(argv[i]));
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
		TextLogger::setWriteOnFileActive(true);

		// If a path is passed nex uses it as the log file path
		if (j + 1 < args.size() && !std::regex_match(args[j + 1], std::regex("^/-"))) {
		  TextLogger::getTextLogger(args[j + 1]);
		  ++j;
		}
	  }

		// ARGUMENTS

		// Help dialog
	  else if (args[j] == "--help" || args[j] == "-h") {
		std::cout << HelpScreen::getHelpScreen() << std::endl;
		break;
	  }

		// Pin generator
	  else if (args[j] == "-b" || args[j] == "--bssid") {
		// Listen for a BSSID as next argument
		++j;
		while (j < args.size() &&
			std::regex_match(args[j], std::regex("^([0-9A-F][0-9A-F]:){5}[0-9A-F][0-9A-F]$"))) {

		  for (int k = j + 2; k < args.size(); ++k) {

			// Pin using generator
			if (args[k] == "-g" || args[k] == "--generator") {
			  std::cout << "Results from generator:" << std::endl;
			  std::shared_ptr<GeneratorInterface> generator(new bertof::Generator);
			  std::vector<Pin> results = generator->generatePin(args[j]);
			  for (int l = 0; l < results.size(); ++l) {
				std::cout << l << ":\t" << results[l].toString() << std::endl;
			  }
			  std::cout << std::endl;
			}

			//TODO Pin from DB using BSSID

			//TODO Pin from DB using ASSID
		  }
		  ++j;
		}
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
