#include <algorithm>
#include <cmath>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

double euclidean_distance(
    const std::vector<double>& a,
    const std::vector<double>& b
) {
    double sum = 0.0;
    for (size_t i = 0; i < a.size() && i < b.size(); ++i) {
        double diff = a[i] - b[i];
        sum += diff * diff;
    }
    return std::sqrt(sum);
}

std::string knn_predict(
    const std::vector<std::vector<double>>& points,
    const std::vector<std::string>& labels,
    const std::vector<double>& query,
    int k = 3
) {
    std::vector<std::pair<double, std::string>> distances;

    for (size_t i = 0; i < points.size() && i < labels.size(); ++i) {
        distances.push_back({euclidean_distance(points[i], query), labels[i]});
    }

    std::sort(distances.begin(), distances.end());

    std::unordered_map<std::string, int> vote_count;
    for (int i = 0; i < k && i < static_cast<int>(distances.size()); ++i) {
        ++vote_count[distances[i].second];
    }

    std::string best_label;
    int best_votes = -1;
    for (const auto& [label, votes] : vote_count) {
        if (votes > best_votes) {
            best_votes = votes;
            best_label = label;
        }
    }

    return best_label;
}
