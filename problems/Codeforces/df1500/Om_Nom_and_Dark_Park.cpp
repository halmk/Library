/*
 * 解法：ミニマックス法みたいな感じで葉から根へ決定していく 
 * ポイント：2分木をDFSの順で綺麗に再帰で書くのが気持ちいい
 */
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define DEBUG(x) cerr <<#x<<": "<<x<<endl;
#define DEBUG2(x, y) cerr <<#x<<":"<<x<<" "<<#y<<":"<<y<<endl;
#define DEBUG3(x, y, z) cerr <<#x<<":"<<x<<" "<<#y<<":"<<y<<" "<<#z<<":"<<z<<endl;
#define DEBUGVC(x) cerr <<#x<<": "; for(auto a:x) cerr << a <<" "; cerr << endl;
#define DEBUGMP(x) cerr <<#x<<":"<<endl; for(auto a:x) cerr << a.first <<" "<< a.second << endl;
#define MAX_N (2000006)
#define INF (1LL << 60)
const int MOD = (int)1e9 + 7;
 
int n;
vector<int> a(pow(2,n+1));
vector<int> vc(pow(2,n+1),0);
int ans=0;
 
int dfs(int s){
    //DEBUG(s);
    if(2*s >= pow(2,n+1)) return vc[s] = 0;
    vc[s] = max(dfs(2*s+1)+a[2*s+1],dfs(2*s)+a[2*s]);
    ans += vc[s] - vc[2*s] - a[2*s];
    ans += vc[s] - vc[2*s+1] - a[2*s+1];
    return vc[s];
}
 
signed main() {
    cin >> n;
    a.resize(pow(2,n+1));
    vc.resize(pow(2,n+1),0);
    for(int i=2; i<pow(2,n+1); i++) cin >> a[i];
 
    dfs(1);
 
    //cout << vc.size() << endl;
    //DEBUGVC(vc);
 
    cout << ans << endl;
}
