pub fn count_recursive<T>(arr: &[T]) -> usize {
    if arr.is_empty() {
        0
    } else {
        1 + count_recursive(&arr[1..])
    }
}
