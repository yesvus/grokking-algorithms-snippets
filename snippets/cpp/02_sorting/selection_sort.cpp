#include <algorithm>
#include <vector>

std::vector<int> selection_sort(std::vector<int> arr) {
    int n = static_cast<int>(arr.size());

    for (int i = 0; i < n; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_idx]) min_idx = j;
        }
        std::swap(arr[i], arr[min_idx]);
    }

    return arr;
}
