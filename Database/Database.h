//
// Created by pily on 22/03/17.
//

#ifndef WPS_PIN_GENERATOR_DATABASE_H
#define WPS_PIN_GENERATOR_DATABASE_H

#include <boost/shared_ptr.hpp>
class DataBase {
private:
	static std::shared_ptr<DataBase> mainDatabaseManager;
};

#endif //WPS_PIN_GENERATOR_DATABASE_H
