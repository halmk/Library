// unverified

use std::collections::BTreeMap;

fn prime_factor(n: usize) -> BTreeMap<usize,usize> {
    let mut n = n;
    let mut map = BTreeMap::new();
    let mut i = 2;
    while i*i <= n {
        while n%i == 0 {
            let count = map.entry(i).or_insert(0usize);
            *count += 1;
            n /= i;
        }
        i += 1;
    }
    if n!=1 { map.insert(n,1); }
    map
}


#[test]
fn test1() {
    let n = 57;
    let factor = prime_factor(n);
    println!("{:#?}", factor);
}