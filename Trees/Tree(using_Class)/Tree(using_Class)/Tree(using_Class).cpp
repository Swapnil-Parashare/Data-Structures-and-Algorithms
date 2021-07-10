#include <iostream>

#include"Queue.h"                     // For Creating "Tree"

#include"Stack.h"                     // For "Pre", "In", "Post"  order Tracing of Tree without Recursion

using namespace std;

class Tree
{
private:

    Node* root;             // Private Data Member


public:

    Tree()                  // Default Constructor
    {
        root = NULL;
    }

    Node* get_root()
    {
        return root;
    }

    void create_Tree();

    void preorder(Node* p);                 
    void inorder(Node* p);
    void postorder(Node* p);

    void i_preorder(Node* p);
    void i_inorder(Node* p);
    void i_postorder(Node* p);

    void levelorder(Node* p);

    int height(Node* p);

    int sum(Node* p);

    int count(Node* p);


    int leaf(Node* p);
    int degree1(Node* p);
    int degree2(Node* p);

    int nonleaf(Node* p);
    
    
    
};


void Tree::create_Tree()
{
    Queue q(100);                                   // Its Object of our Queue Class                       
                                                    // This queue is created using Array so size is fixed hence give enough size, so code doesn't crash.

                                    
    Node* t;                                         // For creating new Nodes of our Tree.                        
    Node* p;                                         // For Pointing on Current Node and Checking the existance of left and right child and then creating and linking those Nodes with the help of "t".


    int x;
    cout << "\nEnter the Root Value : ";
    cin >> x;


    root = new Node;
    root->data = x;
    root->left_child = NULL;
    root->right_child = NULL;

    q.enqueue(root);

    while (!q.isEmpty())
    {
        p = q.dequeue();

        int x = 0;
        cout << "\nEnter Left Child Value of " << p->data << "  : ";
        cin >> x;

        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->left_child = NULL;
            t->right_child = NULL;


            p->left_child = t;                                          // Here Linking is done with help of p and t.
            q.enqueue(t);
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
            q.enqueue(t);
        }
    }

}

// Recursive Tracing Functions

void Tree::preorder(Node* p)
{
    if (p)
    {
        cout << p->data << " ";
        preorder(p->left_child);
        preorder(p->right_child);
    }
}

void Tree::inorder(Node* p)
{
    if (p)
    {
        inorder(p->left_child);
        cout << p->data << " ";
        inorder(p->right_child);
    }
}

void Tree::postorder(Node* p)
{
    if (p)
    {
        postorder(p->left_child);
        postorder(p->right_child);
        cout << p->data << " ";
    }
}


// Iterative Tracing Functions

void Tree::i_preorder(Node* p)
{
    Stack <Node*> st(100);                                 // This is our Stack with size 100, and type Node** i.e it is capable of Pointing to node pointers. (One "Address of Operator" i.e * is already present in our Stack Defination)
                                                           // What we have to store in our Stack should be given as the Template Argument.
    while (p != NULL || !st.isEmpty())                     // Initially Stack is Empty hence "or" condition is neccesery.
    {
        if (p != NULL)
        {
            cout << p->data << " ";
            st.push(p);
            p = p->left_child;
        }

        else
        {
            p = st.pop();
            p = p->right_child;
        }
    }
}

void Tree::i_inorder(Node* p)
{
    Stack <Node*> st(100);                                 // This is our Stack with size 100, and type Node** i.e it is capable of Pointing to node pointers. (One Address of Operator * is already present in our Stack Defination)
                                                           // What we have to store in our Stack should be given as the Template Argument.
    while (p != NULL || !st.isEmpty())
    {
        if (p != NULL)
        {
            st.push(p);
            p = p->left_child;
        }

        else
        {
            p = st.pop();
            cout << p->data << " ";
            p = p->right_child;
        }
    }
}


void Tree::i_postorder(Node* p)
{
    Stack <long int> st(100);                                  // Here we are supposed to push Negative addresses, as addresses cannot be negative, hence here we need to change type of our stack.
                                                               // What we have to store in our Stack should be given as the Template Argument.
    long int temp;                                         

    while (p != NULL || !st.isEmpty())
    {
        if (p != NULL)
        {
            st.push((long int)p);
            p = p->left_child;
        }

        else
        {
            temp = st.pop();                                       // Stack Stores just integers.
                                                                   
            if (temp > 0)                                          
            {                                                      
                st.push(-temp);                               
                p = ((Node*)temp)->right_child;
            }

            else
            {
                cout << ((Node*)(-1 * temp))->data << " ";           // Converting temp back into positive number then type cast it to Node pointer then printing out its data.
                p = NULL;
            }
        }
    }
}


// Level Order

void Tree::levelorder(Node* p)
{
    Queue q(100);

    cout << p->data << " ";
    q.enqueue(p);

    while (!q.isEmpty())
    {
        p = q.dequeue();

        if (p->left_child)
        {
            cout << p->left_child->data << " ";
            q.enqueue(p->left_child);
        }

        if (p->right_child)
        {
            cout << p->right_child->data << " ";
            q.enqueue(p->right_child);
        }
    }

}

