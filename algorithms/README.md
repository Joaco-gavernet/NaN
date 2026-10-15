# Algorithm library

This is the full collection of available algorithms, including implementations
not selected for World Finals. [The World Finals manifest](../notebook/world_finals.toml)
selects a subset of these same files; it does not maintain another source tree.

Files ending in `_wf26` preserve a distinct World Finals implementation.
They are explicit alternatives pending review, not compatibility wrappers.
An unsuffixed file is not necessarily more correct or more thoroughly tested.
See the [consolidation review](../docs/library_consolidation.md) before choosing
between variants. The source comments retain existing attribution.

Most files are contest snippets rather than standalone programs. Use the
[templates](../templates/README.md) for aliases and includes; consult
[tests](../tests/README.md) for the currently exercised implementations.

Python files contain reference examples as well as helpers and are not intended
to execute from top to bottom as programs.

## Data Structures

| Implementation | World Finals |
| --- | --- |
| [coordinate_compression.cpp](data_structures/coordinate_compression.cpp) | Library only |
| [coordinate_compression_wf26.cpp](data_structures/coordinate_compression_wf26.cpp) | Selected |
| [dsu.cpp](data_structures/dsu.cpp) | Selected |
| [fenwick.cpp](data_structures/fenwick.cpp) | Library only |
| [implicit_treap.cpp](data_structures/implicit_treap.cpp) | Selected |
| [indexed_set.cpp](data_structures/indexed_set.cpp) | Library only |
| [indexed_set_custom.cpp](data_structures/indexed_set_custom.cpp) | Library only |
| [indexed_set_wf26.cpp](data_structures/indexed_set_wf26.cpp) | Selected |
| [linked_list.cpp](data_structures/linked_list.cpp) | Library only |
| [mo_distinct_queries.cpp](data_structures/mo_distinct_queries.cpp) | Selected |
| [segment_tree_iterative/segtree_2d.cpp](data_structures/segment_tree_iterative/segtree_2d.cpp) | Library only |
| [segment_tree_iterative/segtree_2d_wf26.cpp](data_structures/segment_tree_iterative/segtree_2d_wf26.cpp) | Selected |
| [segment_tree_iterative/segtree_point_query.cpp](data_structures/segment_tree_iterative/segtree_point_query.cpp) | Library only |
| [segment_tree_iterative/segtree_range_query.cpp](data_structures/segment_tree_iterative/segtree_range_query.cpp) | Library only |
| [segment_tree_iterative/segtree_range_query_wf26.cpp](data_structures/segment_tree_iterative/segtree_range_query_wf26.cpp) | Selected |
| [segment_tree_recursive/find_kth_min.cpp](data_structures/segment_tree_recursive/find_kth_min.cpp) | Library only |
| [segment_tree_recursive/lazy_arithmetic_sum.cpp](data_structures/segment_tree_recursive/lazy_arithmetic_sum.cpp) | Library only |
| [segment_tree_recursive/lazy_extreme.cpp](data_structures/segment_tree_recursive/lazy_extreme.cpp) | Library only |
| [segment_tree_recursive/lazy_extreme_wf26.cpp](data_structures/segment_tree_recursive/lazy_extreme_wf26.cpp) | Selected |
| [segment_tree_recursive/merge_sort_tree.cpp](data_structures/segment_tree_recursive/merge_sort_tree.cpp) | Library only |
| [segment_tree_recursive/persistent.cpp](data_structures/segment_tree_recursive/persistent.cpp) | Selected |
| [segment_tree_recursive/segtree.cpp](data_structures/segment_tree_recursive/segtree.cpp) | Library only |
| [sqrt_decomposition.cpp](data_structures/sqrt_decomposition.cpp) | Library only |
| [sum_min_k_multiset.cpp](data_structures/sum_min_k_multiset.cpp) | Library only |
| [treap.cpp](data_structures/treap.cpp) | Library only |

## Dynamic Programming

