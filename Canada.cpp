#include "Canada.h"

void Canadian::set_nationality() {
    nationality = "Canada";
};

int Canadian::check_ID(string SIN) {

    if (SIN.size() != 11)
        return 1;

    if ((SIN[3] != '-') || (SIN[7] != '-'))
        return 2;

    int tab[11];
    for (int i = 0; i < 11; i++) {
        if ((i != 3) && (i != 7))
            tab[i] = stoi(SIN.substr(i, 1));
        else
            tab[i] = 0;
    }


    tab[1] = 2 * tab[1];
    if (tab[1] > 9)
        tab[1] = 1 + (tab[1] % 10);
    tab[4] = 2 * tab[4];
    if (tab[4] > 9)
        tab[4] = 1 + (tab[4] % 10);
    tab[6] = 2 * tab[6];
    if (tab[6] > 9)
        tab[6] = 1 + (tab[6] % 10);
    tab[9] = 2 * tab[9];
    if (tab[9] > 9)
        tab[9] = 1 + (tab[9] % 10);

    int sum = tab[0] + tab[1] + tab[2] + tab[4] + tab[5] + tab[6] + tab[8] + tab[9] + tab[10];
    if (sum % 10 == 0)
        return 0;
    else
        return 3;

}

void Canadian::set_ID(string _ID) {
    ID = _ID;
};

Canadian::Canadian() {

};
Canadian::Canadian(string _name = "unknown", string _surname = "unknown", string _sex = "unknown", string _date_of_birth = "unknown", string _ID = "unknown") {

    set_nationality();
    set_name(_name);
    set_surname(_surname);
    set_sex(_sex);
    set_date_of_birth(_date_of_birth);
    set_ID(_ID);
}
