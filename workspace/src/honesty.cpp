#include <bits/stdc++.h>
using namespace std;

#define int long long
#define DEBUG(x) cerr <<#x<<":"<<x<<endl;
#define DEBUG2(x, y) cerr <<#x<<":"<<x<<" "<<#y<<":"<<y<<endl;
#define DEBUG3(x, y, z) cerr <<#x<<":"<<x<<" "<<#y<<":"<<y<<" "<<#z<<":"<<z<<endl;
#define DEBUGVC(x) cerr <<#x<<": "; for(auto a:x) cerr << a <<" "; cerr << endl;
#define DEBUGMP(x) cerr <<#x<<":"<<endl; for(auto a:x) cerr << a.first <<" "<< a.second << endl;
#define MAX_N (1000006)
#define INF (1LL << 60)
const int MOD = (int)1e9 + 7;

struct INFO {
    int first;
    int last;
    int cost;
};

signed main(){
    int n, x;
    cin >> n >> x;
    vector<INFO> vc;
    for(int i=0; i<n; i++) {
        int l, r, c;
        cin >> l >> r >> c;
        vc.push_back({l,r,c});
    }

    int mn=INF;
    bool F=false;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int d1 = vc[i].last-vc[i].first+1;
            int d2 = vc[j].last-vc[j].first+1;
            if(vc[i].last < vc[j].first || vc[j].last < vc[i].first){
                if(d1+d2==x){
                    F=true;
                    mn = min(mn, vc[i].cost+vc[j].cost);
                }
            }
        }
    }

    cout << (F?mn:-1) << endl;
}