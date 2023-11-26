//>>>Qiansui
#include<stdio.h>
#include<string.h>

using namespace std;
const int N = 1e3 + 5;

void solve(){
	int p;
	char s[N] = {}, ans[N] = {};
	scanf("%d %s", &p, s);
	int len = strlen(s);
	for(int i = 0; i < len; ++ i){
		ans[i] = (26 - p + s[i] - 'A') % 26 + 65;
	}
	printf("%s\n", ans);
	return ;
}

signed main(){
	int test_case;
	scanf("%d", &test_case);
	while(test_case --){
		solve();
	}
	return 0;
}