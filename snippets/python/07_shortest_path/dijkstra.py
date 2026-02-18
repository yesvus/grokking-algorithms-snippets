import heapq


def dijkstra(graph, start):
    # graph: {node: {neighbor: weight}}
    distances = {node: float("inf") for node in graph}
    distances[start] = 0
    heap = [(0, start)]

    while heap:
        current_dist, node = heapq.heappop(heap)
        if current_dist > distances[node]:
            continue

        for neighbor, weight in graph[node].items():
            new_dist = current_dist + weight
            if new_dist < distances[neighbor]:
                distances[neighbor] = new_dist
                heapq.heappush(heap, (new_dist, neighbor))

    return distances
