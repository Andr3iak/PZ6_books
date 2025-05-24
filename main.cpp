#include <windows.h>
#include "Structs_functions.h"

using namespace std;

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    Head_node* head = creat_list();

    int choice=0;
    while (choice != 100) {
        cout << "\nВыберите действие:" << endl;
        cout << "1. Добавление элемента в начало" << endl;
        cout << "2. Добавление элемента в конец" << endl;
        cout << "3. Добавление после заданного элемента (по его номеру)" << endl;
        cout << "4. Удаление элемента (по номеру)" << endl;
        cout << "5. Вывести весь список" << endl;
        cout << "6. Вывести количество элементов"<< endl;
        cout << "7. Найти по названию" << endl;
        cout << "8. Найти по автору" << endl;
        cout << "9. Найти по году издания" << endl;
        cout << "10. Очистить список" << endl;
        cout << "11. Сохранить список в бинарный файл" << endl;
        cout << "12. Импортировать целый список из бинарного файла (Старый список удаляется)" << endl;
        cout << "13. Импортировать дополнительные книги из файла (Новые книги добавляются к старым)" << endl;
        cout << "14. Отсортировать список по названиям"<< endl;
        cout << "15. Отсортировать список по авторам"<< endl;
        cout << "16. Отсортировать список по годам"<< endl;
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
                cout << head->count<<endl;
            }
            case 7: {
                string name;
                cout << "Введите название искомой книги: ";
                cin >> name;
                search_name(head, name);
                break;
            }
            case 8: {
                string author;
                cout << "Введите имя автора книги: ";
                cin >> author;
                search_author(head, author);
                break;
            }
            case 9: {
                int year;
                cout << "Введите год написания книги: ";
                cin >> year;
                search_year(head, year);
                break;
            }
            case 10: {
                clear_all_list(head);
                cout << "Список очищен."<< endl;
                break;
            }
            case 11: {
                string file_name;
                cout << "Введите название файла: ";
                cin >> file_name;
                save_binfile(head, file_name);
                cout << "Сохранено" << endl;
                break;
            }
            case 12: {
                string file_name;
                cout << "Введите название файла со списком для импорта: ";
                cin >> file_name;
                import_bin(head,file_name);
                cout << "Список импортирован" << endl;
                break;
            }
            case 13: {
                string file_name;
                cout << "Введите название файла со списком для импорта: ";
                cin >> file_name;
                add_books_from_binfile(head, file_name);
                cout << "Книги импортированы" << endl;
                break;
            }
            case 14: {
                sort_names(head);
                cout << "Список отсортирован по именам."<< endl;
                break;
            }
            case 15: {
                sort_author(head);
                break;
            }
            case 16: {
                sort_year(head);
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