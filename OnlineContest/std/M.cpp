#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int maxn = 1e7+5;
vector<int> prime;
bool not_prime[maxn];
void get_prime(int max_num)
{
	not_prime[0] = not_prime[1] = 1;
	for (int i=2; i<=max_num; i++)		
	{
		if (!not_prime[i])		prime.push_back(i);
		for (int idx=0; idx<prime.size() && i*prime[idx]<=max_num; idx++)
		{
			not_prime[i*prime[idx]] = 1;
			if (!(i%prime[idx]))	break;	
		}
	}
}
signed main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    get_prime(1e7);
    int n;
    cin>>n;
    while (n--)
    {
        int x, y;
        cin>>x>>y;
        if (x>y)
            swap(x,y);
        if (x+1==y)
        {
            cout<<"-1"<<endl;
            continue;  
        }
        else if (x==y)
        {
            cout<<"0"<<endl;
            continue;
        }
        vector<int> factor;
        int cha = y-x;
        for (int u:prime)
        {
            if (u*u>cha || not_prime[cha]==0)  break;
            if (cha%u==0)
            {
                factor.push_back(u);
                while (cha%u==0)
                    cha/=u;
            }
        }
        if (cha>1)
            factor.push_back(cha);
        int ans=1e9;
        for (int u:factor)
        {
            if (x%u==0) ans=0;
            else        ans=min(ans, u-x%u);
        }
        cout<<ans<<endl;
    }
    return 0;
}