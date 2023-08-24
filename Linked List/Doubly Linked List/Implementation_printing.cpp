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
    return 0;
}