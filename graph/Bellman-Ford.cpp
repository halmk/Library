#include <bits/stdc++.h>
using namespace std;

const int MAX_E=1000;
const int MAX_V=1000;

#define INF (1 << 29)

//
struct edge { int from, to, cost; };

edge es[MAX_E]; // 辺

int d[MAX_V];
int V, E;

//
void bellman_ford(int s){
    //
    for(int i=0; i<V; i++) d[i]=INF;
    //
    d[s] = 0;
    while(true){
        bool update=false;
        //
        for(int i=0; i<E; i++){
            //
            edge e = es[i];
            cout << d[e.from] <<" "<< d[e.to] <<" "<< e.cost <<"  ";
            //
            if(d[e.from] != INF && d[e.to] > d[e.from] + e.cost){
                //
                d[e.to] = d[e.from] + e.cost;
                //
                update = true;
            }
        }
        cout << endl;
        //
        if(!update) break;
    }
    
    cout << d[E-1] << endl;
}

//
//
bool find_negative_loop(){
    //
    memset(d, 0, sizeof(d));
    
    //
    for(int i=0; i<V; i++){
        for(int j=0; j<E; j++){
            edge e = es[j];
            if(d[e.to]>d[e.from]+e.cost){
                d[e.to]=d[e.from]+e.cost;
                
                // 
                if(i==V-1) return true;
            }
        }
    }
    return false;
}

int main(){
    cin >> V >> E;
    int from, to, cost;
    for(int i=0; i<E; i++){
        cin >> from >> to >> cost;
        es[i] = (edge){from,to,cost};
    }
    bellman_ford(0);
}
