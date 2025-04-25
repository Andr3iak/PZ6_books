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
        // new_node->next = after_node->next;
        after_node->next = new_node;
        head->count++;
    }
}

void print_list(Head_node* head) {
    books_nodes* temp = head->first;
    while (temp != nullptr) {
        cout << temp->name <<"; "<<temp->author <<"; "<<temp->year <<"; "<<temp->publisher <<"; "<<temp->pages << endl;
        temp = temp->next;
    }
}