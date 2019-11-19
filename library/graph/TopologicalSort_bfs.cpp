#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

static const int MAX = 100000;
static const int INF = (1 << 29);

vector<int> G[MAX];	// 隣接リスト
list<int> out;	// トポロジカルソートした結果を格納するリスト
bool V[MAX];	// その頂点が完了したかどうか
int N;			// 頂点数
int indeg[MAX];	// その頂点の入次数

// 幅優先探索
void bfs(int s) {
	queue<int> q;
	q.push(s);
	V[s] = true;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		out.push_back(u);
		// u と隣接している頂点を調べる
		for (int i = 0; i < G[u].size(); i++) {
			// 頂点 u は完了している頂点なので、頂点 u と頂点 v をつなぐ辺を削除して考える -> 入次数をデクリメント
			int v = G[u][i];
			indeg[v]--;
			// 入次数が０で完了していない頂点をキューにプッシュ
			if (indeg[v] == 0 && !V[v]) {
				V[v] = true;
				q.push(v);
			}
		}
	}
}

void tsort() {
	// 入次数の初期化
	for (int i = 0; i < N; i++) {
		indeg[i] = 0;
	}

	// 入次数の設定
	for (int u = 0; u < N; u++) {
		for (int i = 0; i < G[u].size(); i++) {
			// 頂点 u から頂点 v へ辺が繋がっているので入次数をインクリメント
			int v = G[u][i];
			indeg[v]++;
		}
	}

	for (int u = 0; u < N; u++) {
		// 入次数が０で完了していない頂点を幅優先探索
		if (indeg[u] == 0 && !V[u]) {
			bfs(u);
		}
	}

	// トポロジカルソートした結果を表示
	for (list<int>::iterator it = out.begin(); it != out.end(); it++) {
		cout << *it << endl;
	}
}

int main() {
	int s, t, M;
	cin >> N >> M;

	for(int i=0; i<N; i++) V[i] = false;

	// 閉路なし有向グラフ
	for (int i = 0; i < M; i++) {
		cin >> s >> t;
		G[s].push_back(t);
	}

	tsort();
}
