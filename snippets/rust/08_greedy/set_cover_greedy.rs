use std::collections::{HashMap, HashSet};

pub fn set_cover_greedy(
    universe: &HashSet<String>,
    subsets: &HashMap<String, HashSet<String>>,
) -> (Vec<String>, HashSet<String>) {
    let mut uncovered = universe.clone();
    let mut selected = Vec::new();

    while !uncovered.is_empty() {
        let mut best_name: Option<String> = None;
        let mut best_cover: HashSet<String> = HashSet::new();

        for (name, subset) in subsets {
            let covered: HashSet<String> = subset.intersection(&uncovered).cloned().collect();
            if covered.len() > best_cover.len() {
                best_name = Some(name.clone());
                best_cover = covered;
            }
        }

        if let Some(name) = best_name {
            for item in &best_cover {
                uncovered.remove(item);
            }
            selected.push(name);
        } else {
            break;
        }
    }

    (selected, uncovered)
}
