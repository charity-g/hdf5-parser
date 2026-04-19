#include <stdlib.h>
#include "b_tree.h"


void initialization() {
    BTree *  btree = create_btree();
    print_btree(btree);


    free(btree);
}

int main(int argc, char *argv[])
{
    
    initialization();
    return EXIT_SUCCESS;
}