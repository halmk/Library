#include <bits/stdc++.h>
using namespace std;

#define int long long
#define debug(x) cerr << #x <<" : "<< x << endl;
#define MAX_N (200005)
#define INF (1LL << 60)
const int MOD = (int)1e9 + 7;

vector<double> a(10);

double f(double x, int dm){
    double res;
    int cntx = dm;
    for(int i=0; i<dm; i++){
        double b = a[i];
        for(int j=0; j<cntx; j++) b *= x;
        cntx--;
        res += b;
    }
    return res;
}

double fdash(double x, int dm){
    double res;
    int cntx = dm-1, k=dm;
    for(int i=0; i<dm-1; i++){
        double b = a[i]*k;
        for(int j=0; j<dm-1; j++) b *= x;
        cntx--;
        k--;
        res += b;
    }
    return res;
}

double newton(double x0, double eps, int dm){
    while(1){
        printf("%.10f\n", x0);
        double x1 = x0 - f(x0, dm) / fdash(x0, dm);
        if(abs(x1-x0)<eps) return x1;
        x0 = x1;
    }
}

signed main(){
    double x0=1.0e6, eps=1.0e-6, dm;
    cin >> dm;

    for(int i=0; i<=dm; i++){
        cin >> a[i];
    }

    cout <<"Start."<< endl;
    printf("%.10f\n", newton(x0, eps, dm));

}