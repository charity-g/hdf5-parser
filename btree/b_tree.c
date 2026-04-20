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
    short int capacity; //describes # of values, will always have more than one except in root
    union {
        int leaf_keys[5]; //for leaf
        int keys[4];      //for internal 
    };
    union {
        int *values[5];                // for leaf
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
    BTreeNode ** stack = NULL; //TODO change to efficient queue 
    arrput(stack, btree->root);
    free(btree->root->values);
    arrfree(stack);
    free(btree->root);
    free(btree);
}

BTreeNode * get_closest_leaf(BTree * btree, int key) {
    BTreeNode *curr = btree->root;
    while (curr && !curr->is_leaf) {
        if (curr->capacity <= 0) { return NULL; }; 
        for (int i = 0; i < (curr->capacity - 1); ++i) {
            if (key < curr->keys[i]) {
                curr = curr->children[i];
                break;
            }
        }
        if (key > curr->keys[(curr->capacity - 1)]) {
            curr = curr->children[(curr->capacity)];
        }
    }
    return curr; // guaranteed curr->is_leaf since init starts as true
}

int * search_helper(BTree * btree, int key, BTreeNode * leaf) {
    if (leaf == NULL) {
        leaf = get_closest_leaf(btree, key);
    }
    for (int i = 0; i < (leaf->capacity); ++i) {
        if (leaf->leaf_keys[i] == key) {
            return leaf->values[i];
        }
    } 
    return NULL;
}

int * search(BTree * btree, int key) {
    return search_helper(btree, key, NULL);
}

int insert(BTree * btree, int key, int value) {
    BTreeNode * leaf = get_closest_leaf(btree, key);
    int * target = search_helper(btree, key, leaf);
    if (target != NULL) {
        *target = value; 
        return;
    }

    //use leaf
    if (leaf->capacity >= btree->m) {
        // SPLIT TODO  
    } else {
        leaf->capacity++;
        //TODO
        // add to keys, add to values at end
        // sort values by keys
        // sort keys
        //isn't O(n) just better for insert and move since m just inserting one
        // TRUE could just iterate and shift right
    }

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




