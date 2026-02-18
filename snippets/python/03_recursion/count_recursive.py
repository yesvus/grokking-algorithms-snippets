def count_recursive(arr):
    if not arr:
        return 0
    return 1 + count_recursive(arr[1:])
