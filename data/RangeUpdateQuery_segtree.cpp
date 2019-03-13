/* Range Update Query */
#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

#define INF (1<<20)
const int MAX_N = 1 << 18;
typedef pair<int,int> P;

int n;
// Segment-Tree first:�Ō�ɕύX�����ԍ�, second:���̋�Ԃ̒l
P dat[2*MAX_N-1];

// 2�ׂ̂���ŏ�����
void init(int n_) {
	n=1;
	while(n < n_) n*=2;
	for(int i=0; i<2*n-1; i++) dat[i].first = -1, dat[i].second = INT_MAX;
}

// k �Ԗڂ̒l(0-indexed)�����߂� 
// (�t�̒l��k�Ԗڂ̒l�Ƃ͌���Ȃ�. �e�̋�ԂōŌ�ɍX�V���ꂽ�ꏊ��T��)
int find(int k) {
	// �t�̐ߓ_
	k += n-1;
	P p=dat[k];

	// �o��Ȃ��狁�߂�
	while (k > 0) {
		// k�̐e�����߂�
		k = (k-1)/2;
		// first�̍ő�l�����߂� -> �Ō�ɕύX���ꂽ�ꏊ
		p = max(p, dat[k]);
	}
	return p.second;
}

// [a,b)�� x �ɕύX����. k:�ߓ_, [l,r)
void update(int a, int b, int k, P p, int l, int r) {
	// �͈͊O�Ȃ�return
	if(r <= a || b <= l) return;
	// [l,r)��[a,b)�̋�ԂɊ��S�Ɋ܂܂��Ȃ炻�̐ߓ_�� p ������
	if (a <= l && r <= b) {
		dat[k] = p;
	}
	// ����ȊO�Ȃ�A�Q�̎q�Ɉڂ�
	else {
		update(a,b,k*2+1,p,l,(l+r)/2);
		update(a,b,k*2+2,p,(l+r)/2,r);
	}
}


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