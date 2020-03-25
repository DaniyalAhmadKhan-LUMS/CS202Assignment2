#include <iostream>
#include "avl.hpp"
#include "zambeel.hpp"

using namespace std;

Zambeel::Zambeel(bool isAVL) {

	myTree = new AVL<int,int>(isAVL);
}

Zambeel::~Zambeel() {

	//delete myTree;
}




bool Zambeel::istDropCourse(int course_id)
        {
            if(myTree->searchNode(course_id)==NULL)
            {
                return false;
            }
            myTree->deleteNode(course_id);
            return true;
        }

void Zambeel::istCleanEnrollment()
        {
            node<int,int>* curr = myTree->getRoot();
            node<int,int>* pre;
            if(curr==NULL) return;
            while(curr!=NULL){
                if(curr->left==NULL)
                    {
                        curr->value = 0;
                        curr = curr->right;
                    }
                else
                {
                    pre = curr->left;
                    while (pre->right != NULL && pre->right != curr)
                        pre = pre->right;
                    if (pre->right == NULL)
                    {
                        pre->right = curr;
                        curr = curr->left;
                    }
                    else
                    {
                        pre->right = NULL;
                        curr->value = 0;
                        curr = curr->right;
                    }
                }
            }
            return;
        }
bool Zambeel::istAddCourse(int course_id) {
    if(myTree->searchNode(course_id)!=NULL){
        return false;
    }
    node<int,int>* newNode = new node<int,int>(course_id,0);
    myTree->insertNode(newNode);
	return true;
}

bool Zambeel::stuAddCourse(int course_id) {
    if(myTree->searchNode(course_id)==NULL){
        return false;
    }
    node<int,int>* temp = myTree->searchNode(course_id);
    temp->value++;
	return true;
}

bool Zambeel::stuDropCourse(int course_id) {
    if(myTree->searchNode(course_id)==NULL){
        return false;
    }
    node<int,int>* temp = myTree->searchNode(course_id);
    if(temp->value==0) return false;
    temp->value--;
	return true;
}

bool Zambeel::stuSwapCourse(int course1_id, int course2_id){
    return (stuAddCourse(course1_id)&&stuDropCourse(course2_id));
}

int main()
{
    srand(time(0));
    Zambeel ob1(0);
    Zambeel ob2(1);
    int list2[10]={ 800, 440, 240, 760, 470, 210, 450, 180, 880, 360};
    int list1[10]={500,555,570,597,675,680,698,700,709,715};
    int list3[10]={100, 500, 600, 101, 510, 520, 400, 410, 325, 110};

//using list 1 for bst

   /* for(int a=0;a<100;a++){
        int b=rand()%10;
        ob1.stuAddCourse(list1[b]);
    }
    for(int a=0;a<100;a++){
        int b=rand()%10;
        ob1.stuDropCourse(list1[b]);
    }
    for(int a=0;a<100;a++){
        int b=rand()%10;
        int c=rand()%10;
        ob1.stuSwapCourse(list1[b],list1[c]);
    }

    for(int a=0;a<10;a++){
        ob1.istAddCourse(list1[a]);
    }*/

    //using list 2 for bst
     for(int a=0;a<10;a++){
        ob1.istAddCourse(list2[a]);
    }
    for(int a=0;a<100;a++){
        int b=rand()%10;
        ob1.stuDropCourse(list2[b]);
    }


    for(int a=0;a<100;a++){
        int b=rand()%10;
        int c=rand()%10;
        ob1.stuSwapCourse(list2[b],list2[b]);
    }
    for(int a=0;a<100;a++){
        int b=rand()%10;
        ob1.stuAddCourse(list2[b]);
    }

    //case 3 for BST using list 3
    /*
    for(int a=0;a<100;a++){
        int b=rand()%10;
        ob1.stuAddCourse(list3[b]);
    }
    for(int a=0;a<100;a++){
        int b=rand()%10;
        int c=rand()%10;
        ob1.stuSwapCourse(list3[b],list3[c]);
    }
    for(int a=0;a<100;a++){
        int b=rand()%10;
        ob1.stuDropCourse(list3[b]);
    }
//using list 1 for AVL
    for(int a=0;a<10;a++){
        ob2.istAddCourse(list1[a]);
    }
    for(int a=0;a<100;a++){
        int b=rand()%10;
        ob2.stuAddCourse(list1[b]);
    }
    for(int a=0;a<100;a++){
        int b=rand()%10;
        int c=rand()%10;
        ob2.stuSwapCourse(list1[b],list1[c]);
    }
    for(int a=0;a<100;a++){
        int b=rand()%10;
        ob2.stuDropCourse(list1[b]);
    }
//using list 2 for AVL
    for(int a=0;a<100;a++)
    {
        int b=rand()%10;
        int c=rand()%10;
        ob2.stuSwapCourse(list2[b],list2[c]);
    }
    for(int a=0;a<10;a++)
    {
        ob2.istAddCourse(list2[a]);
    }

    for(int a=0;a<100;a++){
        int b=rand()%10;
        ob2.stuDropCourse(list2[b]);
    }
    for(int a=0;a<100;a++){
        int b=rand()%10;
        ob2.stuAddCourse(list2[b]);
    }
//Using list 3 for AVL



    for(int a=0;a<10;a++){
        ob1.istAddCourse(list3[a]);
    }
    for(int a=0;a<100;a++){
        int b=rand()%10;
        int c=rand()%10;
        ob2.stuSwapCourse(list3[b],list3[c]);
    }

    for(int a=0;a<100;a++){
        int b=rand()%10;
        ob2.stuDropCourse(list3[b]);
    }

    for(int a=0;a<10;a++){
        ob2.istAddCourse(list3[a]);
    }
    for(int a=0;a<100;a++){
        int b=rand()%10;
        ob2.stuAddCourse(list3[b]);
    }*/


	return 0;
}
