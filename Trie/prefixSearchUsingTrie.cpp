#include<bits/stdc++.h>
using namespace std;

struct TrieNode
{
	struct TrieNode *children[26];
	int wc = 0;
	bool isLeaf;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode *getNewNode()
{
	struct TrieNode *pNode = new TrieNode;
	if(pNode)
	{
		int i;
		pNode->isLeaf = false;
		for(i=0;i<26;i++)
		{
			pNode->children[i] = NULL;
		}
	}
	return pNode;
}

void insert(struct TrieNode *root,string key)
{
	int length = key.size();
	int index;
	struct TrieNode *pCrawl = root;
	for(int level = 0 ; level < length ; level++)
	{
		index = key[level]-'a';
		if(pCrawl->children[index] == NULL)
			pCrawl->children[index] = getNewNode();
		pCrawl = pCrawl->children[index];
	}
	
	/*last node must be marked as leaf*/
	pCrawl->isLeaf = true;
}
/* This Functions counts and returns the number of children of current node*/
int countChildren(struct TrieNode *node,int *index)
{
	int count=0;
	for(int i=0;i<26;i++)
	{
		if(node->children[i] != NULL)
		{
			count++;
			*index = i;
		}
	}
	return count;
}

/*this function performs walk on tree and returns the longest common prefix string*/
string walkTrie(struct TrieNode* root)
{
	struct TrieNode *pCrawl = root;
	int index;
	string prefix;

	while(countChildren(pCrawl,&index) == 1 && pCrawl->isLeaf == false)
	{
		pCrawl = pCrawl->children[index];
		prefix.push_back('a'+index);
	}
	return prefix;
}

/* A functions to construct Trie*/
void constructTrie(string ar[],int n,struct TrieNode *root)
{
	for(int i=0;i<n;i++)
		insert(root,ar[i]);
	return ;
}

/* This function returns LCP from array of Strings*/
string commonPrefix(string ar[],int n)
{
	struct TrieNode *root = getNewNode();
	constructTrie(ar,n,root);
	return walkTrie(root);
}

int main()
{
	string ar[] = {"geeksforgeeks", "geeks", 
                    "geek", "geezer"};
      int n = sizeof(ar)/sizeof(ar[0]);
      string ans = commonPrefix(ar,n);
      if(ans.size())
      	cout<<ans<<endl;
      else
      	cout<<"NA"<<endl;
	return 0;
}
