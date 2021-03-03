#include<bits/stdc++.h>
using namespace std;
/*Calculating Hash value of string*/
/*
	 Σ asciiValOfChar * (primeNo^indexOfChar)
	 for calculating next value
	 1. substract prev index
	 2. divide by prime number
	 3. add next value 




*/
int rollingHash(string s,int start,int end,int prime)
{
	int hash=0;
	for(int i=start;i<=end;i++)
	{
		int val = int(s[i]);
		// cout<<val<<" "<<s[i]<<endl;
		hash = hash + val*(pow(prime,i-start));
		// cout<<hash<<" ";
	}
	// cout<<endl;
	return hash;
}
int rollingHashnxt(char prev,char next,int prime,int currHash,int n){
	int val1=int(prev),val2=int(next);
	currHash -= val1;
	currHash/=prime;
	currHash += (val2 * (pow(prime,n-1)));
	return currHash;
}
int main(){
	string pattern = "abc";
	string s = "abedabc";
	int ans = rollingHash(pattern,0,pattern.size()-1,3);
	cout<<ans<<endl;
	int n = pattern.size();
	int m = s.size();
	int patHash = rollingHash(pattern,0,n-1,3);
	cout<<patHash<<endl;
	int hash;
	char prev=s[0];
	for(int i=0;i<m-n+1;i++)
	{
		if(i == 0)
		{
			hash = rollingHash(s,i,n-1,3);
		}
		else{
			hash = rollingHashnxt(prev,s[i+n-1],3,hash,n);
		}
		prev=s[i];
		// cout<<s.substr(i,n)<<" "<<hash<<endl;
		if(hash == patHash)
		{
			int k1=0,k2=i;
			while(k1<n)
			{
				if(pattern[k1] == s[k2])
				{
					k1++;
					k2++;
				}
			}
			if(k1==n)
				cout<<"Pattern found at "<<i<<endl;
		}
	}

	return 0;
}