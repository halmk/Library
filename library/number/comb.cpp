#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 510000;
const int MOD = (int)1e9+7;

ll fac[MAX], finv[MAX], inv[MAX]; // a!(fac[a]), (a!)^{-1}(finv[a]), a^{-1}(inv[a])

// テーブルを作る前処理
void comb_init(){
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for(int i=2; i<MAX; i++){
        fac[i] = fac[i-1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i-1] * inv[i] % MOD;
    }
}

ll comb(int n, int k){
    if(n < k) return 0;
    if(n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n-k] % MOD) % MOD;
}

int main() {
    // 前処理
    comb_init();
    
    // 計算例
    cout << comb(4, 2) << endl;
}
