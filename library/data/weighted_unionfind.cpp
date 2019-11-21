#include <bits/stdc++.h>
using namespace std;

class WeightedUnionFind {
public:
    vector<int> par;
    vector<int> rank;
    vector<int> diff_weight;
    
    WeightedUnionFind() {}
    WeightedUnionFind(int size, int weight){
        rank.resize(size,0);
        par.resize(size,0);
        diff_weight.resize(size,0);
        for(int i=0; i<size; i++) makeSet(i,weight);
    }
    
    void makeSet(int x, int weight){
        par[x] = x;
        rank[x] = 0;
        diff_weight[x] = weight;
    }
    
    bool same(int x, int y){
        return findSet(x) == findSet(y);
    }
    
    bool relate(int x, int y, int w){
        w += weight(x); w -= weight(y);
        x = findSet(x); y = findSet(y);
        
        if(x == y) return false;
        if(rank[x] < rank[y]){
            swap(x,y);
            w = -w;
        }
        if(rank[x] == rank[y]) rank[x]++;
        par[y] = x;
        diff_weight[y] = w;
        return true;
    }
    
    int diff(int x, int y){
        return weight(y) - weight(x);
    }
    
    int weight(int x){
        findSet(x);
        return diff_weight[x];
    }
    
    int findSet(int x){
        if(par[x] == x){
            return x;
        }
        else {
            int r = findSet(par[x]);
            diff_weight[x] += diff_weight[par[x]];
            return par[x] = r;
        }
    }
    
};

int main() {
    int n, q;
    cin >> n >> q;
    
    WeightedUnionFind wuf = WeightedUnionFind(n, 0);
    
    for(int i=0; i<q; i++){
        int t, x, y;
        cin >> t >> x >> y;
        if(t==0){
            int z; cin >> z;
            wuf.relate(x, y, z);
        }
        else if(t==1){
            if(!wuf.same(x,y)){
                cout << '?' << endl;
                continue;
            }
            cout << wuf.diff(x,y) << endl;
        }
    }
}
