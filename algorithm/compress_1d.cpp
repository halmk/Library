#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

vector<int> compress(vector<int> a) {
	vector<int> b = a, res;
	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());
	for (int x : a) {
		int tmp = lower_bound(b.begin(), b.end(), x) - b.begin();
		res.push_back(tmp);
	}

	return res;
}

int main() {
	int N; cin >> N;
	vector<int> a(N);
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	
	vector<int> b = compress(a);
	for(int x:b) cout << x <<" "; cout << endl;

}
