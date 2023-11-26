//>>>Qiansui
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define mem(x,y) memset(x, y, sizeof(x))
#define debug(x) cout << #x << " = " << x << '\n'
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = "<< y << '\n'
//#define int long long

using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pull;
typedef pair<double, double> pdd;
/*

*/
const int N = 5e2 + 5, inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f, mod = 998244353;
ll n, m, a[N];

struct DSU{
    int num;
    vector<int> fa;
    DSU(int x = 5e2 + 5) : num(x), fa(x + 1){
        for(int i = 0; i <= x; ++ i) fa[i] = i;
    }
    int findfa(int x){
        while (x != fa[x]) x = fa[x] = fa[fa[x]];
        return x;
    }
    void merge(int u, int v){
        fa[findfa(u)] = findfa(v); return ;
    }
    bool same(int u, int v){ return findfa(u) == findfa(v); }
};

ll qpow(ll a, ll x, ll p){
    a %= p;
    ll ans = 1;
    while(x){
        if(x & 1) ans = ans * a % p;
        x >>= 1;
        a = a * a % p;
    }
    return ans;
}

struct edge{
    int u, v, w;
    bool operator < (const edge & x) const {
        return w < x.w;
    }
};

void solve(){
    cin >> n >> m;
    priority_queue<edge> q;
    for(int i = 1; i <= n; ++ i){
        cin >> a[i];
        for(int j = 1; j < i; ++ j){
            edge t;
            t.u = i;
            t.v = j;
            t.w = (qpow(a[i], a[j], m) + qpow(a[j], a[i], m)) % m;
            q.push(t);
        }
    }
    DSU dsu(n);
    ll ans = 0;
    while(q.size()){
        edge t = q.top();
        q.pop();
        if(!dsu.same(t.u, t.v)){
            ans += t.w;
            dsu.merge(t.u, t.v);
        }
    }
    cout << ans << '\n';
    return ;
}

signed main(){
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while(_ --){
        solve();
    }
    return 0;
}
