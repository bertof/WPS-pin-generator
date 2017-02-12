//
// Created by pily on 11/02/17.
//

#ifndef WPS_PIN_GENERATOR_GENERATORINERFACE_H
#define WPS_PIN_GENERATOR_GENERATORINERFACE_H

#include <vector>
#include "../Pin/Pin.h"

class GeneratorInterface {
public:
	/** Method called to generate a pin
	 * @param s	string of the mac address
	 * @return 	non empty vector of valid Pins
	 */
	virtual std::vector<Pin> generatePin(const std::string &s) const =0;

	/** Method called to return the author of the generator
	 * @return
	 */
	virtual std::string author() const =0;

	/** Method called to return the version of the generator
	 * @return
	 */
	virtual std::string version() const =0;
};

#endif //WPS_PIN_GENERATOR_GENERATORINERFACE_H
