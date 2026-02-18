#include <vector>

int count_recursive(const std::vector<int>& arr, int idx = 0) {
    if (idx >= static_cast<int>(arr.size())) return 0;
    return 1 + count_recursive(arr, idx + 1);
}
