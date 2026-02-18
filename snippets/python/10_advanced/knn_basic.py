from collections import Counter
from math import sqrt


def euclidean_distance(a, b):
    return sqrt(sum((x - y) ** 2 for x, y in zip(a, b)))


def knn_predict(points, labels, query, k=3):
    distances = [
        (euclidean_distance(point, query), label)
        for point, label in zip(points, labels)
    ]
    distances.sort(key=lambda x: x[0])
    top_k_labels = [label for _, label in distances[:k]]
    return Counter(top_k_labels).most_common(1)[0][0]
