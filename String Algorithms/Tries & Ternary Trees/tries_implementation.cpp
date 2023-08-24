#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    unordered_map<char, TrieNode*> children; //will contain the data character which will point to the next childrern node
    bool isEndOfWord;
    TrieNode()
    {
        isEndOfWord = false;
    }
};

class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        if(root==NULL)
            root->isEndOfWord = true;
        TrieNode *curr = root;

        for(char c: word)
        {
            if(curr->children.find(c) == curr->children.end())
            {
                curr->children[c] = new TrieNode();
            }

            curr = curr->children[c];
        }
        curr->isEndOfWord=true;
    }

    bool search(string word)
    {
        TrieNode *curr = root;
        for(char c: word)
        {
            if(curr->children.find(c) == curr->children.end())
                return false;
            
            curr = curr->children[c];
        }

        return curr->isEndOfWord; //kyyki agar akhir tak aagaya matlab milgaya na word so uska endofword true hi rahega

    }

};
int main()
{
    Trie apna;
    apna.insert("and");
    apna.insert("ant");
    apna.insert("any");
    apna.insert("andy");
    apna.insert("anymy");
    cout<<apna.search("andy")<<endl;
    cout<<apna.search("and")<<endl;
    cout<<apna.search("anderson")<<endl;
    return 0;
}