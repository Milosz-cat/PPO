#include "Polish.h"

void Pole::set_nationality() {
    nationality = "Polish";
};

int Pole::check_ID(string _ID) {
    int tab[11];

    if (_ID.size() != 11) {
        return 1;
    }

    for (int i = 0; i < 11; i++)
    {
        tab[i] = stoi(_ID.substr(i, 1));
    }
    /*for (int i = 0; i < 11; ++i)
    {
        cout<<"["<<tab[i]<<"]"<<" ";
    }
    cout<<"\n";*/
    int sum_number;
    sum_number = (tab[0] + (3 * tab[1]) + (7 * tab[2]) + (9 * tab[3]) + tab[4] + (3 * tab[5]) + (7 * tab[6]) + (9 * tab[7]) + tab[8] + (3 * tab[9]));
    //cout<<sum_number<<"\n";
    int ones_number;
    ones_number = sum_number % 10;
    //cout<<ones_number<<"\n";
    int control_number;
    if (ones_number == 0)
    {
        control_number = 0;
        //cout<<control_number<<"\n";
    }
    else
    {
        control_number = 10 - ones_number;
        //cout<<control_number<<"\n";
    }
    if (control_number != tab[10]) {
        return 2;
    }
    return 0;
};

void Pole::set_ID(string _ID) {

    ID = _ID;

    //set_sex(_ID);

    if (get_ID() == "unknown")
        set_sex("unknown");
    else{
    int tab[11];
    for (int i = 0; i < 11; i++)
    {
        tab[i] = stoi(_ID.substr(i, 1));
    }

    int temp;
    temp = tab[9];
    if ((temp % 2) == 1)
        set_sex("Male");
    else
        set_sex("Female");
    }
    //set_date_of_birth(_ID);
   
    if (get_ID() == "unknown")
        set_date_of_birth("unknown");
    else{
    int tab[11];
    for (int i = 0; i < 11; i++)
    {
        tab[i] = stoi(_ID.substr(i, 1));
    }
    string date;

    int y_i, m_i, d_i; 
    string y, m, d;

    y_i = (10 * tab[0]) + tab[1];
    m_i = (10 * tab[2]) + tab[3];
    if (m_i >= 0 && m_i <= 12)
    {
        y_i += 1900;
    }
    else if (m_i >= 21 && m_i <= 32)
    {
        y_i += 2000;
        m_i -= 20;
    }
    d_i = (10 * tab[4]) + tab[5];
    y = to_string(y_i);
    m = to_string(m_i);
    d = to_string(d_i);
    if (m_i < 10)
    {
        if (d_i < 10) {
            date = '0' + d + '.' + '0' + m + '.' + y;
            set_date_of_birth(date);
        }
        else {
            date = d + '.' + '0' + m + '.' + y;
            set_date_of_birth(date);
        }
    }
    else
    {
        if (d_i < 10) {
            date = '0' + d + '.' + m + '.' + y;
            set_date_of_birth(date);
        }
        else {
            date = d + '.' + m + '.' + y;
            set_date_of_birth(date);
        }
    }}
};

Pole::Pole() {

};

Pole::Pole(string _name = "unknown", string _surname = "unknown", string _ID = "unknown") {
    
    set_nationality();
    set_name(_name);
    set_surname(_surname);
    set_ID(_ID);
}
