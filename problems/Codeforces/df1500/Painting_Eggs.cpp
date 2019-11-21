/* 解法は貪欲だよ！ちゃんと証明してね！！ */
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define DEBUG(debug_x) cerr <<#debug_x<<": "<<debug_x<<endl;
#define DEBUG2(debug_x, debug_y) cerr <<#debug_x<<":"<<debug_x<<" "<<#debug_y<<":"<<debug_y<<endl;
#define DEBUG3(debug_x, debug_y, debug_z) cerr <<#debug_x<<":"<<debug_x<<" "<<#debug_y<<":"<<debug_y<<" "<<#debug_z<<":"<<debug_z<<endl;
#define DEBUGVC(debug_x) cerr <<#debug_x<<": "; for(auto a:debug_x) cerr << a <<" "; cerr << endl;
#define DEBUGMP(debug_x) cerr <<#debug_x<<":"<<endl; for(auto a:debug_x) cerr << a.first <<" "<< a.second << endl;
#define MAX_N (105)
#define INF (1LL << 60)
const int MOD = (int)1e9;
typedef pair<int,int> Pii;
typedef pair<double,double> Pdd;
 
 
signed main() {
    int n;
    cin >> n;
    int Sa=0, Sg=0;
    string ans;
    for(int i=0; i<n; i++){
        int a, g;
        cin >> a >> g;
        if(abs(Sa + a - Sg) <= 500) {
            ans.push_back('A');
            Sa += a;
        } else {
            ans.push_back('G');
            Sg += g;
        }
    }
 
    cout << ans << endl;
}
