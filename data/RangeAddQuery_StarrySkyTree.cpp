#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
static const int MAX_N = 1 << 17;

struct StarrySky {
	// datm[]:区間の最大値を管理する, data[]:加算された区間を管理する
	int datm[2 * MAX_N], data[2 * MAX_N], n;
	StarrySky() {}
	StarrySky(int n_) { init(n_); }

	// 初期化 2のべき乗に設定
	void init(int n_) {
		n = 1;
		while (n<n_) n *= 2;
		for (int i = 0; i<n * 2; i++) datm[i] = data[i] = 0;
	}

	// [a,b), x, k:節点, [l,r)
	void add(int a, int b, int x, int k, int l, int r) {
		// 区間外
		if (r <= a || b <= l) return;

		// [a,b)が[l,r)を完全に含む場合
		if (a <= l && r <= b) {
			// 区間に x を足す
			data[k] += x;
		}
		else {
			// 左の子の区間に移動
			add(a, b, x, k * 2 + 1, l, (l + r) / 2);
			// 右の子の区間に移動
			add(a, b, x, k * 2 + 2, (l + r) / 2, r);
			// 親の区間の最大値は、子の区間の最大値 + 自分に一様に加算されている値
			datm[k] = max(datm[k * 2 + 1] + data[k * 2 + 1], datm[k * 2 + 2] + data[k * 2 + 2]);
		}
	}

	// 区間[a,b)の最大値を取得する
	int get(int a, int b, int k, int l, int r) {
		// 区間外
		if (r <= a || b <= l) return 0;

		// 区間に完全に含まれる場合 
		if (a <= l && r <= b) return datm[k] + data[k];

		// 子を調べる
		int vl = get(a, b, k * 2 + 1, l, (l + r) / 2);
		int vr = get(a, b, k * 2 + 2, (l + r) / 2, r);

		// 親の区間の最大値は、この区間の最大値 + 自分に一様に加算されている値
		return max(vl, vr) + data[k];
	}

	void add(int a, int b, int x) {
		add(a, b, x, 0, 0, n);
	}

	int get(int a, int b) {
		return get(a, b, 0, 0, n);
	}

};

int main() {
	int n, q;
	cin >> n >> q;

	StarrySky ss(n);

	for (int i = 0; i < q; i++) {
		int c, s, t, x;
		cin >> c;
		if (c) {
			cin >> x;
			cout << ss.get(x - 1, x) << endl;
		}
		else {
			cin >> s >> t >> x;
			ss.add(s - 1, t, x);
		}
	}
	return 0;
}