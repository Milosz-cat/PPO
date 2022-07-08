#pragma once
#include "Person.h"

using namespace std;

class Attendance_list
{
private:

    string date;
    bool* attendance = nullptr;

public:

    void set_date(string _date);
    void set_attendance(bool choice, int nr);

    string get_date();
    bool get_attendance(int nr);

    Attendance_list();
    Attendance_list(int size, string day);

    int Show_attendance(Attendance_list*& list_, int choice, int i);
};

