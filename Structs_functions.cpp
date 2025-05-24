#include "Structs_functions.h"

// using namespace std;

Head_node* creat_list() {
    Head_node* head = new Head_node;
    head -> first = nullptr;
    head -> count = 0;
    return head;
}

void add_first_book(Head_node* head, const string& name,const string& author, int year,const string& publisher, int pages) {
    books_nodes* new_node = new books_nodes{name, author, year, publisher, pages};
    new_node->next = head->first;
    head->first = new_node;
    head->count++;
}

void add_end(Head_node* head, const string& name,const string& author, int year,const string& publisher, int pages) {
    books_nodes* new_node = new books_nodes{name, author, year, publisher, pages};
    new_node->next = nullptr;

    if (head->first == nullptr) {
        head->first = new_node;
    }
    else {
        books_nodes* temp = head->first;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    head->count++;
}

void add_after(Head_node* head,int number, const string& name,const string& author, int year, const string& publisher, int pages) {
    if (number > head->count || number < 1) {
        cout<< "Элемент, после которого осуществляется вставка, не определен. Либо номер некорректный. "<< endl;
    }
    else {
        books_nodes* after_node = head->first;
        for (int i = 1; i < number; i++) {
            after_node= after_node->next;
        }
        books_nodes* new_node = new books_nodes{name, author, year, publisher, pages, after_node->next};
        after_node->next = new_node;
        head->count++;
    }
}

void print_node(books_nodes* node_for_print) {
    cout << node_for_print->name <<"; "<<node_for_print->author <<"; "<<node_for_print->year <<"; "<<node_for_print->publisher <<"; "<<node_for_print->pages <<".\n"<< endl;
}

void print_list(Head_node* head) {
    books_nodes* temp = head->first;
    int n = 1;
    while (temp != nullptr) {
        cout << n << ". " <<temp->name <<"; "<<temp->author <<"; "<<temp->year <<"; "<<temp->publisher <<"; "<<temp->pages <<"."<< endl;
        temp = temp->next;
        n++;
    }
    cout<<endl;
}

void delete_node(Head_node* head, int number) {
    if (head -> count == 0) {
        cout<< "Ваш список еще пуст. Удалять пока нечего)\n "<< endl;
        return;
    }
    if (number > head->count || number < 1) {
        cout << "Ошибка: в списке всего " << head->count << " элементов, а введен: " << number << "\n" << endl;
        return;
    }
    books_nodes* to_delete = nullptr;
    if (number == 1)  {
        to_delete = head->first;
        head->first = to_delete->next;
    }
    else {
        books_nodes* temp= head->first;
        for (int i = 1; i<number-1; i++) {
            temp = temp->next;
        }
        to_delete= temp->next;
        temp->next = to_delete->next;
    }
    cout<<"Элемент под номером: "<<number<< " (" << to_delete->name <<") "<< "успешно удален\n"<< endl;
    delete to_delete;
    head->count--;
}


void search_name(Head_node* head, const string& target_name) {
    if (head->count == 0) {
        cout << "Ваш список пуст. \n\n";
        return;
    }
    books_nodes* temp = head->first;
    int n = 1;
    bool found = false;
    while (temp!=nullptr) {
        if (temp -> name == target_name) {
            cout << n <<". ";
            print_node(temp);
            found = true;
        }
        n++;
        temp = temp->next;
    }
    if (!found) {
        cout << "Совпадений не найдено. \n\n";
    }
}

void search_author(Head_node* head, const string& target_author) {
    if (head->count == 0) {
        cout << "Ваш список пуст. \n\n";
        return;
    }
    books_nodes* temp = head->first;
    int n = 1;
    bool found = false;
    while (temp!=nullptr) {
        if (temp -> author == target_author) {
            cout << n <<". ";
            print_node(temp);
            found = true;
        }
        n++;
        temp = temp->next;
    }
    if (!found) {
        cout << "Совпадений не найдено. \n\n";
    }
}

void search_year(Head_node* head, int target_year) {
    if (head->count == 0) {
        cout << "Ваш список пуст. \n\n";
        return;
    }
    books_nodes* temp = head->first;
    int n = 1;
    bool found = false;
    while (temp!=nullptr) {
        if (temp -> year == target_year) {
            cout << n <<". ";
            print_node(temp);
            found = true;
        }
        n++;
        temp = temp->next;
    }
    if (!found) {
        cout << "Совпадений не найдено. \n\n";
    }
}

void clear_all_list(Head_node* head) {
    books_nodes* temp = head->first;
    while (temp!=nullptr) {
        books_nodes* temp2 = temp->next;
        delete temp;
        temp = temp2;
    }
    head->first = nullptr;
    head->count = 0;
    // cout << "Ваш список успешно очищен" << endl;
}

books_nodes_convert convert_in_new_struct(books_nodes * old_node) {
    books_nodes_convert convert_node {};

    strncpy(convert_node.name, old_node->name.c_str(), sizeof(convert_node.name)-1);
    strncpy(convert_node.author, old_node->author.c_str(), sizeof(convert_node.author)-1);
    strncpy(convert_node.publisher, old_node->publisher.c_str(), sizeof(convert_node.publisher) - 1);

    convert_node.year = old_node->year;
    convert_node.pages = old_node->pages;

    return convert_node;
}

void save_binfile(Head_node *head, const string &file_name) {
    if (head->first == nullptr || head->count == 0) {
        cout << "Ваш список пуст" << endl;
        return;
    }
    ofstream outfile(file_name, ios::binary);

    if (!outfile) {
        cout << "Ошибка открытия файла для сохранения."<< endl;
    }

    outfile.write(reinterpret_cast<const char*>(&head->count), sizeof(int));

    books_nodes* temp = head->first;

    while (temp!=nullptr) {
        books_nodes_convert convert_node = convert_in_new_struct(temp);
        outfile.write(reinterpret_cast<const char*>(&convert_node), sizeof(convert_node));
        temp = temp->next;
    }
    outfile.close();
}

books_nodes* return_convert(books_nodes_convert convert_node) {
    books_nodes* default_node = new books_nodes();

    default_node->name = convert_node.name;
    default_node->year = convert_node.year;
    default_node->author = convert_node.author;
    default_node->pages = convert_node.pages;
    default_node->publisher = convert_node.publisher;
    default_node->next = nullptr;

    return default_node;
}

void import_bin(Head_node* head, const string &file_name) {
    ifstream infile(file_name, ios::binary);
    if (!infile) {
        cout << "Ошибка открытия файла для чтения\n";
        return;
    }
    int count;
    infile.read(reinterpret_cast<char*>(&count), sizeof(int));

    clear_all_list(head);

    head->count = 0;
    head->first = nullptr;

    books_nodes* last = nullptr;
    for (int i = 0; i < count; ++i) {
            books_nodes_convert convert_node;
            infile.read(reinterpret_cast<char*>(&convert_node), sizeof(convert_node));
            books_nodes * node = return_convert(convert_node);
            if (head->first == nullptr) {
                head->first = node;
            } else {
                last->next = node;
            }
            last = node;
            head->count++;
        }
    }

void add_books_from_binfile(Head_node* head, const string& file_name) {
        ifstream infile(file_name, ios::binary);
        if (!infile) {
            cout << "Ошибка открытия файла для импорта\n";
            return;
        }

        int new_count = 0;
        infile.read(reinterpret_cast<char*>(&new_count), sizeof(int));
        if (new_count <= 0) {
            cout << "Файл не содержит книг для импорта.\n";
            return;
        }

        books_nodes* last = head->first;
        if (last != nullptr) {
            while (last->next != nullptr) {
                last = last->next;
            }
        }
        bool found = false;
        for (int i = 0; i < new_count; ++i) {
            books_nodes_convert convert_node;
            infile.read(reinterpret_cast<char*>(&convert_node), sizeof(convert_node));

            books_nodes* new_node = return_convert(convert_node);
            books_nodes* temp = head->first;

            while (temp != nullptr) {
                if (temp->name == new_node->name || temp->author == new_node->author || temp->publisher == new_node->publisher || temp->year == new_node->year || temp->pages == new_node->pages) {
                    found = true;
                    break;
                }
                temp = temp->next;
            }
            if (!found) {
                if (head->first == nullptr) {
                    head->first = new_node;
                    last = new_node;
                } else {
                    last->next = new_node;
                    last = new_node;
                }
                head->count++;
                }
            else {
                delete new_node;
            }
        }
        infile.close();
        cout << "Импортировано " << new_count << " книг из файла '" << file_name << "'\n";
}

void sort_names(Head_node* head) {
    if (head->first == nullptr || head->first->next == nullptr) {
        return;
    }

    bool swapped;
    books_nodes* a;
    books_nodes* b = nullptr;

    do {
        swapped = false;
        a = head->first;

        while (a->next != b) {
            if (a->name > a->next->name) {

                string temp_name = a->name;
                a->name = a->next->name;
                a->next->name = temp_name;

                string temp_author = a->author;
                a->author = a->next->author;
                a->next->author = temp_author;

                string temp_publisher = a->publisher;
                a->publisher = a->next->publisher;
                a->next->publisher = temp_publisher;

                int temp_year = a->year;
                a->year = a->next->year;
                a->next->year = temp_year;

                int temp_pages = a->pages;
                a->pages = a->next->pages;
                a->next->pages = temp_pages;

                swapped = true;
            }
            a = a->next;
        }
        b = a;
    } while (swapped);
}

void sort_author(Head_node* head) {
    if (head->first == nullptr || head->first->next == nullptr) {
        return;
    }

    bool swapped;
    books_nodes* a;
    books_nodes* b = nullptr;

    do {
        swapped = false;
        a = head->first;

        while (a->next != b) {
            if (a->author > a->next->author) {

                string temp_name = a->name;
                a->name = a->next->name;
                a->next->name = temp_name;

                string temp_author = a->author;
                a->author = a->next->author;
                a->next->author = temp_author;

                string temp_publisher = a->publisher;
                a->publisher = a->next->publisher;
                a->next->publisher = temp_publisher;

                int temp_year = a->year;
                a->year = a->next->year;
                a->next->year = temp_year;

                int temp_pages = a->pages;
                a->pages = a->next->pages;
                a->next->pages = temp_pages;

                swapped = true;
            }
            a = a->next;
        }
        b = a;
    } while (swapped);
}

void sort_year(Head_node* head) {
    if (head->first == nullptr || head->first->next == nullptr) {
        return;
    }

    bool swapped;
    books_nodes* a;
    books_nodes* b = nullptr;

    do {
        swapped = false;
        a = head->first;

        while (a->next != b) {
            if (a->year > a->next->year) {

                string temp_name = a->name;
                a->name = a->next->name;
                a->next->name = temp_name;

                string temp_author = a->author;
                a->author = a->next->author;
                a->next->author = temp_author;

                string temp_publisher = a->publisher;
                a->publisher = a->next->publisher;
                a->next->publisher = temp_publisher;

                int temp_year = a->year;
                a->year = a->next->year;
                a->next->year = temp_year;

                int temp_pages = a->pages;
                a->pages = a->next->pages;
                a->next->pages = temp_pages;

                swapped = true;
            }
            a = a->next;
        }
        b = a;
    } while (swapped);
}