| Implementation | World Finals |
| --- | --- |
| [convex_hull_trick.cpp](dynamic_programming/convex_hull_trick.cpp) | Library only |
| [convex_hull_trick_dynamic.cpp](dynamic_programming/convex_hull_trick_dynamic.cpp) | Library only |
| [convex_hull_trick_dynamic_wf26.cpp](dynamic_programming/convex_hull_trick_dynamic_wf26.cpp) | Selected |
| [count_cycles.cpp](dynamic_programming/count_cycles.cpp) | Library only |
| [divide_and_conquer_optimization.cpp](dynamic_programming/divide_and_conquer_optimization.cpp) | Library only |
| [divide_and_conquer_optimization_wf26.cpp](dynamic_programming/divide_and_conquer_optimization_wf26.cpp) | Selected |
| [elevator_problem.cpp](dynamic_programming/elevator_problem.cpp) | Library only |
| [knapsack.cpp](dynamic_programming/knapsack.cpp) | Library only |
| [knapsack_big_w.cpp](dynamic_programming/knapsack_big_w.cpp) | Library only |
| [knapsack_weighted.cpp](dynamic_programming/knapsack_weighted.cpp) | Library only |
| [knapsack_weighted_wf26.cpp](dynamic_programming/knapsack_weighted_wf26.cpp) | Selected |
| [knuth_optimization.cpp](dynamic_programming/knuth_optimization.cpp) | Library only |
| [knuth_optimization_wf26.cpp](dynamic_programming/knuth_optimization_wf26.cpp) | Selected |
| [lcs.cpp](dynamic_programming/lcs.cpp) | Library only |
| [li_chao_tree.cpp](dynamic_programming/li_chao_tree.cpp) | Library only |
| [lis.cpp](dynamic_programming/lis.cpp) | Library only |
| [lis_wf26.cpp](dynamic_programming/lis_wf26.cpp) | Selected |
| [merge_sort.cpp](dynamic_programming/merge_sort.cpp) | Library only |

## Geometry

| Implementation | World Finals |
| --- | --- |
| [angular_sort.cpp](geometry/angular_sort.cpp) | Selected |
| [calipers.cpp](geometry/calipers.cpp) | Selected |
| [closest_points.cpp](geometry/closest_points.cpp) | Library only |
| [closest_points_monogon.cpp](geometry/closest_points_monogon.cpp) | Selected |
| [complex.cpp](geometry/complex.cpp) | Library only |
| [convex_hull.cpp](geometry/convex_hull.cpp) | Library only |
| [convex_hull_wf26.cpp](geometry/convex_hull_wf26.cpp) | Selected |
| [formulas.cpp](geometry/formulas.cpp) | Library only |
| [formulas_wf26.cpp](geometry/formulas_wf26.cpp) | Selected |
| [intersection_all.cpp](geometry/intersection_all.cpp) | Selected |
| [kd_tree.cpp](geometry/kd_tree.cpp) | Library only |
| [minimum_enclosing_circle.cpp](geometry/minimum_enclosing_circle.cpp) | Selected |
| [point.cpp](geometry/point.cpp) | Library only |
| [point_in_polygon.cpp](geometry/point_in_polygon.cpp) | Library only |
| [point_in_polygon_wf26.cpp](geometry/point_in_polygon_wf26.cpp) | Selected |
| [point_wf26.cpp](geometry/point_wf26.cpp) | Selected |

## Graphs

