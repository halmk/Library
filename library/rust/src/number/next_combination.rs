// unverified

fn next_combination(sub: i64) -> i64 {
    let x = sub & -sub;
    let y = sub + x;
    (((sub & !y) / x) >> 1) | y
}

#[test]
fn test1() {
    let n = 5;
    let k = 3;

    // 5C3
    let mut bit = (1 << k) - 1;
    while bit < (1 << n) {
        let mut s = vec![];
        for i in 0..n {
            if bit & (1 << i) > 0 {
                s.push(i);
            }
        }
        println!("{}: {:05b}", bit, bit);
        for i in 0..s.len() {
            print!("{} ", s[i]);
        }
        println!("");

        bit = next_combination(bit);
    }
}