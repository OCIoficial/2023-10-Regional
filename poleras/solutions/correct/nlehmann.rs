// #![feature(register_tool, custom_inner_attributes)]
// #![register_tool(flux)]
// #![flux::cfg(check_overflow = true, scrape_quals = true)]

use std::io::{self, BufRead, BufReader};

// #[flux::trusted]
fn main() {
    let mut stdin = BufReader::new(io::stdin());

    let [n, k] = read_uints(&mut stdin).try_into().unwrap();

    let mut a = read_uints(&mut stdin);
    let b = read_uints(&mut stdin);

    if sol(a.len(), &mut a, &b, k) {
        println!("SI");
    } else {
        println!("NO");
    }
}

// #[flux::sig(fn(
//     usize[@n],
//     &mut [u32{v: v <= 1000000000}][n],
//     &[u32{v: v <= 1000000000}][n],
//     u32
// ) -> bool)]
fn sol(n: usize, a: &mut [u32], b: &[u32], k: u32) -> bool {
    let mut i = n;
    let mut j = n;
    while i > 0 {
        assert(j - i <= k as usize);

        loop {
            let ai = a[i - 1];
            let bi = b[i - 1];
            if !(ai < bi) {
                break;
            }

            assert(j >= i);
            if i == j {
                return false;
            }

            let aj = a[j - 1];
            let bj = b[j - 1];
            if aj > bj {
                let s = min(bi - ai, aj - bj);
                a[i - 1] = ai + s;
                a[j - 1] = aj - s;
            } else {
                j -= 1;
            }
        }

        if j - i >= k as usize {
            j -= 1;
        }
        i -= 1;
    }
    true
}

// #[flux::sig(fn(bool[true]))]
fn assert(_: bool) {}

// #[flux::sig(fn(a: u32, b: u32) -> u32[if a < b { a } else { b }])]
fn min(a: u32, b: u32) -> u32 {
    if a < b {
        a
    } else {
        b
    }
}

// #[flux::trusted]
fn read_uints<R: BufRead>(mut buf: R) -> Vec<u32> {
    let mut line = String::new();
    buf.read_line(&mut line).unwrap();
    line.split_whitespace()
        .map(|x| x.parse().unwrap())
        .collect()
}
