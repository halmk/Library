#include <bits/stdc++.h>
using namespace std;

/* snippet part start */
// 素因数分解O(√n)
map<int, int> prime_factor(int n){
    map<int, int> res;
    for(int i=2; i*i<=n; i++){
        while(n%i==0){
            ++res[i];
            n /= i;
        }
    }
    if(n!=1) res[n] = 1;
    return res;
}
/* snippet part end */

int main(){
    int n;
    n = 57;
    map<int, int> factor;
    factor = prime_factor(n);
    cout << "素因数分解 : " << endl;
    for(auto itr = factor.begin(); itr != factor.end(); itr++){
        cout << itr->first <<" "<< itr->second << endl;
    }
}
