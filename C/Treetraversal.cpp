#include <iostream>
#include <stdlib.h>
using namespace std;

struct st
{
    int data;
    struct st *left;
    struct st *right;
};

class Tree_traversal
{
public:
    struct st *root = NULL, *temp;
    void insertElements();
    void preorder(struct st *);
    void inorder(struct st *);
    void postorder(struct st *);
};

void Tree_traversal::insertElements()
{
    struct st *nc, *pNode;
    int v;
    cout << "\n enter the value ";
    cin >> v;
    temp = new st;
    temp->data = v;
    temp->left = NULL;
    temp->right = NULL;
    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        nc = root;
        while (nc != NULL)
        {
            pNode = nc;
            if (v < nc->data)
                nc = nc->left;
            else
                nc = nc->right;
        }
        if (v < pNode->data)
        {
            pNode->left = temp;
        }
        else
            pNode->right = temp;
    }
}
void Tree_traversal::preorder(struct st *temp)
{
    if (temp != NULL)
    {
        cout << " " << temp->data;
        preorder(temp->left);
        preorder(temp->right);
    }
}

void Tree_traversal::inorder(struct st *temp)
{
    if (temp != NULL)
    {
        inorder(temp->left);
        cout << " " << temp->data;
        inorder(temp->right);
    }
}

void Tree_traversal::postorder(struct st *temp)
{
    if (temp != NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        cout << " " << temp->data;
    }
}

int main()
{
    Tree_traversal t;
    struct st *root = NULL, *temp;
    int ch;
    while (1)
    {
        cout << "\n 1.insert Elements \n 2.preorder \n 3.inorder \n 4.postorder \n5.exit";
        cout << "\n enter ur choice ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            t.insertElements();
            break;
        case 2:
            t.preorder(root);
            break;
        case 3:
            t.inorder(root);
            break;
        case 4:
            t.postorder(root);
            break;
        case 5:
            exit(1);
            break;
        default:
            cout << "invalid operation";
        }
    }
}