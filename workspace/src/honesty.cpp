#include <bits/stdc++.h>
using namespace std;

#define int long long
#define DEBUG(x) cerr <<#x<<":"<<x<<endl;
#define DEBUG2(x, y) cerr <<#x<<":"<<x<<" "<<#y<<":"<<y<<endl;
#define DEBUG3(x, y, z) cerr <<#x<<":"<<x<<" "<<#y<<":"<<y<<" "<<#z<<":"<<z<<endl;
#define DEBUGVC(x) cerr <<#x<<": "; for(auto a:x) cerr << a <<" "; cerr << endl;
#define DEBUGMP(x) cerr <<#x<<":"<<endl; for(auto a:x) cerr << a.first <<" "<< a.second << endl;
#define MAX_N (1000006)
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

signed main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) scanf("%lld", &a[i]);
    vector<bool> f(MAX_N, false);
    for(int i=0; i<n; i++){
        f[a[i]] = true;
    }

    int dp[MAX_N];
    for(int i=0; i<MAX_N; i++) dp[i]=0;

    for(int i=0; i<MAX_N; i++){
        if(!f[i]) continue;
        vector<int> dv = divisor(i);
        for(int j=0; j<dv.size(); j++){
            dp[i] = max(dp[i], dp[dv[j]]);
        }
        //DEBUG(i);
        //DEBUGVC(dv);
        dp[i]++;
    }

    //for(int i=0; i<30; i++) printf("%2lld ", i); puts("");
    //for(int i=0; i<30; i++) printf("%2lld ", dp[i]); puts("");

    int mx = 0;
    for(int i=0; i<MAX_N; i++) mx = max(mx, dp[i]);

    cout << mx << endl;

}