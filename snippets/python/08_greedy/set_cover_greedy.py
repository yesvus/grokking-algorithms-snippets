def set_cover_greedy(universe, subsets):
    # subsets: {name: set(elements)}
    uncovered = set(universe)
    selected = []

    while uncovered:
        best_name = None
        best_cover = set()

        for name, subset in subsets.items():
            covered = uncovered & subset
            if len(covered) > len(best_cover):
                best_name = name
                best_cover = covered

        if not best_name:
            break

        uncovered -= best_cover
        selected.append(best_name)

    return selected, uncovered
