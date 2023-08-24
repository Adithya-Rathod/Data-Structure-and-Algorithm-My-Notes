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

    void display(ListNode* head){
        ListNode* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }


void reverse(ListNode* &head, ListNode* p)
    {
        if(p->next == NULL){
            head = p;
            return;
        }
        reverse(head, p->next);
        ListNode* temp = p->next;
        temp->next = p;
        p->next = NULL;
    }

int main()
{   
    ListNode* head =NULL;
    push(head, 1);
    push(head, 2);
    push(head, 3);
    push(head, 4);
    display(head);
    ListNode* p = head;
    reverse(head, p);
    display(head);
    return 0;
}