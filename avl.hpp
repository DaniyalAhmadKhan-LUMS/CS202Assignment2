#include "avl.cpp"

#ifndef __AVL_HPP
#define __AVL_HPP


template <class T, class S>
struct node{
    T key;
    S value;
    node *left;
    node *right;
    int height;

    node (T key, S value){
        this->key = key;
        this->value = value;
        left = NULL;
        right = NULL;
        height = 1;
    }
};


template <class T, class S>
class AVL {
    node<T,S> *root;
    bool isAVL;
    node<T,S>* structure (node<T,S>* p);

    node<T,S>* Rotate_LR(node<T,S>* p);
    node<T,S>* Rotate_RL(node<T,S>* p);

    node<T,S>* Rotate_RR(node<T,S>* p);
    node<T,S>* Rotate_LL(node<T,S>* p);


    node<T,S> *inorder_successor(node<T,S>* p);
    void printTreeInOrder(node<T,S>*p);
    node<T,S> *insert_avl(node<T,S>* p, node<T,S>* newNode);
    node<T,S> *delete_avl(node<T,S>* p, T k);
    int balance (node<T,S>* p);
    void insertnodehelper(node<T,S>* temp,node<T,S>* newNode);
    node<T,S>* searchnodehelper(node<T,S>* temp,T k);

public:
    AVL(bool);
    ~AVL();
    void insertNode(node<T,S>*);
    void deleteNode(T k);
    node<T,S>* searchNode(T k);
    node<T,S>* getRoot();
    int height (node<T,S>* p);
};


#endif
