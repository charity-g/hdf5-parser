

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

struct BTree {
    struct BTreeRoot * root;
    short int m;
    int height;
};


int search(struct BTree * root, int key) {
    // TODO
}

int insert(struct BTree * root, int key, int value) {
    // TODO
}

int delete(struct BTree * root, int key) {
    // TODO
}


// ==================================================================================================================
// PRIVATE functions

struct BTreeNode {
    int key;

    int value;
};

int search(struct BTreeNode * root, int key) {
    // TODO
}

int insert(struct BTreeNode * root, int key, int value) {
    // TODO
}

int delete(struct BTreeNode * root, int key) {
    // TODO
}

// ==================================================================================================================
// ITERATION

struct BTreeIterator {
    // struct BTreeNode * root; // needed?
    struct BTreeNode * curr;
};


struct BTreeIterator * create_iterator(struct BTree * btree) {
    // TODO
}

// returns leaf nodes?? or leaf values?? TODO
// int or null get_iterator_next(struct BTreeIterator * iter) {
//     // TODO
// }




