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

    Trie()
    {
        root = new TrieNode('\0'); // null diya hai abhi start mei
    }

    // insertion
    // util
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

    // word
    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    // SEARCHING

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

    bool searchWord(string word)
    {
        return searchUtil(root, word);
    }
};

int main()
{
    Trie *t = new Trie();

    t->insertWord("ABCD");
    cout << "presnt or Not " << t->searchWord("ABC");
    return 0;
}