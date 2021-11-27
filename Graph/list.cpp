#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};
node *head = NULL;
node *p = NULL;

void accept(int data)
{
    node *temp = new node;

    temp->data = data;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
}

void display(node *p)
{
    if (p == NULL)
    {
        cout << "NO DATA!" << endl;
    }
    else
    {
        while (p != NULL)
        {
            cout << p->data << "-->"<< " ";
            p = p->next;
        }
        cout << endl;
    }
}

node *deleten()
{
    p = head;
    while (p->next != NULL && p->next->next != NULL)
    {
        if (p->next->data < p->next->next->data)
        {
            p->next = p->next->next;
        }
        else
            p = p->next;
    }
    // head->next = head->next->next;
    return head;
}

int main()
{

    accept(6);
    accept(5);
    accept(9);
    accept(12);
    accept(8);

    display(head);
    node *z = deleten();
    display(z);
    return 0;
}