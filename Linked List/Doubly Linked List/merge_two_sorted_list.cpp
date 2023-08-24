#include <bits/stdc++.h>
using namespace std;
#define mINF -1e9
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

class Solution
{
public:
    ListNode *mergeTwoList(ListNode *L1, ListNode *L2)
    {
        if (L1 == NULL)
            return L2;
        if (L2 == NULL)
            return L1;

        ListNode *dummy = new ListNode(mINF);
        ListNode *head = dummy;

        while (L1 != NULL && L2 != NULL)
        {
            if(L1->data < L2->data)
            {
                ListNode *newNode = new ListNode(L1->data);
                dummy->next  = newNode;
                L1= L1->next;
            }
            else
            {
                ListNode* newNode = new ListNode(L2->data);
                dummy->next = newNode;
                L2 = L2->next;
            }
                dummy = dummy->next;
        }
        if(L1 != NULL) dummy->next = L2;
        if(L2 != NULL) dummy->next = L1;
        return head->next;
    }

    ListNode* mergeByReccursion(ListNode *L1, ListNode *L2){
        if (L1 == NULL) return L2;
        if (L2 == NULL) return L1;

        if(L1->data < L2->data){
            L1->next = mergeByReccursion(L1->next, L2);
            return L1;
        }
        else{
            L2->next = mergeByReccursion(L1, L2->next);
            return L2;
        }
    }
};

 void push(ListNode* &head,int val)  //calling by reference because we need changes in the list
        {

            ListNode *curr = new ListNode(val); // allocating a memeory to the new node and to be added and setting its data as 'val' and pointing to NULL(using constructor of the class ListNode)

            if (head == NULL)   //Inititally there weren't any node so head was NULL
            { 
                head = curr;
                return;
            }
            else
            {
                ListNode *temp = head;      //creating a temp node to traverse in the list 
                while (temp->next != NULL)  //all the way to the last element i.e. the node which points NULL
                {
                    temp = temp->next;
                }  
                temp->next = curr;     //ponting the last element of the list to the current node which is to be added
            }
        }

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

int main()
{   
    ListNode* L1, *L2;
    push(L1,1);
    push(L1,2);
    push(L1,3);
    push(L2,1);
    push(L2,3);
    push(L2,4);
    Solution jk;
    ListNode* ans = jk.mergeTwoList(L1, L2);
    ListNode* ans2 = jk.mergeByReccursion(L1, L2);
    display(ans);
    display(ans2);
    return 0;
}