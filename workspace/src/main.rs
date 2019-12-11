use std::io::*;
use std::str::FromStr;
use std::char::*;
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

//const MAX:usize = 100006;


fn main(){
    let n:i32 = read();
    let a:Vec<(i32,i32)> = (0..n).map(|_| (read(),read())).collect();

    
}