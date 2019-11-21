// DP: [1,j]まで使える時の合計がiになる集合を合計０から書き下せば分かる.
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define DEBUG(x) cerr <<#x<<":"<<x<<endl;
#define DEBUG2(x, y) cerr <<#x<<":"<<x<<" "<<#y<<":"<<y<<endl;
#define DEBUG3(x, y, z) cerr <<#x<<":"<<x<<" "<<#y<<":"<<y<<" "<<#z<<":"<<z<<endl;
#define DEBUGVC(x) cerr <<#x<<": "; for(auto a:x) cerr << a <<" "; cerr << endl;
#define DEBUGVCP(x) cerr <<#x<<": "<<endl; for(auto a:x) cerr << a.first <<" "<< a.second << endl;
#define DEBUGMP(x) cerr <<#x<<":"<<endl; for(auto a:x) cerr << a.first <<" "<< a.second << endl;
#define MAX_N (100005)
#define INF (1LL << 60)
const int MOD = (int)1e9 + 7;

/*
DP

*/

signed main() {
    int n, k, d;
    cin >> n >> k >> d;

    int dp[111][111];
    for(int i=0; i<111; i++) for(int j=0; j<111; j++) dp[i][j]=0;
    for(int j=0; j<111; j++) dp[0][j]=1;

    for(int i=0; i<=n; i++){
        for(int j=1; j<=k; j++){
            for(int l=1; l<=j; l++){
                if((i-l)<0) break;
                dp[i][j] += dp[i-l][j];
                dp[i][j] %= MOD;
            }
        }
    }

    /*
    for(int i=0; i<=n; i++){
        for(int j=0; j<=k; j++){
            cout << dp[i][j] <<"\t";
        }
        cout << endl;
    }
    */
    

    int ans = (dp[n][k] - dp[n][d-1]) % MOD;
    cout << (ans<0?ans+MOD:ans) << endl;
    
}
