/* imos法のオンパレード */

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define DEBUG(debug_x) cerr <<#debug_x<<": "<<debug_x<<endl;
#define DEBUG2(debug_x, debug_y) cerr <<#debug_x<<":"<<debug_x<<" "<<#debug_y<<":"<<debug_y<<endl;
#define DEBUG3(debug_x, debug_y, debug_z) cerr <<#debug_x<<":"<<debug_x<<" "<<#debug_y<<":"<<debug_y<<" "<<#debug_z<<":"<<debug_z<<endl;
#define DEBUGVC(debug_x) cerr <<#debug_x<<": "; for(auto a:debug_x) cerr << a <<" "; cerr << endl;
#define DEBUGMP(debug_x) cerr <<#debug_x<<":"<<endl; for(auto a:debug_x) cerr << a.first <<" "<< a.second << endl;
#define MAX_N (105)
#define INF (1LL << 60)
const int MOD = (int)1e9;
typedef pair<int,int> Pii;
typedef pair<double,double> Pdd;


signed main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n+1,0);
    for(int i=0; i<n; i++) cin >> a[i];
    vector<tuple<int,int,int>> vt;
    for(int i=0; i<m; i++){
        int l, r, d;
        cin >> l >> r >> d;
        l--; r--;
        vt.push_back(make_tuple(l,r,d));
    }
    vector<int> imos(m+1,0);
    for(int i=0; i<k; i++){
        int x, y;
        cin >> x >> y;
        x--; y--;
        imos[x]++;
        imos[y+1]--;
    }
    for(int i=0; i<m; i++) imos[i+1] += imos[i];
    //DEBUGVC(imos);

    vector<int> imos2(n+1,0);
    for(int i=0; i<m; i++){
        int op = imos[i];
        int x = get<0>(vt[i]), y = get<1>(vt[i]);
        int dop = op * get<2>(vt[i]);
        //DEBUG3(x,y,dop);
        imos2[x] += dop;
        imos2[y+1] -= dop;
    }

    for(int i=0; i<n; i++) imos2[i+1]+=imos2[i];

    for(int i=0; i<n; i++) {
        printf("%lld ", imos2[i]+a[i]);
    }
    cout << endl;

}
