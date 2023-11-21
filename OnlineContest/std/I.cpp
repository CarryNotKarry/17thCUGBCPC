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
const int maxm = 2e2 + 5, inf = 0x3f3f3f3f, mod = 998244353;
int n, m, a[maxm][maxm];
 
struct BIT{
    int num;
    vector<ll> c;
    BIT(int x = maxm) : num(x), c(x + 1, 0){}
    int lowbit(int x){ return x & (-x); }
 
    void update(int x, int v){
        while(x <= num){
            c[x] += v; x += lowbit(x);
        }
        return ;
    }
 
    ll getsum(int x){
        ll res = 0;
        while(x){
            res += c[x]; x -= lowbit(x);
        }
        return res;
    }
};

void solve(){
    cin >> n >> m;
    bool f = true;//ÅÐ¶Ï¾ØÕóµÄÐÐÁÐÊÇ·ñÎªÓÐÐò¾ØÕó²Ù×÷¶øÀ´µÄ
    int cntc = 0, cntr = 0;//Í³¼ÆÐÐÁÐÓÐÐòµÄ¸öÊý
    BIT bitr(n);
    vector<int> c(m + 1, 0);
    int rcha = 0;// Í³¼ÆÐÐÄæÐò¶ÔµÄ¸öÊý
    for(int i = 1; i <= n; ++ i){
        int mina = inf, maxa = 0;
        for(int j = 1; j <= m; ++ j){
            cin >> a[i][j];
            mina = min(mina, a[i][j]);
            maxa = max(maxa, a[i][j]);
            if(i == 1) c[j] = a[i][j] % m;
            else if(a[i][j] % m != c[j]) f = false;
        }
        if(!(maxa % m == 0 && maxa - mina + 1 == m)) f = false;
        int x = mina / m;
        if(x == i - 1) ++ cntr;//ÓÐÐòÐÐ
        ++ x;
        rcha += i - 1 - bitr.getsum(x);
        bitr.update(x, 1);
    }
    if(!f){//¾ØÕóÂÒÐò£¬ÎÞ·¨ÊµÏÖ
        cout << "Bad game!\n"; return ;
    }
    BIT bitc(m);
    int ccha = 0;// Í³¼ÆÁÐÄæÐò¶ÔµÄ¸öÊý
    for(int i = 1; i <= m; ++ i){
        if((a[1][i] - 1) % m + 1 == i) ++ cntc;//ÓÐÐòÁÐ
        ccha += i - 1 - bitc.getsum((a[1][i] - 1) % m + 1);
        bitc.update((a[1][i] - 1) % m + 1, 1);
    }
    if(cntr + 2 == n && cntc == m){//foxÒ»²½Ó®
        cout << "Qs is the winner!\n"; return ;
    }
    if(m == 2 && rcha % 2 != ccha % 2){//foxÓÐÏÞ²½Ó®£¬ºóÊÖ²Ù×÷ÒÔ2ÎªÖÜÆÚ
        cout << "Qs is the winner!\n"; return ;
    }
    if(n == 2 && rcha % 2 == ccha % 2){//catÓÐÏÞ²½Ó®
        cout << "Sn is the winner!\n"; return ;
    }
    cout << "Bad game!\n";
    return ;
}

signed main(){
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
    int _ = 1;
    cin >> _;
    while(_ --){
        solve();
    }
    return 0;
}
