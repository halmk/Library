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


#[allow(unused_imports)]
use std::f64;

fn dfs(crt:&mut Vec<char>, s:&Vec<char>, idx:usize, map:&HashMap<char,i64>) -> i64 {
    //debug!(crt,idx);
    if idx == s.len() {
        if crt.len() == 0 { return 0; }
        let mut sum:i64 = 1;
        for &ch in crt.iter() {
            let cnt = map.get(&ch).unwrap();
            sum *= *cnt;
            sum %= MOD;
        }
        return sum;
    }
    let mut total = 0;

    crt.push(s[idx]);
    total += dfs(crt, s, idx+1, map);
    crt.pop();
    total += dfs(crt, s, idx+1, map);

    total%MOD
}

fn main() {
    input!{_n:usize, s:chars};
    let mut s = s;
    s.sort();
    let mut map = HashMap::new();
    for &ch in s.iter() {
        let count = map.entry(ch).or_insert(0);
        *count += 1;
    }
    //debug!(map);
    let mut t = vec![];
    for (key,_val) in map.iter() {
        t.push(key.clone());
    }
    //debug!(t);

    println!("{}", dfs(&mut vec![], &t, 0, &map));

}