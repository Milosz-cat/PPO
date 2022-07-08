#include "GUI.h"

using namespace std;

int GUI(Person* person, Attendance_list* list) {
    
    
    Factory* f = nullptr;

    int size = 0;
    person = new Person[size];

    int n = 1;
    list = new Attendance_list[n];

    string name, surname, ID, sex, date_of_birth, date_a;

    while (true) {
        int choice_1;
        do {
            cout << " _________________________\n|----------MENU-----------|\n|                         |\n| 1.Add Person.           |\n| 2.Show Person list.     |\n| 3.Add Attendance list.  |\n| 4.Set attendance.       |\n| 5.Show Attendance list. |\n| 6.Exit.                 |\n|_________________________|\n\n     Choose option : ";
            cin >> choice_1; system("cls");

        } while ((choice_1 != 1) && (choice_1 != 2) && (choice_1 != 3) && (choice_1 != 4) && (choice_1 != 5) && (choice_1 != 6));

        if (choice_1 == 6)
            break;

        switch (choice_1) {
        case 1: {

            int choice;

            cout << "1.Poland\n2.Spain\n3.Portugal\n4.Canada\n\nChoose nationality: ";
            cin >> choice; system("cls");

            cout << "Enter name: ";   //wprowadzanie danych
            cin >> name; system("cls");
            cout << "Enter surname: ";
            cin >> surname; system("cls");

            if (choice != 1) {
                int sex_int;
                cout << "1.Male \n2.Female \n3.Other \n\nChoose sex: ";
                cin >> sex_int;
                switch (sex_int) {
                case 1:
                    sex = "Male"; break;
                case 2:
                    sex = "Female"; break;
                default:
                    sex = "Other"; break;
                }

                system("cls");
                do {
                    cout << "Enter date of birth (DD.MM.RRRR) : ";
                    cin >> date_of_birth;
                    if ((*person).check_date(date_of_birth, 2) == 1)
                        cout << "Incorrectly entered date !\n"; system("pause"); system("cls");

                } while ((*person).check_date(date_of_birth, 2) != 0);
                system("cls");
            }

            /////////////////////////

            if (choice == 1) {
                Pole pole;
                do {
                    cout << "Enter PESEL: ";
                    cin >> ID; system("cls");
                    if (pole.check_ID(ID) == 1) {
                        cout << "Incorrectly entered ID (number of dignits or format)!\n"; system("pause"); system("cls");
                    }
                    else if (pole.check_ID(ID) == 2) {
                        cout << "Incorrectly entered ID(control number)!\n"; system("pause"); system("cls");
                    }
                } while (pole.check_ID(ID) != 0);
            }


            if (choice == 2) {
                Spaniard spaniard;
                do {
                    cout << "Enter your DNI number (LLLLLLLLR, L-digit,R-letter) : ";
                    cin >> ID; system("cls");
                    if (spaniard.check_ID(ID) == 1) {
                        cout << "Incorrectly entered DNI (number of dignits or format)!\n";
                    }
                } while (spaniard.check_ID(ID) != 0);
            }
            if (choice == 3) {
                Portuguese portuguese;
                do {
                    cout << "Enter your CIN number (LLLLLLLL , L-liczba) : ";
                    cin >> ID; system("cls");
                    if (portuguese.check_ID(ID) == 1) {
                        cout << "Incorrectly entered CIN (number of dignits or format)!\n";
                    }
                } while (portuguese.check_ID(ID) != 0);

            }
            if (choice == 4) {
                Canadian canadian;
                do {
                    cout << "Enter your SIN number (LLLLLLLL , L-liczba) : (LLL-LLL-LLL , L-liczba) : ";
                    cin >> ID; system("cls");
                    if (canadian.check_ID(ID) == 1) {
                        cout << "Incorrectly entered SIN (lenght)!\n";
                    }
                    if (canadian.check_ID(ID) == 2) {
                        cout << "Incorrectly entered SIN (chars)!\n";
                    }
                    if (canadian.check_ID(ID) == 3) {
                        cout << "Incorrectly entered SIN (digits)!\n";
                    }
                } while (canadian.check_ID(ID) != 0);
            }

            person = person->Add(person, f->Add(name, surname, ID, sex, date_of_birth, choice), size); //zastepowanie wskaznika nowym wiekszym z dodana osoba przez wskaznik factory

            break; }
        case 2: {
            if (size == 0) {
                cout << "You must add least one person first!\n"; system("pause"); system("cls"); break;
            }
            for (int i = 0; i < size; i++) {
                cout << person[i].show_person();
                cout << "-------------------------------" << "\n";
            }
            system("pause"); system("cls");
            break; }
        case 3: {
            if (size == 0) {
                cout << "You must add at least one person first!\n"; system("pause"); system("cls"); break;
            }
            do {
                cout << "Enter today's date (DD.MM.RRRR) : \n";
                cin >> date_a;
                if (n != 1) {
                    for (int i = 0; i < n - 1; i++) {
                        if (list[i].get_date() == date_a) {
                            system("cls"); cout << "Entered date already exists!\n"; system("pause"); system("cls"); break;
                        }
                    }

                }
                if ((*person).check_date(date_a, 1) == 1) {
                    system("cls"); cout << "Incorrectly entered date !\n"; system("pause"); system("cls");
                }
            } while ((*person).check_date(date_a, 1) != 0);

            if (n != 1) {
                Attendance_list* temp = new Attendance_list[n + 1];
                for (int i = 0; i < size - 1; i++)
                    temp[i] = list[i];
                delete[] list;
                list = temp;
            }

            list[n - 1] = Attendance_list(size - 1, date_a); system("cls");
            n++;

            break; }

        case 4: {
            if (n < 2) {
                cout << "You must add at least one attendance list first!\n"; system("pause"); system("cls"); break;
            }
            int choice_11;
            for (int i = 0; i < n - 1; i++)
                cout << i + 1 << " : " << list[i].get_date() << "\n";
            cout << "Choose day : ";
            cin >> choice_11; system("cls");

            for (int i = 0; i < size; i++) {

                cout << "Is " << person[i].get_name() << " " << person[i].get_surname() << " present ?(Y/N)";
                if (_getch() == 'y')
                    list[choice_11 - 1].set_attendance(1, i);
                system("cls");
            }
            break; }
        case 5: {
            if (n < 2) {
                cout << "You must set attendance in at least one attendance list first!\n"; system("pause"); system("cls"); break;
            }
            int choice_2;
            for (int i = 0; i < n - 1; i++)
                cout << i + 1 << " : " << list[i].get_date() << "\n";
            cout << "Choose day : ";
            cin >> choice_2; system("cls");
            for (int i = 0; i < size; i++) {

                cout << person[i].show_person();

                if ((*list).Show_attendance(list, choice_2, i) == 1) {
                    cout << "Present : YES\n"; cout << "---------------------------------------------------\n";
                }
                else {
                    cout << "Present : NO\n";  cout << "---------------------------------------------------\n";
                }
            }
            system("pause"); system("cls");
            break; }
        default:
            break;
        }
    }
    delete[] person;
    delete[] list;

    return 0;
}