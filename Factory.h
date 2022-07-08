#pragma once
#include "Person.h"
#include "Polish.h"
#include "Spanish.h"
#include "Portugal.h"
#include "Canada.h"

using namespace std;

class Factory: public Person
{
public:
	Factory();
	Person Add(string name, string surname, string ID, string sex, string date_of_birth, int choice);
};