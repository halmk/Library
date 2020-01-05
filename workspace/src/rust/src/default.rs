#[allow(unused_imports)]
use std::char::*;
#[allow(unused_imports)]
use std::cmp::*;
use std::io::*;
use std::str::FromStr;
#[allow(unused_imports)]
use std::collections::*;

#[allow(unused_macros)]
macro_rules! debug {
    ($($a:expr),*) => {
        println!(concat!($(stringify!($a), " = {:?}, "),*), $($a),*);
    }
}

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

#[derive(PartialEq, PartialOrd)]
pub struct Total<T>(pub T);

impl<T: PartialEq> Eq for Total<T> {}

impl<T: PartialOrd> Ord for Total<T> {
    fn cmp(&self, other: &Total<T>) -> std::cmp::Ordering {
        self.0.partial_cmp(&other.0).unwrap()
    }
}

#[allow(dead_code)]
const MAX:usize = 100006;
#[allow(dead_code)]
const INF_U32:u32 = 1 << 31;
#[allow(dead_code)]
const INF_I32:i32 = 1 << 30;
#[allow(dead_code)]
const INF_U64:u64 = 1 << 63;
#[allow(dead_code)]
const INF_I64:i64 = 1 << 62;


fn main() {
    
    
}
