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

void insertAtEnd(ListNode *&head, int val) // calling by reference because we need changes in the list
{

    ListNode *curr = new ListNode(val); // allocating a memeory to the new node and to be added and setting its data as 'val' and pointing to NULL(using constructor of the class ListNode)

    if (head == NULL) // Inititally there weren't any node so head was NULL
    {
        head = curr;
        return;
    }
    else
    {
        ListNode *temp = head;     // creating a temp node to traverse in the list
        while (temp->next != NULL) // all the way to the last element i.e. the node which points NULL
        {
            temp = temp->next;
        }
        temp->next = curr; // ponting the last element of the list to the current node which is to be added
    }
}

void deleteAtAny(ListNode *&head, int n)
{
    ListNode *temp = head;  
    ListNode *pred;

    if (n == 1)     //if first node is to be deleted 
    {
        head = head->next;
        delete temp;
        return;
    }

    int index = n ;     //deleting the nth node
    while (index > 1 && temp != NULL)
    {   
        pred = temp;    //will reach node previous to the deleting node
        temp=temp->next;    //will reach the node which is to be deleted
        index--;        
    }

    pred->next = temp->next;    //pointer of the previous node equals to the pointer of the deleting node 
    delete temp;    //deallocate 

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

// driver funtion
int main()
{
    ListNode *head = NULL;
    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);

    deleteAtAny(head, 2);
    display(head);
    return 0;
}