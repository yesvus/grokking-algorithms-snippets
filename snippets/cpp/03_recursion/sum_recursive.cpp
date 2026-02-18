#include <vector>

int sum_recursive(const std::vector<int>& arr, int idx = 0) {
    if (idx >= static_cast<int>(arr.size())) return 0;
    return arr[idx] + sum_recursive(arr, idx + 1);
}
