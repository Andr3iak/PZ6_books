#include "Structs_functions.h"

using namespace std;

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
    cout << node_for_print->name <<"; "<<node_for_print->author <<"; "<<node_for_print->year <<"; "<<node_for_print->publisher <<"; "<<node_for_print->pages <<"."<< endl;
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
    cout << "Ваш список успешно очищен" << endl;
}

void save_binfile(Head_node* head, const string& file_name) {
    if (head -> first ==nullptr || head->count ==0) {
        cout << "Ваш список пуст, сохранять нечего. \n";
        return;
    }
    ofstream outfile(file_name, ios::binary);
    if (!outfile) {
        cout<<"Ошибка открытия фойла\n";
        return;
    }
    outfile.write(reinterpret_cast<const char*>(&head->count), sizeof(int));

    books_nodes* temp = head->first;
    while (temp!=nullptr) {
        save_string(outfile, temp->name);
        save_string(outfile, temp->author);
        outfile.write(reinterpret_cast<const char*> (&temp->year), sizeof(int));
        save_string(outfile, temp->publisher);
        outfile.write(reinterpret_cast<const char*>(&temp->pages), sizeof(int));
        temp = temp->next;
    }
    outfile.close();
    cout << "Список успешно сохранен в файл '" <<file_name <<"' \n";
}

void save_string(ofstream& outfile, const string& str) {
    size_t length  = str.size();
    outfile.write(reinterpret_cast<const char*>(&length), sizeof(size_t));
    outfile.write(str.c_str(), length);
}

Head_node* import_bin(const string& file_name) {
    ifstream infile(file_name, ios::binary);
    if (!infile) {
        cerr << "Ошибка открытия файла для чтения!\n";
        return nullptr;
    }
    Head_node* head = creat_list();

    int count = 0;
    infile.read(reinterpret_cast<char*>(&count), sizeof(int));

    for (int i =0; i<count; i++) {
        string name = import_string(infile);
        string author = import_string(infile);
        int year, pages;
        infile.read(reinterpret_cast<char*>(&year), sizeof(int));
        string publisher = import_string(infile);
        infile.read(reinterpret_cast<char*>(&pages), sizeof(int));
        add_end(head, name, author, year, publisher, pages);
    }
    head->count = count;
    cout << "Успешно импортировано " << count << " книг из файла '" << file_name <<"' \n";
    return head;
}

string import_string(ifstream& file_name) {
    size_t length;
    file_name.read(reinterpret_cast<char*> (&length), sizeof(size_t));

    string str;
    str.resize(length);
    file_name.read(&str[0], length);

    return str;
}