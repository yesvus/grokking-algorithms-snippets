# Grokking Algorithms - Concise Summary + Snippets

A compact, chapter-aligned reference of **Grokking Algorithms** with minimal, reusable Python snippets.

## Book Summary (Concise)

**Core idea:** pick the right data structure + algorithm for the problem shape.

### Important topics to master
1. **Big O notation**
- Measure scalability, not exact runtime.
- Common classes: `O(log n)`, `O(n)`, `O(n log n)`, `O(n^2)`.

2. **Binary Search**
- Works on sorted data.
- Repeatedly halves the search space (`O(log n)`).

3. **Recursion + Call Stack**
- Break a problem into smaller subproblems.
- Define a base case + recursive case clearly.

4. **Divide and Conquer**
- Split, solve subproblems, combine.
- Foundation for fast sorting/searching strategies.

5. **Quicksort**
- Practical sorting pattern with divide-and-conquer.
- Average `O(n log n)`.

6. **Hash Tables**
- Fast lookup/insert/delete on average (`O(1)`).
- Great for caching, counting, membership checks.

7. **Graph Traversal (BFS)**
- Explore shortest path in unweighted graphs.
- Uses a queue and visited set.

8. **Dijkstra’s Algorithm**
- Shortest path in weighted graphs (no negative edges).
- Greedy relaxation over current cheapest node.

9. **Greedy Algorithms**
- Build solution by local best choices.
- Fast, but not always globally optimal.

10. **Dynamic Programming (DP)**
- Use subproblem overlap + optimal substructure.
- Turn recursion into table/state transitions.

11. **Advanced ideas (brief)**
- K-nearest neighbors, trees, and where MapReduce-style thinking helps at scale.

## Snippet Structure

```text
snippets/
  python/
    01_search/
      binary_search.py
    02_sorting/
      selection_sort.py
    03_recursion/
      sum_recursive.py
      count_recursive.py
    04_divide_and_conquer/
      quicksort.py
    05_hash_tables/
      frequency_counter.py
    06_graphs/
      bfs_shortest_path.py
    07_shortest_path/
      dijkstra.py
    08_greedy/
      set_cover_greedy.py
    09_dynamic_programming/
      longest_common_subsequence.py
    10_advanced/
      knn_basic.py
```

## Learning Roadmap

1. **Week 1 - Foundations**
- Learn Big O + binary search + recursion basics.
- Practice tracing by hand on tiny inputs.

2. **Week 2 - Sorting and splitting**
- Implement selection sort and quicksort.
- Compare complexity and when each is useful.

3. **Week 3 - Fast data access**
- Use hash tables for counting, caching, and lookups.
- Focus on modeling problems as key-value operations.

4. **Week 4 - Graph thinking**
- Start with BFS (unweighted shortest path).
- Move to Dijkstra for weighted shortest path.

5. **Week 5 - Optimization patterns**
- Learn greedy (quick approximation/heuristics).
- Learn DP for guaranteed optimal substructure problems.

6. **Week 6 - Advanced + integration**
- Read KNN and advanced chapters.
- Solve mixed problems combining multiple techniques.

## How to Use

- Start from lower-numbered folders.
- Read one snippet, run it, then modify inputs.
- Keep each snippet as a template for interview/problem-solving reuse.
