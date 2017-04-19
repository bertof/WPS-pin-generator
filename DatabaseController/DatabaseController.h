//
// Created by pily on 22/03/17.
//

#ifndef WPS_PIN_GENERATOR_DATABASE_H
#define WPS_PIN_GENERATOR_DATABASE_H

#include <boost/shared_ptr.hpp>
class DatabaseController {
private:
	static const std::string defaultDatabaseLocation;
protected:
	DatabaseController();
	virtual ~DatabaseController();
public:
	static std::shared_ptr<DatabaseController> getDatabaseController();
	bool readInfo();
	bool writeInfo();
};

#endif //WPS_PIN_GENERATOR_DATABASE_H
