// unverified

fn extgcd(a:i64, b:i64, x:&mut i64, y:&mut i64) -> i64 {
    let mut d = a;
    if b != 0 {
        d = extgcd(b, a%b, y, x);
        *y -= (a / b) * *x;
    } else {
        *x = 1; *y = 0;
    }
    d
}

#[test]
fn test1() {
    let a = 4;
    let b = 11;
    let mut x = 0;
    let mut y = 0;
    let d = extgcd(a,b,&mut x,&mut y);
    println!("extra_gcd({},{},0,0): x={}, y={}, d={}", a, b, x, y ,d);
}