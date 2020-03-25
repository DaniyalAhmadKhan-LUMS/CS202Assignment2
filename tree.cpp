#ifndef __TREE_CPP
#define __TREE_CPP

#include <iostream>
#include "tree.hpp"


template <class T, class S>
Tree<T,S>::Tree(node<T,S> *root) {
	this->root = root;
}

template <class T, class S>
node<T,S>* Tree<T,S>::findKey(T key) {

	return findKeyHelper(root,key);
}

template <class T, class S>
node<T,S>* Tree<T,S>::findKeyHelper(node<T,S> *currNode, T key) {
    if (currNode==NULL)
    {
        return currNode;
	}
	if (currNode->key==key)
	{
        return currNode;
	}
	node<T,S>* childsearch;
	node<T,S>* siblingsearch;

	childsearch = findKeyHelper(currNode->child,key);
    siblingsearch = findKeyHelper(currNode->sibling,key);

    if (childsearch==NULL&&siblingsearch==NULL)
	{
        return NULL;

	}

	else if(childsearch!=NULL)
	{
        return childsearch;

	}


	return siblingsearch;



}

template <class T, class S>
bool Tree<T,S>::insertChild(node<T,S> *child, T key) {

node<T,S>* nodesearch = findKey(key);
if (nodesearch==NULL)
{
    return false;
}
if (findKey(child->key)!=NULL)
{
    return false;
}
else{
    if(nodesearch->child==NULL)
    {
        nodesearch->child = child;
        return true;
    }
    else
        {
            node<T,S>* temp = nodesearch->child;
            while(temp->sibling!=NULL)
            {
                temp =temp->sibling;
            }
            temp->sibling = child;
            return true;
        }
    }

}

template <class T, class S>
std::vector<node<T,S>*> Tree<T,S>::getAllChildren(T key)
{


    node<T,S>* searchchildren = findKey(key);
    std::vector<node<T,S>*> children;
    if(searchchildren==NULL||searchchildren->child==NULL)

    {
        return children;
    }

    searchchildren = searchchildren->child;
    while(searchchildren!=NULL)

    {
        children.push_back(searchchildren);
        searchchildren = searchchildren->sibling;
    }

    return children;


}

template <class T, class S>
int Tree<T,S>::findHeight() {

	return findHeightHelper(root);
}

template <class T, class S>
int Tree<T,S>::findHeightHelper(node<T,S> *currNode) {
    if (currNode==NULL)
    {
        return 0;
	}
	int  height = findHeightHelper(currNode->child);
	findHeightHelper(currNode->sibling);
	return 1+height;
}

template <class T, class S>
bool Tree<T,S>::deleteLeaf(T key)
{
    node<T,S>* leaftodelete = findKey(key);
    if(leaftodelete==NULL||root->key==leaftodelete->key||leaftodelete->child!=NULL)
    {
        return false;
    }

    if(leaftodelete->sibling==NULL)
    {
        delete leaftodelete;
    }

    node<T,S>* temp = deleteLeafHelper(root,leaftodelete->key);
    temp->child = leaftodelete->sibling;
    delete leaftodelete;
    return true;
}

template <class T, class S>
node<T,S>* Tree<T,S>::deleteLeafHelper(node<T,S> *currNode, T key) {

	    if(currNode==NULL||currNode->child->key==key)
	    {
        return currNode;
        }

	node<T,S>* temp = deleteLeafHelper(currNode->child,key);

	node<T,S>* temp2 = deleteLeafHelper(currNode->sibling,key);

	if(temp==NULL&&temp2==NULL)
	{
        return NULL;
	}
	else if(temp!=NULL)
	{
        return temp;
	}
	return temp2;
}

template <class T, class S>
Tree<T,S>::~Tree() {

	deleteTree(root);
}

template <class T, class S>
void Tree<T,S>::deleteTree(node<T,S> *currNode) {


    if (currNode == NULL)//if the current node is empty means the whole tree is empty.
        return;

    //the rest of the code deltes all the siblings and childs in a node
    deleteTree(currNode->sibling);
    deleteTree(currNode->child);
    delete currNode;

}

template <class T, class S>
node<T,S>* Tree<T,S>::getRoot()
{

	return root;
}

#endif
