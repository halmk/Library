// verified: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=4230034

#[derive(Debug, Clone)]
struct UnionFind {
    p: Vec<usize>,
    sizes: Vec<usize>
}

impl UnionFind {
    fn new(size: usize) -> UnionFind {
        let mut tree = UnionFind{ p: vec![0;size], sizes: vec![1;size] };
        for i in 0..size { tree.make_set(i); }
        tree
    }

    // 初期化
    fn make_set(&mut self, x: usize) {
        self.p[x] = x;
    }

    // xとyが同じ集合に属しているかどうか
    fn same(&mut self, x: usize, y: usize) -> bool {
        self.find_set(x) == self.find_set(y)
    }

    // xの集合のサイズを求める
    fn size(&mut self, x: usize) -> usize {
        let root_x = self.find_set(x);
        self.sizes[root_x]
    }

    // xとyの集合を併合する
    fn unite(&mut self, x: usize, y: usize) {
        let x = self.find_set(x);
        let y = self.find_set(y);
        if x == y { return; }
        if self.sizes[x] < self.sizes[y] { self.sizes.swap(x,y); }
        self.sizes[x] += self.sizes[y];
        self.p[y] = x;
    }

    // xの根を求める
    fn find_set(&mut self, x: usize) -> usize {
        if x != self.p[x] {
            let q = self.p[x];
            self.p[x] = self.find_set(q);
        }
        self.p[x]
    }
}