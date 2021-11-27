// #include<iostream>
// using namespace std;
// class Tree
// {
//     int data;
//     Tree* leftChild;
//     Tree* rightChild;
//     Tree *root = NULL;
//     public:
//     void AddNode(int data )
//     {
//         Tree * temp;
//         Tree *p;
//         temp = new Tree;  
//         p = root;
//         temp->data = data;
//         temp->leftChild = NULL;
//         temp->rightChild = NULL;
//         if(root == NULL)
//             {
//                 root = temp;
//             }
//         else
//         {
//             while(p != NULL)
//             {
            
        
//                 if(temp->data <= p->data && p->leftChild == NULL)
//                 {
//                      p->leftChild = temp;
//                      return;
//                 }
//                 else if(temp->data > p->data && p->rightChild == NULL)
//                 {
//                     p->rightChild = temp;
//                     return;
//                 }
//                 else if(temp->data <= p->data)
//                 {
//                     p = p->leftChild;
//                 }
//                 else if(temp->data > p->data )
//                 {
//                     p = p->rightChild;
//                 }
            
            
//             }

//         }
//     }
//     void print()
//     {
//         printInOrder(root);
//     }
//     void printInOrder(Tree * p)
//     {
//         if(p == NULL)
//             return;
//         else{
//             printInOrder(p->leftChild);
//         cout<<p->data;
//         cout<<" ";
//         printInOrder(p->rightChild);
//         }
        
//     }

// };
// int main()
// {
// Tree t;
// t.AddNode(5);
// t.AddNode(4);
// t.AddNode(2);
// t.AddNode(3);
// t.AddNode(7);
// t.print();

// }
#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};
node *root = NULL;
node *p = NULL;

void create(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    if (root == NULL)
    {
        root = temp;
        cout << "ROOT inserted!" << endl;
    }
    else
    {
        p = root;
        while (p != NULL)
        {
            if (p->data == temp->data)
            {
                cout << "Data already exists!" << endl;
                return;
            }
            else if (temp->data < p->data && p->left == NULL)
            {
                p->left = temp;
                cout << p->data << " ---> " << p->left->data << "    | Node inserted at left! " << endl;
                break;
            }
            else if (temp->data < p->data)
            {
                p = p->left;
            }
            else if (temp->data > p->data && p->right == NULL)
            {
                p->right = temp;
                cout << p->data << " ---> " << p->right->data << "   | Node inserted at right! " << endl;
                break;
            }
            else
            {
                p = p->right;
            }
        }
    }
}

void inorder(node *p)
{
    if (p == NULL)
    {
        return;
    }
    else
    {
        inorder(p->left);
        cout << p->data << " ";
        inorder(p->right);
    }
}

void preorder(node *p)
{
    if(p==NULL)
    {
        return;
    }
    else
    {
        cout<<p->data<<" ";
        preorder(p->left);
        preorder(p->right);
    }
}

void postorder(node *p)
{
    if (p==NULL)
    {
        return;
    }
    else
    {
        postorder(p->left);
        postorder(p->right);
        cout<<p->data<<" ";
    }

}

int main()
{
    create(34);
    create(65);
    create(12);
    create(1);
    create(100);
    create(24);
    create(77);

    cout<<"<< ROOT -> LEFT -> RIGHT >> PREORDER: ";
    preorder(root);
    cout<<endl;

    cout<<"<< LEFT -> ROOT -> RIGHT >> INORDER: ";
    inorder(root);
    cout<<endl;

    cout<<"<< LEFT -> RIGHT -> ROOT >>POSTORDER: ";
    postorder(root);
    cout<<endl;
    return 0;
}