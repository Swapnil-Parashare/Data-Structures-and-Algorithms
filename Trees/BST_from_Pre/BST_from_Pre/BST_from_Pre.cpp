#include <iostream>
#include<stack>

using namespace std;

class Node
{
public:

    Node* l_child;
    int data;
    Node* r_child;
};

class BST
{
private:

    Node* root;

public:

    BST()
    {
        root = NULL;
    }

    Node* get_root()
    {
        return root;
    }

    void create_from_pre(int* pre, int n);
    void inorder(Node* p);
    
};



void BST::create_from_pre(int* pre, int n)
{
    Node* t = NULL;                          // For Creating Nodes.
    int i = 0;                               // For while-loop.

    root = new Node;
    root->data = pre[i++];
    root->l_child = root->r_child = NULL;

    Node* p = root;

    stack<Node*> stk;                        // It means Stack "stk" can store Node Pointers in itself.


    while (i < n)
    {
        if(pre[i] < p->data)
        {
            t = new Node;
            t->data = pre[i++];
            t->l_child = t->r_child = NULL;

            p->l_child = t;
            stk.push(p);
            p = t;
        }

        else
        {
            if (pre[i] > p->data && pre[i] < (stk.empty() ? 32767 : stk.top()->data))           // Actually its just that pre[i] should be less than Stack top, but if stack is empty then maximum value is taken, here 32767.
            {
                t = new Node;
                t->data = pre[i++];
                t->l_child = t->r_child = NULL;

                p->r_child = t;
                p = t;                                           // Don't Push.

            }

            else
            {
                p = stk.top();
                stk.pop();
            }
        }
    }   
}


void BST::inorder(Node* p)
{
    if (p)
    {
        inorder(p->l_child);
        cout << p->data << " ";
        inorder(p->r_child);
    }
}




int main()
{

    cout << "BST from Preorder: " << endl;
    int pre[] = { 30, 20, 10, 15, 25, 40, 50, 45 };
    int n = sizeof(pre) / sizeof(pre[0]);

    BST b;
    b.create_from_pre(pre, n);
    b.inorder(b.get_root());
    cout << endl;
}
