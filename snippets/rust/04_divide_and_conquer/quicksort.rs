pub fn quicksort(arr: &[i32]) -> Vec<i32> {
    if arr.len() < 2 {
        return arr.to_vec();
    }

    let pivot = arr[0];
    let less: Vec<i32> = arr[1..].iter().copied().filter(|&x| x <= pivot).collect();
    let greater: Vec<i32> = arr[1..].iter().copied().filter(|&x| x > pivot).collect();

    let mut result = quicksort(&less);
    result.push(pivot);
    result.extend(quicksort(&greater));
    result
}
