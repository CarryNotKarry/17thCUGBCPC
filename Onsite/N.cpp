#include <bits/stdc++.h>
#define lowbit(i) i & (-i)

using namespace std;
typedef long long ll;

const int size_tree = 1e7 + 5;
const int MOD = 1e9 + 7;
const int maxn = 5e4 + 5;
int n, m, pos[maxn], rt[maxn], cnt;
ll ans, value[maxn], qs, qsz;

struct tree
{
    int L, R, num;
    ll sum;
} t[size_tree];

void update(int &x, int l, int r, int k, int v, int v1) //
{
    if (!x)
        x = ++cnt;
    if (l == r)
    {
        t[x].num += v1;
        t[x].sum += v * v1;
        return;
    }
    int mid = (l + r) >> 1;
    if (k <= mid)
        update(t[x].L, l, mid, k, v, v1);
    else
        update(t[x].R, mid + 1, r, k, v, v1);
    t[x].sum = (t[t[x].L].sum + t[t[x].R].sum) % MOD;
    t[x].num = t[t[x].L].num + t[t[x].R].num;
    return;
}

void add(int x, int fg) //
{
    int p = pos[x], v = value[x];
    for (; x <= n; x += lowbit(x))
        update(rt[x], 1, n, p, v, fg);
}

void query(int x, int l, int r, int l1, int r1, int fg) //
{
    if (l >= l1 && r <= r1)
        return qsz += fg * t[x].num, (qs += fg * t[x].sum) %= MOD, void();
    int mid = (l + r) >> 1;
    if (l1 <= mid)
        query(t[x].L, l, mid, l1, r1, fg);
    if (r1 > mid)
        query(t[x].R, mid + 1, r, l1, r1, fg);
}

void ask(int l, int r, int l1, int r1) //
{
    qsz = qs = 0;
    if (l > r || l1 > r1)
        return;
    for (; r; r -= lowbit(r))
        query(rt[r], 1, n, l1, r1, 1);
    --l;
    if (l)
        for (; l; l -= lowbit(l))
            query(rt[l], 1, n, l1, r1, -1);
}

int f(int x)
{
    return (qs + 1ll * qsz * value[x] % MOD) % MOD;
}

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> pos[i] >> value[i];
        add(i, 1);
        ask(1, i - 1, pos[i] + 1, n);
        ans += f(i);
        ans %= MOD;
    }
    cout << ans << '\n';
    for (int i = 1; i <= m - 1; i++)
    {
        int l, r;
        cin >> l >> r;
        if (l > r)
            swap(l, r);
        if (l != r)
        {
            ask(l + 1, r - 1, 1, pos[l] - 1);
            ans -= f(l);
            ans %= MOD;
            ask(l + 1, r - 1, pos[l] + 1, n);
            ans += f(l);
            ans %= MOD;
            ask(l + 1, r - 1, 1, pos[r] - 1);
            ans += f(r);
            ans %= MOD;
            ask(l + 1, r - 1, pos[r] + 1, n);
            ans -= f(r);
            ans %= MOD;
            pos[l] > pos[r] ? ans -= value[l] + value[r] : ans += value[l] + value[r];
            ans %= MOD;
            add(l, -1), add(r, -1);
            swap(pos[l], pos[r]), swap(value[l], value[r]);
            add(l, 1), add(r, 1);
        }
        if (ans < 0)
            ans += MOD;
        cout << ans << '\n';
    }
    return 0;
}

/*
5 5
1 1
2 2
3 3
4 4
5 5
1 5
1 5
2 4
5 3
1 3
*/
