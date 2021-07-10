#include <iostream>

using namespace std;

struct Node
{
    Node* l_child;
    int data;
    Node* r_child;
    int height;
};

struct Node* root = NULL;                                   // Global Root Node.

int NodeHeight(Node* p)
{
    int hl;
    int hr;

    hl = p && p->l_child ? p->l_child->height : 0;
    hr = p && p->r_child ? p->r_child->height : 0; 


    return hl>hr? hl + 1 : hr + 1;

}

int BalanceFactor(Node* p)
{
    int hl;
    int hr;

    hl = p && p->l_child ? p->l_child->height : 0;
    hr = p && p->r_child ? p->r_child->height : 0;

    return hl - hr;
}

// Rotation Functions               [We use these Rotations during Insertion and Deletion of Elements to maintian "Balance Factor" in Range {1,0,-1}]

Node* LLRotation(Node* p)
{
    Node* pl = p->l_child;
    Node* plr = pl->r_child;

    pl->r_child = p;
    p->l_child = plr;

    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    if (root == p)
    {
        root = pl;
    }


    return pl;                                           // Always Returns Node at Root Position.
}

Node* LRRotation(Node* p)
{
    Node* pl = p->l_child;
    Node* plr = pl->r_child;

    pl->r_child = plr->l_child;
    p->l_child = plr->r_child;
    plr->l_child = pl;
    plr->r_child = p;

    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);
    plr->height = NodeHeight(plr);

    if (root == p)
    {
        root = plr;
    }

    return plr ;                                            
}


Node* RRRotation(Node* p)
{
    Node* pr = p->r_child;
    Node* prl = pr->l_child;

    pr->l_child = p;
    p->r_child = prl;

    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);

    if (p == root)
    {
        root = pr;
    }


    return pr;
}


Node* RLRotation(Node* p)
{
    Node* pr = p->r_child;
    Node* prl = pr->l_child;

    p->r_child = prl->l_child;
    pr->l_child = prl->r_child;
    prl->l_child = p;
    prl->r_child = pr;

    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);
    prl->height = NodeHeight(prl);

    if (root = p)
    {
        root = prl;
    }

    return prl;
}


// Insertion Operation

Node* r_insert(Node* p, int key)
{
    Node* t = NULL;                                                               // For Creating Nodes.

    if (p == NULL)
    {
        t = new Node;
        t->data = key;
        t->l_child = t->r_child = NULL;
        t->height = 1;                                                            // If Node Exits then its height is 1.

        return t;
    }

 
 
    if (key < p->data)
    {
        p->l_child = r_insert(p->l_child, key);
    }

    else if(key > p->data)
    {
        p->r_child = r_insert(p->r_child, key);
    }
 
    // Returning Phase

    p->height = NodeHeight(p);                                                               // Initially Heights are Initialized for every Node.

    if (BalanceFactor(p) == 2 && BalanceFactor(p->l_child) == 1)
            return LLRotation(p);

    else if (BalanceFactor(p) == 2 && BalanceFactor(p->l_child) == -1)
             return LRRotation(p);

    else if (BalanceFactor(p) == -2 && BalanceFactor(p->r_child) == -1)
             return RRRotation(p);

    else if (BalanceFactor(p) == -2 && BalanceFactor(p->r_child) == 1)
            return RLRotation(p);


    return p;

}

// To Use Recursive Insert Function Effectively

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

   // Node* p = root;


    cout << "\nFor Terminating Enter -1" << endl;

    cout << "\nEnter the Elements : " << endl;
    cout << endl;

    while (x != -1)
    {
        cin >> x;
        if (x != -1)
        {
            r_insert(root, x);
        }
    }
}

// Deletion Operation

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

Node* r_delete(Node* p, int key)
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
        p->l_child = r_delete(p->l_child, key);
    }

    else if (key > p->data)
    {
        p->r_child = r_delete(p->r_child, key);
    }

    else
    {
        if (NodeHeight(p->l_child) > NodeHeight(p->r_child))
        {
            q = InPre(p->l_child);
            p->data = q->data;
            p->l_child = r_delete(p->l_child, q->data);                     // After Copying the Data, p->left is considered as root and q is again deleted as its data is copied.
        }

        else
        {
            q = InSucc(p->r_child);
            p->data = q->data;
            p->r_child = r_delete(p->r_child, q->data);                     // After Copying the Data, p->right is considered as root and q is again deleted as its data is copied.
        }
    }

    // Returning Phase

    // 1]Update Height

    p->height = NodeHeight(p);

    // 2]Checking Balance Factor and Performing Rotations if Required.

    if (BalanceFactor(p) == 2 && BalanceFactor(p->l_child) == 1)                             // L1 Rotation
    {  
        return LLRotation(p);
    }

    else if (BalanceFactor(p) == 2 && BalanceFactor(p->l_child) == -1)                      // L-1 Rotation
    {  
        return LRRotation(p);
    }

    else if (BalanceFactor(p) == -2 && BalanceFactor(p->r_child) == -1)                     // R-1 Rotation
    {  
        return RRRotation(p);
    }

    else if (BalanceFactor(p) == -2 && BalanceFactor(p->r_child) == 1)                      // R1 Rotation
    {  
        return RLRotation(p);
    }

    else if (BalanceFactor(p) == 2 && BalanceFactor(p->l_child) == 0)                       // L0 Rotation
    {  
        return LLRotation(p);
    }

    else if (BalanceFactor(p) == -2 && BalanceFactor(p->r_child) == 0)                      // R0 Rotation
    {  
        return RRRotation(p);
    }

    return p;
}




void Inorder(Node* p)
{
    if (p)
    {
        Inorder(p->l_child);
        cout << p->data << " ";
        Inorder(p->r_child);
    }
}



int main()
{

    int choice = 0;

    do
    {
        cout << "\nEnter Choice : " << endl;
        cout << "\n1]Create \n2]Insert \n3]Delete \n4]Inorder Traversal \n5]Tree Height";
        cout << "\n\nChoice :";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            r_create();
            break;
        }

        case 2:
        {
            int x;
            cout << "\nElement : ";
            cin >> x;
            Node* p = root;
            r_insert(p, x);

            break;
        }

        case 3:
        {
            int x;
            cout << "\nElement : ";
            cin >> x;
            Node* p = root;
            r_delete(p, x);
            break;

        }

        case 4:
        {
            cout << "\nInorder : ";
            Inorder(root);
            cout << endl;
            break;
        }

        case 5:
        {
            cout << "\nTree Height : " << NodeHeight(root) << endl;
            break;

        }

        }


    } while (choice > 0);


}
