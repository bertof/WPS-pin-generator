//
// Created by pily on 27/01/17.
//

/***    GeneratorInterface
 * GeneratorInterface is an base class interface used to implement
 * the design pattern strategy
 */

#ifndef WPS_PIN_GENERATOR_GENERATORINTERFACE_H
#define WPS_PIN_GENERATOR_GENERATORINTERFACE_H

#include "Pin.h"
#include <string>

class GeneratorInterface {
public:
	virtual Pin generatePin(const std::string &s) const =0;
};

#endif //WPS_PIN_GENERATOR_GENERATORINTERFACE_H
