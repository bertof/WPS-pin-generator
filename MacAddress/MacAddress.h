//
// Created by pily on 29/03/17.
//

#ifndef WPS_PIN_GENERATOR_MACADDRESS_H
#define WPS_PIN_GENERATOR_MACADDRESS_H

class MacAddress {
private:
	std::string value;
protected:
	static bool checkValue(const std::string &value);
public:
	MacAddress(std::string);
	virtual ~MacAddress() {};
};

#endif //WPS_PIN_GENERATOR_MACADDRESS_H
