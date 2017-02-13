//
// Created by pily on 27/01/17.
//

#ifndef WPS_PIN_GENERATOR_GENERATOR_H
#define WPS_PIN_GENERATOR_GENERATOR_H

#include "GeneratorInterface.h"

#include <string>
#include <vector>

/**
 * Base class Generator
 * Used to generate valid Pins
 */
class Generator : public GeneratorInterface {
public:
	std::vector<Pin> generatePin(const std::string &s) const override;

private:
	std::vector<Pin> generatePinImp(const std::string &s) const;
};


#endif //WPS_PIN_GENERATOR_GENERATOR_H
