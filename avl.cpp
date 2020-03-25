#ifndef __AVL_CPP
#define __AVL_CPP

#include <iostream>
using namespace std;
#include "avl.hpp"


template <class T, class S>
AVL<T,S>::AVL(bool isAVL){
	this->root = NULL;
    this->isAVL = isAVL;
}

template <class T, class S>
AVL<T,S>:: ~AVL()
{
    while(root!=NULL)
    {
        deleteNode(root->key);
    }
}
template <class T, class S>
int AVL<T,S> :: height (node<T,S>* p)
    {
        if(p==NULL)
            {
                return 0;
            }

        else if(p->left==NULL)
            {
                if(p->right==NULL)
                {
                    return 1;
                }
            }
        int right_height=height(p->right);

        int left_height=height(p->left);



        if(left_height>right_height)
        {
            return left_height+1;
        }
        else if(left_height<right_height)
        {
            return right_height+1;
        }
    }
template <class T, class S>
int AVL<T,S> :: balance (node<T,S>* p)
{
    int left_height;
    int right_height;

    left_height = height(p->left);
    right_height = height(p->right);

    int balance_factor;
    balance_factor = left_height-right_height;

    return balance_factor;
}
template <class T, class S>
node<T,S>* AVL<T,S> :: Rotate_LL(node<T,S>* p)
{
    //single rotaion
    node<T,S>* temp_node=p->left;
    p->left=temp_node->right;

    temp_node->right=p;
    return temp_node;
}
template <class T, class S>
node<T,S>* AVL<T,S> :: Rotate_RR(node<T,S>* p)
{
    //single rotation
    node<T,S>* temp=p->right;
    p->right=temp->left;
    temp->left=p;
    return temp;
}
template <class T, class S>
node<T,S>* AVL<T,S> :: Rotate_LR(node<T,S>* p)
{
    //double rotation
    p->left=Rotate_RR(p->left);
    p=Rotate_LL(p);
    return p;
}
template <class T, class S>
node<T,S>* AVL<T,S> :: Rotate_RL(node<T,S>* p)
{
    //double rotation
    p->right=Rotate_LL(p->right);
    p=Rotate_RR(p);
    return p;
}
template <class T, class S>
node<T,S>* AVL<T,S> :: structure(node<T,S>* p){
    if(p==NULL)
    {
        return NULL;
    }
    if(balance(p)<-1)
    {
         if(balance(p->right)<0)
        {
            return Rotate_RR(p);
        }
        else
        {
            return Rotate_RL(p);
        }
    }

    else if(balance(p)>1)
    {
       if(balance(p->left)>0)
        {
            return Rotate_LL(p);
        }
        else
        {
            return Rotate_LR(p);
        }

    }
    return p;
}
template <class T, class S>
node<T,S>* AVL<T,S> :: insert_avl(node<T,S>* p,node<T,S>* newNode)
{
    if(p==NULL)
    {
        p=newNode;
        return p;
    }
    if(p->key>newNode->key)
    {
        p->left=insert_avl(p->left,newNode);
        p=structure(p);
        return p;
    }
    else if(p->key<newNode->key)
    {
        p->right=insert_avl(p->right,newNode);
        p=structure(p);
        return p;
    }
}
template <class T, class S>
void AVL<T,S> :: insertNode(node<T,S>* newNode){

    insertnodehelper(root,newNode);
}
template <class T, class S>
void AVL<T,S> :: insertnodehelper(node<T,S>* temp,node<T,S>* newNode)
    {
        if(isAVL==0)
        {
            if(root==NULL)
            {
                root=newNode;
                return;
            }
            //temp=root;
            if(newNode->key<temp->key)
            {
                if(temp->left==NULL)
                {

                    temp->left=newNode;
                    return;
                }
                insertnodehelper(temp->left,newNode);
            }
            else
            {
                if(temp->right==NULL)
                {
                    temp->right=newNode;
                    return;

                }
                insertnodehelper(temp->right,newNode);
            }

        }
        if (isAVL==1)
        {
            root=insert_avl(root,newNode);
        }
        return;

    }


