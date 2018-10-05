#include <bits/stdc++.h>
using namespace std;

/* 区間内の素数の個数 */

#define MAX_L (1000000)
#define MAX_SQRT_B (1000000)
typedef long long ll;

bool is_prime[MAX_L];
bool is_prime_small[MAX_SQRT_B];

// [a,b)の整数に対して篩を行う。is_prime[i-a]=true ⇔ iが素数
void segment_sieve(ll a, ll b){
    for(int i=0; (ll)i * i < b; i++) is_prime_small[i] = true;
    for(int i=0; i < b-a; i++) is_prime[i] = true;
    
    for(int i=2; (ll)i * i < b; i++){
        if(is_prime_small[i]){
            // [2,√b)の表から素数が得られるたびに、その素数の倍数を[a,b)から除く
            for(int j=2*i; (ll)j * j <b; j+=i) is_prime_small[j]=false; // [2,√b)の篩
            for(ll j=max(2LL, (a+i-1)/i) * i; j<b; j+=i) is_prime[j-a]=false; // [a,b)の篩
        }
    }
}

int main(){
    ll a, b;
    a=22; b=37;
    segment_sieve(a,b);
    int cnt=0;
    for(ll i=a; i<b; i++){
        if(is_prime[i-a]){
            cnt++;
            cout << i << endl;
        }
    }
    cout << cnt << endl;
}
