#include<bits/stdc++.h>
using namespace std;
/*
naive approach Time Complexity -> O(m x n)

	m->length of text
	n->length of pattern to be searched
KMP Time Complexity -> O(m+n)

1.) logic -> 
 		whenever we find a mismatch at a index in pattern we look in left part of pattern 
 		that is there any suffix which is also a prefix
 		if there exists a one, then we continue matching from endindex of prefix + 1 
 		else start from 0 again. 

2.) building lps array ->
		j=0,i=1
		int lps[n]
		while(j<n && i<n)
		{
			if(s[i] == s[j]){
				lps[i]=j+1;
				i++;
				j++;
			}else{
				j=lps[j-1];
			}

			if(s[i] != s[j] && j == 0)
				i++;
		}
	lps[x] = y -> indicates that there is a prefix of length y which is also a suffix 
3.) Searching pattern in mainString using lps array
	i -> traverses mainString
	j -> traverses pattern
	n -> mainString length
	m -> pattern length

	i,j = 0,0
	while(i <n && j <m)
		if mainString[i] == pattern[j]
			i+=1
			j+=1
		if(j == m)
			pattern found at i-j
		else if(i < n && mainString[i]!=pattern[j])
			if j!= 0 
				j = lps[j-1]
			else
				i+=1

*/
void kmpSearch(string mainString,string pattern,vector<int> &lps)
{
	int n = mainString.size();
	int m = pattern.size();
	int i=0,j=0;
	while(i<n && j<m)
	{
		if(mainString[i] == pattern[j])
		{
			i++;
			j++;
		}

		if(j == m)
		{
			cout<<"Pattern found at "<<i-j<<endl;
			j=lps[j-1];
		}
		else if(i < n && mainString[i] != pattern[j]){
			if(j!=0)
				j=lps[j-1];
			else
				i++;
		}
	}
}
int main(){  
	string mainString = "ABABDABACDABABCABAB";
	string pattern="ABABCABAB";
	int n = pattern.size();
	int m = mainString.size();
	// cout<<n<<endl;
	// cout<<s<<endl;
	/*Building Prefix Array*/
	vector<int> lps(n,0);
	int j=0,i=1;
	while(i<n && j<n)
	{
		if(pattern[i] == pattern[j]){
			lps[i]=j+1;
			i++;
			j++;
		}else{
			if(j==0)
				i++;
			else
				j=lps[j-1];
		}
	}

	/*For printing lps array*/
	for(auto x:lps)
		cout<<x<<" ";
	cout<<endl;

	/*Searching for pattern In Main String*/
	kmpSearch(mainString,pattern,lps);
	return 0;
}