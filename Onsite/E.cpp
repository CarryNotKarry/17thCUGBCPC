/*
 author:YoungChigga
*/

#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const int maxn = 50010;
ll aa[maxn], tag[maxn], a[maxn], w[maxn];
int block[maxn];
int fa[maxn], dep[maxn], siz[maxn], top[maxn], dfn[maxn], son[maxn];
int tim;
vector<ll> ve[maxn];
int n, blo;

//bruce force
// void init()
// {
//     for(int i = 1; i <= n; i++)
//         a[i] = w[i];
// }
// void update(int l, int r, int x)
// {
//     for(int i = l; i <= r; i++)
//         a[i] += x;
// }
// int query(int l, int r, ll lo, ll hi)
// {
//     int ans = 0;
//     for(int i = l; i <= r; i++)
//     {
//         if(a[i] >= lo && a[i] <= hi)
//             ans += 1;
//     }
//     return ans;
// }

//std
void init()
{
    blo = sqrt(n);
    for(int i = 1; i <= n; i++)
    {
        tag[i] = 0;
        aa[i] = w[i];
    }
    for(int i = 1; i <= n; i++)
    {
        block[i] = (i - 1) / blo + 1;
        ve[block[i]].emplace_back(aa[i]);
    }
    for(int i = 1; i <= block[n]; i++)
        sort(ve[i].begin(), ve[i].end());
}
void reset(int x)
{
    ve[x].clear();
    for(int i = (x - 1) * blo + 1; i <= min(x * blo, n); i++)
        ve[x].emplace_back(aa[i]);
    sort(ve[x].begin(), ve[x].end());
}
void update(int l, int r, int x)
{
    for(int i = l; i <= min(1ll * block[l] * blo, (ll)r); i++)
        aa[i] += x;
    reset(block[l]);
    if(block[l] != block[r])
    {
        for(int i = (block[r] - 1) * blo + 1; i <= r; i++)
            aa[i] += x;
        reset(block[r]);
    }
    for(int i = block[l] + 1; i <= block[r] - 1; i++)
        tag[i] += x;
}
int query(int l, int r, ll lo, ll hi)
{
    int ans = 0;
    for(int i = l; i <= min(1ll * block[l] * blo, (ll)r); i++)
    {
        ll now = aa[i] + tag[block[l]];
        if(now <= hi && now >= lo)
            ans++;
    }
    if(block[l] != block[r])
    {
        for(int i = (block[r] - 1) * blo + 1; i <= r; i++)
        {
            ll now = aa[i] + tag[block[r]];
            if(now <= hi && now >= lo)
                ans++;
        }
    }
    for(int i = block[l] + 1; i <= block[r] - 1; i++)
    {
        ll loo = lo - tag[i];
        ll hii = hi - tag[i];
        ans += upper_bound(ve[i].begin(), ve[i].end(), hii) - lower_bound(ve[i].begin(), ve[i].end(), loo);
    }
    return ans;
}
//


vector<int> g[maxn];
void add(int uu, int vv)
{
    g[uu].push_back(vv);
    g[vv].push_back(uu);
}
void dfs1(int now, int fr)
{
    fa[now] = fr;
    dep[now] = dep[fr] + 1;
    siz[now] = 1;
    int max_size = -1;
    for (int x : g[now])
    {
        if (x == fr)
            continue;
        dfs1(x, now);
        siz[now] += siz[x];
        if (siz[x] > max_size)
        {
            max_size = siz[x];
            son[now] = x;
        }
    }
}
void dfs2(int now, int tp)
{
    dfn[now] = ++tim;
    top[now] = tp;
    w[tim] = a[now];
    if (!son[now])
        return;
    dfs2(son[now], tp);
    for (int x : g[now])
    {
        if (x == fa[now] || x == son[now])
            continue;
        dfs2(x, x);
    }
}
void make_tree(int root)
{
    dfs1(root, root);
    dfs2(root, root);
    init();
}
void update_son(int x, int z)
{
    update(dfn[x], dfn[x] + siz[x] - 1, z);
}
int query_son(int x, ll l, ll r)
{
    return query(dfn[x], dfn[x] + siz[x] - 1, l, r);
}
void update_chain(int x, int y, int z)
{
    while (top[x] != top[y])
    {
        if (dep[top[x]] < dep[top[y]])
            swap(x, y);
        update(dfn[top[x]], dfn[x], z);
        x = fa[top[x]];
    }
    if (dep[x] > dep[y])
        swap(x, y);
    update(dfn[x], dfn[y], z);
}
int query_chain(int x, int y, ll l, ll r)
{
    int res = 0;
    while (top[x] != top[y])
    {
        if (dep[top[x]] < dep[top[y]])
            swap(x, y);
        res += query(dfn[top[x]], dfn[x], l, r);
        x = fa[top[x]];
    }
    if (dep[x] > dep[y])
        swap(x, y);
    res += query(dfn[x], dfn[y], l, r);
    return res;
}

void check(ll num, ll l, ll r)
{
    assert(num >= l && num <= r);
}

void solve()
{
    int q;
    cin >> n >> q;
    check(n, 1, 5e4);check(q, 1, 5e4);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        check(a[i], 1, 1e9);
    }
    tim = 0;
    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        check(u, 1, n); check(u, 1, n);
        add(u, v);
    }

    make_tree(1);

    while(q--)
    {
        int op;
        cin >> op;
        check(op, 1, 4);
        int u, v, x;
        ll l, r;
        if(op == 1)
        {
            cin >> u >> x;
            check(u, 1, n);check(x, 1, 1e9);
            update_son(u, x);
        }
        else if(op == 2)
        {
            cin >> u >> v >> x;
            check(u, 1, n);check(v, 1, n);check(x, 1, 1e9);
            update_chain(u, v, x);
        }
        else if(op == 3)
        {
            cin >> u >> l >> r;
            check(u, 1, n);check(l, 1, 1e18);check(r, 1, 1e18);
            cout << query_son(u, l, r) << "\n";
        }
        else
        {
            cin >> u >> v >> l >> r;
            check(u, 1, n);check(v, 1, n);check(l, 1, 1e18);check(r, 1, 1e18);
            cout << query_chain(u, v, l, r) << "\n";
        }
    }
}



signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    // for(int i = 17; i < 18; i++)
    // {
    //     string in = to_string(i) + ".in";
    //     string ou = to_string(i) + ".out";
    //     int len1 = in.size();
    //     char inn[len1 + 1];
    //     for(int j = 0; j < len1; j++)
    //         inn[j] = in[j];
    //     inn[len1] = 0;
    //     int len2 = ou.size();
    //     char ouu[len2 + 1];
    //     for(int j = 0; j < len2; j++)
    //         ouu[j] = ou[j];
    //     ouu[len2] = 0;
    //     freopen(inn,"r",stdin);
    //     freopen(ouu,"w",stdout);
    //     solve();
    // }
    return 0;
}