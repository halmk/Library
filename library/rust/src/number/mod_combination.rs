// unverified

const MAX_N:usize = 3000;
const MOD:i64 = 1e9 as i64 + 7;

struct Comb {
    fac: Vec<i64>,
    finv: Vec<i64>,
    inv: Vec<i64>
}

impl Comb {
    fn new() -> Self {
        let mut fac = vec![0i64;MAX_N];
        let mut finv = vec![0i64;MAX_N];
        let mut inv = vec![0i64;MAX_N];

        fac[0] = 1;
        fac[1] = 1;
        finv[0] = 1;
        finv[1] = 1;
        inv[1] = 1;

        for i in 2..MAX_N {
            fac[i] = fac[i-1] * i as i64 % MOD;
            inv[i] = MOD - inv[(MOD%i as i64) as usize] * (MOD/i as i64) % MOD;
            finv[i] = finv[i-1] * inv[i] % MOD;
        }

        Comb{fac:fac,finv:finv,inv:inv}
    }

    fn comb(&self, n: usize, k: usize) -> i64 {
        if n < k { return 0; }
        if n < 0 || k < 0 { return 0; }
        self.fac[n] * (self.finv[k] * self.finv[n-k] % MOD) % MOD
    }
}

#[test]
fn test1() {
    let table = Comb::new();
    let n = 20;
    let k = 4;
    println!("comb({},{}): {}", n, k, table.comb(n,k));
}