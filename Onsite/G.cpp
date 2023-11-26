#include <bits/stdc++.h>

using namespace std;

bool check(string s)
{
    for (int i = 0; i < s.size(); i++)
        if (s[i] == 'k' || s[i] == 'K')
            return false;
    return true;
}

int main()
{
    string a, b;
    int flag = 0, ans = 0, Minute = 0, Second = 0;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> a >> b;
        sscanf(a.c_str(), "%d:%d", &x, &y);
        if (i == n)
        {
            if (flag == 1)
                ans += (x * 60 + y - Minute * 60 - Second);
            break;
        }
        if (check(b))
        {
            if (flag == 1)
            {
                ans += (x * 60 + y - Minute * 60 - Second);
                flag = 0;
            }
            else
            {
                flag = 1;
                Minute = x;
                Second = y;
            }
        }
    }
    cout << setw(2) << setfill('0') << ans / 60 << ":" << setw(2) << setfill('0') << ans % 60;
    return 0;
}

/*
5
10:45 bulubiubulubiu
20:13 WoMeiK!
25:00 KonglongKanglangKanglangKang
30:00 RepayTheCountry!
31:05 Defeat
*/