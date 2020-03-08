// unverified

use std::cmp::max;

fn segment_sieve(a: usize, b: usize) -> Vec<bool> {
    let mut is_prime_small = vec![true;(b as f64).sqrt() as usize + 1];
    let mut is_prime = vec![true;b-a];

    for i in 2..(b as f64).sqrt() as usize {
        if is_prime_small[i] {
            let mut j = 2*i;
            while j*j < b {
                is_prime_small[j] = false;
                j += i;
            }
            let mut j = max(2, (a+i-1)/i) * i;
            while j < b {
                is_prime[j-a] = false;
                j += i;
            }
        }
    }

    is_prime
}

#[test]
fn test1() {
    let a = 22;
    let b = 37;
    let is_prime = segment_sieve(a,b);
    let mut cnt = 0;
    for i in a..b {
        if is_prime[i-a] {
            cnt += 1;
            println!("{}", i);
        }
    }
    println!("count: {}", cnt);
}