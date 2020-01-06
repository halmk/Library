#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/* snippet part start */
const int MOD = 1000000007;

/* x^nを高速に求める */
int mod_pow(int x, int n) {
	int res = 1;
	while (n > 0) {
		if (n & 1) res = res*x%MOD;  // 最下位ビットが立ってる時にx^(2^i)を掛ける
		x = x*x%MOD;              // xを順次二乗していく
		n >>= 1;    // 右ビットシフト
	}
	return res;
}
/* snippet part end */


int main(){
    int n;
    cin >> n;

    for(ll x=2; x<n; x++){
        cout << mod_pow(x,n) <<" "<< x%n << endl;
    }
}
