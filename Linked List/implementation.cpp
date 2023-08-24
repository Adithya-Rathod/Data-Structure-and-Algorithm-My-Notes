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
     void swapPairs() {
       if(head==NULL||head->next==NULL)
       {
           return;
       }
        ListNode *dummy = new ListNode(0);
        dummy->next= head;
        ListNode *curr = head;
        ListNode * prev = dummy;
        while(curr!=NULL || curr->next!=NULL)
        {
            ListNode *temp = curr->next;
            curr->next = temp->next;
            temp->next = curr;
            prev->next= temp;
            prev = prev->next;
            curr =curr->next;
       } 
    }

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
};

int main()
{
    LinkedList ll;
    ll.insert(1);
    ll.insert(2);
    ll.insert(3);
    ll.insert(4);
    string s;
    ll.print();
    cout<<endl;
    ll.swapPairs();
    ll.print();
    cout<< endl;
    return 0;
}