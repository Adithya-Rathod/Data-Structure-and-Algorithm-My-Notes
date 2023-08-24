#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;
    ListNode(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertAtTheBeggining(ListNode *&head, int val)
{ // called by refernce of the List and val of the node to be added

    ListNode *curr = new ListNode(val); // allocating memory to the new node to be added in the list
    if (head == NULL)
    { // if no node is present at the beginning
        head = curr;
        return;
    }

    curr->next = head; // this new node will point the existing head node
    head = curr;       // new node has become the head node because it is in the beginning now
}

void insertAtAny(ListNode *&head, int val, int n)
{
    ListNode *curr = new ListNode(val); // allocating memory to the new node which is being inserted
    ListNode *pred = head;              // preceeding node to which new node is being added

    if (head == NULL)
    { // If inititally List in empty
        head = curr;
        return;
    }
    if (n == 1)
    { // If insert at poisition 1 then insert at beginning
        curr->next = head;
        return;
    }

    else
    {
        int index = n - 1;                // index to reach the poistion where we r required to add new node
        while (index > 1 && pred != NULL) // index reposition and avoiding reaching the last node
        {
            pred = pred->next; // reaching the preceeding node of at the position where it needs to be inserted
            index--;
        }
        curr->next = pred->next; // pointing the new node to next node which was initially pointed by pred node
        pred->next = curr;       // pointing the pred node to new added node
    }
}

void display(ListNode *head)
{
    while (head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL";
}

int main()
{
    ListNode *head = NULL;
    insertAtTheBeggining(head, 1);
    insertAtTheBeggining(head, 2);
    insertAtTheBeggining(head, 3);
    insertAtTheBeggining(head, 4);
    insertAtAny(head, 10, 5);
    insertAtAny(head, 12, 3);
    display(head);
    return 0;
}