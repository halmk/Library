/* Range Update Query */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF (1<<20)

/* snippet part start */
const int MAX_N = 1 << 18;
typedef pair<int,int> P;

int n;
// Segment-Tree first:最後に変更した番号, second:その区間の値
P dat[2*MAX_N-1];

// 2のべき乗で初期化
void init(int n_) {
	n=1;
	while(n < n_) n*=2;
	for(int i=0; i<2*n-1; i++) dat[i].first = -1, dat[i].second = INT_MAX;
}

// k 番目の値(0-indexed)を求める
// (葉の値がk番目の値とは限らない. 親の区間で最後に更新された場所を探す)
int find(int k) {
	// 葉の節点
	k += n-1;
	P p=dat[k];

	// 登りながら求める
	while (k > 0) {
		// kの親を求める
		k = (k-1)/2;
		// firstの最大値を求める -> 最後に変更された場所
		p = max(p, dat[k]);
	}
	return p.second;
}

// [a,b)を x に変更する. k:節点, [l,r)
void update(int a, int b, int k, P p, int l, int r) {
	// 範囲外ならreturn
	if(r <= a || b <= l) return;
	// [l,r)が[a,b)の区間に完全に含まれるならその節点を p をする
	if (a <= l && r <= b) {
		dat[k] = p;
	}
	// それ以外なら、２つの子に移る
	else {
		update(a,b,k*2+1,p,l,(l+r)/2);
		update(a,b,k*2+2,p,(l+r)/2,r);
	}
}
/* snippet part end */


int main() {
	int _n, q;
	cin >> _n >> q;
	init(_n+1);

	for (int i = 0; i < q; i++) {
		// 0:update(s,t+1,0,(i,x),0,n), 1:find(u)
		int f;
		cin >> f;
		if (f) {
			int u;
			cin >> u;
			cout << find(u) << endl;
		}
		else {
			int s,t,x;
			cin >> s >> t >> x;
			update(s,t+1,0,P(i,x),0,n);
		}
	}

}