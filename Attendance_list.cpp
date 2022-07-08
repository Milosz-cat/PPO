#pragma once
#include "Attendance_list.h"

using namespace std;

void Attendance_list::set_date(string _date)
{
    this->date = _date;
}

void Attendance_list::set_attendance(bool choice, int nr) {
    this->attendance[nr] = choice;
}

string Attendance_list::get_date() {
    return this->date;
}
bool Attendance_list::get_attendance(int nr) {
    return this->attendance[nr];

}
Attendance_list::Attendance_list() {
    //date = "unknown";
    //attendance = nullptr;
};
Attendance_list::Attendance_list(int size = 1, string day = "unknown") {
    this->date = day;
    attendance = new bool[size];
    for (int i = 0; i < size; i++)
        this->attendance[i] = 0;

}

int Attendance_list::Show_attendance(Attendance_list*& list_, int choice, int i) {
    if (list_[choice - 1].get_attendance(i) == 1)
        return 1;
    return 0;
}
