#include <bits/stdc++.h>
using namespace std;
#define INF (1 << 29)

struct edge { int to, cost; };
typedef pair<int, int> P;   // firstは最短距離、secondは頂点の番号

const int MAX_V=1000, MAX_E=1000;

int V, E;
vector<edge> G[MAX_V];
int d[MAX_V];

void dijkstra(int s){
    // greater<P>を指定することでfirstが小さい順に取り出せるようにする
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d,d+V,INF);
    d[s]=0;
    que.push(P(0,s));
    
    while(!que.empty()){
        P p = que.top(); que.pop();
        int v=p.second;
        if(d[v] < p.first) continue;
        for(int i=0; i<G[v].size(); i++){
            edge e=G[v][i];
            if(d[e.to] > d[v]+e.cost){
                d[e.to] = d[v]+e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}
int main() {
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int s, t, cost;
		cin >> s >> t >> cost;
		s--; t--;
		G[s].push_back(edge{ t, cost });
		G[t].push_back(edge{ s, cost });
	}
	// 処理
}
