#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1000000007;

/* x^nを高速に求める */
ll mod_pow(ll x, ll n) {
	ll res = 1;
	while (n > 0) {
		if (n & 1) res = res*x%MOD;  // 最下位ビットが立ってる時にx^(2^i)を掛ける
		x = x*x%MOD;              // xを順次二乗していく
		n >>= 1;    // 右ビットシフト
	}
	return res;
}


int main(){
    int n;
    cin >> n;
    
    for(ll x=2; x<n; x++){
        cout << mod_pow(x,n) <<" "<< x%n << endl;
    }
}
