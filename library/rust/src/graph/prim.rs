// unverified

use std;
use std::cmp::min;

const MAX_V:usize = 500;
const INF:i64 = std::i64::MAX;

// 最小全域木のコストを求める
fn prim(cost:&mut [[i64;MAX_V];MAX_V], n:usize) -> i64 {
    let mut mincost = [INF;MAX_V]; // MSTからMSTでない頂点へ行く最小コスト
    let mut used = [false;MAX_V]; // MSTに属しているかどうか

    mincost[0] = 0;
    let mut res = 0i64;

    loop {
        let mut v:Option<usize> = None;
        // MSTに属さない頂点のうちMSTからの辺のコストが最小になる頂点を探す
        for u in 0..n {
            println!("{:?}", v);
            if !used[u] && (v.is_none() || mincost[u] < mincost[v.unwrap()]) {
                v = Some(u);
            }
        }

        if v.is_none() { break; }
        let v = v.unwrap();
        used[v] = true;     // 頂点vをMSTに追加
        res += mincost[v];  // 頂点vが確定したので辺のコストを加える

        // 頂点vに隣接している頂点を調べ、その時点での頂点uへの最小コストを更新する
        for u in 0..n {
            mincost[u] = min(mincost[u], cost[v][u]);
        }
    }
    res
}

#[test]
fn test1() {
    let v = 5;
    let mut cost = [[INF;MAX_V];MAX_V];
    cost[0][1] = 3;
    cost[1][2] = 3;
    cost[3][2] = 4;
    cost[4][3] = 2;
    cost[2][4] = 1;
    cost[0][4] = 5;
    println!("{}", prim(&mut cost, v));
}