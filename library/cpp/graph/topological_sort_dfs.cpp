#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/* snippet part start */
static const int MAX = 100000;

vector<int> G[MAX];	// 隣接リスト
list<int> out;	// トポロジカルソートした結果を格納するリスト
bool V[MAX];	// その頂点が完了したかどうか
int N;			// 頂点数
int indeg[MAX];	// その頂点の入次数

// 最後に行うものから順にリストに追加していく深さ優先探索
void dfs(int u) {
	V[u] = true;
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		// 完了していない頂点を深さ優先探索
		if(!V[v]) dfs(v);
	}
	out.push_front(u);
}
/* snippet part end */

int main() {
	int s, t, M;
	cin >> N >> M;

	for(int i=0; i<N; i++) V[i] = false;

	// 閉路なし有向グラフ
	for (int i = 0; i < M; i++) {
		cin >> s >> t;
		G[s].push_back(t);
	}

	for (int i = 0; i < N; i++) {
		// 完了していない頂点を深さ優先探索
		if (!V[i]) {
			dfs(i);
		}
	}

	for (list<int>::iterator it = out.begin(); it != out.end(); it++) {
		cout << *it << endl;
	}

}
