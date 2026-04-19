
#include <stdlib.h>

int main(int argc, char *argv[])
{
    
    BTree *  btree = create_btree();
    free(btree);
    return EXIT_SUCCESS;
}