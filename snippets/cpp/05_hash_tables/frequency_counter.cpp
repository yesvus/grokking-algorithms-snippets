#include <string>
#include <unordered_map>
#include <vector>

std::unordered_map<std::string, int> frequency_counter(
    const std::vector<std::string>& items
) {
    std::unordered_map<std::string, int> counts;
    for (const auto& item : items) {
        ++counts[item];
    }
    return counts;
}
