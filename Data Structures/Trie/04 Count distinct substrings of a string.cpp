//COUNT DISTINCT SUBSTRINGS OF A STRING

//If we use a set, the space complexity is O(n^3), therefore we use trie

struct Node{
    Node *links[26];
    bool isWordEnd = false;

    bool containKey(char ch){
        return links[ch - 'a'] != NULL;
    }
    void put(char ch, Node *node){
        links[ch - 'a'] = node;
    }
    Node *get(char ch){
        return links[ch - 'a'];
    }
};

int countDistinctSubstrings(string &s)
{
    Node *root = new Node(), *node;
    int n = s.length(), countDistSub = 1;       //1 for empty substring
    for(int i=0; i<n; i++){
        node = root;
        for(int j=i; j<n; j++){
            if(!(node->containKey(s[j]))){
                node->put(s[j], new Node());
                countDistSub++;
            }
            node = node->get(s[j]);
        }
    }
    return countDistSub;
}

//Time complexity: O(n^2)       -> To generate all substrings
//Space complexity: O(n^2)      -> To store all substrings

//Problem link: https://bit.ly/3ocRQW0
//              https://leetcode.com/problems/number-of-distinct-substrings-in-a-string/