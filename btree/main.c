#include <stdlib.h>
#include "b_tree.h"


void initialization() {
    BTree *  btree = create_btree();
    print_btree(btree);


    destruct_btree(btree);
}


void test_insert() {
}

void test_insert_many() {
}

void test_search() {
}

void test_delete() {
}

void test_delete_many() {
}

int main(int argc, char *argv[])
{
    initialization();
    test_insert();
    test_insert_many();
    test_search();
    test_delete();
    test_delete_many();
    return EXIT_SUCCESS;
}