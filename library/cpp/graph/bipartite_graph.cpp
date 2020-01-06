#include <bits/stdc++.h>
using namespace std;

/* snippet part start */
const int MAX_V = 10000;

vector<int> G[MAX_V];
int V, E;
int color[MAX_V];

bool dfs(int v, int c){
    color[v] = c; // 頂点vをcで塗る
    for(int i=0; i<G[v].size(); i++){
        // 隣接している頂点が同じ色ならfalse
        if(color[G[v][i]] == c) return false;
        // 隣接している頂点がまだ塗られていないなら-cで塗る
        if(color[G[v][i]] == 0 && !dfs(G[v][i], -c)) return false;
    }
    // 全ての頂点を塗れたらtrue
    return true;
}
/* snippet part end */

int main(){
    cin >> V >> E;
    for(int i=0; i<E; i++){
        int s, t;
        cin >> s >> t;
        G[s].push_back(t);
        G[t].push_back(s);
    }

    for(int i=0; i<V; i++){
        if(color[i] == 0){
            // まだ頂点iが塗られていなければ1で塗る
            if(!dfs(i,1)){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;

    return 0;
}
