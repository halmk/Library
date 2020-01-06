#include <bits/stdc++.h>
using namespace std;

/* snippet part start */
#define MAX_N (1000000)
int prime[MAX_N];           // i番目の素数
bool is_prime[MAX_N+1];     // is_prime[i]がtrueならiは素数

// n 以下の素数の数を返す
int sieve(int n){
    int p=0;
    // 初期化 全てを素数と仮定する
    for(int i=0; i<=n; i++) is_prime[i] = true;
    // 0と1は排除
    is_prime[0] = is_prime[1] = false;

    for(int i=2; i<=n; i++){
        if(is_prime[i]){    // iが素数の時
            prime[p++] = i; // p番目をiとして確定させる
            //cout << prime[p-1] << endl;
            // 表からiの倍数を取り除く
            for(int j=2*i; j<=n; j+=i) is_prime[j] = false;
        }
    }
    return p;
}
/* snippet part end */

int main(){
    int n;
    n = 11;
    cout << sieve(n) << endl;
}
