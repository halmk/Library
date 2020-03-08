// unverified

fn is_prime(n: usize) -> bool {
    let mut i = 2;
    while i*i <= n {
        if n%i==0 { return false; }
        i += 1;
    }
    n != 1
}

#[test]
fn test1() {
    let n = 57;
    println!("is_prime({}): {}", n, is_prime(n));
}