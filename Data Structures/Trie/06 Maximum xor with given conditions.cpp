//MAXIMUM XOR WITH GIVEN CONDITIONS

//Return maximum xor of x (query[0]) with elements smaller equal to m (query[1]) from array nums

struct Node{
    Node *links[2];

    bool containKey(int bit){
        return links[bit] != NULL;
    }
    void put(int bit, Node *node){
        links[bit] = node;
    }
    Node *get(int bit){
        return links[bit];
    }
};

class Trie{
private:
    Node *root;

public:
    Trie(){
        root = new Node();
    }
    void insert(int num){
        Node *node = root;
        int bit;
        for(int i=31; i>=0; i--){
            bit = (num >> i) & 1;
            if(!(node->containKey(bit)))
                node->put(bit, new Node());
            node = node->get(bit);
        }
    }
    int getMaxXor(int num){
        Node *node = root;
        int bit, maxXor = 0;
        for(int i=31; i>=0; i--){
            bit = (num >> i) & 1;
            if(node->containKey(!bit)){
                maxXor |= (1 << i);
                node = node->get(!bit);
            }
            else
                node = node->get(bit);
        }
        return maxXor;
    }
};

vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
    sort(nums.begin(), nums.end());
    vector<pair<int, pair<int, int>>> mThenXThenI;
    int m, x, i = 0;
    for(vector<int> xThenM: queries){
        x = xThenM[0];
        m = xThenM[1];
        mThenXThenI.push_back({m, {x, i++}});
    }
    sort(mThenXThenI.begin(), mThenXThenI.end());
    vector<int> ans(queries.size(), 0);
    int numsI = 0;
    Trie *numsDict = new Trie();
    for(pair<int, pair<int, int>> mXI: mThenXThenI){
        m = mXI.first;
        x = mXI.second.first;
        i = mXI.second.second;
        while(numsI < nums.size() and nums[numsI] <= m)
            numsDict->insert(nums[numsI++]);
        if(numsI)
            ans[i] = numsDict->getMaxXor(x);
        else
            ans[i] = -1;
    }
    return ans;
}

//Time complexity: O(nlogn)
//Space complexity: O(n * 32)

//Problem link: https://leetcode.com/problems/maximum-xor-with-an-element-from-array/