#include <bits/stdc++.h>
using namespace std;

/* snippet part start */
int gcd(int a, int b){
    //cout << a <<" "<< b << endl;
    if(b==0) return a;
    return gcd(b, a%b);
}
/* snippet part end */

int main(){
    int a, b;
    cin >> a >> b;

    cout << gcd(a,b) << endl;
}
