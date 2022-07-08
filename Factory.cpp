#pragma once
#include "Factory.h"



using namespace std;

Factory::Factory() {}


Person Factory::Add(string name, string surname, string ID, string sex, string date_of_birth, int choice) {
	switch (choice) {
	case 1:

		return Pole(name, surname, ID);
		break;

	case 2:

		return Spaniard(name, surname,sex,date_of_birth, ID);
		break;

	case 3:

		return Canadian(name, surname, sex, date_of_birth, ID);
		break;

	case 4:

		return Portuguese(name, surname, sex, date_of_birth, ID);
		break;

	default:
		return Pole(name, surname, ID);
		break;

	}
}

