#include<cstdio>
#include<iostream>
#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
    int n;
    cin>>n;
    map<pair<int,int>,int>mp;
    for(int i=1;i<=n;i++){
        int tmp;
        int x,y;
        cin>>tmp;
        x=tmp;
        y=tmp;
        while(x%2==0){
            x/=2;
            y--;
        }
        pair<int,int> pii = make_pair(x,y);
        if(mp.find(pii)!=mp.end())mp[pii]++;
        else mp.insert({pii,1});
    }
    int ans=0;
    
    for(auto i:mp){
        int num=i.second;
        ans+=num*(num-1)/2;
    }
    cout<<ans<<endl;

    return;
} 
signed main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}