#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
#include <conio.h>


using namespace std;

class Person {
protected:

    string nationality;
    string name, surname;
    string sex;
    string date_of_birth;
    string ID;
    
public:

    //setters
    virtual void set_nationality();
    virtual void set_ID(string _ID);

    void set_name(string _name);
    void set_surname(string  _surname);
    void set_sex(string _sex);
    void set_date_of_birth(string _date_of_birth);
 
    //getters
    string get_nationality();
    string get_name();
    string get_surname();
    string get_sex();
    string get_date_of_birth();
    string get_ID();

    virtual int check_ID(string _ID);
    
    string show_person();

    int check_date(string data, int i);

    Person* Add(Person* person, Person p, int& size);
};

