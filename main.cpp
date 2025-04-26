#include <windows.h>
#include "Structs_functions.h"

using namespace std;

int main() {
    SetConsoleOutputCP(65001);  // UTF-8
    SetConsoleCP(65001);    // UTF-8

    Head_node* head = creat_list();

    int choice=0;
    while (choice != 100) {
        cout << "Выберите действие:" << endl;
        cout << "1. Добавление элемента в начало" << endl;
        cout << "2. Добавление элемента в конец" << endl;
        cout << "3. Добавление после заданного элемента (по его номеру)" << endl;
        cout << "4. Удаление элемента (по номеру)" << endl;
        cout << "5. Вывести весь список" << endl;
        cout << "6. Найти по названию" << endl;
        cout << "7. Найти по автору" << endl;
        cout << "8. Найти по году издания" << endl;
        cout << "9. Очистить список" << endl;
        cout << "10. Сохранить список в бинарный файл" << endl;
        cout << "11. Импортировать целый список из бинарного файла (Старый список удаляется)" << endl;
        cout << "12. Импортировать дополнительные книги из файла (Новые книги добавляются к старым)" << endl;
        cout << "100. Выйти из программы и удаление списка" << endl;

        cin >> choice;

        switch (choice) {
            case 1: {
                string name, author, publisher;
                int year, pages;
                cout << "|Название << Автор << Year << Publisher << Pages|\n";
                cin >> name >> author >> year >> publisher >> pages;
                add_first_book(head, name, author, year, publisher, pages);
                break;
            }
            case 2: {
                string name, author, publisher;
                int year, pages;
                cout << "|Название << Автор << Year << Publisher << Pages|\n";
                cin >> name >> author >> year >> publisher >> pages;
                add_end(head, name, author, year, publisher, pages);
                break;
            }
            case 3: {
                string name, author, publisher;
                int year, pages, number;
                cout << "|Название << Автор << Year << Publisher << Pages|\n";
                cin >> name >> author >> year >> publisher >> pages;
                cout << "Добавление после элемента под номером: ";
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
                break;
            }
            case 6: {
                string name;
                cout << "Введите название искомой книги: ";
                cin >> name;
                search_name(head, name);
                break;
            }
            case 7: {
                string author;
                cout << "Введите имя автора книги: ";
                cin >> author;
                search_author(head, author);
                break;
            }
            case 8: {
                int year;
                cout << "Введите год написания книги: ";
                cin >> year;
                search_year(head, year);
                break;
            }
            case 9: {
                clear_all_list(head);
                break;
            }
            case 10: {
                string file_name;
                cout << "Введите название файла: ";
                cin >> file_name;
                save_binfile(head, file_name);
                break;
            }
            case 11: {
                string file_name;
                cout << "Введите название файла со списком для импорта: ";
                cin >> file_name;
                Head_node* new_head = import_bin(file_name);
                if (new_head) {
                    clear_all_list(head);
                    head = new_head;
                }
                break;
            }
            case 12: {
                string file_name;
                cout << "Введите название файла со списком для импорта: ";
                cin >> file_name;
                add_from_bin(head, file_name);
                break;
            }
            case 100: {
                cout << "Выход из программы.\n";
                clear_all_list(head);
                delete head;
                break;
            }
        }
    }
    return 0;
}