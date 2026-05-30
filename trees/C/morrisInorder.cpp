#include<bits/stdc++.h>
using namespace std;
/*
    find inorder predeccesor of current node
    make right pointer to point to current node
    
    if current does not have left child
        print(data)
        curr = curr->right
    else
        find InorderPred
        if(inordPred == current)
            update right as null
            print(data)
            current=current->right
        else
            pre->right = current
            current=current->left
*/
struct Tree{
    int data;
    struct Tree* left;
    struct Tree* right;
};

struct Tree* newtNode(int data)
{
    struct Tree* node = new Tree();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return (node);
}
void morrisTrav(Tree *root){
    if(root == NULL)
        return;
    struct Tree *curr,*pred;
    curr = root;
    while(curr != NULL)
    {
        if(curr->left == NULL){
            cout<<curr->data<<endl;
            curr = curr->right;
        }
        else{
            pred = curr->left;
            while(pred->right!=NULL && pred->right!=curr){
                pred=pred->right;
            }
            if(pred->right == NULL){
                pred->right=curr;
                curr=curr->left;
            }
            else{
                pred->right = NULL;
                cout<<curr->data<<endl;
                curr = curr->right;
            }
        }
    }

}
int main(){
    struct Tree* root = newtNode(1);
    root->left = newtNode(2);
    root->right = newtNode(3);
    root->left->left = newtNode(4);
    root->left->right = newtNode(5);
    morrisTrav(root);
    return 0;
}