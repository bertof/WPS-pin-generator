//
// Created by pily on 01/03/17.
//

#ifndef WPS_PIN_GENERATOR_SPASHSCREEN_H
#define WPS_PIN_GENERATOR_SPASHSCREEN_H

#include <string>

class SplashScreen {
public:
	static void printSplashScreen();
private:
	static std::string getSplashScreen();
};


#endif //WPS_PIN_GENERATOR_SPASHSCREEN_H
