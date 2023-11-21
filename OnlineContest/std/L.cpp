#include<bits/stdc++.h>
// #define int long long
#define endl '\n'
#define debug(x) cout << #x << " = " << x << endl
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = "<< y << endl
using namespace std;

typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int, int> pii;
const int mod = 998244353;
const int eps = 1e-9;
const int maxn = 1e6 + 10;

char s[maxn];
pii node[maxn << 2];

void push_up(int x) {
    auto [ll, lr] = node[x << 1];
    auto [rl, rr] = node[x << 1 | 1];
    int offset = min(ll, rr);
    node[x] = {ll + rl - offset, lr + rr - offset};
}

void build(int x, int l, int r) {
    if(l == r) {
        if(s[l] == '(') node[x] = {1, 0};
        else node[x] = {0, 1};
        return;
    }
    int mid = (l + r) >> 1;
    build(x << 1, l, mid);
    build(x << 1 | 1, mid + 1, r);
    push_up(x);
}

pii query(int x, int l, int r, int ql, int qr) {
    if(l >= ql && r <= qr) return node[x];
    int mid = (l + r) >> 1;
    pii res;
    if(qr <= mid) res = query(x << 1, l, mid, ql, qr);
    else if(ql > mid) res = query(x << 1 | 1, mid + 1, r, ql, qr);
    else {
        auto [ll, lr] = query(x << 1, l, mid, ql, qr);
        auto [rl, rr] = query(x << 1 | 1, mid + 1, r, ql, qr);
        int offset = min(ll, rr);
        res = {ll + rl - offset, lr + rr - offset};
    }
    return res;
}


signed main() {
    int m;
    scanf("%s%d", s + 1, &m);
    int n = strlen(s + 1);
    build(1, 1, n);
    while(m--) {
        int l, r;
        cin >> l >> r;
        auto [x, y] = query(1, 1, n, l, r);
        cout << r - l + 1 - x - y << endl;
    }
    return 0;
}