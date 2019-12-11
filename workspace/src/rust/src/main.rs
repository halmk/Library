use std::io::*;
use std::str::FromStr;
#[allow(unused_imports)]
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

pub trait LexicalPermutation {
    fn next_permutation(&mut self) -> bool;
    fn prev_permutation(&mut self) -> bool;
}

impl<T> LexicalPermutation for [T] where T: Ord {
    fn next_permutation(&mut self) -> bool {
        if self.len() < 2 { return false; }
        let mut i = self.len() - 1;
        while i > 0 && self[i-1] >= self[i] {
            i -= 1;
        }
        if i == 0 {
            return false;
        }
        let mut j = self.len() - 1;
        while j >= i && self[j] <= self[i-1]  {
            j -= 1;
        }
        self.swap(j, i-1);
        self[i..].reverse();
        true
    }

    fn prev_permutation(&mut self) -> bool {
        if self.len() < 2 { return false; }
        let mut i = self.len() - 1;
        while i > 0 && self[i-1] <= self[i] {
            i -= 1;
        }
        if i == 0 {
            return false;
        }
        self[i..].reverse();
        let mut j = self.len() - 1;
        while j >= i && self[j-1] < self[i-1]  {
            j -= 1;
        }
        self.swap(i-1, j);
        true
    }
}

fn func(v: &Vec<i32>, a: &Vec<(i32,i32)>) -> f64 {
    let mut res: f64 = 0.0;
    for &x in v.iter() {
        if x == (v.len()-1) as i32 {continue}
        let it:usize = x as usize;
        let i:usize = v[it] as usize;
        let j:usize = v[it+1] as usize;
        let d_x:f64 = (a[i].0 - a[j].0).pow(2) as f64;
        let d_y:f64 = (a[i].1 - a[j].1).pow(2) as f64;
        let dist:f64 = (d_x + d_y).sqrt();
        res += dist;
    }
    res
}

fn main(){
    let n:i32 = read();
    let a:Vec<(i32,i32)> = (0..n).map(|_| (read(),read())).collect();

    let mut v: Vec<i32> = (0..n).collect();

    let mut c:i32 = 0;
    let mut ans: f64 = 0.0;
    loop {
        //println!("{:?}", v);
        c += 1;
        ans += func(&v, &a);
        if !v.next_permutation() {break}
    }
    //println!("{}", c);
    println!("{}", format!("{:.10}",ans/(c as f64)));
}