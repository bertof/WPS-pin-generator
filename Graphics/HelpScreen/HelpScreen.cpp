//
// Created by pily on 03/03/17.
//

#include "HelpScreen.h"
#include "../SplashScreen/SplashScreen.h"
#include "../Info/Info.h"

#include <fstream>

std::string HelpScreen::getHelpScreen() {
	return
		"Version: " + Info::getVersion() + "\n" +
			"USAGE:\n" +
			Info::getExecutableName() + " [options]\n" +
			"\n" +
			"OPTIONS:\n" +
			"-b, --bssid <BSSID>\t\tInput target BSSID\n" +
			"-g\t\t\t\t\t\tUse the generator algorithm\n" +
			"-d\t\t\t\t\t\tUse the database\n" +
			"-h, --help\t\t\t\tPrint this help page\n" +
			"--debug\t\t\t\t\tPrint all th debug info" +
			"-v, --verbouse\tLog is more verbouse\n" +
			"--logfile [log.txt]\t\tEnables log to file (default log.txt)\n" +
			"\n" +
			"EXAMPLES:\n" +
			Info::getExecutableName() + " -h\n" +
			Info::getExecutableName() + " -b 00:11:22:33:44:55 -g -d --logfile";
}
