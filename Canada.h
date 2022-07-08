#pragma once
#include "Person.h"

class Canadian : public Person {
public:

	void set_nationality();

	int check_ID(string _ID);

	void set_ID(string _ID);

	Canadian();
	Canadian(string _name, string _surname, string _sex, string _date_of_birth, string _ID);
};