//LONGEST STRING WITH ALL PREFIXES

//Return longest string (among them return lexicographically smallest) with all prefixes present in the array

struct Node{
    Node *links[26];
    bool isEndFlag = false;

    bool containKey(char ch){
        return links[ch - 'a'];
    }
    void put(char ch, Node *node){
        links[ch - 'a'] = node;
    }
    Node *get(char ch){
        return links[ch - 'a'];
    }
    void setEnd(){
        isEndFlag = true;
    }
    bool isEnd(){
        return isEndFlag;
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie(){
        root = new Node();
    }

    void insertWord(string word){
        Node *node = root;
        for(char ch: word){
            if(!(node->containKey(ch)))
                node->put(ch, new Node());
            node = node->get(ch);
        }
        node->setEnd();
    }

    bool checkIfAllPrefixesExist(string word){
        Node *node = root;
        for(char ch: word){
            if(!(node->containKey(ch)))
                return false;
            node = node->get(ch);
            if(!(node->isEnd()))
                return false;
        }
        return true;
    }
};

string completeString(int n, vector<string> &words){
    Trie *dictionary = new Trie();
    for(string word: words)
        dictionary->insertWord(word);

    string answer = "";
    for(string word: words){
        if(dictionary->checkIfAllPrefixesExist(word)){
            if((word.length() > answer.length()) or (word.length() == answer.length() and word < answer))
                answer = word;
        }
    }

    if(answer == "")
        answer = "None";
    return answer;
}

//Time complexity: O(n * l)     l->length of word
//Space complexity: O(n * l)

//Problem link: https://bit.ly/3n3kedU