#include <functional>
#include <limits>
#include <queue>
#include <string>
#include <unordered_map>
#include <utility>

std::unordered_map<std::string, double> dijkstra(
    const std::unordered_map<std::string, std::unordered_map<std::string, double>>& graph,
    const std::string& start
) {
    std::unordered_map<std::string, double> distances;

    for (const auto& [node, _] : graph) {
        distances[node] = std::numeric_limits<double>::infinity();
    }
    distances[start] = 0.0;

    using State = std::pair<double, std::string>;
    std::priority_queue<State, std::vector<State>, std::greater<State>> pq;
    pq.push({0.0, start});

    while (!pq.empty()) {
        auto [current_dist, node] = pq.top();
        pq.pop();

        if (current_dist > distances[node]) continue;

        auto it = graph.find(node);
        if (it == graph.end()) continue;

        for (const auto& [neighbor, weight] : it->second) {
            double new_dist = current_dist + weight;
            if (!distances.count(neighbor) || new_dist < distances[neighbor]) {
                distances[neighbor] = new_dist;
                pq.push({new_dist, neighbor});
            }
        }
    }

    return distances;
}
