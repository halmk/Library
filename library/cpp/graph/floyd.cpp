#include <bits/stdc++.h>
using namespace std;

/* snippet part start */
static const int MAX = 100;
static const long long INFTY = (1LL << 32);

int n;
long long d[MAX][MAX];

// ワーシャルフロイド（全点対間最短経路(動的計画法)）
void floyd() {
	for (int k = 0; k<n; k++) {
		for (int i = 0; i<n; i++) {
			if (d[i][k] == INFTY) continue;
			for (int j = 0; j<n; j++) {
				if (d[k][j] == INFTY) continue;
				// 頂点 k を経由する場合としない場合の最小コストを求める
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
}
/* snippet part end */

int main() {
	int e, u, v, c;
	cin >> n >> e;

	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			d[i][j] = ((i == j) ? 0 : INFTY);
		}
	}

	for (int i = 0; i<e; i++) {
		cin >> u >> v >> c;
		d[u][v] = c;
	}

	floyd();

	// ある頂点からそれ自身への最短距離が負になっていれば負の経路が存在する
	bool negative = false;
	for (int i = 0; i<n; i++) if (d[i][i]<0) negative = true;

	if (negative) {
		cout << "NEGATIVE CYCLE" << endl;
	}
	else {
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<n; j++) {
				if (j) cout << " ";
				if (d[i][j] == INFTY) cout << "INF";
				else cout << d[i][j];
			}
			cout << endl;
		}
	}

	return 0;
}
