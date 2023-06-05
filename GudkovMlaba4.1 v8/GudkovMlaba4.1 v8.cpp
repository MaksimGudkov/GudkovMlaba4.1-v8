#include <iostream>
#include <clocale>
#include <sstream>
#include <string>
#include <fstream>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <list>
#include <cmath>


using namespace std;

struct Film {

    string name;
    string rejiser;
    string strana;

    int year;
    int stoimost;
    int sbori;
};


queue <Film> Films;


int menu() {
    system("chcp 1251"); // настраиваем кодировку консоли

    cout << "\n Выберите действие: \n";
    cout << "1. Добавить новый фильм; \n";
    cout << "2. Удалить первый в списке фильм; \n";
    cout << "3. Просмотреть все фильмы; \n";
    cout << "4. Редактирование данных первого фильма; \n";
    cout << "5. Выход. \n";

    int a; //ввести в a
    cin >> a;
    return a; // для работы меню все эти 3 строки(типа чел ввёл какую-то цифру)

}

int main() {


    Film f1 = { "Мстители","Джо Руссо","США",2012,220000000,1518812988 };
    Films.push(f1);
    Film f2 = { "Бойцовский клуб","Дэвид Финчер","США",1999,63000000,100853753 };
    Films.push(f2);
    Film f3 = { "Муха","Дэвид Кроненберг","США",1986,15000000,60629159 };
    Films.push(f3);


    int a = menu(); //вывели меню
    system("chcp 1251"); // настраиваем кодировку консоли

    while (a != 5) {

        if (a == 1) {
            Film NewFilm;
            cout << "\n Выбран режим добавления нового фильма" << endl;
            cout << "Введите название фильма: ";
            cin.ignore();
            getline(cin, NewFilm.name);
            cout << "Введите Режиссера фильма: ";
            getline(cin, NewFilm.rejiser);
            cout << "Введите Страну производства: ";
            getline(cin, NewFilm.strana);
            cout << "Введите год производства: ";
            cin >> NewFilm.year;
            cout << "Введите стоимость производства: ";
            cin >> NewFilm.stoimost;
            cout << "Введите Кассовые сборы: ";
            cin >> NewFilm.sbori;
            Films.push(NewFilm);
            cout << "Фильм успешно добавлен" << endl;

        }

        if (a == 2) {
            Films.pop();
        }

        if (a == 3) {
            int i = 1;

            while (!Films.empty()) {
                Film f = Films.front();
                Films.pop();

                cout << "Номер фильма: " << to_string(i++) << endl;
                cout << "Название фильма: " << f.name << endl;
                cout << "Режисcер: " << f.rejiser << endl;
                cout << "Страна: " << f.strana << endl;
                cout << "Год: " << f.year << endl;
                cout << "Стоимость производства: " << f.stoimost << endl;
                cout << "Кассовые сборы: " << f.sbori << endl << endl;

            }




        }

        if (a == 4) {
            int x;
            Film f = Films.front();
            Films.pop();
            cout << "Какой элемент вы бы хотели редактировать." << endl << "1.Название" << endl << "2.Режиссер" << endl << "3.Страна" << endl << "4.Год" << endl << "5.Стоимость производства" << endl << "6.Кассовые сборы" << endl << "Введите число, параметр которого вы хотите изменить: ";

            cin >> x;

            switch (x) {
            case 1:
                cout << "Введите новое значение: ";
                cin.ignore();
                getline(cin, f.name);
                break;
            case 2:
                cout << "Введите новое значение: ";
                cin.ignore();
                getline(cin, f.rejiser);
                break;
            case 3:
                cout << "Введите новое значение: ";
                cin.ignore();
                getline(cin, f.strana);
                break;
            case 4:
                cout << "Введите новое значение: ";
                cin.ignore();
                cin >> f.year;
                break;
            case 5:
                cout << "Введите новое значение: ";
                cin >> f.stoimost;
                break;
            case 6:
                cout << "Введите новое значение: ";
                cin >> f.sbori;
                break;
            }
            Films.push(f);
        }

        if (a == 5) {
            break;
        }

        a = menu();
    }
}

