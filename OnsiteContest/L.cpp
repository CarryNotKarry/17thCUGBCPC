#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#define int long long
using namespace std;
void solve(){
    int a,b,c;
    cin>>a>>b>>c;
    int m;
    cin>>m;
    int g1=0,g2=0;
    g1=std::__gcd(a,b);
    g2=std::__gcd(g1,m);
    int ans=c%g2;
    cout<<ans<<endl;   
    return;
}
signed main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}