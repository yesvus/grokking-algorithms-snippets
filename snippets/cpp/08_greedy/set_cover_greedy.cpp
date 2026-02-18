#include <set>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

std::pair<std::vector<std::string>, std::set<std::string>> set_cover_greedy(
    const std::set<std::string>& universe,
    const std::unordered_map<std::string, std::set<std::string>>& subsets
) {
    std::set<std::string> uncovered = universe;
    std::vector<std::string> selected;

    while (!uncovered.empty()) {
        std::string best_name;
        std::set<std::string> best_cover;

        for (const auto& [name, subset] : subsets) {
            std::set<std::string> covered;
            for (const auto& item : subset) {
                if (uncovered.count(item)) covered.insert(item);
            }
            if (covered.size() > best_cover.size()) {
                best_name = name;
                best_cover = std::move(covered);
            }
        }

        if (best_name.empty()) break;

        for (const auto& item : best_cover) {
            uncovered.erase(item);
        }
        selected.push_back(best_name);
    }

    return {selected, uncovered};
}
