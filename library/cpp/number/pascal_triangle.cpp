#include <bits/stdc++.h>
using namespace std;

#define INF (1<<30)

/* snippet part start */
int comb[3010][1510];

void calc_comb(int n, int k) {
	comb[0][0] = 0;
	comb[1][0] = comb[1][1] = 1;

	for (int i = 2; i < n; i++) {
		for (int j = 0; j < k; j++) {
			if(i<j) continue;
			if(j==0 || j==i) comb[i][j] = 1;
			else {
				if(comb[i-1][j]==-1 || comb[i-1][j-1]==-1) comb[i][j]=-1;
				else comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
			}
			if(comb[i][j] > (int)1e16) comb[i][j]=-1;
		}
	}
}
/* snippet part end */


int main() {
	calc_comb(3010,1510);
}
