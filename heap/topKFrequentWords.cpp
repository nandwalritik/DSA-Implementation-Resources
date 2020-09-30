#include<bits/stdc++.h>
using namespace std;
struct Comp{
	bool operator()(const pair<string,int>&a,const pair<string,int>&b){
		return a.second>b.second || (a.second == b.second && a.first<b.first);
	}
};
int main(){
	
}