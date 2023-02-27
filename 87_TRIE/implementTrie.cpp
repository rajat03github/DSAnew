/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

#include <iostream>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26]; // harr node ke 26 A-Z tak child ho stke hain
    bool isTerminal;        // to end a string

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
        int index = word[0] - 'A';
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

    /** Returns if the word is in the trie. */
    bool searchUtil(TrieNode *root, string word)
    {
        // for one word
        // base case
        if (word.length() == 0)
            return root->isTerminal;

        // declare index
        int index = word[0] - 'A';
        TrieNode *child;

        // is present
        if (root->children[index] != NULL)
            child = root->children[index];
        // not present
        else
            return false;

        // recursion for other remaining words
        return searchUtil(child, word.substr(1));
    }

    bool search(string word)
    {
        return searchUtil(root, word);
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool prefixSearch(TrieNode *root, string word)
    {
        // for one word
        // base case
        if (word.length() == 0)
            return true;

        // declare index
        int index = word[0] - 'A';
        TrieNode *child;

        // is present
        if (root->children[index] != NULL)
            child = root->children[index];
        // not present
        else
            return false;

        // recursion for other remaining words
        return prefixSearch(child, word.substr(1));
    }
    bool startsWith(string prefix)
    {
        return prefixSearch(root, prefix);
    }
};