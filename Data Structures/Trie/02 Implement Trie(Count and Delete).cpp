//IMPLEMENT TRIE (COUNT AND DELETE)

struct Node
{
    Node *links[26];
    int cntWordsEndingHere = 0;
    int cntPrefix = 0;

    bool containKey(char ch){
        return links[ch - 'a'] != NULL;
    }
    void put(char ch, Node *node){
        links[ch - 'a'] = node;
    }
    Node *get(char ch){
        return links[ch - 'a'];
    }
    void increaseCntWordsEndingHere(){
        cntWordsEndingHere++;
    }
    void decreaseCntWordsEndingHere(){
        cntWordsEndingHere--;
    }
    int getCntWordsEndingHere(){
        return cntWordsEndingHere;
    }
    void increaseCntPrefix(){
        cntPrefix++;
    }
    void decreaseCntPrefix(){
        cntPrefix--;
    }
    int getCntPrefix(){
        return cntPrefix;
    }
};

class Trie{
private:
    Node *root;

public:

    Trie(){
        root = new Node();
    }

    void insert(string &word){
        Node *node = root;
        for(char ch: word){
            if(!(node->containKey(ch)))
                node->put(ch, new Node());
            node = node->get(ch);
            node->increaseCntPrefix();
        }
        node->increaseCntWordsEndingHere();
    }

    int countWordsEqualTo(string &word){
        Node *node = root;
        for(char ch: word){
            if(!(node->containKey(ch)))
                return 0;
            node = node->get(ch);
        }
        return node->getCntWordsEndingHere();
    }

    int countWordsStartingWith(string &word){
        Node *node = root;
        for(char ch: word){
            if(!(node->containKey(ch)))
                return 0;
            node = node->get(ch);
        }
        return node->getCntPrefix();
    }

    void erase(string &word){
        Node *node = root;
        for(char ch: word){
            if(!(node->containKey(ch)))
                return;
            node = node->get(ch);
            node->decreaseCntPrefix();
        }
        node->decreaseCntWordsEndingHere();
    }
};

//Time complexity: O(n)     n-> length of word
//Space complexity: O(n * x)    x-> total words in dictionary

//Problem link: https://www.codingninjas.com/codestudio/problems/implement-trie_1387095?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos
//              https://leetcode.com/problems/implement-trie-ii-prefix-tree/