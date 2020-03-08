// unverified

fn divisor(n:usize) -> Vec<usize> {
    let mut res = Vec::new();
    let mut i = 1;
    while i*i <= n {
        if n%i == 0 {
            res.push(i);
            if i != n/i { res.push(n/i); }
        }
        i += 1;
    }
    res.sort();
    res
}

#[test]
fn test1() {
    let n = 57;
    println!("{:?}", divisor(n));
}