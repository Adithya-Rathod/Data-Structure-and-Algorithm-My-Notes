#include <bits/stdc++.h>
using namespace std;

class ListNode
{

public:
    int data;
    ListNode *next;

    // constructor
    ListNode(int val)
    {
        data = val;
        next = NULL;
    }
};

void display(ListNode *head)
{ // taken by value because no need to modify

    ListNode *temp = head; // iterator banaya
                           // directly head ko leke jaate to bhi ho jata because call by value hi hua hai
                           // kuch fark nhi padhta real waale mei
    while (temp!= NULL)
    {
        cout << temp->data << "-";
        temp = temp->next;
    }
    cout << endl;
}

// driver
int main()
{
    return 0;
}