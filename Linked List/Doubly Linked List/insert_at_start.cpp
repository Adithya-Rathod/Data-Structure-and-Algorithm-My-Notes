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

void insertAtStart(DLLNode *&head, int val)
{
    DLLNode *curr = new DLLNode(val);
    if(head == NULL)
        {head = curr;
        return;
    }
    curr->prev = NULL;
    head->prev = curr;
    curr->next = head;
    head = curr;

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
    insertAtStart(head, 1);
    insertAtStart(head, 2);
    insertAtStart(head, 3);
    insertAtStart(head, 4);
    insertAtStart(head, 5);
    display(head);
    return 0;
}