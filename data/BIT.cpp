#include "bits/stdc++.h"
using namespace std;

int N;
// bit[1]からbit[N]までを使用
int bit[1000010];


// v[a] += w  O(logN)
void add(int a, int w) {
	// x & -x は x の最も下に立っているビットで、bit[x]が管理する区間の長さ.
	// 次に更新すべき区間は、番号に区間の長さを足すと求まる.
	for (int x = a; x <= N; x += x & -x) bit[x] += w;
}

// v[1]+...+v[a]  O(logN)
int sum(int a) {
	int ret = 0;
	// 次に足すべき区間は、番号から区間の長さを引くと求まる.
	for (int x = a; x > 0; x -= x & -x) ret += bit[x];
	return ret;
}

int main() {
	int q;
	cin >> N >> q;
	for (int i = 0; i<q; i++) {
		int com, x, y;
		cin >> com >> x >> y;
		if (com == 0) {
			add(x, y);
		}
		else if (com == 1) {
			cout << sum(y) - sum(x - 1) << endl;
		}
	}
}
