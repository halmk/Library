#[allow(unused_imports)]
use std::char::*;
#[allow(unused_imports)]
use std::cmp::*;
#[allow(unused_imports)]
use std::collections::*;

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
const INF_U32:u32 = 1 << 31;
#[allow(dead_code)]
const INF_I32:i32 = 1 << 30;
#[allow(dead_code)]
const INF_U64:u64 = 1 << 63;
#[allow(dead_code)]
const INF_I64:i64 = 1 << 62;
#[allow(dead_code)]
const MOD:i64 = 1e9 as i64 + 7;

#[allow(dead_code)]
fn read_vec<T: std::str::FromStr>() -> Vec<T> {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).ok();
    s.trim().split_whitespace()
        .map(|e| e.parse().ok().unwrap()).collect()
}

pub trait BinarySearch<T> {
    fn lower_bound(&self, x: &T) -> usize;
    fn upper_bound(&self, x: &T) -> usize;
}

impl<T: Ord> BinarySearch<T> for [T] {
    fn lower_bound(&self, x: &T) -> usize {
        let mut low = 0;
        let mut high = self.len();

        while low != high {
            let mid = (low + high) / 2;
            match self[mid].cmp(x) {
                Ordering::Less => {
                    low = mid + 1;
                }
                Ordering::Equal | Ordering::Greater => {
                    high = mid;
                }
            }
        }
        low
    }

    fn upper_bound(&self, x: &T) -> usize {
        let mut low = 0;
        let mut high = self.len();

        while low != high {
            let mid = (low + high) / 2;
            match self[mid].cmp(x) {
                Ordering::Less | Ordering::Equal => {
                    low = mid + 1;
                }
                Ordering::Greater => {
                    high = mid;
                }
            }
        }
        low
    }
}

#[allow(unused_imports)]
use std::f64;

fn main() {
    input!{s:chars, k:i64};
    let mut s = s;
    let n = s.len();
    for _i in 0..k-1 {
        for j in 0..n { let el = s[j].clone(); s.push(el); }
    }
    //debug!(s);
    let mut cnt = 0;
    for i in 0..s.len()-1 {
        if s[i] == s[i+1] {
            cnt += 1;
            s[i+1] = '_';
        }
    }
    println!("{}", cnt);
}