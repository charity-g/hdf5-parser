#include <stdlib.h>
#include "b_tree.h"


void initialization() {
    BTree *  btree = create_btree();
    print_btree(btree);


    destruct_btree(btree);
}


void test_insert() {
    // 1, 6, 9 insert 0
    // 1 6  9 insert 1
    // 1 6  9 insert 2
    // 1 6  9 insert 5
    // 1 6  9 insert 6
    // 1 6  9 insert 7
    // 1 6  9 insert 8
    // 1 6  9 insert 9
    // 1 6  9 insert 10
}

void test_insert_split() {
    
}

void test_search() {
}

void test_delete() {
}

void test_delete_merge() {
}

void test_complex() {

}

int main(int argc, char *argv[])
{
    initialization();
    
    test_insert();
    test_insert_split();
    
    test_search();

    test_delete();
    test_delete_merge();

    test_complex();
    
    return EXIT_SUCCESS;
}