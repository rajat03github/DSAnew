#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    char data;
    bool isTerminal;
    int childcount;
    TrieNode *children[26];

    // constructor
    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;

        // starting mei false hoga string ka end-char
        isTerminal = false;
        childcount = 0;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie(char ch)
    {
        root = new TrieNode(ch);
    }
    void insertUtil(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            // last node ko terminal banadao fir
            root->isTerminal = true;
            return;
        }
        // assumption that characters are in CAPS
        // index banaya hai
        int index = word[0] - 'a';
        TrieNode *child;

        // present of index of that word in Children array
        if (root->children[index] != NULL)
            child = root->children[index];
        else
        { // absent
            child = new TrieNode(word[0]);
            root->childcount++;
            root->children[index] = child;
        }

        // recursion
        insertUtil(child, word.substr(1)); // next word ke lie
    }

    void insert(string word)
    {
        insertUtil(root, word);
    }

    void lcp(string str, string &ans)
    {
        for (int i = 0; i < str.length(); i++)
        {
            char ch = str[i];

            if (root->childcount == 1)
            {
                ans.push_back(ch);
                // /aage badh jao
                int index = ch - 'a';
                root = root->children[index];
            }
            else
            {
                break;
                ;
            }
            if (root->isTerminal)
            {
                break;
            }
        }
    }
};

string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    Trie *t = new Trie('\0');

    // insert kardo all strings into Trie
    for (int i = 0; i < n; i++)
    {
        t->insert(arr[i]);
    }
    string first = arr[0];
    string ans = "";

    t->lcp(first, ans);
    return ans;
}
