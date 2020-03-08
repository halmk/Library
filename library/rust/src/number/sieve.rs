// unverified

fn sieve(n:usize) -> usize {
    let mut p = 0;
    let mut is_prime = vec![true;n+1];
    let mut prime = vec![0;n+1];

    is_prime[0] = false;
    is_prime[1] = false;

    for i in 2..n+1 {
        if is_prime[i] {
            prime[p] = i;
            p += 1;
            let mut j = 2*i;
            while j<=n {
                is_prime[j] = false;
                j += i;
            }
        }
    }
    p
}

#[test]
fn test1() {
    let n = 1000;
    println!("{}", sieve(n));
}