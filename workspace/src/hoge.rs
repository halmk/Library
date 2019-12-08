use std::io::*;
use std::str::FromStr;
use std::cmp::*;

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

fn main(){
    use std::collections::BTreeSet;
    let v = vec![1, 2, 2, 3, 4, 4];
    println!("{:?}", v.iter().cloned());
    let a: BTreeSet<u32> = v.iter().cloned().collect();
    println!("{:?}", a);
}