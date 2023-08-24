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

void insertAtEnd(DLLNode *&head, int val)
{
    DLLNode *curr = new DLLNode(val);
    DLLNode *temp = head;
    if (head == NULL)
    {
        head = curr;
        return;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp=temp->next;
        }
        temp->next = curr;
        curr->prev = temp;
        return;
    }
}
// for printing
void display(DLLNode *head)
{
    cout<<"NULL <- ";
    while (head != NULL)
    {
        cout << head->data << " <-> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main()
{   
    DLLNode* head = NULL;
    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);
    insertAtEnd(head, 5);
    display(head);
    return 0;
}