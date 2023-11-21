#include <cmath>
#include <cstdio>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <map>
#include <cmath>
using namespace std;

typedef long long LL;
typedef unsigned long long uLL;
const int inf = 0x3f3f3f3f;
const LL lnf = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
const int maxn = 4e5 + 10;
const int maxm = 200;

LL n, m;
map<int, int> mp;
vector<LL> a(maxn), b(maxm), t(maxm), s(maxm);
LL f[35][35][35][35][35];

void solve() {

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= m; ++i) cin >> b[i];

    int num = 0;
    for (int i = 1; i <= m; ++i) {
        if (!mp[b[i]]) {
            ++num;
            t[num] = 1;
            s[num] = b[i];
            mp[b[i]] = num;
        }
        else {
            ++t[mp[b[i]]];
        }
    }

    for (int t1 = 0; t1 <= t[1]; ++t1)
    for (int t2 = 0; t2 <= t[2]; ++t2)
    for (int t3 = 0; t3 <= t[3]; ++t3)
    for (int t4 = 0; t4 <= t[4]; ++t4)
    for (int t5 = 0; t5 <= t[5]; ++t5)
        f[t1][t2][t3][t4][t5] = -lnf;


    f[0][0][0][0][0] = 0;
    for (int t1 = 0; t1 <= t[1]; ++t1)
    for (int t2 = 0; t2 <= t[2]; ++t2)
    for (int t3 = 0; t3 <= t[3]; ++t3)
    for (int t4 = 0; t4 <= t[4]; ++t4)
    for (int t5 = 0; t5 <= t[5]; ++t5) {
        int x = t1 * s[1] + t2 * s[2] + t3 * s[3] + t4 * s[4] + t5 * s[5];
        if (t1 >= 1) f[t1][t2][t3][t4][t5] = max(f[t1][t2][t3][t4][t5], f[t1 - 1][t2][t3][t4][t5] + a[x]);
        if (t2 >= 1) f[t1][t2][t3][t4][t5] = max(f[t1][t2][t3][t4][t5], f[t1][t2 - 1][t3][t4][t5] + a[x]);
        if (t3 >= 1) f[t1][t2][t3][t4][t5] = max(f[t1][t2][t3][t4][t5], f[t1][t2][t3 - 1][t4][t5] + a[x]);
        if (t4 >= 1) f[t1][t2][t3][t4][t5] = max(f[t1][t2][t3][t4][t5], f[t1][t2][t3][t4 - 1][t5] + a[x]);
        if (t5 >= 1) f[t1][t2][t3][t4][t5] = max(f[t1][t2][t3][t4][t5], f[t1][t2][t3][t4][t5 - 1] + a[x]);
    }

    cout << f[t[1]][t[2]][t[3]][t[4]][t[5]] << '\n';

}

int main() {

    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);

    int T = 1; // cin >> T;
    for (int i = 1; i <= T; ++i) solve();

    // cout << endl; system("pause");
    return 0;
}