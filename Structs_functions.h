//
// Created by andre on 26.04.2025.
//
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;
#ifndef STRUCTS_FUNCTIONS_H
#define STRUCTS_FUNCTIONS_H

struct books_nodes {
    string name;
    string author;
    int year;
    string publisher;
    int pages;
    books_nodes* next;

};

struct Head_node {
    int count=0;
    books_nodes* first=nullptr;
};

struct books_nodes_convert {
    char name[100];
    char author[100];
    int year;
    char publisher[100];
    int pages;
};

Head_node* creat_list();
void add_first_book(Head_node* head, const string& book,const string& author, int year,const string& publisher, int pages);
void add_end(Head_node* head, const string& book,const string& author, int year,const string& publisher, int pages);
void add_after(Head_node* head,int number, const string& book,const string& author, int year, const string& publisher, int pages);

void print_node(books_nodes* node_for_print);
void print_list(Head_node* head);

void search_name(Head_node* head, const string& target_name);
void search_author(Head_node* head, const string& target_author);
void search_year(Head_node* head, int target_year);


void delete_node(Head_node* head, int number);
void clear_all_list(Head_node* head);

void save_binfile(Head_node *head, const string &file_name);
void import_bin(Head_node* head, const string &file_name);
void add_books_from_binfile(Head_node* head, const string& file_name);

void sort_names(Head_node* head);
void sort_author(Head_node* head);
void sort_year(Head_node* head);


#endif //STRUCTS_FUNCTIONS_H
