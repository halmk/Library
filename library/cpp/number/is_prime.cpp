#include <bits/stdc++.h>
using namespace std;

/* snippet part start */
// 素数判定O(√n)
bool is_prime(int n){
    for(int i=2; i*i<=n; i++){
        if(n%i==0) return false;
    }
    return n != 1;  // 1の場合は例外
}
/* snippet part end */


int main(){
    int n;
    n = 57;
    cout << "素数判定 : ";
    cout << (is_prime(n)?"Yes":"No") << endl;
}
