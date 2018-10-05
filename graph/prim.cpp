#include <bits/stdc++.h>
using namespace std;
#define INF (1 << 29)

const int MAX_V=1000;

int cost[MAX_V][MAX_V];
int mincost[MAX_V];
bool used[MAX_V];
int V;

int prim(){
    for(int i=0; i<V; i++){
        mincost[i] = INF;
        used[i] = false;
    }
    mincost[0] = 0;
    int res = 0;
    
    while(true){
        int v=-1;
        // Xに属さない頂点のうちXからの辺のコストが最小になる頂点を探す
        for(int u=0; u<V; u++){
            if(!used[u] && (v==-1 || mincost[u] < mincost[v])) v=u;
        }
        
        if(v==-1) break;
        used[v] = true;     // 頂点vをXに追加
        res += mincost[v];  // 辺のコストを加える
        
        for(int u=0; u<V; u++){
            mincost[u] = min(mincost[u], cost[v][u]);
        }
    }
    return res;
}


int main(){
    
}
