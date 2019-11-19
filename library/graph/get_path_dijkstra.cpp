#include <bits/stdc++.h>
using namespace std;
#define INF (1 << 29)

struct edge { int to, cost; };
typedef pair<int, int> P;   // firstは最短距離、secondは頂点の番号

const int MAX_V=1000, MAX_E=1000;

int V;
vector<edge> G[MAX_V];
int d[MAX_V];

int Prev[MAX_V];

void dijkstra(int s){
    // greater<P>を指定することでfirstが小さい順に取り出せるようにする
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d,d+V,INF);
    fill(Prev,Prev+V,-1);
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
                Prev[e.to]=v;
            }
        }
    }
}

// 頂点tへの最短路
vector<int> get_path(int t){
    vector<int> path;
    for(; t != -1; t=Prev[t]) path.push_back(t);  // tがsになるまでprev[t]を辿っていく
    // このままだとt->sの順になっているので逆順にする
    reverse(path.begin(),path.end());
    return path;
}

int main(){
    
}
