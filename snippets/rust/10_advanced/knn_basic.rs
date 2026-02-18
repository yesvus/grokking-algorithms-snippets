use std::cmp::Ordering;
use std::collections::HashMap;

fn euclidean_distance(a: &[f64], b: &[f64]) -> f64 {
    a.iter()
        .zip(b.iter())
        .map(|(x, y)| {
            let d = x - y;
            d * d
        })
        .sum::<f64>()
        .sqrt()
}

pub fn knn_predict(
    points: &[Vec<f64>],
    labels: &[String],
    query: &[f64],
    k: usize,
) -> Option<String> {
    let mut distances: Vec<(f64, String)> = points
        .iter()
        .zip(labels.iter())
        .map(|(point, label)| (euclidean_distance(point, query), label.clone()))
        .collect();

    distances.sort_by(|a, b| a.0.partial_cmp(&b.0).unwrap_or(Ordering::Equal));

    let mut votes: HashMap<String, usize> = HashMap::new();
    for (_, label) in distances.iter().take(k) {
        *votes.entry(label.clone()).or_insert(0) += 1;
    }

    votes.into_iter().max_by_key(|(_, count)| *count).map(|(label, _)| label)
}
