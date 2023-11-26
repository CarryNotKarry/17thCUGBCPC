#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define debug(x) cout << #x << " = " << x << endl
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = "<< y << endl
using namespace std;

typedef long long LL;
typedef unsigned long long uLL; 
typedef pair<int, int> pii;
const int mod = 998244353;
const int maxn = 2e5 + 10;
const int INF = 1e9;

int sze[maxn << 2], mina[maxn << 2], pos[maxn << 2];
LL sum[maxn << 2], tag[maxn << 2];

void push_up(int x) {
    sum[x] = sum[x << 1] + sum[x << 1 | 1];
	sze[x] = sze[x << 1] + sze[x << 1 | 1];
    mina[x] = min(mina[x << 1], mina[x << 1 | 1]);
    pos[x] = mina[x << 1] <= mina[x << 1 | 1] ? pos[x << 1] : pos[x << 1 | 1];
}

void build(int x, int l, int r) {
    tag[x] = 0;
	if(l == r) {
		sze[x] = 1;
		sum[x] = l;
        mina[x] = l;
        pos[x] = l;
		return;
	}
	int mid = (l + r) >> 1;
	build(x << 1, l, mid);
	build(x << 1 | 1, mid + 1, r);
    push_up(x);
}

inline void pushtag(int x, LL a) {
	tag[x] += a;
	sum[x] += a * sze[x];
    mina[x] += a;
}

inline void pushdown(int x) {
	if(tag[x]) {
		pushtag(x << 1, tag[x]);
		pushtag(x << 1 | 1, tag[x]);
		tag[x] = 0;
	}
}

void add(int x, int l, int r, int ql, int qr, LL a) {
	if(l >= ql && r <= qr) {
		pushtag(x, a);
		return;
	}
	int mid = (l + r) >> 1; pushdown(x);
	if(ql <= mid) add(x << 1, l, mid, ql, qr, a);
	if(qr > mid) add(x << 1 | 1, mid + 1, r, ql, qr, a);
	push_up(x);
}

pii query(int x, int l, int r, int ql, int qr) {
    if(l >= ql && r <= qr) return {mina[x], pos[x]};
    int mid = (l + r) >> 1; pushdown(x);
    pii res = {INF, INF};
    if(ql <= mid) res = query(x << 1, l, mid, ql, qr);
    if(qr > mid) res = min(res, query(x << 1 | 1, mid + 1, r, ql, qr));
    return res;
}

inline void solve() {
    int n;
    cin >> n;
    build(1, 1, n);
    int cnt = 0;
    LL sum = 0, pre = 0;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        pre += x;
        add(1, 1, n, x, n, -1);
        auto [val, id] = query(1, 1, n, 1, n);
        // debug2(val, id);
        if(val == -1) {
            add(1, 1, n, id, n, 1);
            cnt++;
            sum += id;
        }
        // debug2(sum, cnt);
        cout << max(pre - sum - (1LL + i - cnt) * (i - cnt) / 2 - 1, 0LL) << " \n"[i == n];
    }
}


signed main() {

    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}