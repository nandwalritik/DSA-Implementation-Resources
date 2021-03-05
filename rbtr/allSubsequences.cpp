#include<bits/stdc++.h>
using namespace std;
void solve(string ip,string op)
{
	if(ip.size() == 0)
	{
		cout<<op<<endl;
		return;
	}
	string op1,op2;
	op1 = op;
	op2 = op;
	op2.push_back(ip[0]);
	ip.erase(ip.begin());
	solve(ip,op1);
	solve(ip,op2); 
}
int main(){
	string s="aaa";
	// cin>>s;
	string op="";
	solve(s,op);
	return 0;
}