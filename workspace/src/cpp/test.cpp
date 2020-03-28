#include "bits/stdc++.h"
using namespace std;

typedef long long Int;

#define MAX_N (200005)
#define INF (1LL<<60)
#define EPS (1e-7)
#define DEBUG(x) cerr << #x <<":"<< x << endl;
#define DEBUGVC(x) cerr << #x <<": "; for(auto p:(x)) cerr << p <<" "; cerr << endl;
#define DEBUGVCP(x) for(auto p:(x)) cerr << #x <<": "<< p.first <<", "<< p.second << endl;
#define DEBUG2(x, y) cerr << #x <<" : "<< x <<", "<< #y <<" : "<< y << endl;
#define DEBUG3(x, y, z) cerr << #x <<" : "<< x <<", "<< #y <<" : "<< y <<", "<< #z <<" : "<< z << endl;
const int MOD = (int)1e9+7;

int main() {
    Int n;
    cin >> n;
    cout << n << endl;
    int a[] = {0,0,0,0,1,1,1,1,2,3,4,4,4,7,8,9,10,11,12,13,14,15};
	auto cmp = [](pair<int,int> l, pair<int,int> r){
        if(l.first > r.first) return false;
        else if(l.first < r.first) return true;
        else {
            if(l.second < r.second) return false;
            else return true;
        }
    };
    priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);

    for(int i=0; i<22; i++){
        pq.push(make_pair(a[i],i));
    }

    while(!pq.empty()){
        cout << pq.top().first <<" "<< pq.top().second << endl;
        pq.pop();
    }
}