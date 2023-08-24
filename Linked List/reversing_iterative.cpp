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

class LinkedList{
public:
        ListNode* head;
        LinkedList() 
            {head = NULL;}
   void push(int val)  //calling by reference because we need changes in the list
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

    void reverse()
    {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* temp;
        while(curr){
           temp = curr->next;
           curr->next = prev;
           prev = curr;
           curr = temp;
        } 
        head = prev;
    }
    
    void display()
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
};


int main()
{
    LinkedList list;

    list.push(1);
    list.push(2);
    list.push(3);
    list.push(4);
    list.reverse();
    list.display();
    return 0;
}