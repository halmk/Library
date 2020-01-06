/* snippet ignore */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/* snippet part start */
static const int MAX = 100;
static const int INFTY = (1<<21);
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

int n, M[MAX][MAX];	// n:頂点数, M[][]:隣接行列

// primのアルゴリズム
int prim() {
	int u, minv;
	// d[n]:d[v]にTに属する頂点とV-Tに属する頂点をつなぐ辺の中で、重みが最小の辺の重みを記録
	// p[n]:p[v]にMSTにおける頂点vの親を記録する
	int d[MAX], p[MAX], color[MAX];

	// 初期化
	for (int i = 0; i < n; i++) {
		d[i] = INFTY;
		p[i] = -1;
		color[i] = WHITE;
	}

	d[0] = 0;

	while (1) {
		minv = INFTY;
		u = -1;
		// VとV-Tをつなぐ辺のうち最小の辺の重みとなる頂点 u を探す
		for (int i = 0; i < n; i++) {
			if (minv > d[i] && color[i] != BLACK) {
				u = i;
				minv = d[i];
			}
		}
		if(u == -1) break;
		// 頂点 u をMSTに追加
		color[u] = BLACK;

		for (int v = 0; v < n; v++) {
			if (color[v] != BLACK && M[u][v] != INFTY) {
				if (d[v] > M[u][v]) {
					// この時点での頂点 v への最小コストを更新する。またその親を u とする
					d[v] = M[u][v];
					p[v] = u;
					color[v] = GRAY;
				}
			}
		}
	}
	// 最小全域木の総和を計算　最適な辺は頂点 i と 頂点 p[i](頂点iの親) を結ぶ辺となる。
	int sum=0;
	for (int i = 0; i < n; i++) {
		if(p[i] != -1) sum += M[i][p[i]];
	}

	return sum;
}
/* snippet part end */

int main() {
	cin >> n;

	// 隣接行列が与えられる
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int e; cin >> e;
			M[i][j] = (e == -1) ? INFTY : e;
		}
	}

	cout << prim() << endl;
}
