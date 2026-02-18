use std::collections::{HashMap, HashSet, VecDeque};

pub fn bfs_shortest_path(
    graph: &HashMap<String, Vec<String>>,
    start: &str,
    goal: &str,
) -> Option<Vec<String>> {
    let mut queue: VecDeque<(String, Vec<String>)> = VecDeque::new();
    let mut visited: HashSet<String> = HashSet::new();

    queue.push_back((start.to_string(), vec![start.to_string()]));
    visited.insert(start.to_string());

    while let Some((node, path)) = queue.pop_front() {
        if node == goal {
            return Some(path);
        }

        if let Some(neighbors) = graph.get(&node) {
            for neighbor in neighbors {
                if visited.insert(neighbor.clone()) {
                    let mut next_path = path.clone();
                    next_path.push(neighbor.clone());
                    queue.push_back((neighbor.clone(), next_path));
                }
            }
        }
    }

    None
}
