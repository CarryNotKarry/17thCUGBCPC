#include<bits/stdc++.h>
using namespace std;
signed main() {
    int n, m, k;
    cin>>n>>m>>k;
    k = min(k, n);
    vector<pair<int,int>> a(n);
    for (int i=0; i<n; i++)
        cin>>a[i].first>>a[i].second;
    sort(a.begin(), a.end());
    vector<int> pre(n+5);
    multiset<int> st;
    int res=0;
    for (int i=n-1; i>=0; i--)
    {
        int v = a[i].second;
        st.insert(v);
        res += v;
        if (st.size()>k)
        {
            res -= *st.begin();
            st.erase(st.begin());
        }
        pre[i] = res;
    }

    int ans = pre[0];
    vector<int> dp(m+5);
    for (int i=0; i<n; i++)
    {
        auto [w, v] = a[i];
        for (int j=m; j>=w; j--)
            dp[j] = max(dp[j], dp[j-w]+v);
        ans = max(ans, dp[m]+pre[i+1]);
    }

    cout<<ans<<endl;
    return 0;
}