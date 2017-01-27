//
// Created by pily on 27/01/17.
//

#ifndef WPS_PIN_GENERATOR_GENERATOR_H
#define WPS_PIN_GENERATOR_GENERATOR_H

#include "GeneratorInterface.h"

#include <string>

class Generator : public GeneratorInterface {
public:
	Pin generatePin(const std::string &s) const override;

private:
	Pin generatePinImp(const std::string &s) const;
};


#endif //WPS_PIN_GENERATOR_GENERATOR_H
