

                        /*****************************   Creating Binary Tree Using "Linked Representation"    *******************************/


#include <iostream>

#include "Queue.h"

using namespace std;


Node* root = NULL;                                   // This is Global pointer pointing at root of our tree.

void create_Tree()
{
    Queue q;
    create(&q, 100);                                 // This queue is created using Array so size is fixed hence give enough size, so code doesn't crash.


    Node* t;                                         // For creating new Nodes of our Tree.                        
    Node* p;                                         // For Pointing on Current Node and Checking the existance of left and right child and then creating and linking those Nodes with the help of "t".


    int x;
    cout << "\nEnter the Root Value : ";
    cin >> x;


    root = new Node;
    root->data = x;
    root->left_child = NULL;
    root->right_child = NULL;

    enqueue(&q, root);

    while (!isEmpty(q))
    {
        p = dequeue(&q);

        int x = 0;
        cout << "\nEnter Left Child Value of " << p->data << " : ";
        cin >> x;

        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->left_child = NULL;
            t->right_child = NULL;


            p->left_child = t;                                          // Here Linking is done with help of p and t.
            enqueue(&q, t);
        }


        int y = 0;
        cout << "\nEnter Right Child Value of " << p->data << " : ";
        cin >> y;

        if (y != -1)
        {
            t = new Node;
            t->data = y;
            t->left_child = NULL;
            t->right_child = NULL;


            p->right_child = t;                                          // Here Linking is done with help of p and t.
            enqueue(&q, t);
        }
    }

}

void preorder(Node* p)
{
    if(p)
    {
        cout << p->data << " ";
        preorder(p->left_child);
        preorder(p->right_child);
    }
}

void inorder(Node* p)
{
    if(p)
    {
        inorder(p->left_child);
        cout << p->data << " ";
        inorder(p->right_child);
    }
}

void postorder(Node* p)
{
    if (p)
    {
        postorder(p->left_child);
        postorder(p->right_child);
        cout << p->data << " ";
    }
}

int main()
{
    create_Tree();

    cout << "\nPreorder : ";
    preorder(root);
    cout << endl;

    cout << "\nInorder : ";
    inorder(root);
    cout << endl;

    cout << "\nPostorder : ";
    postorder(root);
    cout << endl;
}
