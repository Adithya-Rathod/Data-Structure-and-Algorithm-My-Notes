#include<bits/stdc++.h>
using namespace std;

class ListNode{
public:
    int data;
    ListNode *next;
    //constructor
    ListNode(int val){
        data =val;
        next = NULL;
    }
};

void insertAtTheBeggining(ListNode *&head, int val){    //called by refernce of the List and val of the node to be added

    ListNode *curr = new ListNode(val);    //allocating memory to the new node to be added in the list
    if(head == NULL){   //if no node is present at the beginning
        head = curr;
        return;
    }

    curr->next = head;  //this new node will point the existing head node
    head = curr;    //new node has become the head node because it is in the beginning now
}

//For printing the List
void display(ListNode *head)
{
    while (head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout<<"NULL";
}


//Driver code
int main(){

    ListNode *head = NULL;
    insertAtTheBeggining(head, 1);
    insertAtTheBeggining(head, 2);
    insertAtTheBeggining(head, 3);
    insertAtTheBeggining(head, 4);
    display(head);
    return 0;
}