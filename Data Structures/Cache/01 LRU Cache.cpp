//IMPLEMENT LRU CACHE

class LRUCache {

private:
    struct Node{
        int key, val;
        Node *prev, *next;
        Node(int key, int val){
            this->key = key;
            this->val = val;
        } 
    };

    int capacity;
    Node *head, *tail;
    unordered_map<int, Node *> keyNodeMap;

    void addNode(Node *newNode){
        Node *temp = head->next;
        newNode->next = temp;
        temp->prev = newNode;
        head->next = newNode;
        newNode->prev = head;
    }

    void deleteNode(Node *delNode){
        Node *prevNode = delNode->prev;
        Node *nextNode = delNode->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int _key) {
        if(keyNodeMap.find(_key) == keyNodeMap.end())
            return -1;
        Node *node = keyNodeMap[_key];

        keyNodeMap.erase(_key);
        deleteNode(node);

        addNode(node);
        keyNodeMap[_key] = head->next;

        return node->val;
    }
    
    void put(int _key, int _val) {
        Node *node;
        if(keyNodeMap.find(_key) != keyNodeMap.end()){
            node = keyNodeMap[_key];
            keyNodeMap.erase(_key);
            deleteNode(node);
        }
        if(keyNodeMap.size() == capacity){
            node = tail->prev;
            keyNodeMap.erase(node->key);
            deleteNode(node);
        }
        node = new Node(_key, _val);
        addNode(node);
        keyNodeMap[_key] = node;
    }
};

//Time complexity: O(1)
//Space complexity: O(2*n)

//Problem link: https://leetcode.com/problems/lru-cache/