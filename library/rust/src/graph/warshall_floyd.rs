// unverified

use std;
use std::cmp::min;

const MAX_V:usize = 100;
const INF:i64 = std::i64::MAX;

// 全点対間最短経路 O(V^3)
fn warshall_floyd(n:usize, d: &mut [[i64;MAX_V];MAX_V]) {
    for k in 0..n {
        for i in 0..n {
            if d[i][k] == INF { continue; }
            for j in 0..n {
                if d[k][j] == INF { continue; }
                d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
            }
        }
    }
}

#[test]
fn test1() {
    let n = 5;
    let e = 4;
    let mut d = [[0i64;MAX_V];MAX_V];
    for i in 0..n {
        for j in 0..n {
            d[i][j] = if i==j {0} else {INF};
        }
    }

    d[0][1] = 3;
    d[1][3] = 4;
    d[2][3] = 2;
    d[1][2] = 3;

    warshall_floyd(n, &mut d);

    assert_eq!(3, d[0][1]);
    assert_eq!(6, d[0][2]);
    assert_eq!(7, d[0][3]);
}