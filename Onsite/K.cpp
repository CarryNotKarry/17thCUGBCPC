#include<bits/stdc++.h>
using namespace std;
signed main() {
	int n, m, ans=0;
	cin>>n>>m;
	while (n--)
	{
		string s;
		cin>>s;
		ans += count(s.begin(), s.end(), '1');
	}
	cout<<ans<<endl;
    return 0;
}