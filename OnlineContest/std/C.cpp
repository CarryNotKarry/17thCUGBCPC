/*
 author:YoungChigga
*/
 
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n, m;
    n = 4;
    vector<pair<int, int>> a(n);
    set<pair<int, int>> st;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
        assert(0 <= a[i].first && a[i].first <= (int)1e9);
        assert(0 <= a[i].second && a[i].second <= (int)1e9);
        st.emplace(a[i]);
    }
    assert(st.size() == 4);
    sort(a.begin(), a.end());
    if(a[0].first == a[1].first && a[0].second == a[2].second && a[2].first == a[3].first && a[1].second == a[3].second)
    {
        vector<int> len;
        len.emplace_back(a[2].first - a[0].first);
        len.emplace_back(a[3].first - a[1].first);
        len.emplace_back(a[1].second - a[0].second);
        len.emplace_back(a[3].second - a[2].second);
        if(count(len.begin(), len.end(), len[0]) == 4 && len[0] >= 1)
            cout << "square" << "\n";
        else if(len[0] == len[1] && len[2] == len[3] && *min_element(len.begin(), len.end()) >= 1)
            cout << "rectangle" << "\n";
        else
            cout << "no" << "\n";
    }
    else
        cout << "no" << "\n";
}

int main() 
{
    int _t = 1;
    cin >> _t;
 
    while(_t--)
        solve();
    
    return 0;
}