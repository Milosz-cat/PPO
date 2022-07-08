#pragma once
#include "Person.h"

class Pole : public Person {
public:

	void set_nationality();
	
	int check_ID(string _ID);

	void set_ID(string _ID);
	
	Pole();
	Pole(string _name, string _surname, string _ID);
};