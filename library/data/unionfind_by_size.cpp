#include <bits/stdc++.h>
using namespace std;

#define int long long
#define DEBUG(x) cerr <<#x<<":"<<x<<endl;
#define DEBUG2(x, y) cerr <<#x<<":"<<x<<" "<<#y<<":"<<y<<endl;
#define DEBUG3(x, y, z) cerr <<#x<<":"<<x<<" "<<#y<<":"<<y<<" "<<#z<<":"<<z<<endl;
#define DEBUGVC(x) cerr <<#x<<": "; for(auto a:x) cerr << a <<" "; cerr << endl;
#define DEBUGMP(x) cerr <<#x<<":"<<endl; for(auto a:x) cerr << a.first <<" "<< a.second << endl;
#define MAX_N (100005)
#define INF (1LL << 60)
const int MOD = (int)1e9 + 7;


class  DisjointSet {
    public:
        vector<int> p, siz;

        DisjointSet() {}
        DisjointSet(int size) {
            p.resize(size, 0);
            siz.resize(size, 1);
            for(int i=0; i<size; i++) makeSet(i);
        }

        void makeSet(int x){
            p[x] = x;
        }

        bool same(int x, int y){
            return findSet(x) == findSet(y);
        }

        int size(int x){
            return siz[findSet(x)];
        }

        void unite(int x, int y){
            x = findSet(x);
            y = findSet(y);
            if(x == y) return;
            if(siz[x] < siz[y]) swap(x, y);
            siz[x] += siz[y];
            p[y] = x;
        }

        int findSet(int x){
            if(x != p[x]){
                p[x] = findSet(p[x]);
            }
            return p[x];
        }
};


signed main(){
    int n, a, b, q;
    int t;

    cin >> n >> q;
    DisjointSet ds = DisjointSet(n);

    for(int i=0; i<q; i++){
        cin >> t >> a >> b;
        if(t==0) ds.unite(a, b);
        else if(t==1){
            if(ds.same(a, b)) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }

}