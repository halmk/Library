// verified: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=4233861

use std;
use std::collections::BinaryHeap;

#[derive(Debug, Clone, Copy)]
struct Edge {
    to: usize,
    cost: i64
}

// 単一始点最短路問題 O(ElogV)
fn dijkstra(s: usize, G: &Vec<Vec<Edge>>, V: usize) -> Vec<i64> {
    // 最も小さい距離のものを高速に取り出す優先度付きキュー
    let mut que = BinaryHeap::new();

    let mut d = vec![std::i64::MAX; V];
    d[s] = 0;
    que.push((0,s));

    while !que.is_empty() {
        // 最も距離の小さいものを取り出す
        let p = que.pop().unwrap();
        let v = p.1;
        // これまでの頂点vへのコストより距離が大きいならスキップ
        if d[v] < p.0 { continue; }
        // 頂点vと隣接している頂点を調べる
        for i in 0..G[v].len() {
            let e = &G[v][i];
            // この時点での頂点e.toへの最短経路より頂点vを経由して頂点e.toに行く経路の方が短いとき、最短経路を更新する
            if d[e.to] > d[v] + e.cost {
                d[e.to] = d[v] + e.cost;
                que.push((-d[e.to], e.to));
            }
        }
    }

    d
}


#[cfg(test)]
mod tests {
    use super::dijkstra;
    use super::Edge;
    use std;

    #[test]
    fn test1() {
        let V = 5;
        let E = 4;
        let mut G = vec![vec![];V];

        G[0].push(Edge{to:1,cost:2});
        G[2].push(Edge{to:4,cost:4});
        G[1].push(Edge{to:0,cost:1});
        G[4].push(Edge{to:0,cost:3});

        let d = dijkstra(0, &G, V);
        println!("{:?}", d);
        assert_eq!(0, d[0]);
        assert_eq!(2, d[1]);
        assert_eq!(std::i64::MAX, d[2]);
        assert_eq!(std::i64::MAX, d[3]);
        assert_eq!(std::i64::MAX, d[4]);

    }
}