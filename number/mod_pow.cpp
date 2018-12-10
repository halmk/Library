#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool is_prime(int n){
    for(int i=2; i*i<=n; i++){
        if(n%i==0) return false;
    }
    return n != 1;  // 1の場合は例外
}

ll mod_pow(ll x, ll n, ll mod){
    ll res=1;
    while(n>0){
        if(n&1) res = res*x%mod;  // 最下位ビットが立ってる時にx^(2^i)を掛ける
        x = x*x%mod;              // xを順次二乗していく
        n >>= 1;    // 右ビットシフト
    }
    return res;
}


int main(){
    int n;
    cin >> n;
    
    for(ll x=2; x<n; x++){
        cout << mod_pow(x,n,n) <<" "<< x%n << endl;
    }
}
