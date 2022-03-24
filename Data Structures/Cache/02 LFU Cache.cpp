//IMPLEMENT LFU CACHE

struct Node{
    int key, val, freq;
    Node *prev, *next;
    Node(int key, int val){
        this->key = key;
        this->val = val;
        freq = 1;
    }
};

class List
{
public:
    int size;
    Node *head, *tail;
    
    List(){
        size = 0;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    void addNode(Node *newNode){
        Node *temp = head->next;

        newNode->next = temp;
        temp->prev = newNode;

        head->next = newNode;
        newNode->prev = head;

        size++;
    }
    void deleteNode(Node *delNode){
        Node *prevNode = delNode->prev;
        Node *nextNode = delNode->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;

        size--;
    }
};

class LFUCache {
private:
    map<int, Node *> keyNodeMap;
    map<int, List *> freqListMap;
    int capacity, currSize, minFreq;

    void updateMaps(Node *node){
        int key = node->key, freq = node->freq;
        List *list;

        if(keyNodeMap.find(key) != keyNodeMap.end()){
            list = freqListMap[freq];
            list->deleteNode(node);

            if(freq == minFreq and list->size == 0)
                minFreq++;

            keyNodeMap.erase(key);
            
            node->freq = ++freq;
        }

        if(freqListMap.find(freq) == freqListMap.end())
            list = new List();
        else
            list = freqListMap[freq];

        list->addNode(node);
        freqListMap[freq] = list;
        keyNodeMap[key] = node;
    }

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        currSize = 0;
        minFreq = 0;
    }
    
    int get(int key) {
        if(keyNodeMap.find(key) == keyNodeMap.end())
            return -1;
        Node *node = keyNodeMap[key];
        updateMaps(node);
        return node->val;
    }
    
    void put(int key, int val) {
        if(capacity == 0)
            return;
        Node *node;
        List *list;
        if(keyNodeMap.find(key) != keyNodeMap.end()){
            node = keyNodeMap[key];
            node->val = val;
            updateMaps(node);
            return;
        }

        if(currSize == capacity){
            list = freqListMap[minFreq];
            node = list->tail->prev;
            list->deleteNode(node);

            keyNodeMap.erase(node->key);

            currSize--;
        }

        minFreq = 1;
        node = new Node(key, val);
        updateMaps(node);

        currSize++;
    }
};

//Time complexity: O(1)
//Space complexity: O(2*n)

//Problem link: https://leetcode.com/problems/lfu-cache/