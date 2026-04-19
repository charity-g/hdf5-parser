

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

typedef struct {
    BTreeNode * root;
    short int m;
    int height;
} BTree;

typedef struct {
    int key;

    int value;
} BTreeNode;

BTree * create_btree() {
    BTree * btree = alloc(sizeof(BTree));
    BTreeNode * root = alloc(sizeof(BTreeNode));
    btree->root = root;
    btree->m = 5;
    btree->height = 0;
}

int search(BTree * root, int key) {
    // TODO
}

int insert(BTree * root, int key, int value) {
    // TODO
}

int delete(BTree * root, int key) {
    // TODO
}


// ==================================================================================================================
// PRIVATE functions


int search(BTreeNode * root, int key) {
    // TODO
}

int insert(BTreeNode * root, int key, int value) {
    // TODO
}

int delete(BTreeNode * root, int key) {
    // TODO
}

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




