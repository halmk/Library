/* x > A[i] を満たすものの中で最も大きいA[i]を取り出す二分探索 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> a = {1, 14, 32, 51, 51, 243, 419, 750, 910};

// index が条件を満たすかどうか
bool isOK(int index, int key){
    if(a[index] < key) return true;
    else return false;
}

// 汎用的な二分探索のテンプレ
int binary_search(int key){
    int ng = (int)a.size();
    int ok = -1;
    
    // ここは変える必要なし
    while(abs(ok-ng) > 1){
        int mid = (ok+ng) / 2;
        
        if(isOK(mid,key)) ok = mid;
        else ng = mid;
    }
    return ok;
}

int main() {
    
    cout << binary_search(51) << endl;
    cout << binary_search(1) << endl;
    cout << binary_search(910) << endl << endl;
    
    cout << binary_search(52) << endl;
    cout << binary_search(0) << endl;
    cout << binary_search(911) << endl;
    
    
}
