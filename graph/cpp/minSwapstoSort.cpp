#include<bits/stdc++.h>
using namespace std;
int minSwaps(int ar[],int n){
    vector<pair<int,int>> p(n);
    for(int i = 0 ; i < n ; i++){
        p[i].first=ar[i];
        p[i].second=i;
    }
    // for(auto x:p)
    //     cout<<x.first<<" "<<x.second<<endl;
    sort(p.begin(),p.end());
    int ans=0;
    vector<bool> vis(n,false);
    for(int i=0;i<n;i++){
        if(vis[i] || p[i].second == i)
            continue;
        int j=i;
        int cycle_sz = 0;
        while(!vis[j]){
            vis[j]=true;
            // cout<<p[j].first<<" ";
            j = p[j].second;

            cycle_sz++;
        }
        // cout<<endl;
        // cout<<cycle_sz<<" ";
        ans+=(cycle_sz-1);
    }
    return ans;
}
int main(){
    int ar[]={5,3,8,32,6,15};
    cout<<minSwaps(ar,sizeof(ar)/sizeof(int))<<endl;
    return 0;
}