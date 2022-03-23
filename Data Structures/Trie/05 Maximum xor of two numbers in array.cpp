//MAXIMUM XOR OF 2 NUMBERS IN AN ARRAY

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
	void insertNum(int num){
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

int findMaximumXOR(vector<int>& nums) {
	Trie *numDict = new Trie();
	for(int num: nums)
		numDict->insertNum(num);
	int maxXor = 0;
	for(int num: nums)
		maxXor = max(maxXor, numDict->getMaxXor(num));
	return maxXor;
}

//Time complexity: O(n*32)
//Space complexity: O(n*32)

//Problem link: https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/