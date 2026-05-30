// #include<stdio.h>
// #include<stdlib.h>


// struct Node{
// 	int key;
// 	struct Node *left;
// 	struct Node *right;
// 	int height;
// };

// int height(struct Node *N){
// 	if(N == NULL)
// 		return 0;
// 	return N->height;
// }

// int max(int a,int b){
// 	return (a > b) ? a : b ;
// }

// struct Node* newNode(int key){
// 	struct Node* node = (struct Node*)malloc(sizeof(struct Node));

// 	node->key 	=	key;
// 	node->left 	=	NULL;
// 	node->right	=	NULL;
// 	node->height=	1;
// 	return node; 
// }

// struct Node *rightRotate(struct Node *y){
// 	struct Node *x 	= y->left;
// 	struct Node *T2	= x->right;

// 	x->right = y;
// 	y->left	 = T2;

// 	x->height = max(height(x->left),height(x->right))+1;
// 	y->height = max(height(y->left),height(y->right))+1;

// 	return y;
// }

// struct Node *leftRotate(struct Node *y){ 
// 	struct Node *x 	= y->right;
// 	struct Node *T2	= x->left; 

// 	x->left  = y;
// 	y->right = T2;

// 	y->height = max(height(x->left),height(x->right))+1;
// 	x->height = max(height(y->left),height(y->right))+1;

// 	return y;
// }

// int getBalance(struct Node *N){
// 	if(N == NULL)
// 		return 0;
// 	return height(N->left) - height(N->right);
// }

// struct Node* insert(struct Node* node,int key){
// 	/*1. Normal BST Insertion	*/
// 	if(node == NULL)
// 		return(newNode(key));
// 	if(key < node->key)
// 		node->left = insert(node->left,key);
// 	else if(key > node->key)
// 		node->right=insert(node->right,key);
// 	else
// 		return node;
// 	/*2. Updating height*/
// 	node->height = 1 + max(height(node->left),height(node->right));
// 	int balance  = getBalance(node);
// 	//left left case
// 	if(balance  > 1 && key < node->left->key)
// 		return rightRotate(node);
// 	//right right case
// 	if(balance < -1 && key > node->right->key)
// 		return leftRotate(node);
// 	//left right case
// 	if(balance > 1 && key > node->left->key){
// 		node->left  =  leftRotate(node->left);
// 		return rightRotate(node);
// 	}
// 	//right left case
// 	if(balance < -1 && key < node->right->key){
// 		node->right = rightRotate(node->right);
// 		return leftRotate(node);
// 	}
// 	return node;
// }
/* Node is defined as :
typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
} node; */

int height(node *root){
    if(root == NULL)
        return -1;
    return 1+max(height(root->left),height(root->right));
}
int getBal(node* root)
{
    if(root==NULL)
        return 0;
    return height(root->left)-height(root->right);
}
node* getNode(int data){
    struct node *newNode = new node();
    newNode->val = data;
    newNode->left = NULL;
    newNode->right=NULL;
    newNode->ht = 0;
    return newNode;
}
node *rotateLeft(node *root)
{
    node *x     = root->right;
    node *temp  = x->left;
    x->left     = root;
    root->right = temp;
    x->ht = height(x);
    root->ht = height(root);
    return x;
}
node *rotateRight(node* root){
    node *x     = root->left;
    node *temp  = x->right;
    x->right    = root;
    root->left  = temp;
    x->ht = height(x);
    root->ht = height(root);
    return x;
}

node * insert(node * root,int val)
{
	if(root == NULL)
        return getNode(val);
    else if(val > root->val)
    {
        root->right = insert(root->right,val);
    }
    else if(val < root->val)
    {
        root->left = insert(root->left,val);
    }
    int bal = getBal(root);
    if(bal > 1)
    {
        if(val < root->left->val)
            return rotateRight(root);
        else if(val > root->left->val){
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }
    }
    else if(bal < -1)
    {
        if(val > root->right->val)
            return rotateLeft(root);
        else
        {
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }
    }
    root->ht = height(root);
    return root;
  
}