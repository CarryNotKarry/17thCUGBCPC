//lower_bound 二分
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
vector<int>bst;

void solve(){
    int n;
    cin>>n;
    while(n--){
        int op;
        cin>>op;
        int x,pos;
        switch (op)
        {
        case 1:
            cin>>x;
            bst.insert(lower_bound(bst.begin(),bst.end(),x),x);
            break;
        case 2:
            cin>>x;
            bst.erase(lower_bound(bst.begin(),bst.end(),x));
            break;
        case 3:
            cin>>x;
            pos=lower_bound(bst.begin(),bst.end(),x)-bst.begin()+1;
            cout<<pos<<endl;
            break;
        case 4:
            cin>>pos;
            cout<<bst[pos-1]<<endl;
            break;
        case 5:
            cin>>x;
            cout << *(lower_bound(bst.begin(), bst.end(), x)-1) << endl;
            break;
        case 6:
            cin>>x;
            cout << *(upper_bound(bst.begin(), bst.end(), x)) << endl;
            break;
        default:
            break;
        }
    }
    return;
} 
signed main(){
    // ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
//平衡树
/*
#include <cstdio>
#include <algorithm>
const int maxlog = 25;
const int MAXN = 100010;
using namespace std;
namespace trie{
    int id = 2;
    int ch[MAXN * maxlog][2];
    int sz[MAXN * maxlog];
    int newnode(){
        ch[id][0] = ch[id][1] = sz[id] = 0;
        return id++;
    }               
    void ins(int x,int d){          
        int u = 1;          
        for(int i = maxlog - 1;i >= 0;i--){         
            int v = (x >> i) & 1;       
            if(!ch[u][v]) ch[u][v] = newnode();         
            u = ch[u][v];       
            sz[u] += d; 
        }                           
    }                                       
    int kth(int k){
        int u = 1;
        int x = 0;
        for(int i = maxlog - 1;i >= 0;i--){
            if(sz[ch[u][0]] >= k){                  
                u = ch[u][0]; 
            }
            else{
                x |= (1 << i);
                k -= sz[ch[u][0]];
                u = ch[u][1];
            }
        }
        return x;
    }
    int nlt(int x){
        int ans = 0;
        int u = 1;
        for(int i = maxlog - 1;i >= 0;i--){
            if((x >> i) & 1){
                ans += sz[ch[u][0]];
                u = ch[u][1];
            }
            else{
                u = ch[u][0];
            }
            if(!u) break; 
        }             
        return ans;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
    }   
    void clear(){
        ch[1][0] = ch[1][1] = 0;
        id = 2;
    } 
    int pre(int x){
        int ans;
        ans = kth(nlt(x));
        return ans;
    }
    int next(int x){
        int ans;
        ans = kth(nlt(x+1)+1);
        return ans;
    }
} 

const int num = 10000000; 
int main(){
     int n;
     scanf("%d",&n);
     for(int i = 0;i < n;i++){
        int ord,t;
        scanf("%d%d",&ord,&t);
        switch(ord){
            case 1:trie::ins(t + num,1);break;
            case 2:trie::ins(t + num,-1);break;
            case 3:printf("%d\n",trie::nlt(t + num) + 1);break;
            case 4:printf("%d\n",trie::kth(t) - num);break;
            case 5:printf("%d\n",trie::pre(t + num) - num);break;
            case 6:printf("%d\n",trie::next(t + num) - num);break;
        }
    }
    return 0;
} 
*/