#include <bits/stdc++.h>
using namespace std;

#define int long long
#define debug(x) cerr << #x <<" : "<< x << endl;
#define debugVec(x) for(auto p:x) cerr << p <<" "; cerr << endl;
#define debug2arg(x, y) cerr << #x <<":"<< x <<" "<< #y <<":"<< y << endl;
#define debug3arg(x, y, z) cerr << #x <<":"<< x <<" "<< #y <<":"<< y <<" "<< #z <<":"<< z << endl;
#define MAX_N (200005)
#define MAX (300005)
#define INF (1LL << 60)
const int MOD = (int)1e9 + 7;

/* 引数 s がBracket Sequence かどうかを返す O(s.length()) */
bool isBracket(string s){
    // 括弧のそれぞれの数をカウント
    int cnt1=0, cnt2=0;
    for(int i=0; i<s.length(); i++){
        if(s[i]=='(') cnt1++;
        else cnt2++;
    }
    // スタックで部分的にBracketSequenceになっている場所を削除していく
    stack<char> st;
    for(int i=0; i<s.length(); i++){
        char ch = '0';
        if(!st.empty()) ch = st.top();
        if(s[i]==')'){
            if(ch=='('){
                cnt1--;
                cnt2--;
                st.pop();
            } else {
                st.push(s[i]);
            }
        } else {
            st.push(s[i]);
        }
    }

    // 消されなかった括弧がある場合はfalse
    if(cnt1>0 || cnt2>0) return false;
    else return true;
}

signed main(){
    string s = ")()", t = "(()())";

    cout << isBracket(s) << endl;
    cout << isBracket(t) << endl;

}