#include "bits/stdc++.h"
using namespace std;
#define INF (1 << 29)

const int MAX_V = 1000;

int cost[MAX_V][MAX_V];	// グラフの隣接行列
int mincost[MAX_V];	// MSTからMSTでないの頂点へ行く最小コスト
bool used[MAX_V];	// MSTの属しているかどうか
int V;	// 頂点数

int prim() {
	for (int i = 0; i<V; i++) {
		mincost[i] = INF;
		used[i] = false;
	}
	mincost[0] = 0;
	int res = 0;	// MSTのコストの総和

	while (true) {
		int v = -1;
		// MSTに属さない頂点のうちMSTからの辺のコストが最小になる頂点を探す
		for (int u = 0; u<V; u++) {
			if (!used[u] && (v == -1 || mincost[u] < mincost[v])) v = u;
		}

		if (v == -1) break;
		used[v] = true;     // 頂点 v をMSTに追加
		res += mincost[v];  // 頂点 v が確定したので辺のコストを加える

		// 頂点 v に隣接している頂点を調べ、その時点での頂点 u への最小コストを更新する
		for (int u = 0; u<V; u++) {
			mincost[u] = min(mincost[u], cost[v][u]);
		}
	}
	return res;
}


int main() {
	cin >> V;

	// グラフが隣接行列で与えられた場合の入力
	for (int i = 0; i<V; i++) {
		for (int j = 0; j<V; j++) {
			int e; cin >> e;
			cost[i][j] = (e == -1) ? INF : e;
		}
	}

	cout << prim() << endl;
}
