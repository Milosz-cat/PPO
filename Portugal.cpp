#include "Portugal.h"

void Portuguese::set_nationality() {
    nationality = "Portugal";
};

int Portuguese::check_ID(string CIN) {
    if (CIN.length() != 8)
        return 1;
    for (int i = 0; i < 8; i++) {
        if (CIN[i] < 48 || CIN[i] > 57)
            return 1;
    }

    return 0;

}

void Portuguese::set_ID(string _ID) {
    ID = _ID;
};

Portuguese::Portuguese() {

};
Portuguese::Portuguese(string _name = "unknown", string _surname = "unknown", string _sex = "unknown", string _date_of_birth = "unknown", string _ID = "unknown") {

    set_nationality();
    set_name(_name);
    set_surname(_surname);
    set_sex(_sex);
    set_date_of_birth(_date_of_birth);
    set_ID(_ID);
}
