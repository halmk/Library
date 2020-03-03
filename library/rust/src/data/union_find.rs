// verified: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=4229956

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


#[cfg(test)]
mod tests {
    use super::UnionFind;

    #[test]
    fn test1() {
        let mut tree = UnionFind::new(10);
        tree.unite(0,1);
        tree.unite(2,3);
        tree.unite(4,5);
        assert!(tree.same(0,1));
        assert!(tree.same(3,2));
        tree.unite(3,4);
        assert!(tree.same(2,5));
    }
}