| Implementation | World Finals |
| --- | --- |
| [bellman_ford.cpp](graphs/bellman_ford.cpp) | Library only |
| [bellman_ford_wf26.cpp](graphs/bellman_ford_wf26.cpp) | Selected |
| [bfs.cpp](graphs/bfs.cpp) | Library only |
| [biconnected.cpp](graphs/biconnected.cpp) | Library only |
| [biconnected_wf26.cpp](graphs/biconnected_wf26.cpp) | Selected |
| [dfs.cpp](graphs/dfs.cpp) | Library only |
| [dijkstra.cpp](graphs/dijkstra.cpp) | Library only |
| [dijkstra_wf26.cpp](graphs/dijkstra_wf26.cpp) | Selected |
| [directed_mst.cpp](graphs/directed_mst.cpp) | Selected |
| [dominator_tree.cpp](graphs/dominator_tree.cpp) | Library only |
| [dynamic_connectivity.cpp](graphs/dynamic_connectivity.cpp) | Library only |
| [dynamic_connectivity_wf26.cpp](graphs/dynamic_connectivity_wf26.cpp) | Selected |
| [eulerian_cycle.cpp](graphs/eulerian_cycle.cpp) | Selected |
| [flow/blossom.cpp](graphs/flow/blossom.cpp) | Library only |
| [flow/blossom_wf26.cpp](graphs/flow/blossom_wf26.cpp) | Selected |
| [flow/dinic.cpp](graphs/flow/dinic.cpp) | Selected |
| [flow/hopcroft_karp.cpp](graphs/flow/hopcroft_karp.cpp) | Library only |
| [flow/hungarian.cpp](graphs/flow/hungarian.cpp) | Library only |
| [flow/hungarian_wf26.cpp](graphs/flow/hungarian_wf26.cpp) | Selected |
| [flow/max_flow.cpp](graphs/flow/max_flow.cpp) | Library only |
| [flow/max_flow_min_cost.cpp](graphs/flow/max_flow_min_cost.cpp) | Library only |
| [flow/max_flow_min_cost_multiedge.cpp](graphs/flow/max_flow_min_cost_multiedge.cpp) | Selected |
| [flow/maximum_bipartite_matching.cpp](graphs/flow/maximum_bipartite_matching.cpp) | Library only |
| [flow/min_cost_flow.cpp](graphs/flow/min_cost_flow.cpp) | Library only |
| [flow/min_cost_flow_wf26.cpp](graphs/flow/min_cost_flow_wf26.cpp) | Selected |
| [floyd_warshall.cpp](graphs/floyd_warshall.cpp) | Library only |
| [floyd_warshall_wf26.cpp](graphs/floyd_warshall_wf26.cpp) | Selected |
| [ford_fulkerson.cpp](graphs/ford_fulkerson.cpp) | Library only |
| [ford_fulkerson_wf26.cpp](graphs/ford_fulkerson_wf26.cpp) | Selected |
| [kruskal.cpp](graphs/kruskal.cpp) | Library only |
| [prim.cpp](graphs/prim.cpp) | Library only |
| [strongly_connected_components.cpp](graphs/strongly_connected_components.cpp) | Library only |
| [strongly_connected_components_wf26.cpp](graphs/strongly_connected_components_wf26.cpp) | Selected |
| [topological_sort.cpp](graphs/topological_sort.cpp) | Library only |
| [topological_sort_wf26.cpp](graphs/topological_sort_wf26.cpp) | Selected |
| [two_sat.cpp](graphs/two_sat.cpp) | Library only |
| [two_sat_wf26.cpp](graphs/two_sat_wf26.cpp) | Selected |

## Math

| Implementation | World Finals |
| --- | --- |
| [bell.cpp](math/bell.cpp) | Library only |
| [berlekamp_massey.cpp](math/berlekamp_massey.cpp) | Library only |
| [binomial_coefficients.cpp](math/binomial_coefficients.cpp) | Library only |
| [catalan.cpp](math/catalan.cpp) | Library only |
| [fft.cpp](math/fft.cpp) | Library only |
| [fft_mod.cpp](math/fft_mod.cpp) | Library only |
| [fft_mod_wf26.cpp](math/fft_mod_wf26.cpp) | Selected |
| [fht.cpp](math/fht.cpp) | Library only |
| [fht_wf26.cpp](math/fht_wf26.cpp) | Selected |
| [fractions.cpp](math/fractions.cpp) | Library only |
| [gaussian_elimination.cpp](math/gaussian_elimination.cpp) | Library only |
| [gaussian_elimination_wf26.cpp](math/gaussian_elimination_wf26.cpp) | Selected |
| [inverse_matrix.cpp](math/inverse_matrix.cpp) | Library only |
| [inverse_matrix_wf26.cpp](math/inverse_matrix_wf26.cpp) | Selected |
| [iterate_submask.cpp](math/iterate_submask.cpp) | Library only |
| [lagrange.cpp](math/lagrange.cpp) | Library only |
| [lagrange_wf26.cpp](math/lagrange_wf26.cpp) | Selected |
| [linear_rec.cpp](math/linear_rec.cpp) | Selected |
| [matrix_fast_pow.cpp](math/matrix_fast_pow.cpp) | Selected |
| [matrix_reduce.cpp](math/matrix_reduce.cpp) | Library only |
| [matrix_reduce_wf26.cpp](math/matrix_reduce_wf26.cpp) | Selected |
| [ntt.cpp](math/ntt.cpp) | Library only |
| [polynomial.cpp](math/polynomial.cpp) | Library only |
| [print_int128.cpp](math/print_int128.cpp) | Library only |
| [print_int128_wf26.cpp](math/print_int128_wf26.cpp) | Selected |
| [random.cpp](math/random.cpp) | Library only |
| [random_wf26.cpp](math/random_wf26.cpp) | Selected |
| [shortest_path_matrix_exp.cpp](math/shortest_path_matrix_exp.cpp) | Library only |
| [simplex.cpp](math/simplex.cpp) | Library only |
| [simplex_wf26.cpp](math/simplex_wf26.cpp) | Selected |
| [simpson.cpp](math/simpson.cpp) | Library only |

