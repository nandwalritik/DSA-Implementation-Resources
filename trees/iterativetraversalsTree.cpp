#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

void postOrder(Node *root)
{
    stack<Node *> st;
    stack<int> out;
    st.push(root);
    while (!st.empty())
    {
        Node *tp = st.top();
        st.pop();
        out.push(tp->data);
        if (tp->left)
        {
            st.push(tp->left);
        }
        if (tp->right)
        {
            st.push(tp->right);
        }
    }
    while (!out.empty())
    {
        cout << out.top() << " ";
        out.pop();
    }
    cout << endl;
}

void inOrder(Node *root)
{
    if (root == nullptr)
        return;
    stack<Node *> st;
    Node *curr = root;
    while (!st.empty() || curr != nullptr)
    {
        if (curr != nullptr)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            curr = st.top();
            st.pop();
            cout << curr->data << " ";
            curr = curr->right;
        }
    }
    cout << endl;
}

void preOrder(Node *root)
{
    if (root == nullptr)
        return;
    stack<Node *> st;
    st.push(root);
    while (!st.empty())
    {
        Node *curr = st.top();
        st.pop();
        cout << curr->data << " ";
        if (curr->right)
        {
            st.push(curr->right);
        }
        if (curr->left)
        {
            st.push(curr->left);
        }
    }
    cout << endl;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);
    cout << "-------------Post Order------------\n";
    postOrder(root);
    cout << "-------------In Order------------\n";
    inOrder(root);
    cout << "-------------Pre Order------------\n";
    preOrder(root);

    return 0;
}