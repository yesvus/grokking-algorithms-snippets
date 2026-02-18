#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

std::vector<std::string> bfs_shortest_path(
    const std::unordered_map<std::string, std::vector<std::string>>& graph,
    const std::string& start,
    const std::string& goal
) {
    std::queue<std::pair<std::string, std::vector<std::string>>> q;
    std::unordered_set<std::string> visited;

    q.push({start, {start}});
    visited.insert(start);

    while (!q.empty()) {
        auto [node, path] = q.front();
        q.pop();

        if (node == goal) return path;

        auto it = graph.find(node);
        if (it == graph.end()) continue;

        for (const auto& neighbor : it->second) {
            if (visited.count(neighbor)) continue;
            visited.insert(neighbor);
            auto next_path = path;
            next_path.push_back(neighbor);
            q.push({neighbor, next_path});
        }
    }

    return {};
}
