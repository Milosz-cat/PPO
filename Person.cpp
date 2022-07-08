#include "Person.h"

    //setters
    void Person::set_nationality() {
        nationality = "unknown";
    }
    void Person::set_name(string _name) {
        name = _name;
    };
    void Person::set_surname(string  _surname) {
        surname = _surname;
    };
    void Person::set_ID(string _ID) {
        ID = _ID;
    }
    void Person::set_sex(string _sex) {
        sex = _sex;
    };
    void Person::set_date_of_birth(string _date_of_birth) {
        date_of_birth = _date_of_birth;
    };
    
    //getters
    string Person::get_nationality() {
        return nationality;
    };
    string Person::get_name() {
        return name;
    };
    string Person::get_surname() {
        return surname;
    };
    string Person::get_sex() {
        return sex;
    };
    string Person::get_date_of_birth() {
        return date_of_birth;
    };
    string Person::get_ID() {
        return ID;
    };
    
    int Person::check_ID(string _ID) {
        return 0;
    };

    string Person::show_person()  {
        return "Nationality : " + get_nationality() + "\n" + "Name: " + get_name() + "\n" + "Surname: " + get_surname() + "\n" + "ID: " + get_ID() + "\n" + "Sex: " + get_sex() + "\n" + "Date of birth : " + get_date_of_birth() + "\n";
    };

    int Person::check_date(string data, int i) {
        int day, month, year;
        if (data.length() < 8 || data.length() > 10)
            return 1;
        if (data[2] == '.' && data[5] == '.' && data.length() == 10) {
            if (data[0] == '0')
                day = stoi(data.substr(1, 1));
            else
                day = stoi(data.substr(0, 2));
            if (data[3] == '0')
                month = stoi(data.substr(4, 1));
            else
                month = stoi(data.substr(3, 2));
            year = stoi(data.substr(6, 4));
            if (i == 1) {//obecnosc
                if ((day <= 0) || (day > 31) || (month <= 0) || (month > 12) || (year < 2022) || (year > 2100))
                    return 1;
            }
            if (i == 2) {//data urodznia
                if ((day <= 0) || (day > 31) || (month <= 0) || (month > 12) || (year < 1900) || (year > 2022))
                    return 1;
            }
        }
        else if (data[1] == '.' && data[4] == '.' && data.length() == 9) {
            day = stoi(data.substr(0, 1));
            if (data[2] == '0')
                month = stoi(data.substr(3, 1));
            else
                month = stoi(data.substr(2, 2));
            year = stoi(data.substr(5, 4));
            if (i == 1) {
                if ((day <= 0) || (day > 31) || (month <= 0) || (month > 12) || (year < 2022) || (year > 2100))
                    return 1;
            }
            if (i == 2) {
                if ((day <= 0) || (day > 31) || (month <= 0) || (month > 12) || (year < 1900) || (year > 2022))
                    return 1;
            }
        }
        else if (data[1] == '.' && data[3] == '.' && data.length() == 8) {
            day = stoi(data.substr(0, 1));
            month = stoi(data.substr(2, 1));
            year = stoi(data.substr(4, 4));
            if (i == 1) {
                if ((day <= 0) || (day > 31) || (month <= 0) || (month > 12) || (year < 2022) || (year > 2100))
                    return 1;
            }
            if (i == 2) {
                if ((day <= 0) || (day > 31) || (month <= 0) || (month > 12) || (year < 1900) || (year > 2022))
                    return 1;
            }
        }
        else if (data[2] == '.' && data[4] == '.' && data.length() == 9) {
            if (data[0] == '0')
                day = stoi(data.substr(1, 1));
            else
                day = stoi(data.substr(0, 2));
            month = stoi(data.substr(3, 1));
            year = stoi(data.substr(5, 4));
            if (i == 1) {
                if ((day <= 0) || (day > 31) || (month <= 0) || (month > 12) || (year < 2022) || (year > 2100))
                    return 1;
            }
            if (i == 2) {
                if ((day <= 0) || (day > 31) || (month <= 0) || (month > 12) || (year < 1900) || (year > 2022))
                    return 1;
            }
        }

        return 0;

    }

    Person* Person::Add(Person* person, Person p, int& size) {
        
        if (size > 30){
            cout << "The list is full, you cannot add another person!\n";
            system("pause"); return person;
        }

        Person* temp = new Person[size + 1];
        if (size > 0) {
            for (int i = 0; i < size; i++) {
                if (((person[i].get_name() == p.get_name()) && (person[i].get_surname() == p.get_surname())) || (person[i].get_ID() == p.get_ID())) {
                    cout << "The person that you want to add already exist on list!\n";
                    return person;
                }
                temp[i] = person[i];
            }
        }
        temp[size] = p;
        size++;

        delete[] person;
        person = temp;

        return person;    //zwracamy nowy wskaznik do powiekszonej tablicy person
    
    };
    