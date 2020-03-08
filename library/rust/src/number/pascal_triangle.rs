// unverified

const MAX_N:usize = 1000;
const MOD:i64 = 1e9 as i64 + 7;

// O(N^2)
fn init_comb() -> Vec<Vec<i64>> {
    let mut comb = vec![vec![0i64;MAX_N];MAX_N];
    comb[1][0] = 1;
    comb[1][1] = 1;

    for i in 2..MAX_N {
        for j in 0..MAX_N {
            if i < j { continue; }
            if j==0 || j==i { comb[i][j] = 1; }
            else {
                comb[i][j] = comb[i-1][j] + comb[i-1][j-1];
                comb[i][j] %= MOD;
            }
        }
    }
    comb
}

#[test]
fn test1() {
    let comb = init_comb();
    let n = 20;
    let k = 4;
    println!("comb[{}][{}]: {}", n, k, comb[n][k]);
}