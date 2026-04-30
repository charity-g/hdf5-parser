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

Internal Node Invariant
    - given a key in internal node
        - all keys in left child are larger than key
        - all keys in right child are >= than key

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
        if (curr->capacity <= 0) { return NULL; }
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


int * find_value_by_key(BTreeNode * leaf, int key) {
    for (int i = 0; i < (leaf->capacity); ++i) {
        if (leaf->leaf_keys[i] == key) {
            return leaf->values[i];
        }
    } 
    return NULL;
}

int * search(BTree * btree, int key) {
    BTreeNode * leaf = get_closest_leaf(btree, key);
    return find_value_by_key(leaf, key);
}

void insert(BTree * btree, int key, int value) {
    // return the int * to value
    BTreeNode * right = insert_recursive(btree, btree->root, key, value);
    if (right != NULL) {
        // TODO  we need to reassign root push up!
    }
}

/*
** Returns NULL if there was no split in the child.
*  Returns right pointer if there was a split. The left was modified.
*/
// TODO check for balanced?? it auto balances in insert since we always split top.
BTreeNode * insert_recursive(BTree * btree, BTreeNode * curr, int key, int value) {
    if (curr->is_leaf) {
        int * key_exists = find_value_by_key(curr, key);
        if (key_exists != NULL) {
            *key_exists = value; 
            return NULL;
        }
        
        if (curr->capacity >= btree->m) { //split
            add_key_value_to_leaf_split(curr, key, value, btree->m);
        } else {
            add_key_value_to_leaf(curr, key, value);   
            return NULL;
        }

    } else {
        // we are a parent, need to propogate result downstream, then pick it back upstream
        //find ideal road to go down to:
        BTreeNode * child = NULL; // TODO find target child
        BTreeNode * right = insert_recursive(btree, child, key, value);
        if (right == NULL) {
            return NULL;
        }
        if (curr->capacity >= btree->m) {
            // split!
            int keys[5];
            BTreeNode * children[6];
            BTreeNode * right = split_internal(curr, keys, children); 
            return right;
        } else {
            curr->capacity++;
            // insert into it
        }
    }
}



int * insert_nonrecursive(BTree * btree, int key, int value) {
    BTreeNode * leaf = get_closest_leaf(btree, key);
    int * target = find_value_by_key(leaf, key);
    if (target != NULL) {
        *target = value; 
        return target;
    }

    //use leaf
    if (leaf->capacity >= btree->m) {
        // SPLIT TODO  
        // how do we back propagate to parents? need to make recursive
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

int get_min_node_capacity(int m) {
    return m % 2 == 0 ? m / 2 : (m / 2) + 1;
}

void add_key_value_to_leaf(BTreeNode * curr, int key, int value) {
    int i;
    for (i = 0; i < curr->capacity; ++i) {
        if (key < curr->leaf_keys[i] ) { break; }
    }

    //shift everything up, starting from end to avoid temp var
    for (int j = curr->capacity - 1; j >= i; --j) {
        curr->leaf_keys[j+1] = curr->leaf_keys[j];
        curr->values[j+1] = curr->values[j];
    }
    curr->leaf_keys[i] = key;
    int * value_ptr = malloc(sizeof(int));
    *value_ptr = value;
    curr->values[i] = value_ptr;
    curr->capacity++; 
}


BTreeNode * add_key_value_to_leaf_split(BTreeNode * left, int key, int value, int m) {
    int min_cap = get_min_node_capacity(m);

    BTreeNode * right = malloc(sizeof(BTreeNode));
    right->is_leaf = 1;
    right->capacity = min_cap;

    int left_to_move_count = min_cap;
    short int inserted_key = 0;
    int i;
    for (; left_to_move_count > 0; --left_to_move_count) {
        i = left->capacity - left_to_move_count;
        if (!inserted_key) --i;

        if (key >= left->leaf_keys[i] && !inserted_key ) {
            right->leaf_keys[left_to_move_count] = key;
            int * value_ptr = malloc(sizeof(int));
            *value_ptr = value;
            right->values[left_to_move_count] = value_ptr;
                
            inserted_key++;
        } else {
            right->leaf_keys[left_to_move_count] = left->values[i];
            right->values[left_to_move_count] = left->values[i];
        }
    }
    
    left->capacity = m % 2 == 0 ? min_cap + 1 : min_cap;
    if (!inserted_key) {
        add_key_value_to_leaf(left, key, value);
    }

    return right;
}



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




