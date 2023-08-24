#include <bits/stdc++.h>
using namespace std;

class DLLNode
{
public:
    int data;
    DLLNode *next;
    DLLNode *prev;
    DLLNode(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

void insertAtAny(DLLNode *&head, int val, int n)
{

    DLLNode *curr = new DLLNode(val);
    DLLNode *temp = head;
    if (head == NULL && n<1)
    {
        head = curr;
        return;
    }
    if(n == 1){
        head->prev = curr;
        curr->next = head;
        head = curr;
        return;
    }
    else
    {
        int index = n - 1;
        while (index > 1 && temp->next !=NULL){
            index--;
            temp=temp->next;
        }
        if(index>1)
            return;
        curr->next = temp->next;
        curr->prev = temp; 
        if(temp->next)
             temp->next->prev = curr;
        temp->next = curr;
        return;

    }
}
void display(DLLNode *head)
{
    cout << "NULL <- ";
    while (head != NULL)
    {
        cout << head->data << " <-> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main()
{   
    DLLNode* head =NULL;
    insertAtAny(head, 1, 0);
    insertAtAny(head, 2, 1);
    insertAtAny(head, 3, 2);
    insertAtAny(head, 4, 3);
    insertAtAny(head, 10, 2);
    insertAtAny(head, 33, 1);
    display(head);
    return 0;
}