template <class T, class S>
node<T,S>* AVL<T,S> :: searchNode(T key){
    /*node<T,S>* temp=root;
        if(key==temp->key)
        {
            return temp;
        }
        if(key<temp->key)
        {
            //temp=temp->left;
            searchNode(temp->left);
        }
        else
        {
         //   temp=temp->right;
            searchNode(temp->right);
        }


    return NULL;*/
    searchnodehelper(root,key);
}
template <class T,class S>
node<T,S>* AVL<T,S> :: searchnodehelper(node<T,S>* temp,T key)
{
        if(temp==NULL||temp->key==key) return temp;
        if(key<temp->key)
        {
            return searchnodehelper(temp->left,key);
        }
        else
        {
            return searchnodehelper(temp->right,key);
        }
}


template <class T, class S>
void AVL<T,S>::printTreeInOrder(node<T,S>* p)
{
    if(p == NULL) return;
    printTreeInOrder(p->left);
	cout << p->key << " ";
	printTreeInOrder(p->right);
}
template <class T, class S>
node<T,S>* AVL<T,S> ::delete_avl(node<T,S>* p, T k)
{
    if(p==NULL)
    {
        return p;
    }
    if(k<p->key)
    {
        p->left=delete_avl(p->left,k);
    }
    else if(k>p->key)
    {
        p->right=delete_avl(p->right,k);
    }
    else
    {
        if(p->left==NULL&&p->right==NULL)
        {
            delete p;
            return NULL;
        }
        else if(p->left==NULL&&p->right!=NULL)
        {
            node<T,S>* temp=p->right;
            p->right=NULL;
            delete p;
            return temp;
        }
        else if(p->right==NULL&&p->left!=NULL)
        {
            node<T,S>* temp=p->left;
            p->left=NULL;
            delete p;
            return temp;
        }
        else
        {
            node<T,S>* temp=inorder_successor(p->right);
            T k1=temp->key;
            S v1=temp->value;
            deleteNode(temp->key);
            p->key=k1;
            p->value=v1;
            return p;
        }
        if (p==NULL){return p;}
    }
    return structure(p);
}
template <class T, class S>
void AVL<T,S>::deleteNode(T k){
    if(isAVL==0)
    {
        node<T,S>* temp=root;
        node<T,S>* nodeto_delete=root;
        while(nodeto_delete!=NULL)
        {
            if(k==nodeto_delete->key)
            {
                break;
            }
            if(k<nodeto_delete->key)
            {
                temp=nodeto_delete;
                nodeto_delete=nodeto_delete->left;
            }
            else
            {
                temp=nodeto_delete;
                nodeto_delete=nodeto_delete->right;
            }
        }
        if(temp==NULL)
        {
            return;
        }
        if(nodeto_delete->left==NULL&&nodeto_delete->right==NULL)
        {

            if(nodeto_delete->key>temp->key)
            {
                temp->right=NULL;
            }
            else
            {
                temp->left=NULL;
            }
            delete nodeto_delete;
        }
        else if(nodeto_delete->left==NULL&&nodeto_delete->right!=NULL)
        {

            if(nodeto_delete->key<temp->key)
            {
                temp->left=nodeto_delete->right;
                nodeto_delete->right=NULL;
                delete nodeto_delete;
            }
            else
            {
                temp->right=nodeto_delete->right;
                nodeto_delete->right=NULL;
                delete nodeto_delete;
            }
        }
        else if(nodeto_delete->right==NULL&&nodeto_delete->left!=NULL)
        {

            if(nodeto_delete->key<temp->key)
            {
                temp->left=nodeto_delete->left;
                nodeto_delete->left=NULL;
                delete nodeto_delete;
            }
            else
            {
                temp->right=nodeto_delete->left;
                nodeto_delete->left=NULL;
                delete nodeto_delete;
            }
        }
        else
        {
            //cout<< "2 children"<<endl;
            node<T,S>* temp=inorder_successor(nodeto_delete->right);
            T key1=temp->key;
            S valueofkey=temp->value;
            deleteNode(temp->key);
            nodeto_delete->key=key1;
            nodeto_delete->value=valueofkey;
        }
    return;
    }
    if(isAVL==1)
    {
        root=delete_avl(root,k);
    }
}
template <class T, class S>
node<T,S>* AVL<T,S>::inorder_successor(node<T,S>* p)
    {
        node<T,S>* temp=p;
        while(temp->left!=NULL)
            {
                temp=temp->left;
            }
        return temp;
    }

template <class T, class S>
node<T,S>* AVL<T,S>::getRoot()
{

    node<T,S>* temp =root;

    return temp;
}

#endif
