#include <bits/stdc++.h>
using namespace std;
class ListNode
{
public:
    int data;       // data value
    ListNode *next; // pointer to next node
};

void display(ListNode *head)
{ // taken by value because no need to modify

    ListNode *temp = head; // iterator banaya
                           // directly head ko leke jaate to bhi ho jata because call by value hi hua hai
                           // kuch fark nhi padhta real waale mei
    while (temp!= NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout <<"NULL"<<endl;
}

int legth(ListNode *head)
{
    ListNode *cur = head;

    int count = 0;
    for (cur = head; cur != nullptr; cur = cur->next)
    {
        count++;
    }

    return count;
}

int main()
{

    return 0;
}