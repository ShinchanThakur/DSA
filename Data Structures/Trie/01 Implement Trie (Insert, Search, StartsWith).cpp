//IMPLEMENT TRIE (Insert, Search, StartsWith)

struct Node {
    Node *links[26];
    bool isEndFlag = false;

    bool containKey(char ch){
        return links[ch - 'a'] != NULL;
    }
    void put(char ch, Node *node){
        links[ch - 'a'] = node;
    }
    Node *get(char ch){
        return links[ch - 'a'];
    }
    void setEnd() {
        isEndFlag = true;
    }
    bool isEnd() {
        return isEndFlag;
    }
};

class Trie {
private:
    Node *root;

public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *node = root;
        for(char ch: word){
            if(!(node->containKey(ch)))
                node->put(ch, new Node());
            node = node->get(ch);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node *node = root;
        for(char ch: word){
            if(!(node->containKey(ch)))
                return false;
            node = node->get(ch);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node *node = root;
        for(char ch: prefix){
            if(!(node->containKey(ch)))
                return false;
            node = node->get(ch);
        }
        return true;
    }
};

//Time complexity: O(n)     -> n = length of longest word
//Space complexity: O(n * t)    -> t = total words in dictionary

//Problem link: https://leetcode.com/problems/implement-trie-prefix-tree/