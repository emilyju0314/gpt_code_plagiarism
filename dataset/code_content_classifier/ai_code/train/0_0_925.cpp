To solve this problem, you can use network flow algorithms. One way to approach this problem is to convert it to a maximum flow problem.

Here is some pseudocode to achieve this:

1. Read input values n, m, and the edge descriptions.
2. Create a graph with n+2 vertices (n vertices for the original graph, 1 source vertex, and 1 sink vertex).
3. Add edges from the source vertex to each edge vertex in the graph with capacities equal to r_e(t) - l_e(t).
4. Add edges from each edge vertex to its startpoint and endpoint vertices in the graph with capacities equal to infinity.
5. Add edges from each vertex in the graph to the sink vertex with capacities equal to ∑_{e ∈ \delta^{-}(v)} (r_e(t)) - ∑_{e ∈ \delta^{+}(v)} (l_e(t)).
6. Use a maximum flow algorithm (such as Edmonds-Karp or Ford-Fulkerson) to find the maximum flow in the graph.
7. If the maximum flow is equal to the sum of capacities of edges from the source vertex, there exists an lr-circulation in the graph for the chosen t value.
8. Calculate the probability by dividing the number of times an lr-circulation exists by the total possible t values.

You can implement this algorithm in C++ using various network flow libraries or by coding the algorithms from scratch. Remember to handle the input and output as described in the problem statement.