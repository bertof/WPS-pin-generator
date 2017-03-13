//
// Created by pily on 03/03/17.
//

#include "HelpScreen.h"
#include "../SplashScreen/SplashScreen.h"

#include "../Info/Info.h"

std::string HelpScreen::getHelpScreen() {
	return "Version: " + Info::getVersion() + "\n" +
		"Usage: " + Info::getExecutableName() + " [options]\n" +
		"OPTIONS:\n" +
		"-b, --bssid <BSSID>\t\tInput target BSSID\n" +
		"-h, --help\t\t\t\tPrint this help page\n" +
		"--debug\t\t\t\t\tPrint all th debug info" +
		"-v, --verbouse\tLog is more verbouse\n" +
		"--logfile [log.txt]\t\tEnables log to file (default log.txt)\n";
}
