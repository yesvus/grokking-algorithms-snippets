pub fn selection_sort(input: &[i32]) -> Vec<i32> {
    let mut arr = input.to_vec();
    let n = arr.len();

    for i in 0..n {
        let mut min_idx = i;
        for j in (i + 1)..n {
            if arr[j] < arr[min_idx] {
                min_idx = j;
            }
        }
        arr.swap(i, min_idx);
    }

    arr
}
