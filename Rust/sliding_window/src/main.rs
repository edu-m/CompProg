use std::collections::BinaryHeap;
use std::cmp::Reverse;

fn max_sliding_window(nums: Vec<i32>, k: i32) -> Vec<i32> {
    let mut ret = Vec::new();
    let mut heap: BinaryHeap<(i32, usize)> = BinaryHeap::new();

    for i in 0..k {
        heap.push((nums[i as usize], i as usize));
    }
    ret.push(heap.peek().unwrap().0);

    for i in k..nums.len() as i32{
        heap.push((nums[i as usize], i as usize));
        while heap.peek().unwrap().1 <= (i - k) as usize{
            heap.pop();
        }
        ret.push(heap.peek().unwrap().0);
    }

    ret
}

fn main(){

}