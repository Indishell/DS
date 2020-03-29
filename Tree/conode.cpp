#include<bits/stdc++.h>
using namespace std;

// This code is written by Anurag Mishra.

class Node
{
    public:
        int data;
        Node *left, *right, *nextLeft, *nextRight;
};

Node* newNode(int item)
{
    Node* temp = new Node;
    temp->data = item;
    temp->left= temp->right = NULL;
    temp->nextLeft =  temp->nextRight =   NULL;
 
    return temp;
}

void connectNodes_nextLeft(Node* root)
{
    if(root== NULL)
        return;

    queue<Node*> mq;
    mq.push(root);
    mq.push(NULL);

    while (!mq.empty())
    {
        Node* p = mq.front();
        mq.pop();

        if(p !=  NULL)
        {
            p->nextLeft =  mq.front();

            if(p->right)
                mq.push(p->right);

            if(p->left)
                mq.push(p->left);                
                    
        }

        else if(!mq.empty())
            mq.push(NULL);

    }
    

}

void connectNodes_nextRight(Node* root)
{
    if(root== NULL)
        return;

    queue<Node*> mq;
    mq.push(root);
    mq.push(NULL);

    while (!mq.empty())
    {
        Node* p = mq.front();
        mq.pop();

        if(p !=  NULL)
        {
            p->nextRight =  mq.front();

            if(p->left)
                mq.push(p->left); 
             if(p->right)
                mq.push(p->right);
                    
        }

        else if(!mq.empty())
            mq.push(NULL);

    }
    

}



int main()
{
    Node* root = newNode(10); 
    root->left = newNode(8); 
    root->right = newNode(2); 
    root->left->left = newNode(3); 
    root->right->right = newNode(90); 
    
    /* Constructed binary tree is 
              10 
            /   \ 
          8      2 
        /         \ 
      3            90

    nextleft of 10 is -1 
    nextleft of 8 is -1
    nextleft of 2 is 8 
    nextlet of 3 is -1 
    nextleft of 90 is 3 
    */






    connectNodes_nextLeft(root); 
    connectNodes_nextRight(root);

    // Let us check the values of nextLeft pointers 
    printf("Following are populated nextLeft pointers in \n"
     "the tree (-1 is printed if there is no nextLeft) \n"); 
    printf("nextLeft of %d is %d \n", root->data, 
     root->nextLeft ? root->nextLeft->data : -1); 
    printf("nextLeft of %d is %d \n", root->left->data, 
     root->left->nextLeft ? root->left->nextLeft->data : -1); 
    printf("nextLeft of %d is %d \n", root->right->data, 
     root->right->nextLeft ? root->right->nextLeft->data : -1); 
    printf("nextLeft of %d is %d \n", root->left->left->data, 
     root->left->left->nextLeft ? root->left->left->nextLeft->data : -1); 
    printf("nextLeft of %d is %d \n", root->right->right->data, 
     root->right->right->nextLeft ? root->right->right->nextLeft->data : -1);




    printf("\n");

    printf("nextRight of %d is %d \n", root->data, 
     root->nextRight ? root->nextRight->data : -1); 
    printf("nextRight of %d is %d \n", root->left->data, 
     root->left->nextRight ? root->left->nextRight->data : -1); 
    printf("nextRight of %d is %d \n", root->right->data, 
     root->right->nextRight ? root->right->nextRight->data : -1); 
    printf("nextRight of %d is %d \n", root->left->left->data, 
     root->left->left->nextRight ? root->left->left->nextRight->data : -1); 
    printf("nextRight of %d is %d \n", root->right->right->data, 
     root->right->right->nextRight ? root->right->right->nextRight->data : -1); 


    return 0; 

}