# Library consolidation review

The reorganization preserves the executable source of the existing collection and
the WF26 selection. Of 200 source references (128 original and 72 WF26),
191 retain byte-identical content; nine share the more documented source with
only full-line comments or whitespace differences. All 73 printed entries retain
their previous membership and order. Other differing pairs remain explicit alternatives;
some may still be equivalent, but they have not been silently merged.

## Recent changes that were not propagated

| Change | Current disposition | Next action |
| --- | --- | --- |
| Eulerian-path existence notes (`e3b1998`) | Shared [Eulerian implementation](../algorithms/graphs/eulerian_cycle.cpp); WF now uses the documented source. | No executable change to promote. |
| Signed int128 printing (`afee527`) | [Library implementation](../algorithms/math/print_int128.cpp) and [WF variant](../algorithms/math/print_int128_wf26.cpp) remain distinct. | Test zero, positive, negative, and extreme values, then deliberately switch the WF manifest and retire the old variant. |
| Lazy segment tree neutral values and initialization (`b18f8ce`, `ee293f1`) | [Library implementation](../algorithms/data_structures/segment_tree_recursive/lazy_extreme.cpp) and [WF variant](../algorithms/data_structures/segment_tree_recursive/lazy_extreme_wf26.cpp) remain distinct. | Differential-test updates and queries, including custom neutral values, before changing the selection. |
| FFT update (`b8031e7`) | [FFT](../algorithms/math/fft.cpp) stays in the full library; WF selects a different modular FFT implementation. | Evaluate it as a selection choice, not a missing copy operation. |
| Miller–Rabin fix (`c4839da`, issue #9) | [Corrected implementation](../algorithms/number_theory/miller_rabin_pollard_rho.cpp) is shared by the library and WF. The unsafe original is historical material only. | Regression tests now cover this implementation in CI. |

## How fixes reach a notebook

1. Edit the selected source in `algorithms/` and add an appropriate regression test.
2. Every manifest pointing to that file receives the fix on the next build.
3. If another implementation of the same algorithm exists, review it explicitly.
   A fix to one variant does not establish correctness of the other.
4. To consolidate variants, test the intended contract, point the manifest to the
   chosen implementation, and remove the obsolete active variant. Git retains history.
5. Freeze contest snapshots with a tag and release PDF. Avoid copying the library
   into another maintained event directory.

The presence of a variant does not imply that it is validated. This change moves
and selects algorithms; it does not apply the pending behavioral fixes above.

## Source inventory

Paths below record where the previous WF26 sources now live. "Shared" means the
same executable lines after ignoring full-line comments and whitespace. "Variant"
means conservatively retained for review, not necessarily behaviorally different.

| Previous WF26 source | Library source | WF selection source | Disposition |
| --- | --- | --- | --- |
| `Python/numbs.py` | [algorithms/python/numbers.py](../algorithms/python/numbers.py) | [algorithms/python/numbers_wf26.py](../algorithms/python/numbers_wf26.py) | variant |
| `Python/strings.py` | [algorithms/python/strings.py](../algorithms/python/strings.py) | [algorithms/python/strings_wf26.py](../algorithms/python/strings_wf26.py) | variant |
| `data_structures/Mo_DQuery.cpp` | [algorithms/data_structures/mo_distinct_queries.cpp](../algorithms/data_structures/mo_distinct_queries.cpp) | [algorithms/data_structures/mo_distinct_queries.cpp](../algorithms/data_structures/mo_distinct_queries.cpp) | shared |
| `data_structures/compresion_de_coordenadas.cpp` | [algorithms/data_structures/coordinate_compression.cpp](../algorithms/data_structures/coordinate_compression.cpp) | [algorithms/data_structures/coordinate_compression_wf26.cpp](../algorithms/data_structures/coordinate_compression_wf26.cpp) | variant |
| `data_structures/dsu.cpp` | [algorithms/data_structures/dsu.cpp](../algorithms/data_structures/dsu.cpp) | [algorithms/data_structures/dsu.cpp](../algorithms/data_structures/dsu.cpp) | shared |
| `data_structures/implicit_treap.cpp` | [algorithms/data_structures/implicit_treap.cpp](../algorithms/data_structures/implicit_treap.cpp) | [algorithms/data_structures/implicit_treap.cpp](../algorithms/data_structures/implicit_treap.cpp) | shared |
| `data_structures/indexed_set.cpp` | [algorithms/data_structures/indexed_set.cpp](../algorithms/data_structures/indexed_set.cpp) | [algorithms/data_structures/indexed_set_wf26.cpp](../algorithms/data_structures/indexed_set_wf26.cpp) | variant |
| `data_structures/lazy-propagation.cpp` | [algorithms/data_structures/segment_tree_recursive/lazy_extreme.cpp](../algorithms/data_structures/segment_tree_recursive/lazy_extreme.cpp) | [algorithms/data_structures/segment_tree_recursive/lazy_extreme_wf26.cpp](../algorithms/data_structures/segment_tree_recursive/lazy_extreme_wf26.cpp) | variant |
| `data_structures/persistent.cpp` | [algorithms/data_structures/segment_tree_recursive/persistent.cpp](../algorithms/data_structures/segment_tree_recursive/persistent.cpp) | [algorithms/data_structures/segment_tree_recursive/persistent.cpp](../algorithms/data_structures/segment_tree_recursive/persistent.cpp) | shared |
| `data_structures/segtree-iterative.cpp` | [algorithms/data_structures/segment_tree_iterative/segtree_range_query.cpp](../algorithms/data_structures/segment_tree_iterative/segtree_range_query.cpp) | [algorithms/data_structures/segment_tree_iterative/segtree_range_query_wf26.cpp](../algorithms/data_structures/segment_tree_iterative/segtree_range_query_wf26.cpp) | variant |
| `data_structures/segtree_2d.cpp` | [algorithms/data_structures/segment_tree_iterative/segtree_2d.cpp](../algorithms/data_structures/segment_tree_iterative/segtree_2d.cpp) | [algorithms/data_structures/segment_tree_iterative/segtree_2d_wf26.cpp](../algorithms/data_structures/segment_tree_iterative/segtree_2d_wf26.cpp) | variant |
| `dp/CHT_Dynamic.cpp` | [algorithms/dynamic_programming/convex_hull_trick_dynamic.cpp](../algorithms/dynamic_programming/convex_hull_trick_dynamic.cpp) | [algorithms/dynamic_programming/convex_hull_trick_dynamic_wf26.cpp](../algorithms/dynamic_programming/convex_hull_trick_dynamic_wf26.cpp) | variant |
| `dp/Knapsack_weighted.cpp` | [algorithms/dynamic_programming/knapsack_weighted.cpp](../algorithms/dynamic_programming/knapsack_weighted.cpp) | [algorithms/dynamic_programming/knapsack_weighted_wf26.cpp](../algorithms/dynamic_programming/knapsack_weighted_wf26.cpp) | variant |
| `dp/LIS.cpp` | [algorithms/dynamic_programming/lis.cpp](../algorithms/dynamic_programming/lis.cpp) | [algorithms/dynamic_programming/lis_wf26.cpp](../algorithms/dynamic_programming/lis_wf26.cpp) | variant |
| `dp/divide_and_conquer_dp_opt.cpp` | [algorithms/dynamic_programming/divide_and_conquer_optimization.cpp](../algorithms/dynamic_programming/divide_and_conquer_optimization.cpp) | [algorithms/dynamic_programming/divide_and_conquer_optimization_wf26.cpp](../algorithms/dynamic_programming/divide_and_conquer_optimization_wf26.cpp) | variant |
| `dp/knuth_division_dp_opt.cpp` | [algorithms/dynamic_programming/knuth_optimization.cpp](../algorithms/dynamic_programming/knuth_optimization.cpp) | [algorithms/dynamic_programming/knuth_optimization_wf26.cpp](../algorithms/dynamic_programming/knuth_optimization_wf26.cpp) | variant |
| `geometry/angular_sort.cpp` | [algorithms/geometry/angular_sort.cpp](../algorithms/geometry/angular_sort.cpp) | [algorithms/geometry/angular_sort.cpp](../algorithms/geometry/angular_sort.cpp) | shared |
| `geometry/calipers.cpp` | [algorithms/geometry/calipers.cpp](../algorithms/geometry/calipers.cpp) | [algorithms/geometry/calipers.cpp](../algorithms/geometry/calipers.cpp) | shared |
| `geometry/closest_points_Monogon.cpp` | [algorithms/geometry/closest_points_monogon.cpp](../algorithms/geometry/closest_points_monogon.cpp) | [algorithms/geometry/closest_points_monogon.cpp](../algorithms/geometry/closest_points_monogon.cpp) | shared |
| `geometry/convex_hull.cpp` | [algorithms/geometry/convex_hull.cpp](../algorithms/geometry/convex_hull.cpp) | [algorithms/geometry/convex_hull_wf26.cpp](../algorithms/geometry/convex_hull_wf26.cpp) | variant |
| `geometry/formulas.cpp` | [algorithms/geometry/formulas.cpp](../algorithms/geometry/formulas.cpp) | [algorithms/geometry/formulas_wf26.cpp](../algorithms/geometry/formulas_wf26.cpp) | variant |
| `geometry/intersection_all.cpp` | [algorithms/geometry/intersection_all.cpp](../algorithms/geometry/intersection_all.cpp) | [algorithms/geometry/intersection_all.cpp](../algorithms/geometry/intersection_all.cpp) | shared |
| `geometry/minimum_enclosing_circle.cpp` | — | [algorithms/geometry/minimum_enclosing_circle.cpp](../algorithms/geometry/minimum_enclosing_circle.cpp) | WF26-only |
| `geometry/point_in_poly.cpp` | [algorithms/geometry/point_in_polygon.cpp](../algorithms/geometry/point_in_polygon.cpp) | [algorithms/geometry/point_in_polygon_wf26.cpp](../algorithms/geometry/point_in_polygon_wf26.cpp) | variant |
| `geometry/template_punto.cpp` | [algorithms/geometry/point.cpp](../algorithms/geometry/point.cpp) | [algorithms/geometry/point_wf26.cpp](../algorithms/geometry/point_wf26.cpp) | variant |
| `grafos/2SAT.cpp` | [algorithms/graphs/two_sat.cpp](../algorithms/graphs/two_sat.cpp) | [algorithms/graphs/two_sat_wf26.cpp](../algorithms/graphs/two_sat_wf26.cpp) | variant |
| `grafos/FordFulkerson.cpp` | [algorithms/graphs/ford_fulkerson.cpp](../algorithms/graphs/ford_fulkerson.cpp) | [algorithms/graphs/ford_fulkerson_wf26.cpp](../algorithms/graphs/ford_fulkerson_wf26.cpp) | variant |
| `grafos/MST_Directed.cpp` | — | [algorithms/graphs/directed_mst.cpp](../algorithms/graphs/directed_mst.cpp) | WF26-only |
| `grafos/bellman_ford.cpp` | [algorithms/graphs/bellman_ford.cpp](../algorithms/graphs/bellman_ford.cpp) | [algorithms/graphs/bellman_ford_wf26.cpp](../algorithms/graphs/bellman_ford_wf26.cpp) | variant |
| `grafos/biconnected.cpp` | [algorithms/graphs/biconnected.cpp](../algorithms/graphs/biconnected.cpp) | [algorithms/graphs/biconnected_wf26.cpp](../algorithms/graphs/biconnected_wf26.cpp) | variant |
| `grafos/blossom.cpp` | [algorithms/graphs/flow/blossom.cpp](../algorithms/graphs/flow/blossom.cpp) | [algorithms/graphs/flow/blossom_wf26.cpp](../algorithms/graphs/flow/blossom_wf26.cpp) | variant |
| `grafos/componentes_fuertemente_conexas.cpp` | [algorithms/graphs/strongly_connected_components.cpp](../algorithms/graphs/strongly_connected_components.cpp) | [algorithms/graphs/strongly_connected_components_wf26.cpp](../algorithms/graphs/strongly_connected_components_wf26.cpp) | variant |
| `grafos/dijkstra.cpp` | [algorithms/graphs/dijkstra.cpp](../algorithms/graphs/dijkstra.cpp) | [algorithms/graphs/dijkstra_wf26.cpp](../algorithms/graphs/dijkstra_wf26.cpp) | variant |
| `grafos/dinic.cpp` | [algorithms/graphs/flow/dinic.cpp](../algorithms/graphs/flow/dinic.cpp) | [algorithms/graphs/flow/dinic.cpp](../algorithms/graphs/flow/dinic.cpp) | shared |
| `grafos/dynamic_connectivity.cpp` | [algorithms/graphs/dynamic_connectivity.cpp](../algorithms/graphs/dynamic_connectivity.cpp) | [algorithms/graphs/dynamic_connectivity_wf26.cpp](../algorithms/graphs/dynamic_connectivity_wf26.cpp) | variant |
| `grafos/eulerian_cycle.cpp` | [algorithms/graphs/eulerian_cycle.cpp](../algorithms/graphs/eulerian_cycle.cpp) | [algorithms/graphs/eulerian_cycle.cpp](../algorithms/graphs/eulerian_cycle.cpp) | shared |
| `grafos/floyd_warshall.cpp` | [algorithms/graphs/floyd_warshall.cpp](../algorithms/graphs/floyd_warshall.cpp) | [algorithms/graphs/floyd_warshall_wf26.cpp](../algorithms/graphs/floyd_warshall_wf26.cpp) | variant |
| `grafos/hungarian.cpp` | [algorithms/graphs/flow/hungarian.cpp](../algorithms/graphs/flow/hungarian.cpp) | [algorithms/graphs/flow/hungarian_wf26.cpp](../algorithms/graphs/flow/hungarian_wf26.cpp) | variant |
| `grafos/max_flow_min_cost_multiedge.cpp` | [algorithms/graphs/flow/max_flow_min_cost_multiedge.cpp](../algorithms/graphs/flow/max_flow_min_cost_multiedge.cpp) | [algorithms/graphs/flow/max_flow_min_cost_multiedge.cpp](../algorithms/graphs/flow/max_flow_min_cost_multiedge.cpp) | shared |
| `grafos/min_cost_flow.cpp` | [algorithms/graphs/flow/min_cost_flow.cpp](../algorithms/graphs/flow/min_cost_flow.cpp) | [algorithms/graphs/flow/min_cost_flow_wf26.cpp](../algorithms/graphs/flow/min_cost_flow_wf26.cpp) | variant |
| `grafos/toposort.cpp` | [algorithms/graphs/topological_sort.cpp](../algorithms/graphs/topological_sort.cpp) | [algorithms/graphs/topological_sort_wf26.cpp](../algorithms/graphs/topological_sort_wf26.cpp) | variant |
| `math/fft_mod.cpp` | [algorithms/math/fft_mod.cpp](../algorithms/math/fft_mod.cpp) | [algorithms/math/fft_mod_wf26.cpp](../algorithms/math/fft_mod_wf26.cpp) | variant |
| `math/fht.cpp` | [algorithms/math/fht.cpp](../algorithms/math/fht.cpp) | [algorithms/math/fht_wf26.cpp](../algorithms/math/fht_wf26.cpp) | variant |
| `math/gauss_sistema_ecuaciones.cpp` | [algorithms/math/gaussian_elimination.cpp](../algorithms/math/gaussian_elimination.cpp) | [algorithms/math/gaussian_elimination_wf26.cpp](../algorithms/math/gaussian_elimination_wf26.cpp) | variant |
| `math/inverse_matrix.cpp` | [algorithms/math/inverse_matrix.cpp](../algorithms/math/inverse_matrix.cpp) | [algorithms/math/inverse_matrix_wf26.cpp](../algorithms/math/inverse_matrix_wf26.cpp) | variant |
| `math/lagrange.cpp` | [algorithms/math/lagrange.cpp](../algorithms/math/lagrange.cpp) | [algorithms/math/lagrange_wf26.cpp](../algorithms/math/lagrange_wf26.cpp) | variant |
| `math/linear_rec.cpp` | [algorithms/math/linear_rec.cpp](../algorithms/math/linear_rec.cpp) | [algorithms/math/linear_rec.cpp](../algorithms/math/linear_rec.cpp) | shared |
| `math/matrix_fast_pow.cpp` | [algorithms/math/matrix_fast_pow.cpp](../algorithms/math/matrix_fast_pow.cpp) | [algorithms/math/matrix_fast_pow.cpp](../algorithms/math/matrix_fast_pow.cpp) | shared |
| `math/matrix_reduce.cpp` | [algorithms/math/matrix_reduce.cpp](../algorithms/math/matrix_reduce.cpp) | [algorithms/math/matrix_reduce_wf26.cpp](../algorithms/math/matrix_reduce_wf26.cpp) | variant |
| `math/print_int128.cpp` | [algorithms/math/print_int128.cpp](../algorithms/math/print_int128.cpp) | [algorithms/math/print_int128_wf26.cpp](../algorithms/math/print_int128_wf26.cpp) | variant |
| `math/random.cpp` | [algorithms/math/random.cpp](../algorithms/math/random.cpp) | [algorithms/math/random_wf26.cpp](../algorithms/math/random_wf26.cpp) | variant |
| `math/simplex.cpp` | [algorithms/math/simplex.cpp](../algorithms/math/simplex.cpp) | [algorithms/math/simplex_wf26.cpp](../algorithms/math/simplex_wf26.cpp) | variant |
| `number_theory/binexp_invmod.cpp` | [algorithms/number_theory/binary_exponentiation_inverse.cpp](../algorithms/number_theory/binary_exponentiation_inverse.cpp) | [algorithms/number_theory/binary_exponentiation_inverse_wf26.cpp](../algorithms/number_theory/binary_exponentiation_inverse_wf26.cpp) | variant |
| `number_theory/criba_primos.cpp` | [algorithms/number_theory/prime_sieve.cpp](../algorithms/number_theory/prime_sieve.cpp) | [algorithms/number_theory/prime_sieve_wf26.cpp](../algorithms/number_theory/prime_sieve_wf26.cpp) | variant |
| `number_theory/discrete_log.cpp` | [algorithms/number_theory/discrete_log.cpp](../algorithms/number_theory/discrete_log.cpp) | [algorithms/number_theory/discrete_log_wf26.cpp](../algorithms/number_theory/discrete_log_wf26.cpp) | variant |
| `number_theory/discrete_root.cpp` | [algorithms/number_theory/discrete_root.cpp](../algorithms/number_theory/discrete_root.cpp) | [algorithms/number_theory/discrete_root.cpp](../algorithms/number_theory/discrete_root.cpp) | shared |
| `number_theory/divisors.cpp` | [algorithms/number_theory/divisors.cpp](../algorithms/number_theory/divisors.cpp) | [algorithms/number_theory/divisors.cpp](../algorithms/number_theory/divisors.cpp) | shared |
| `number_theory/fast_factorization_mrabin_prho.cpp` | [archive/original/number_theory/miller_rabin_pollard_rho.cpp](../archive/original/number_theory/miller_rabin_pollard_rho.cpp) | [algorithms/number_theory/miller_rabin_pollard_rho.cpp](../algorithms/number_theory/miller_rabin_pollard_rho.cpp) | retired unsafe original |
| `number_theory/teo_chino_resto.cpp` | [algorithms/number_theory/chinese_remainder.cpp](../algorithms/number_theory/chinese_remainder.cpp) | [algorithms/number_theory/chinese_remainder_wf26.cpp](../algorithms/number_theory/chinese_remainder_wf26.cpp) | variant |
| `strings/aho_corasick.cpp` | [algorithms/strings/aho_corasick.cpp](../algorithms/strings/aho_corasick.cpp) | [algorithms/strings/aho_corasick.cpp](../algorithms/strings/aho_corasick.cpp) | shared |
| `strings/dynamic_Hash.cpp` | [algorithms/strings/dynamic_hash.cpp](../algorithms/strings/dynamic_hash.cpp) | [algorithms/strings/dynamic_hash_wf26.cpp](../algorithms/strings/dynamic_hash_wf26.cpp) | variant |
| `strings/hashing.cpp` | [algorithms/strings/hashing.cpp](../algorithms/strings/hashing.cpp) | [algorithms/strings/hashing.cpp](../algorithms/strings/hashing.cpp) | shared |
| `strings/manacher.cpp` | [algorithms/strings/manacher.cpp](../algorithms/strings/manacher.cpp) | [algorithms/strings/manacher_wf26.cpp](../algorithms/strings/manacher_wf26.cpp) | variant |
| `strings/prefix_function.cpp` | [algorithms/strings/prefix_function.cpp](../algorithms/strings/prefix_function.cpp) | [algorithms/strings/prefix_function.cpp](../algorithms/strings/prefix_function.cpp) | shared |
| `strings/suffix_array.cpp` | [algorithms/strings/suffix_array.cpp](../algorithms/strings/suffix_array.cpp) | [algorithms/strings/suffix_array.cpp](../algorithms/strings/suffix_array.cpp) | shared |
| `strings/suffix_automaton.cpp` | [algorithms/strings/suffix_automaton.cpp](../algorithms/strings/suffix_automaton.cpp) | [algorithms/strings/suffix_automaton_wf26.cpp](../algorithms/strings/suffix_automaton_wf26.cpp) | variant |
| `strings/trie.cpp` | [algorithms/strings/trie.cpp](../algorithms/strings/trie.cpp) | [algorithms/strings/trie.cpp](../algorithms/strings/trie.cpp) | shared |
| `strings/z_function.cpp` | [algorithms/strings/z_function.cpp](../algorithms/strings/z_function.cpp) | [algorithms/strings/z_function.cpp](../algorithms/strings/z_function.cpp) | shared |
| `tree/LCA.cpp` | [algorithms/trees/lca.cpp](../algorithms/trees/lca.cpp) | [algorithms/trees/lca_wf26.cpp](../algorithms/trees/lca_wf26.cpp) | variant |
| `tree/centroid_cses.cpp` | [algorithms/trees/centroid_cses.cpp](../algorithms/trees/centroid_cses.cpp) | [algorithms/trees/centroid_cses.cpp](../algorithms/trees/centroid_cses.cpp) | shared |
| `tree/hld.cpp` | [algorithms/trees/hld.cpp](../algorithms/trees/hld.cpp) | [algorithms/trees/hld.cpp](../algorithms/trees/hld.cpp) | shared |
| `tree/sm_to_large.cpp` | [algorithms/trees/small_to_large.cpp](../algorithms/trees/small_to_large.cpp) | [algorithms/trees/small_to_large_wf26.cpp](../algorithms/trees/small_to_large_wf26.cpp) | variant |

Trie remains library-only, matching its prior explicit exclusion from the PDF.
Python reference snippets are included in the inventory; the contest setup files
live in `templates/cpp/`.
