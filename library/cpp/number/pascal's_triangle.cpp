#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define INF (1<<30)

ll comb[3010][1510];

void calc_comb(ll n, ll k) {
	comb[0][0] = 0;
	comb[1][0] = comb[1][1] = 1;

	for (ll i = 2; i < n; i++) {
		for (ll j = 0; j < k; j++) {
			if(i<j) continue;
			if(j==0 || j==i) comb[i][j] = 1;
			else {
				if(comb[i-1][j]==-1 || comb[i-1][j-1]==-1) comb[i][j]=-1;
				else comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
			}
			// ‚Å‚©‚·‚¬‚½‚ç-1‚É‚·‚é
			if(comb[i][j] > (ll)1e16) comb[i][j]=-1;
		}
	}
}


int main() {
	// ‘Oˆ—
	calc_comb(3010,1510);
}
