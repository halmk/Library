#include <bits/stdc++.h>
using namespace std;

/* 素数判定 */

// 入力は全て正とする
// 素数判定O(√n)
bool is_prime(int n){
    for(int i=2; i*i<=n; i++){
        if(n%i==0) return false;
    }
    return n != 1;  // 1の場合は例外
}

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

int main(){
    int n;
    n = 57;
    cout << "素数判定 : ";
    cout << (is_prime(n)?"Yes":"No") << endl;
    vector<int> div;
    div = divisor(n);
    cout << "約数の列挙 : ";
    for(int i=0; i<div.size(); i++) cout << div[i] <<" ";
    cout << endl;
    map<int, int> factor;
    factor = prime_factor(n);
    cout << "素因数分解 : " << endl;
    for(auto itr = factor.begin(); itr != factor.end(); itr++){
        cout << itr->first <<" "<< itr->second << endl;
    }
}
