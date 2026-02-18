use std::cmp::Ordering;
use std::collections::{BinaryHeap, HashMap};

#[derive(Clone)]
struct State {
    cost: f64,
    node: String,
}

impl Eq for State {}

impl PartialEq for State {
    fn eq(&self, other: &Self) -> bool {
        self.cost == other.cost && self.node == other.node
    }
}

impl Ord for State {
    fn cmp(&self, other: &Self) -> Ordering {
        other
            .cost
            .partial_cmp(&self.cost)
            .unwrap_or(Ordering::Equal)
    }
}

impl PartialOrd for State {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

pub fn dijkstra(
    graph: &HashMap<String, HashMap<String, f64>>,
    start: &str,
) -> HashMap<String, f64> {
    let mut distances: HashMap<String, f64> = graph
        .keys()
        .cloned()
        .map(|k| (k, f64::INFINITY))
        .collect();
    distances.insert(start.to_string(), 0.0);

    let mut heap = BinaryHeap::new();
    heap.push(State {
        cost: 0.0,
        node: start.to_string(),
    });

    while let Some(State { cost, node }) = heap.pop() {
        if let Some(&best) = distances.get(&node) {
            if cost > best {
                continue;
            }
        }

        if let Some(neighbors) = graph.get(&node) {
            for (neighbor, weight) in neighbors {
                let new_cost = cost + weight;
                let current = *distances.get(neighbor).unwrap_or(&f64::INFINITY);
                if new_cost < current {
                    distances.insert(neighbor.clone(), new_cost);
                    heap.push(State {
                        cost: new_cost,
                        node: neighbor.clone(),
                    });
                }
            }
        }
    }

    distances
}
