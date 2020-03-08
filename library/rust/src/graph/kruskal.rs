// unverified

use std::cmp::*;

#[derive(Debug, Clone)]
struct UnionFind {
    rank: Vec<usize>,
    p: Vec<usize>,
}

impl UnionFind {
    fn new(size: usize) -> UnionFind {
        let mut tree = UnionFind{ rank: vec![0;size], p: vec![0;size] };
        for i in 0..size { tree.make_set(i); }
        tree
    }

    // 初期化
    fn make_set(&mut self, x: usize) {
        self.p[x] = x;
        self.rank[x] = 0;
    }

    // xとyが同じ集合かどうか
    fn same(&mut self, x: usize, y: usize) -> bool {
        self.find_set(x) == self.find_set(y)
    }

    // xとyの属する集合を併合
    fn unite(&mut self, x: usize, y: usize) {
        let (root_x, root_y) = (self.find_set(x), self.find_set(y));
        self.link(root_x, root_y);
    }

    // xとyの属する木を併合する時の操作
    fn link(&mut self, x: usize, y: usize) {
        if self.rank[x] > self.rank[y] {
            self.p[y] = x;
        } else {
            self.p[x] = y;
            if self.rank[x] == self.rank[y] {
                self.rank[y] += 1;
            }
        }
    }

    // xの根を求める. 求める途中で辿った要素が根に直接指すようにする
    fn find_set(&mut self, x: usize) -> usize {
        if x != self.p[x] {
            let q = self.p[x];
            self.p[x] = self.find_set(q);
        }
        self.p[x]
    }
}

#[derive(Debug, Clone, Copy, PartialEq, Eq, PartialOrd)]
struct Edge {
    from: usize,
    to: usize,
    cost: i64,
}

impl Ord for Edge {
    fn cmp(&self, other: &Self) -> Ordering {
        self.cost.cmp(&other.cost)
    }
}

fn kruskal(n:usize, edges:&mut Vec<Edge>) -> i64 {
    let mut total_cost = 0i64;
    edges.sort();

    let mut tree = UnionFind::new(n+1);

    for i in 0..edges.len() {
        let e = edges[i];
        if !tree.same(e.from, e.to) {
            total_cost += e.cost;
            tree.unite(e.from, e.to);
        }
    }
    total_cost
}

#[test]
fn test1() {
    let n = 5;
    let m = 4;
    let mut edges = vec![];
    edges.push(Edge{from:0, to:1, cost:2});
    edges.push(Edge{from:1, to:4, cost:3});
    edges.push(Edge{from:2, to:4, cost:4});
    edges.push(Edge{from:1, to:3, cost:1});
    edges.push(Edge{from:3, to:4, cost:3});

    println!("{}", kruskal(n, &mut edges));
}