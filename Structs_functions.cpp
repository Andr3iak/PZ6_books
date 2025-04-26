#include "Structs_functions.h"
#include <iostream>

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

