#include <iostream>

using namespace std;

struct Node
{
    struct Node* l_child;
    int data;
    struct Node* r_child;
};

struct Node* root = NULL;                                              // Global Root Pointer


void i_insert(int key)
{
    Node* t = NULL;                                                    // For Creating Nodes.
    Node* p = root;                                                    // For Finding out correct position.
    Node* r = NULL;                                                    // Tailing Pointer.

    if (root == NULL)
    {
        t = new Node;
        t->data = key;
        t->l_child = t->r_child = NULL;

        root = t;                                                      // 't' address should be given to Global "root" and not p.
        return;
    }

    while(p)
    {
        r = p;

        if (key == p->data)                                            // No Dupliacte Values allowded
        {
            return;
        }

        else if (key < p->data)
        {
            p = p->l_child;
        }

        else if (key > p->data)
        {
            p = p->r_child;
        }

    }

    t = new Node;
    t->data = key;
    t->l_child = t->r_child = NULL;

    if (key < r->data)
    {
        r->l_child = t;
    }
    else
    {
        r->r_child = t;
    }

}

Node* i_search(int key)
{
    Node* p = root;

    while (p)
    {
        if (key == p->data)
            return p;

        else if (key < p->data)
            p = p->l_child;

        else
            p = p->r_child;
    }
    return NULL;
}

Node* r_insert(Node* p, int key)
{
    Node* t = NULL;                                                               // For Creating Nodes.

    if (p == NULL)
    {
        t = new Node;
        t->data = key;
        t->l_child = t->r_child = NULL;

        return t;
    }

    
    if (key < p->data)
    {
        p->l_child = r_insert(p->l_child, key);
    }

    else
    {
        p->r_child = r_insert(p->r_child, key);
    }

    return p;

}

Node* r_search(Node* p, int key)
{
    if (p == NULL)
    {
        return NULL;
    }
    else
    {
        if (key == p->data)
            return p;

        else if (key < p->data)
            r_search(p->l_child, key);

        else
            r_search(p->r_child, key);
    }

}

void i_create()
{
    int x = 0;

    cout << "\nFor Terminating Enter -1" << endl;

    cout << "\nEnter the Elements : " << endl;
    cout << endl;

    while (x != -1)
    {
        cin >> x;
        if (x != -1)
        {
            i_insert(x);
        }
    }
}

void r_create()
{
    int x = 0;

    if (root == NULL)
    {
        int r = 0;
        cout << "\nEnter Root Value : ";
        cin >> r;
        root = r_insert(root, r);
    }

    Node* p = root;


    cout << "\nFor Terminating Enter -1" << endl;

    cout << "\nEnter the Elements : " << endl;
    cout << endl;

    while (x != -1)
    {
        cin >> x;
        if (x != -1)
        {
            r_insert(p, x);
        }
    }
}

int height(Node* p)
{
    if (p == NULL)
    {
        return 0;
    }
    else
    {
        int x;
        int y;
        x = height(p->l_child);
        y = height(p->r_child);
        return x > y ? x + 1 : y + 1;
    }
}

Node* InPre(Node* p)
{
    while (p && p->r_child)
    {
        p = p->r_child;
    }
    return p;
}

Node* InSucc(Node* p)
{
    while (p && p->l_child)
    {
        p = p->l_child;
    }
    return p;
}

Node* Delete(Node* p, int key)
{
    Node* q;

    if (p == NULL)                                                       // If Root Pointer itself is NULL.
    {
        return NULL;
    }

    else if (!p->l_child && !p->r_child)                                // Deleting Leaf Nodes.
    {
        if (p == root)                                                   // Root is the Only Node Present.
        {
            delete root;
            root = NULL;
        }

        delete p;

        return NULL;
    }


    if (key < p->data)
    {
        p->l_child = Delete(p->l_child, key);
    }

    else if (key > p->data)
    {
        p->r_child = Delete(p->r_child, key);
    }

    else
    {
        if (height(p->l_child) > height(p->r_child))
        {
            q = InPre(p->l_child);
            p->data = q->data;
            p->l_child = Delete(p->l_child, q->data);                     // After Copying the Data, p->left is considered as root and q is again deleted as its data is copied.
        }

        else
        {
            q = InSucc(p->r_child);
            p->data = q->data;
            p->r_child = Delete(p->r_child, q->data);                     // After Copying the Data, p->right is considered as root and q is again deleted as its data is copied.
        }
    }

    return p;
}



void inorder(Node* p)
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
    int choice = 0;

    do
    {
        cout << "\nEnter Choice : " << endl;
        cout << "\n1]Create \n2]Search \n3]Insert \n4]Delete \n5]Display Inorder Traversal";
        cout << "\n\nChoice :";
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                int x;
                cout << "\n1]Iterative \n2]Recursive";
                cout << "\n\nChoice :";
                cin >> x;

                if (x == 1)
                {
                    i_create();
                }
                else
                {
                    r_create();
                }
                break;
            }

            case 2:
            {
                int x;
                cout << "\n1]Iterative \n2]Recursive";
                cout << "\n\nChoice :";
                cin >> x;

                if (x == 1)
                {
                    int i = 0;
                    cout << "\nElement : ";
                    cin >> i;

                    Node* k = i_search(i);

                    if (k)
                        cout << "\nElement " << i << " is present at Node " << k << endl;
                    else
                        cout << "\nElement Not Found" << endl;
                }
                else
                {
                    Node* k = root;

                    int i = 0;
                    cout << "\n\nElement : ";
                    cin >> i;

                    Node* s = r_search(k,i);

                    if (s)
                        cout << "\nElement " << i << " is present at Node " << s << endl;
                    else
                        cout << "\nElement Not Found" << endl;
                }
                break;
            }

            case 3:
            {
                int x;
                cout << "\n1]Iterative \n2]Recursive";
                cout << "\n\nChoice :";
                cin >> x;

                int i = 0;
                cout << "\n\nElement : ";
                cin >> i;

                if (x == 1)
                {
                    i_insert(i);
                }
                else
                {
                    Node* p = root;
                    r_insert(p, i);
                }
                break;

            }


            case 4:
            {
                Node* p = root;
                int x;
                cout << "\nElement : ";
                cin >> x;
                Delete(p, x);
                break;
            }

            case 5:
            {
                Node* p = root;
                cout << endl;
                inorder(p);
                cout << endl;
                break;
            }

            
        }


    } while (choice > 0);

}
