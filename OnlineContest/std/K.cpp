#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3 + 5;
int n, a[maxn][maxn], vis[maxn][maxn], cnt, fina_ans, mx[5] = {0, -1, 1, 0, 0}, my[5] = {0, 0, 0, -1, 1};

void dfs(int x, int y)
{
    if (a[x][y] == 1 || vis[x][y] == 1 || x < 1 || y < 1 || x > n || y > n)
        return;
    cnt++;
    vis[x][y] = 1;
    for (int i = 1; i <= 4; i++)
    {
        int vx = x + mx[i], vy = y + my[i];
        dfs(vx, vy);
    }
    return;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (a[i][j] != 1 && vis[i][j] != 1)
            {
                cnt = 0;
                dfs(i, j);
                fina_ans = max(fina_ans, cnt);
            }
    cout << fina_ans;
    return 0;
}
