#include <windows.h>
#include "Structs_functions.h"

using namespace std;

int main() {
    SetConsoleOutputCP(65001);  // UTF-8
    SetConsoleCP(65001);    // UTF-8

    Head_node* head = creat_list();
    add_end(head, "RED DEAD REDEMPTION", "Akimov", 2025, "AFK", 31);
    add_end(head, "agsaaac", "Andrey", 2015, "School", 3);
    add_end(head, "POKERclub", "Andrey", 2010, "LOgotip102", 51);
    add_after(head, 2,"пробник по русскому", "Andrey", 2010, "AKMF", 51);
    print_list(head);

    delete_node(head, 2);
    print_list(head);

    return 0;
}