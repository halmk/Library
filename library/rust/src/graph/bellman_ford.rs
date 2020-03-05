// unverified

use std;

const MAX_E:usize = 2010;
const MAX_V:usize = 1010;
const INF:i64 = std::i64::MAX;

#[derive(Debug, Clone, Copy)]
struct Edge {
    from: usize,
    to: usize,
    cost: i64
}

// 単一始点最短経路 (負のコストを含む). 負の閉路が存在したら true を返す
fn bellman_ford(s:usize, edges:&Vec<Edge>, d:&mut Vec<i64>, V:usize, E:usize) -> bool {
    let mut cnt = 0;
    // 最短経路の初期化
    let mut d = vec![INF;V];
    d[s] = 0;
    loop {
        cnt += 1;
        let mut update = false;
        // 全ての辺に対して
        for i in 0..E {
            let e = edges[i];
            // この時点での、e.toへ行くコストより、e.fromを経由して行く方がコストが小さい時、d[e.to]を更新する
            if d[e.from] != INF && d[e.to] > d[e.from] + e.cost {
                d[e.to] = d[e.from] + e.cost;
                // V回目のループで更新が行われた場合、負の閉路が存在する
                if cnt == V as i64 { return true; }
                update = true;
            }
        }
        // 更新がなければ終了
        if !update { break; }
    }
    false
}