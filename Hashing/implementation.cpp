#include <bits/stdc++.h>
using namespace std;

class HashTable
{
private:
    vector<list<int>> table;
    int size;

public:
    HashTable(int tableSize)
    {
        size = tableSize;
        table.resize(size);
    }

    int hashFunction(int key)
    {
        return key % size;
    }

    bool find(int key)
    {
        for(auto every : table[hashFunction(key)])
        {
            if(every == key)
                return true;
        }
        return false;
    }
    
    void insert(int key)
    {
        table[hashFunction(key)].push_back(key);
    }

    void remove(int key)
    {
        table[hashFunction(key)].remove(key);
    }

    void display()
    {
        cout<<"KEY"<<" "<<"VALUE"<<endl;
        int index=0;
        for(auto it : table)
        {
            cout<<index<<" ";
            for(auto k: it)
            {
                cout<<k<<" ";
            }
            index++;
            cout<<endl;
        }
    }
};
int main()
{

    return 0;
}