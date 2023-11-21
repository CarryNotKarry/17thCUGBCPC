#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
    int n, k;
    cin >> n >> k;
    int ans = 50;
    for (int i = 1; i <= n; i++)
    {
        if (ans > k)
            ans *= 2;
        else
            ans += k;
    }
    cout << ans << endl;
    return 0;
}