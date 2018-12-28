#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1 << 17;

int n, dat[2*MAX_N-1];

void init(int n_){
    n = 1;
    while(n < n_) n *= 2;
    
    for(int i=0; i<(2*n-1); i++) dat[i] = INT_MAX;
}

// k 番目の値(0-indexed)を a に変更
void update(int k, int a){
    k += n-1;
    dat[k] = a;
    
    while(k > 0){
        k = (k-1)/2;
        dat[k] = min(dat[k*2+1], dat[k*2+2]);
    }
}

// [a,b)の最小値を求める. k:節点の番号. l,r:その節点が[l,r)に対応づいていることを表す.
int find(int a, int b, int k, int l, int r){
    if(r <= a || b <= l) return INT_MAX;
    
    if(a <= l && r <= b) return dat[k];
    else {
        int vl = find(a,b,k*2+1,l,(l+r)/2);
        int vr = find(a,b,k*2+2,(l+r)/2,r);
        return min(vl,vr);
    }
}

int main() {
    int q;
    cin >> n >> q;
    
    init(n);
    
    for(int i=0; i<q; i++){
        int com, x, y;
        cin >> com >> x >> y;
        if(com == 0){
            update(x,y);
        }
        else if(com == 1){
            cout << find(x,y+1,0,0,n) << endl;
        }
    }
}
