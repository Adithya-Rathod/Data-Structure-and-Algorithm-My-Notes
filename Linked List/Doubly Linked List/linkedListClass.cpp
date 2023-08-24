#include <iostream>
using namespace std;
template <typename T>
class node
{
    T val;
    node *next;

public:
    node(T data)
    {
        this->val = data;
        this->next = NULL;
    }

    class LinkedList
    {
        node<T> *head;

    public:
        LinkedList()
        {
            head = NULL;
        }

        void insert(T data);
        void deleteNode(T position);
        void print();
    };
};


int main()
{

   
    l1.insert(4);
    return 0;
}