#include <bits/stdc++.h>
using namespace std;
/*
    time complexity for Trie construction           -> O(n) -> n is total characters in words
    finding character nearest to root with freq 1   -> O(n) -> n is total characters in words
*/
struct Trie
{
    Trie *child[26] = {NULL};
    bool isLeaf = false;
    int cnt = 1;
};

void insert(Trie *root, string s)
{
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        int key = s[i] - 'a';
        if (root->child[key] == NULL)
        {
            root->child[key] = new Trie;
        }else{
            (root->child[key]->cnt)++;
        }
        root = root->child[key];
    }
    root->isLeaf = true;
}
void findPref(Trie *root, string s, vector<string> &ans)
{
    if (root && root->cnt == 1)
    {
        ans.push_back(s);
        return;
    }
    if (root == NULL)
        return;
    for (int i = 0; i < 26; i++)
    {
        if (root->child[i])
        {
            findPref(root->child[i], s + (char)(i + 'a'), ans);
        }
    }
}
int main()
{
    vector<string> v{"geeksgeeks", "geeksquiz", "geeksforgeeks"};
    vector<string> ans;
    int n = v.size();
    Trie *root = new Trie;
    for (int i = 0; i < n; i++)
    {
        insert(root, v[i]);
    }
    for (int i = 0; i < 26; i++)
    {
        string s = "";
        if (root->child[i])
        {
            findPref(root->child[i], s + (char)(i + 'a'), ans);
        }
    }
    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
