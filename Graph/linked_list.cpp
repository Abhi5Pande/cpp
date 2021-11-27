#include<iostream>
using namespace std;
struct node{
    int data;
    struct node* next;
};
struct node* addElem(node* head, int elem)
{
    struct node *p;
    p = head;
    struct node *nodeElem = new node;
    nodeElem->data = elem;
    nodeElem->next = NULL;
    if(head == NULL){
        head = nodeElem;
    }
    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = nodeElem;
}
struct node* modifiedList(node* head)
{
    struct node *p;
    p = head;
    while(p->next->next != NULL)
    {
        if(p == head)
        {
            if(p->data < p->next->data)
            {
                head = p->next;
            }
            p = p->next;
        }
        else{ 
            if(p->next->data < p->next->next->data)
        {
            p->next = p->next->next;
        }
        }
       
    }

}
void printList(node* head)
{
    struct node *p;
    while(p->next != nullptr)
    {
        cout<<p->data<<" -> ";
    }
}
int main()
{
    struct node* head = new node;
    head->next = NULL;
    addElem(head,2);
    addElem(head,3);
    addElem(head,4);
    addElem(head,1);
    addElem(head,6);
    addElem(head,3);
    printList(head);
    return 0;
}