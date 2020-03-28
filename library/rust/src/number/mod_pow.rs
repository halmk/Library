// unverified

const MOD:i64 = 1e9 as i64 + 7;

// x^n を高速に求める
fn mod_pow(x: i64, n: i64) -> i64 {
    let mut x = x;
    let mut n = n;
    let mut res = 1;
    while n > 0 {
        if n & 1 > 0 {
            res = res * x % MOD;
        }
        x = x * x % MOD;
        n >>= 1;
    }
    res
}


fn main() {
    let x = 2;
    let n = 10;
    assert_eq!(1024, mod_pow(2,10));
}