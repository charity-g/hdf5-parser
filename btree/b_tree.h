#include "b_tree.c"

BTree * create_btree();

int search(BTree * btree, int key);

int insert(BTree * btree, int key, int value);

int delete(BTree * btree, int key);

void print_btree(BTree * btree);

void destruct_btree(BTree * btree);