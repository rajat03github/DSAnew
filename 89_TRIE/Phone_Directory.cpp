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
    }
};

class Trie
{

public:
    TrieNode *root;
    /** Initialize your data structure here. */
    Trie()
    {
        root = new TrieNode('\0');
    }

    /** Inserts a word into the trie. */
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
            root->children[index] = child;
        }

        // recursion
        insertUtil(child, word.substr(1)); // next word ke lie
    }

    void insert(string word)
    {
        insertUtil(root, word);
    }

    void printSuggestions(TrieNode *curr, vector<string> &temp, string prefix)
    {
        // base case
        if (curr->isTerminal)
        {
            temp.push_back(prefix);
        }

        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            // check if it is curr child or not
            TrieNode *next = curr->children[ch - 'a'];

            if (next != NULL) // child exits
            {
                prefix.push_back(ch);
                // call recursive now
                printSuggestions(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> getSuggestions(string str)
    {
        TrieNode *prev = root;
        vector<vector<string>> output;
        string prefix = "";

        for (int i = 0; i < str.length(); i++)
        {
            char lastchr = str[i];

            prefix.push_back(lastchr);

            // check for lastch
            TrieNode *curr = prev->children[lastchr - 'a'];

            // if not found
            if (curr == NULL)
                break;

            // if found
            vector<string> temp;
            printSuggestions(curr, temp, prefix);

            output.push_back(temp);
            temp.clear();
            prev = curr;
        }
        return output;
    }
};

vector<vector<string>> phoneDirectory(vector<string> &contactList, string &queryStr)
{
    // creation of trie
    Trie *t = new Trie();

    // insert all contact in trie
    for (int i = 0; i < contactList.size(); i++)
    {
        string ctc = contactList[i];
        t->insert(ctc);
    }

    // return ans

    return t->getSuggestions(queryStr);
}