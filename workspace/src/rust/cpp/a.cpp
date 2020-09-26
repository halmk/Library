#include <bits/stdc++.h>
using namespace std;

#define int long long

// debug methods
// usage: debug(x,y);
#define CHOOSE(a) CHOOSE2 a
#define CHOOSE2(a0,a1,a2,a3,a4,x,...) x
#define debug_1(x1) cout<<#x1<<": "<<x1<<endl
#define debug_2(x1,x2) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<endl
#define debug_3(x1,x2,x3) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<", "#x3<<": "<<x3<<endl
#define debug_4(x1,x2,x3,x4) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<", "#x3<<": "<<x3<<", "#x4<<": "<<x4<<endl
#define debug_5(x1,x2,x3,x4,x5) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<", "#x3<<": "<<x3<<", "#x4<<": "<<x4<<", "#x5<<": "<<x5<<endl
#ifdef _DEBUG
#define debug(...) CHOOSE((__VA_ARGS__,debug_5,debug_4,debug_3,debug_2,debug_1,~))(__VA_ARGS__)
#else
#define debug(...)
#endif

#define MAX_N (1000006)
#define INF (1LL << 60)
const int MOD = (int)1e9 + 7;

vector<vector<int>> c;
vector<vector<bool>> f(100, vector<bool>(100,false));
int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};
int h, w;

void dfs(int i, int j) {
    f[i][j] = true;

    for(int k=-1; k<=1; k++){
        for(int l=-1; l<=1; l++){
            int ni = i+k;
            int nj = j+l;
            if(ni<0||ni>=h||nj<0||nj>=w) continue;
            if(f[ni][nj]) continue;
            if(c[ni][nj] == 0) continue;
            dfs(ni,nj);
        }
    }

}

signed main(){
    while(1) {
        cin >> w >> h;
        if(w==0&&h==0) break;
        c.resize(h);
        for(int i=0; i<h; i++){
            c[i].assign(w, 0);
            f[i].assign(100,false);
            for(int j=0; j<w; j++){
                cin >> c[i][j];
            }
        }
        int ans = 0;
        for(int i=0; i<h; i++) {
            for(int j=0; j<w; j++) {
                if(f[i][j]) continue;
                if(c[i][j]==0) continue;
                ans++;
                dfs(i,j);
            }
        }
        cout << ans << endl;
    }
}

/*


*/
