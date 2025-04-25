#include <windows.h>
#include "Structs_functions.h"

using namespace std;

int main() {
    SetConsoleOutputCP(65001);  // UTF-8
    SetConsoleCP(65001);    // UTF-8

    Head_node* head = creat_list();
    add_end(head, "RED DEAD REDEMPTION", "", 2025, "", 31);
    add_end(head, "agsaaac", "", 2015, "", 3);
    add_end(head, "POKERclub", "Andrey", 2010, "", 51);
    add_after(head, 2,"пробник по русскому", "Andrey", 2010, "", 51);
    print_list(head);
    return 0;
}