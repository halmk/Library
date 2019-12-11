#include <bits/stdc++.h>
using namespace std;

#define int long long
#define DEBUG(x) cerr <<#x<<":"<<x<<endl;
#define DEBUG2(x, y) cerr <<#x<<":"<<x<<" "<<#y<<":"<<y<<endl;
#define DEBUG3(x, y, z) cerr <<#x<<":"<<x<<" "<<#y<<":"<<y<<" "<<#z<<":"<<z<<endl;
#define DEBUGVC(x) cerr <<#x<<": "; for(auto a:x) cerr << a <<" "; cerr << endl;
#define DEBUGMP(x) cerr <<#x<<":"<<endl; for(auto a:x) cerr << a.first <<" "<< a.second << endl;
#define MAX_N (1000006)
#define INF (1LL << 60)
const int MOD = (int)1e9+7;


signed main(){
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    s.push_back('#');

    set<pair<int,int>> st;
    int sum=0, cnt=0;
    pair<int,int> pr;
    pr.first = pr.second = 0;
    for(int i=0; i<=n; i++){
        if(s[i]=='.'){
            if(pr.second==0) pr.first = i;
            pr.second++;
        }
        else {
            if(pr.second==0) continue;
            st.insert(pr);
            sum += pr.second-1;
            pr.first = pr.second = 0;
        }
    }
    for(auto it: st) cout << it.first <<" "<< it.second << endl;
    DEBUG(sum);

    for(int i=0; i<m; i++){
        int x;
        char c;
        cin >> x >> c;
        x--;
        if(st.size()==0){
            if(c=='.'){
                st.insert(make_pair(x,1));
            }
            cout << sum << endl;
            continue;
        }
        auto last = st.upper_bound(make_pair(n-1,INF));
        auto upb = st.upper_bound(make_pair(x,INF));
        
        if(upb == st.begin()) {
            //cout << (*upb).first <<" "<< (*upb).second << endl;
            if(c=='.'){
                if(x+1 == (*upb).first){
                    st.erase(upb);
                    st.insert(make_pair(x, (*upb).second+1));
                    sum++;
                } else {
                    st.insert(make_pair(x,1));
                }
            }
            cout << sum << endl;
            continue;
        }
        auto up = (--st.upper_bound(make_pair(x,INF)));

        auto it = *up;
        DEBUG2(it.first,it.second);
        DEBUG2(x, it.first+it.second-1);
        int rig = it.first+it.second-1;
        if(x <= rig){
            if(c!='.') {
                st.erase(make_pair(it.first,it.second));
                sum -= it.second-1;
                pair<int,int> pr1, pr2;
                pr1 = make_pair(it.first,x-it.first);
                pr2 = make_pair(x+1,rig-x);
                //DEBUG2(pr1.first,pr1.second);
                //DEBUG2(pr2.first,pr2.second);
                if(pr1.second!=0) {
                    st.insert(pr1);
                    sum += pr1.second-1;
                }
                if(pr2.second!=0) {
                    st.insert(pr2);
                    sum += pr2.second-1;
                }
            }
        }
        else if(x == rig+1){
            auto it2 = *(--st.upper_bound(make_pair(x+1,INF)));
            DEBUG2(it2.first, it2.second);
            if(it2.first == x+1){
                st.erase(make_pair(it.first,it.second));
                st.erase(make_pair(it2.first,it2.second));
                int len = it.second+it2.second+1;
                pair<int,int> pr3 = make_pair(it.first, len);
                st.insert(pr3);
                sum -= it.second-1;
                sum -= it2.second-1;
                sum += len-1;
            } else {
                st.erase(make_pair(it.first,it.second));
                st.insert(make_pair(it.first,it.second+1));
                sum++;
            }
        }
        else {
            if(c=='.'){
                st.insert(make_pair(x,1));
            }
        }
        for(auto it: st) cout << it.first <<" "<< it.second << endl;
        cout << sum << endl;
        DEBUG("");
        
    }

}