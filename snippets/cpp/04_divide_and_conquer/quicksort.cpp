#include <vector>

std::vector<int> quicksort(const std::vector<int>& arr) {
    if (arr.size() < 2) return arr;

    int pivot = arr[0];
    std::vector<int> less;
    std::vector<int> greater;

    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] <= pivot) {
            less.push_back(arr[i]);
        } else {
            greater.push_back(arr[i]);
        }
    }

    std::vector<int> left = quicksort(less);
    std::vector<int> right = quicksort(greater);

    left.push_back(pivot);
    left.insert(left.end(), right.begin(), right.end());
    return left;
}
