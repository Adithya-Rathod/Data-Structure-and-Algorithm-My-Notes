/*
Floyd’s cycle finding algorithm or Hare-Tortoise algorithm is a pointer algorithm
that uses only two pointers, moving through the sequence at different speeds.
This algorithm is used to find a loop in a linked list. It uses two pointers one
 moving twice as fast as the other one. The faster one is called the fast pointer
 and the other one is called the slow pointer.

**How Does Floyd’s Cycle Finding Algorithm Works?

While traversing the linked list one of these things will occur-

1. The Fast pointer may reach the end (NULL) this shows that there is no loop in the
    linked list.
2. The Fast pointer again catches the slow pointer at some time therefore a loop
    exists in the linked list.
*/

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

class LinkedList
{
    ListNode *head = NULL;

public:
    void insert(int val)
    {
        ListNode *cur = new ListNode(val);
        if (head == NULL)
            head = cur;
        else
        {
            cur->next = head;
            head = cur;
        }
    }
    void print()
    {
        if (head == NULL)
            return;
        else
        {
            ListNode *curr = head;
            while (curr != NULL)
            {
                cout << curr->data<<" ";
                curr = curr->next;
            }
        }
    }
    bool detectLoop()
    {
        ListNode *slowPointer = head,
                 *fastPointer = head;

        while (slowPointer != NULL && fastPointer != NULL && fastPointer->next != NULL)
        {
            slowPointer = slowPointer->next;
            fastPointer = fastPointer->next->next;
            if (slowPointer == fastPointer)
                return 1;
        }

        return 0;
    }
};

int main()
{
    LinkedList li;
    li.insert(1);
    li.insert(2);
    li.insert(5);
    li.insert(4);
    li.insert(3);
    li.insert(8);
    li.print();
    cout << li.detectLoop();
    return 0;
}