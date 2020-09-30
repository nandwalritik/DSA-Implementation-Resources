#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,i,j,k,n;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        vector<int> v(n);
        for(i=0;i<n;i++)
            cin>>v[i];
        vector<int> ans;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(i=0;i<n;i++){
            pq.push(v[i]);
            if(pq.size() > k){
                ans.push_back(pq.top());
                pq.pop();
            }
        }
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        for(auto x:ans)
            cout<<x<<" ";
            cout<<endl;
    }
    return 0;
}
/*
    Sample test case
    Input
    2
    3 3
    2 1 3
    6 3
    2 6 3 12 56 8

    Output
    1 2 3
    2 3 6 8 12 56
*/