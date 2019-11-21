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
const int MOD = (int)1e9+7;


signed main(){
    int n;
    cin >> n;
    vector<bool> f(MAX_N,false);
    for(int i=0; i<n; i++) {
        int a;
        scanf("%lld", &a);
        f[a] = true;
    }

    int dp[MAX_N];
    for(int i=0; i<MAX_N; i++) dp[i]=0;

    int ans=0;
    for(int i=0; i<MAX_N; i++){
        if(!f[i]) continue;
        //DEBUG3(i, f[i], dp[i]);
        int crt = i, crtn=i;
        int cnt = dp[i]+1, k = 2;
        while(crt < MAX_N){
            //DEBUG3(crt,cnt,dp[crt]);
            if(f[crt]) {
                //DEBUG(crt);
                ans = max(ans, cnt);
            }
            dp[crt] = max(dp[crt], cnt);
            //DEBUG(dp[crt]);
            crt = crtn * k;
            k++;
        }
        //for(int j=0; j<MAX_N; j++) cout << dp[j] <<" "; cout << endl;
    }

    cout << ans << endl;
}