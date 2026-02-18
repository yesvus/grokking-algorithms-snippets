pub fn sum_recursive(arr: &[i32]) -> i32 {
    if arr.is_empty() {
        0
    } else {
        arr[0] + sum_recursive(&arr[1..])
    }
}
