use std::io::*;
use std::str::FromStr;
//use std::cmp::*;

fn read<T: FromStr>() -> T {
    let stdin = stdin();
    let stdin = stdin.lock();
    let token: String = stdin
        .bytes()
        .map(|c| c.expect("failed to read char") as char) 
        .skip_while(|c| c.is_whitespace())
        .take_while(|c| !c.is_whitespace())
        .collect();
    token.parse().ok().expect("failed to parse token")
}

const MAX: usize = 100000;


fn fib(x: usize, memo: &mut Vec<usize>) -> usize {
    if x < 2 { return 1; }
    if memo[x] != 0 {
        return memo[x];
    }
    memo[x] = fib(x-1,memo) + fib(x-2,memo);
    return memo[x];
}

fn main(){
    let n:usize = read();

    let mut memo: Vec<usize> = vec![0;MAX];
    let res = fib(n, &mut memo);

    println!("{}", res);
}