#![allow(unused_imports)]
#![allow(unused_macros)]
#![allow(dead_code)]
#![allow(non_snake_case)]

use std::char::*;
use std::cmp::*;
use std::collections::*;

macro_rules! debug {($($a:expr),*) => {println!(concat!($(stringify!($a), " = {:?}, "),*), $($a),*);}}
macro_rules! input { ( source = $ s : expr , $ ( $ r : tt ) * ) => { let mut iter = $ s . split_whitespace ( ) ; let mut next = || { iter . next ( ) . unwrap ( ) } ; input_inner ! { next , $ ( $ r ) * } } ; ( $ ( $ r : tt ) * ) => { let stdin = std :: io :: stdin ( ) ; let mut bytes = std :: io :: Read :: bytes ( std :: io :: BufReader :: new ( stdin . lock ( ) ) ) ; let mut next = move || -> String { bytes . by_ref ( ) . map ( | r | r . unwrap ( ) as char ) . skip_while ( | c | c . is_whitespace ( ) ) . take_while ( | c |! c . is_whitespace ( ) ) . collect ( ) } ; input_inner ! { next , $ ( $ r ) * } } ; }
macro_rules! input_inner { ( $ next : expr ) => { } ; ( $ next : expr , ) => { } ; ( $ next : expr , $ var : ident : $ t : tt $ ( $ r : tt ) * ) => { let $ var = read_value ! ( $ next , $ t ) ; input_inner ! { $ next $ ( $ r ) * } } ; }
macro_rules! read_value { ( $ next : expr , ( $ ( $ t : tt ) ,* ) ) => { ( $ ( read_value ! ( $ next , $ t ) ) ,* ) } ; ( $ next : expr , [ $ t : tt ; $ len : expr ] ) => { ( 0 ..$ len ) . map ( | _ | read_value ! ( $ next , $ t ) ) . collect ::< Vec < _ >> ( ) } ; ( $ next : expr , chars ) => { read_value ! ( $ next , String ) . chars ( ) . collect ::< Vec < char >> ( ) } ; ( $ next : expr , usize1 ) => { read_value ! ( $ next , usize ) - 1 } ; ( $ next : expr , $ t : ty ) => { $ next ( ) . parse ::<$ t > ( ) . expect ( "Parse error" ) } ; }

#[derive(PartialEq, PartialOrd)]
pub struct Total<T>(pub T);
impl<T: PartialEq> Eq for Total<T> {}
impl<T: PartialOrd> Ord for Total<T> { fn cmp(&self, other: &Total<T>) -> std::cmp::Ordering { self.0.partial_cmp(&other.0).unwrap() }}

const MAX:usize = 100006;
const INF_U32:u32 = 1 << 31;
const INF_I32:i32 = 1 << 30;
const INF_U64:u64 = 1 << 63;
const INF_I64:i64 = 1 << 62;
const MOD:i64 = 1e9 as i64 + 7;

const MAX_N:usize = 100;
const MAX_W:usize = 100;

// o1ナップサック問題
// 重さと価値がそれぞれw_i, v_iであるようなn個の品物がある。これらの品物から、重さの総和がWを超えないように選んだときの、価値の総和の最大値を求める。

// dp[i][j] := i番目以降の品物から重さの総和がj以下となるように選んだときの、価値の総和の最大値
fn main() {
    input!{n:usize, w:[i64;n], v:[i64;n], W:i64};

    let mut dp = [[0;MAX_W+1];MAX_N+1];

    for i in (0..n).rev() {
        for j in 0..W as usize +1 {
            if (j as i64) < w[i] {
                dp[i][j] = dp[i+1][j];
            } else {
                dp[i][j] = max(dp[i+1][j], dp[i+1][(j as i64 - w[i]) as usize] + v[i]);
            }
        }
    }
    println!("{}", dp[0][W as usize]);
}