//
// Created by pily on 27/01/17.
//

#include <stdexcept>
#include <sstream>
#include "Generator.h"

/**
 * Implementation of generatePin
 * Returns result of generatePinImp based on the same data passed
 * @param s string of data
 * @return Pin valid pin generated
 */
std::vector<Pin> Generator::generatePin(const std::string &s) const { return generatePinImp(s); }

/**
 * Generates a valid Pin object using an algorithm based on <a href="http://www.auditoriaswireless.net/wireless-windows/computepin-c83a35-by-zhaochunsheng-(wps)/">zhaochunsheng's ComputePIN-C83A35</a> and <a href="https://github.com/linkp2p/WPS-PIN">linkp2p's WPS-PIN</a>
 * @param s: data passed
 * @return valid Pin object
 */
std::vector<Pin> Generator::generatePinImp(const std::string &s) const {

	std::vector<Pin> result = std::vector<Pin>();

	long calc;

	std::stringstream ss;
	ss << std::hex << s;
	ss >> calc;

}
