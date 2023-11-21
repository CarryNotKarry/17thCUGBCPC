#include <bits/stdc++.h>
#define endl '\n'
#define sup 1<<30
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 4e4+10;

ll n,t,f,m;
ll tcost,fcost,s;

vector<int> edge[maxn];

ll disa[maxn],disb[maxn],disc[maxn];

void dij(ll bg,int num){
    bool vis[maxn];
    for(int i = 0;i<=n;i++){
        if(num == 0) disa[i] = 1e5 + 10;
        if(num == 1) disb[i] = 1e5 + 10;
        if(num == 2) disc[i] = 1e5 + 10;
        vis[i] = 0;
    }
    queue<int> que;
    que.push(bg);
    if(num == 0) disa[bg] = 0;
    if(num == 1) disb[bg] = 0;
    if(num == 2) disc[bg] = 0;
    vis[bg] = true;
    while(!que.empty()){
        int now = que.front();
        que.pop();
        for(auto e: edge[now]){
            if(vis[e]) continue;
            vis[e] = true;
            if(num == 0) disa[e] = disa[now] + 1;
            else if(num == 1) disb[e] = disb[now] + 1;
            else disc[e] = disc[now] + 1;
            que.push(e);
        }
    }
}


int main(){
    cin>>tcost>>fcost>>s;
    cin>>t>>f>>n>>m;
    for(int i = 0;i<m;i++){
        int u,v;
        cin>>u>>v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dij(t,0);
    dij(f,1);
    dij(n,2);
    ll ans = 1e16+10;
    for(int i = 1;i<=n;i++){
        ll res = 1e16+10;
        if(disc[i] < 1e5+10&&disa[i] < 1e5+10&&disb[i] < 1e5+10)
            res = disa[i] * tcost + disb[i] * fcost - disc[i] * s + disc[i] *(tcost + fcost);
        ans = min(ans,res); 
    }
    if(ans == 1e16 + 10) ans = -1;
    cout<<ans<<endl;
    return 0;
}
