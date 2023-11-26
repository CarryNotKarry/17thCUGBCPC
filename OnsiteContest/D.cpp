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
const int maxn = 1e5 + 10;

int sgn(LL x) {
    if(x > 0) return 1;
    if(x < 0) return -1;
    return 0;
}

struct Point {
    LL x, y;
    Point(int _x = 0, int _y = 0) : x(_x), y(_y){}
    Point operator+(const Point& rhs) const {
        return Point(x + rhs.x, y + rhs.y);
    }
    Point operator-(const Point& rhs) const {
        return Point(x - rhs.x, y - rhs.y);
    }
    Point operator-() const {
        return Point(-x, -y);
    }
    bool operator<(const Point& rhs) const {
        if(x == rhs.x) return y < rhs.y;
        return x < rhs.x;
    }
    bool operator==(const Point& rhs) const {
        return x == rhs.x && y == rhs.y;
    }
    friend LL dot(const Point& a, const Point& b) {
        return a.x * b.x + a.y * b.y;
    }
    friend LL cross(const Point& a, const Point& b) {
        return a.x * b.y - a.y * b.x;
    }
    int toleft(const Point& rhs) const {
        const LL t = cross(*this, rhs);
        return sgn(t);
    }
} p1[maxn], p2[maxn], a[maxn], b[maxn], c[maxn], c1[maxn];

int Convex_hull(Point *p, int n, Point *ch) {
    sort(p, p + n);
    n = unique(p, p + n) - p;
    int v = 0;
    for(int i = 0; i < n; i++) {
        while(v > 1 && sgn(cross(ch[v - 1] - ch[v - 2], p[i] - ch[v - 1])) <= 0)
            v--;
        ch[v++] = p[i];
    }
    int j = v;
    for(int i = n - 2; i >= 0; i--) {
        while(v > j && sgn(cross(ch[v - 1] - ch[v - 2], p[i] - ch[v - 1])) <= 0)
            v--;
        ch[v++] = p[i];
    }
    if(n > 1) v--;
    return v;
}

int Minkowski(int n, int m) {
    for(int i = 0; i < n; i++)
        p1[i] = a[i + 1] - a[i];
    for(int i = 0; i < m; i++)
        p2[i] = b[i + 1] - b[i];
    int tot = 1;
    c[0] = a[0] + b[0];
    int i = 0, j = 0;
    while(i < n && j < m) {
        c[tot] = c[tot - 1] + (p1[i].toleft(p2[j]) >= 0 ? p1[i++] : p2[j++]);
        tot++;
    }
    while(i < n) {
        c[tot] = c[tot - 1] + p1[i++];
        tot++;
    }
    while(j < m) {
        c[tot] = c[tot - 1] + p2[j++];
        tot++;
    }
    return tot;
}

bool inConvex(Point t, Point *p, int n) {
    if(t.toleft(p[1]) > 0 || p[n - 1].toleft(t) > 0) return 0;
    int l = 1, r = n - 2, res;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(p[mid].toleft(t) >= 0) {
            res = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    return cross(p[res + 1] - p[res], t - p[res]) >= 0;
}

inline void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 0; i < n; i++) {
        cin >> p1[i].x >> p1[i].y;
    }
    n = Convex_hull(p1, n, a);
    for(int i = 0; i < m; i++) {
        cin >> p2[i].x >> p2[i].y;
        p2[i] = -p2[i];
    }
    m = Convex_hull(p2, m, b);
    int tot = Minkowski(n, m);
    tot = Convex_hull(c, tot, c1);
    Point o = c1[0];
    for(int i = tot - 1; ~i; i--) c1[i] = c1[i] - c1[0];
    while(q--) {
        Point d;
        cin >> d.x >> d.y;
        cout << inConvex(d - o, c1, tot) << endl;
    }
}


// #define sunset
signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
#ifdef sunset
    freopen("war5.in", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int T = 1;
    // cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}