
#include "llist.hpp"

int main() {
    LinkedList<int> list;

    int *x = new int;
    *x = 10;

    list.insert(x);
    
    return 0;
}