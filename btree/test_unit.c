#include <stdlib.h>
#include <stdio.h>
// #include "b_tree.c"


int get_min_node_capacity(int m) {
    return m % 2 == 0 ? m / 2 : (m / 2) + 1;
}

int test_get_min_node_capacity() {
    int errors = 0;

    int res1 = get_min_node_capacity(8);
    int exp1 = 4;
    if (res1 != exp1) printf("test_get_min_node_capacity failed: res1. expected: %d actual: %d", exp1, res1);
    

    int res2 = get_min_node_capacity(7);
    int exp2 = 4;
    if (res2 != exp2) printf("test_get_min_node_capacity failed: res2. expected: %d actual: %d", exp2, res2);

    if (errors > 0) return 1;
    return 0;
}


int main(int argc, char *argv[])
{
    int errors = 0;
    errors += test_get_min_node_capacity();
    
    if (errors > 0) {
        printf("failed");
    }
    return EXIT_SUCCESS;
}