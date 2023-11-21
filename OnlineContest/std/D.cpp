#include <iostream>
using namespace std;

signed main() {
    int n, w;
    string s;
    cin>>n>>w>>s;
    int ans=0;
    while (n--)
    {
        int x;
        string t;
        cin>>x>>t;
        if (t==s || x>w)
            ans++;
    }
    cout<<ans<<endl;
    return 0;
}