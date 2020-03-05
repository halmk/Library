#[allow(unused_imports)]
use std::char::*;
#[allow(unused_imports)]
use std::cmp::*;
#[allow(unused_imports)]
use std::collections::*;
use std::io::*;
use std::str::FromStr;

#[allow(unused_macros)]
macro_rules! debug {($($a:expr),*) => {println!(concat!($(stringify!($a), " = {:?}, "),*), $($a),*);}}
#[allow(unused_macros)]
macro_rules! input { ( source = $ s : expr , $ ( $ r : tt ) * ) => { let mut iter = $ s . split_whitespace ( ) ; let mut next = || { iter . next ( ) . unwrap ( ) } ; input_inner ! { next , $ ( $ r ) * } } ; ( $ ( $ r : tt ) * ) => { let stdin = std :: io :: stdin ( ) ; let mut bytes = std :: io :: Read :: bytes ( std :: io :: BufReader :: new ( stdin . lock ( ) ) ) ; let mut next = move || -> String { bytes . by_ref ( ) . map ( | r | r . unwrap ( ) as char ) . skip_while ( | c | c . is_whitespace ( ) ) . take_while ( | c |! c . is_whitespace ( ) ) . collect ( ) } ; input_inner ! { next , $ ( $ r ) * } } ; }
#[allow(unused_macros)]
macro_rules! input_inner { ( $ next : expr ) => { } ; ( $ next : expr , ) => { } ; ( $ next : expr , $ var : ident : $ t : tt $ ( $ r : tt ) * ) => { let $ var = read_value ! ( $ next , $ t ) ; input_inner ! { $ next $ ( $ r ) * } } ; }
#[allow(unused_macros)]
macro_rules! read_value { ( $ next : expr , ( $ ( $ t : tt ) ,* ) ) => { ( $ ( read_value ! ( $ next , $ t ) ) ,* ) } ; ( $ next : expr , [ $ t : tt ; $ len : expr ] ) => { ( 0 ..$ len ) . map ( | _ | read_value ! ( $ next , $ t ) ) . collect ::< Vec < _ >> ( ) } ; ( $ next : expr , chars ) => { read_value ! ( $ next , String ) . chars ( ) . collect ::< Vec < char >> ( ) } ; ( $ next : expr , usize1 ) => { read_value ! ( $ next , usize ) - 1 } ; ( $ next : expr , $ t : ty ) => { $ next ( ) . parse ::<$ t > ( ) . expect ( "Parse error" ) } ; }

#[derive(PartialEq, PartialOrd)]
pub struct Total<T>(pub T);
impl<T: PartialEq> Eq for Total<T> {}
impl<T: PartialOrd> Ord for Total<T> { fn cmp(&self, other: &Total<T>) -> std::cmp::Ordering { self.0.partial_cmp(&other.0).unwrap() }}

#[allow(dead_code)]
const MAX:usize = 100006;
#[allow(dead_code)]
const MOD:i64 = 1e9 as i64 + 7;


#[allow(dead_code)]
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

#[allow(dead_code)]
fn read_vec<T: std::str::FromStr>() -> Vec<T> {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).ok();
    s.trim().split_whitespace()
        .map(|e| e.parse().ok().unwrap()).collect()
}


#[allow(unused_imports)]
use std::f64;

fn min<T: PartialOrd>(a:T, b:T) -> T {
    if a < b { a }
    else { b }
}


fn main() {
    let mut d = [[INF;MAX_V];MAX_V];

}