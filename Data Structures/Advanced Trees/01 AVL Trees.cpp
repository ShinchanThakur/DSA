//AVL TREES
//AVL tree is a self-balancing Binary Search Tree (BST) 
//where the difference between heights of left and right subtrees 
//cannot be more than one for all nodes. 

//WHY
//AVL trees height = log(n)
//This will ensure that every (almost) operation on BST is of O(logn)

//INSERTION

 //     y                               x
 //    / \     Right Rotation          /  \
 //   x   T3   - - - - - - - >        T1   y 
 //  / \       < - - - - - - -            / \
 // T1  T2     Left Rotation            T2  T3

//CASES

// 1. Left-left

//          z                                      y 
//         / \                                   /   \
//        y   T4      Right Rotate (z)          x      z
//       / \          - - - - - - - - ->      /  \    /  \ 
//      x   T3                               T1  T2  T3  T4
//     / \
//   T1   T2

// 2. Left-right

//      z                               z                           x
//     / \                            /   \                        /  \ 
//    y   T4  Left Rotate (y)        x    T4  Right Rotate(z)    y      z
//   / \      - - - - - - - - ->    /  \      - - - - - - - ->  / \    / \
// T1   x                          y    T3                    T1  T2 T3  T4
//     / \                        / \
//   T2   T3                    T1   T2

// 3. Right-right

//   z                                y
//  /  \                            /   \ 
// T1   y     Left Rotate(z)       z      x
//     /  \   - - - - - - - ->    / \    / \
//    T2   x                     T1  T2 T3  T4
//        / \
//      T3  T4

// 4. Right-left

//    z                            z                            x
//   / \                          / \                          /  \ 
// T1   y   Right Rotate (y)    T1   x      Left Rotate(z)   z      y
//     / \  - - - - - - - - ->     /  \   - - - - - - - ->  / \    / \
//    x   T4                      T2   y                  T1  T2  T3  T4
//   / \                              /  \
// T2   T3                           T3   T4

struct Node
{
    int data, height;
    Node *left, *right;
    Node(int x) {
    	data = x;
    	left = right = NULL;
    	height = 1;
    }
};

class AVL{
private:
	Node *root;
	int findHeight(Node *curr){
		if(curr == NULL)	return 0;
		int height, rightHeight = 0, leftHeight = 0;
		if(curr -> right)	rightHeight = curr -> right -> height;
		if(curr -> left)	leftHeight = curr -> left -> height;
		height = 1 + max(rightHeight, leftHeight);
		return height;
	}

	int findBalance(Node *curr){
		if(curr == NULL)	return 0;
		int rightHeight = findHeight(curr -> right);
		int leftHeight = findHeight(curr -> left);
		return leftHeight - rightHeight;
	}

//     y     rightRotate         x
//    /     -------------->       \
//   x                             y
//    \     <--------------       /
//     w      leftRotate         w
	Node* rightRotate(Node *y){
		Node *x = y -> left;
		Node *w = x -> right;

		x -> right = y;
		y -> left = w;

		//This order matters
		y -> height = findHeight(y);
		x -> height = findHeight(x);

		return x;
	}

	Node* leftRotate(Node *x){
		Node *y = x -> right;
		Node *w = y -> left;

		y -> left = x;
		x -> right = w;

		//This order matters
		x -> height = findHeight(x);
		y -> height = findHeight(y);

		return y;
	}

  public:
  	AVL(){
  		root = NULL;
  	}
    Node* insert(Node* curr, int key)
    {
        if(curr == NULL)
        	return (new Node(key));
        if(key < curr -> data)
        	curr -> left = insert(curr -> left, key);
        else if(key > curr -> data)
        	curr -> right = insert(curr -> right, key);
        else
        	return curr;

        curr -> height = findHeight(curr);

        int balance = findBalance(curr);

        if(balance > 1){
        	if(key < curr -> left -> data){
        		//Left-left
        		curr = rightRotate(curr);
        	}
        	else{
        		//Left-right
        		curr -> left = leftRotate(curr -> left);
        		curr = rightRotate(curr);
        	}
        }
        else if(balance < -1){
        	if(key > curr -> right -> data){
        		//Right-right
        		curr = leftRotate(curr);
        	}
        	else{
        		//Right-left
        		curr -> right = rightRotate(curr -> right);
        		curr = leftRotate(curr);
        	}
        }

        return curr;
    }
};

//Time complexity: O(log(n))
//Space complexity: O(1)

//Problem link: https://practice.geeksforgeeks.org/problems/avl-tree-insertion/1/

//COMPARISON
// 1. The AVL trees are more balanced compared to Red-Black Trees, 
// but they may cause more rotations during insertion and deletion.
// 2. So if your application involves many frequent insertions and deletions, 
// then Red Black trees should be preferred.
// 3. And if the insertions and deletions are less frequent and search is the more frequent operation, 
// then AVL tree should be preferred over Red Black Tree.