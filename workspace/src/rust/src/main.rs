#[allow(unused_imports)]
use std::char::*;
#[allow(unused_imports)]
use std::cmp::*;
use std::io::*;
use std::str::FromStr;

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
//const INF:u64 = u64::max_value();

#[derive(PartialEq, PartialOrd)]
pub struct Total<T>(pub T);

impl<T: PartialEq> Eq for Total<T> {}

impl<T: PartialOrd> Ord for Total<T> {
    fn cmp(&self, other: &Total<T>) -> std::cmp::Ordering {
        self.0.partial_cmp(&other.0).unwrap()
    }
}

fn main() {
    let n:u32 = read();
    let mut v:Vec<f64> = (0..n).map(|_| read::<f64>()).collect();

    v.sort_by_key(|&x| Total(x));
    v.reverse();
    println!("{:?}", v);

    for i in 0..n-1 {
        
    }
}