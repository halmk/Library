/// Permute a slice into its next or previous permutation (in lexical order).

pub trait LexicalPermutation {
    fn next_permutation(&mut self) -> bool;
    fn prev_permutation(&mut self) -> bool;
}

impl<T> LexicalPermutation for [T] where T: Ord {
    fn next_permutation(&mut self) -> bool {
        if self.len() < 2 { return false; }

        let mut i = self.len() - 1;
        while i > 0 && self[i-1] >= self[i] {
            i -= 1;
        }

        if i == 0 {
            return false;
        }

        let mut j = self.len() - 1;
        while j >= i && self[j] <= self[i-1]  {
            j -= 1;
        }

        self.swap(j, i-1);
        self[i..].reverse();

        true
    }

    fn prev_permutation(&mut self) -> bool {
        if self.len() < 2 { return false; }

        let mut i = self.len() - 1;
        while i > 0 && self[i-1] <= self[i] {
            i -= 1;
        }

        if i == 0 {
            return false;
        }

        self[i..].reverse();

        let mut j = self.len() - 1;
        while j >= i && self[j-1] < self[i-1]  {
            j -= 1;
        }

        self.swap(i-1, j);

        true
    }

}

#[test]
fn lexical() {
    let mut data = [1, 2, 3];
    data.next_permutation();
    assert_eq!(&data, &[1, 3, 2]);
    data.next_permutation();
    assert_eq!(&data, &[2, 1, 3]);
    data.prev_permutation();
    assert_eq!(&data, &[1, 3, 2]);
    data.prev_permutation();
    assert_eq!(&data, &[1, 2, 3]);
    assert!(!data.prev_permutation());
    let mut c = 0;
    while data.next_permutation() {
        c += 1;
    }
    assert_eq!(c, 5);
}