## Number Theory

| Implementation | World Finals |
| --- | --- |
| [binary_exponentiation_inverse.cpp](number_theory/binary_exponentiation_inverse.cpp) | Library only |
| [binary_exponentiation_inverse_wf26.cpp](number_theory/binary_exponentiation_inverse_wf26.cpp) | Selected |
| [chinese_remainder.cpp](number_theory/chinese_remainder.cpp) | Library only |
| [chinese_remainder_wf26.cpp](number_theory/chinese_remainder_wf26.cpp) | Selected |
| [diophantine.cpp](number_theory/diophantine.cpp) | Library only |
| [discrete_log.cpp](number_theory/discrete_log.cpp) | Library only |
| [discrete_log_wf26.cpp](number_theory/discrete_log_wf26.cpp) | Selected |
| [discrete_root.cpp](number_theory/discrete_root.cpp) | Selected |
| [divisors.cpp](number_theory/divisors.cpp) | Selected |
| [miller_rabin_pollard_rho.cpp](number_theory/miller_rabin_pollard_rho.cpp) | Selected |
| [mod_ops.cpp](number_theory/mod_ops.cpp) | Library only |
| [modint.cpp](number_theory/modint.cpp) | Library only |
| [moebius.cpp](number_theory/moebius.cpp) | Library only |
| [prime_sieve.cpp](number_theory/prime_sieve.cpp) | Library only |
| [prime_sieve_wf26.cpp](number_theory/prime_sieve_wf26.cpp) | Selected |
| [totient_sieve.cpp](number_theory/totient_sieve.cpp) | Library only |

## Python

| Implementation | World Finals |
| --- | --- |
| [numbers.py](python/numbers.py) | Library only |
| [numbers_wf26.py](python/numbers_wf26.py) | Selected |
| [strings.py](python/strings.py) | Library only |
| [strings_wf26.py](python/strings_wf26.py) | Selected |

## Strings

| Implementation | World Finals |
| --- | --- |
| [aho_corasick.cpp](strings/aho_corasick.cpp) | Selected |
| [dynamic_hash.cpp](strings/dynamic_hash.cpp) | Library only |
| [dynamic_hash_wf26.cpp](strings/dynamic_hash_wf26.cpp) | Selected |
| [find_kth_substr_repetitions.cpp](strings/find_kth_substr_repetitions.cpp) | Library only |
| [hashing.cpp](strings/hashing.cpp) | Selected |
| [manacher.cpp](strings/manacher.cpp) | Library only |
| [manacher_wf26.cpp](strings/manacher_wf26.cpp) | Selected |
| [palindromic_tree.cpp](strings/palindromic_tree.cpp) | Library only |
| [prefix_function.cpp](strings/prefix_function.cpp) | Selected |
| [rabin_karp.cpp](strings/rabin_karp.cpp) | Library only |
| [suffix_array.cpp](strings/suffix_array.cpp) | Selected |
| [suffix_automaton.cpp](strings/suffix_automaton.cpp) | Library only |
| [suffix_automaton_wf26.cpp](strings/suffix_automaton_wf26.cpp) | Selected |
| [trie.cpp](strings/trie.cpp) | Library only |
| [z_function.cpp](strings/z_function.cpp) | Selected |

## Trees

| Implementation | World Finals |
| --- | --- |
| [binary_lifting.cpp](trees/binary_lifting.cpp) | Library only |
| [centroid.cpp](trees/centroid.cpp) | Library only |
| [centroid_cses.cpp](trees/centroid_cses.cpp) | Selected |
| [diameter.cpp](trees/diameter.cpp) | Library only |
| [dsu_on_tree.cpp](trees/dsu_on_tree.cpp) | Library only |
| [dynamic_connectivity.cpp](trees/dynamic_connectivity.cpp) | Library only |
| [find_centroid.cpp](trees/find_centroid.cpp) | Library only |
| [hld.cpp](trees/hld.cpp) | Selected |
| [isomorphism_centroid.cpp](trees/isomorphism_centroid.cpp) | Library only |
| [lca.cpp](trees/lca.cpp) | Library only |
| [lca_wf26.cpp](trees/lca_wf26.cpp) | Selected |
| [link_cut_tree.cpp](trees/link_cut_tree.cpp) | Library only |
| [small_to_large.cpp](trees/small_to_large.cpp) | Library only |
| [small_to_large_wf26.cpp](trees/small_to_large_wf26.cpp) | Selected |
