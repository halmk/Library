/* 2次元配列でやるDP 計算量はO(k*n*(約数の個数))
 * dp[i][j] = ∑ dp[i-1][div] ,div={ jの約数 }
 */
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define DEBUG(debug_x) cerr <<#debug_x<<": "<<debug_x<<endl;
#define DEBUG2(debug_x, debug_y) cerr <<#debug_x<<":"<<debug_x<<" "<<#debug_y<<":"<<debug_y<<endl;
#define DEBUG3(debug_x, debug_y, debug_z) cerr <<#debug_x<<":"<<debug_x<<" "<<#debug_y<<":"<<debug_y<<" "<<#debug_z<<":"<<debug_z<<endl;
#define DEBUGVC(debug_x) cerr <<#debug_x<<": "; for(auto a:debug_x) cerr << a <<" "; cerr << endl;
#define DEBUGMP(debug_x) cerr <<#debug_x<<":"<<endl; for(auto a:debug_x) cerr << a.first <<" "<< a.second << endl;
#define MAX_N (2005)
#define INF (1LL << 60)
const int MOD = (int)1e9 + 7;

// 約数の列挙O(√n)
vector<int> divisor(int n){
    vector<int> res;
    for(int i=1; i*i<=n; i++){
        if(n%i==0){
            res.push_back(i);
            // n の約数が i の時、n/i も n の約数になる
            if(i!=n/i) res.push_back(n/i);
        }
    }
    return res;
}

signed main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> div(n+1);
    for(int i=1; i<=n; i++){
        div[i] = divisor(i);
    }

    int dp[MAX_N][MAX_N];
    for(int i=0; i<k; i++){
        for(int j=0; j<MAX_N; j++){
            dp[i][j]=0;
        }
    }
    for(int i=0; i<MAX_N; i++) dp[0][i]=1;

    for(int i=1; i<k; i++){
        for(int j=1; j<=n; j++){
            for(int d=0; d<div[j].size(); d++){
                int di = div[j][d];
                //DEBUG3(i,j,di);
                dp[i][j] += (dp[i-1][di]%MOD);
                dp[i][j] %= MOD;
            }
        }
    }

    int ans=0;
    for(int i=1; i<=n; i++){
        ans += dp[k-1][i];
        ans %= MOD;
    }

    cout << ans%MOD << endl;

}
