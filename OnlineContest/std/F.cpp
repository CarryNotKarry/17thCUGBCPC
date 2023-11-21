#include<bits/stdc++.h>
// #define int long long
#define endl '\n'
#define debug(x) cout << #x << " = " << x << endl
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = "<< y << endl
using namespace std;

typedef long long LL;
typedef unsigned long long uLL; 
typedef pair<int, int> pii;
const double eps = 1e-9;
const int mod = 998244353;
const int maxn = 2e5 + 10;

int a[maxn];

inline void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    LL ans = 0;
    int pre = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i] > pre + 1) {
            ans += a[i] - (pre + 1);
            pre++;
        }
        else if(a[i] == pre + 1) pre++;
    }
    cout << max(ans - 1, 0LL) << endl;
}


signed main() {

    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}