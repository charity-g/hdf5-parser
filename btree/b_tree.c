#include <stdlib.h>
#include <stdio.h>
#include "stb_ds.h"

/** 
* B-tree is a self-balancing tree data structure that maintains sorted data 
*  allows searches, sequential access, insertions, and deletions in logarithmic time
* 
* B-tree input = m-ary tree
    - Every node has at most m children.
    - Every node, except for the root and the leaves, has at least ⌈m/2⌉ children.
    - The root node has at least two children unless it is a leaf.
    - All leaves appear on the same level.
    - A non-leaf node with k children contains k−1 keys.
*/

//DECLARATIONS


// note: because m is not stored, this node is nonsense when not tied to btree object
typedef struct BTreeNode {
    short int is_leaf;
    short int capacity;
    int keys[4];

    union {
        int *values[5];              // for leaf
        struct BTreeNode *children[5]; // for internal nodes
    };
} BTreeNode;

typedef struct {
    BTreeNode * root;
    short int m;
    int height;
} BTree;


BTree * create_btree() {
    BTree * btree = (BTree *) malloc(sizeof(BTree));
    BTreeNode * root = (BTreeNode *) malloc(sizeof(BTreeNode));
    root->is_leaf = 1;
    root->capacity = 0;
    btree->root = root;
    btree->m = 5;
    btree->height = 0;
}


void destruct_btree(BTree * btree){
     //TODO free all nodes inside recursively via bfs and queue
    free(btree->root->values);
    free(btree->root);
    free(btree);
}

int search(BTree * btree, int key) {
    BTreeNode **queue = NULL;
    arrput(queue, btree->root);
    while (arrlen(queue) > 0) {
        BTreeNode * curr = ;
    
    }
    arrfree(queue);
    return nothing found/?
}

int insert(BTree * btree, int key, int value) {
    // TODO
}

int delete(BTree * btree, int key) {
    // TODO
}

void print_btree(BTree * btree) {
    printf("Root: %p, m: %i, height: %i", btree->root, btree->m, btree->height);
}



// ==================================================================================================================
// PRIVATE functions


// int search(BTreeNode * root, int key) {
//     // TODO
// }

// int insert(BTreeNode * root, int key, int value) {
//     // TODO
// }

// int delete(BTreeNode * root, int key) {
//     // TODO
// }

// ==================================================================================================================
// ITERATION

typedef struct {
    // BTreeNode * root; // needed?
    BTreeNode * curr;
} BTreeIterator;


BTreeIterator * create_iterator(BTree * btree) {
    // TODO
}

// returns leaf nodes?? or leaf values?? TODO
// int or null get_iterator_next(BTreeIterator * iter) {
//     // TODO
// }




