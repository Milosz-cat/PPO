#include "Spanish.h"

void Spaniard::set_nationality() {
    nationality = "Spanish";
};

int Spaniard::check_ID(string DNI) {

    if (DNI.size() != 9) {
        return 1;
    }
    if (sizeof(DNI[8]) != sizeof('R')) {
        return 1;
    }
    int R = stoi(DNI.substr(0, 8));// 8 pierwszych liczb
    char L = DNI[8];// Remainder

    R = (R % 23);
    if (R >= 0 && R <= 22) {
        if ((R == 0 && L == 'T') || (R == 1 && L == 'R') || (R == 2 && L == 'W') || (R == 3 && L == 'A') || (R == 4 && L == 'G') || (R == 5 && L == 'M') || (R == 6 && L == 'Y') || (R == 7 && L == 'F') || (R == 8 && L == 'P') || (R == 9 && L == 'D') || (R == 10 && L == 'X') || (R == 11 && L == 'B') || (R == 12 && L == 'N') || (R == 13 && L == 'J') || (R == 14 && L == 'Z') || (R == 15 && L == 'S') || (R == 16 && L == 'Q') || (R == 17 && L == 'V') || (R == 18 && L == 'H') || (R == 19 && L == 'L') || (R == 20 && L == 'C') || (R == 21 && L == 'K') || (R == 22 && L == 'E'))
            return 0;
    }

    return 1;

}
// R->   0	1	2	3	4	5	6	7	8	9	10	11	12	13	14	15	16	17	18	19	20	21	22
// L->	T	R	W	A	G	M	Y	F	P	D	X	B	N	J	Z	S	Q	V	H	L	C	K	E

void Spaniard::set_ID(string _ID) {
    ID = _ID;
};

Spaniard::Spaniard() {

};
Spaniard::Spaniard(string _name = "unknown", string _surname = "unknown", string _sex = "unknown", string _date_of_birth = "unknown", string _ID = "unknown") {

    set_nationality();
    set_name(_name);
    set_surname(_surname);
    set_sex(_sex);
    set_date_of_birth(_date_of_birth);
    set_ID(_ID);
}
