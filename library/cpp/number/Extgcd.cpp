#include <bits/stdc++.h>
using namespace std;

int extgcd(int a, int b, int& x, int& y){
    int d = a;
    if(b != 0){
        // d は a と b の最大公約数
        d = extgcd(b, a%b, y, x);
        y -= (a / b) * x;
    } else {
        x = 1; y = 0;
    }
    return d;
}

int main(){
    int a, b, x, y, d;
    a=4; b=11;
    d = extgcd(a,b,x,y);
    cout << x <<" "<< y <<" "<< d << endl;
}
