#include <windows.h>
#include "Structs_functions.h"

using namespace std;

int main() {
    SetConsoleOutputCP(65001);  // UTF-8
    SetConsoleCP(65001);    // UTF-8

    Head_node* head = creat_list();
    // add_end(head, "RED DEAD REDEMPTION", "Akimov", 2025, "AFK", 31);
    // add_end(head, "agsaaac", "Andrey", 2015, "School", 3);
    // add_end(head, "POKERclub", "Andrey", 2010, "LOgotip102", 51);
    // add_after(head, 2,"пробник по русскому", "Andrey", 2010, "AKMF", 51);
    // print_list(head);
    //
    // delete_node(head, 2);
    // print_list(head);

    int choice=0;
    while (choice != 10) {
        cout << "Выберите действие:\n1. Добавление элемента в начало\n2. Добавление элемента в конец\n3. Добавление после заданного элемента (по его номеру)\n4. Удаление элемента (по номеру)\n5. Вывести весь список\n6. Найти по названию\n7. Найти по автору\n8. Найти по году издания.\n100. Выйти из программы\n" << endl;

        cin >> choice;

        switch (choice) {
            case 1: {
                string name, author, publisher;
                int year, pages;
                cout << "Введите название: ";
                cin >> name;
                cout << "Введите Автора: ";
                cin >> author;
                cout << "Введите год издания: ";
                cin >> year;
                cout << "Введите издание: ";
                cin >> publisher;
                cout << "Введите количесвто страниц: ";
                cin >> pages;
                add_first_book(head, name, author, year, publisher, pages);
                break;
            }
            case 2: {
                string name, author, publisher;
                int year, pages;
                cout << "Введите название: ";
                getline(cin, name);
                cout << "Введите Автора: ";
                cin >> author;
                cout << "Введите год издания: ";
                cin >> year;
                cout << "Введите издание: ";
                cin >> publisher;
                cout << "Введите количесвто страниц: ";
                cin >> pages;
                add_end(head, name, author, year, publisher, pages);
                break;
            }
            case 3: {
                string name, author, publisher;
                int year, pages, number;
                cout << "Введите название: ";
                cin >> name;
                cout << "Введите Автора: ";
                cin >> author;
                cout << "Введите год издания: ";
                cin >> year;
                cout << "Введите издание: ";
                cin >> publisher;
                cout << "Введите количесвто страниц: ";
                cin >> pages;
                cout << "Добавление после элемнта под номером: ";
                cin >> number;
                add_after(head, number, name, author, year, publisher, pages);
                break;
            }
            case 4: {
                int number;
                cout << "Введите номер элемента для удаления: ";
                cin >> number;
                delete_node(head, number);
                break;
            }
            case 5: {
                print_list(head);
            }
        }

    }
    // int a;
    // cout << "Введите : ";

    return 0;
}