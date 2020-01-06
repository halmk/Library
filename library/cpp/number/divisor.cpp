#include <bits/stdc++.h>
using namespace std;


/* snippet part start */
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
/* snippet part end */


int main(){
    vector<int> div;
    div = divisor(n);
    cout << "約数の列挙 : ";
    for(int i=0; i<div.size(); i++) cout << div[i] <<" ";
    cout << endl;
}