// Sum of all Nodes

int Tree::sum(Node* p)
{
    int x = 0; int y = 0;

    if (p)
    {
        x = sum(p->left_child);
        y = sum(p->right_child);

        return x + y + p->data;

    }
    else
    {
        return 0;
    }
}

// Height

int Tree::height(Node* p)                        // Its Actually Returning "Level" which is one more than height. Height of Tree starts from 0 onwards.
{                                                // Or we can say Function is Returning Usual Height(which user Understand).
    int x = 0;
    int y = 0;

    if(p)
    {
        x = height(p->left_child);
        y = height(p->right_child);

        if (x > y)
            return x + 1;
        else
            return y + 1;
    }
    else
    {
        return 0;
    }
    
}

// Count

int Tree::count(Node* p)
{
    if (p)
    {
        return count(p->left_child) + count(p->right_child) + 1;
    }
    else
    {
        return 0;
    }
}





// Leaf Nodes(Degree 0)                                                 // Nodes with no children i.e Degree = 0 (Degree  = Number of Childrens)

int Tree::leaf(Node* p)
{
    int x = 0; int y = 0;

    if (p)
    {
        x = leaf(p->left_child);
        y = leaf(p->right_child);

        if (!p->left_child && !p->right_child)                           //(We may change these conditions to count different types of Nodes)
        {
            return x + y + 1;                                          // If Both child exit then only the Node is counted.
        }
        else
        {
            return x + y;                                              // Otherwise Node is not counted.
        }
    }
    else
    {
        return 0;
    }
}

// Nodes with degree 1

int Tree::degree1(Node* p)
{
    int x = 0; int y = 0;

    if (p)
    {
        x = degree1(p->left_child);
        y = degree1(p->right_child);

        if ((p->left_child && !p->right_child) || (!p->left_child && p->right_child))                          //Lenghty :-  Instead use Xor operation. But Logical exor not present in c++.
        {
            return x + y + 1;                                          // If any "one" of the child is present then the Node is Counted.
        }
        else
        {
            return x + y;                                              // Otherwise Node is not counted.
        }
    }
    else
    {
        return 0;
    }
}


// Nodes with degree 2

int Tree::degree2(Node* p)
{
    int x = 0; int y = 0;

    if (p)
    {
        x = degree2(p->left_child);
        y = degree2(p->right_child);

        if (p->left_child && p->right_child)                           //(We may change these conditions to count different types of Nodes)
        {
            return x + y + 1;                                          // If Both child exit then only the Node is counted.
        }
        else
        {
            return x + y;                                              // Otherwise Node is not counted.
        }
    }
    else
    {
        return 0;
    }
}

// Only Non-Leaf (Degree 1 and 2)

int Tree::nonleaf(Node* p)
{
    int x = 0; int y = 0;

    if (p)
    {
        x = nonleaf(p->left_child);
        y = nonleaf(p->right_child);

        if (p->left_child || p->right_child)                           //(We may change these conditions to count different types of Nodes)
        {
            return x + y + 1;                                          // If Both child exit then only the Node is counted.
        }
        else
        {
            return x + y;                                              // Otherwise Node is not counted.
        }
    }
    else
    {
        return 0;
    }
}




int main()
{
    Tree t;                                                 // Object of our Class Tree.

    t.create_Tree();

    cout << "\n\n\t**********TREE ANALYSIS***********\n\n" << endl;

    cout << "\nRecursive Preorder  : ";
    t.preorder(t.get_root());
    cout << endl;

    cout << "\nRecursive Inorder   : ";
    t.inorder(t.get_root());
    cout << endl;

    cout << "\nRecursive Postorder : ";
    t.postorder(t.get_root());
    cout << endl;

    cout << "\nIterative Preorder  : ";
    t.i_preorder(t.get_root());
    cout << endl;

    cout << "\nIterative Inorder   : ";
    t.i_inorder(t.get_root());
    cout << endl;

    cout << "\nIterative Postorder : ";
    t.i_postorder(t.get_root());
    cout << endl;

    cout << "\nLevel Order         : ";
    t.levelorder(t.get_root());
    cout << endl;

    cout << "\nHeight  : ";
    cout << t.height(t.get_root());
    cout << endl;

    cout << "\nSum of all Nodes       : ";
    cout << t.sum(t.get_root());
    cout << endl;

    cout << "\nTotal Number of Nodes  : ";
    cout << t.count(t.get_root());
    cout << endl;

    cout << "\nNodes with Degree 0(Leaf Nodes)     : ";
    cout << t.leaf(t.get_root());
    cout << endl;

    cout << "\nNodes with Degree 1(Non-Leaf Nodes) : ";
    cout << t.degree1(t.get_root());
    cout << endl;

    cout << "\nNodes with Degree 2(Non-Leaf Nodes) : ";
    cout << t.degree2(t.get_root());
    cout << endl;

    cout << "\nNon Leaf Node                       : ";
    cout << t.nonleaf(t.get_root());
    cout << "\n" <<endl;

}
