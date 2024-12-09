CutGenerator CreateStronglyConnectedGraphCutGenerator(
    int num_nodes, const std::vector<int>& tails, const std::vector<int>& heads,
    const std::vector<IntegerVariable>& vars) {
  CutGenerator result;
  result.vars = vars;
  result.type = "StronglyConnectedGraph";
  result.generate_cuts =
      [num_nodes, tails, heads,
       vars](const gtl::ITIVector<IntegerVariable, double>& lp_values) {
        int num_arcs_in_lp_solution = 0;
        std::vector<double> var_lp_values;
        std::vector<std::vector<int>> graph(num_nodes);
        for (int i = 0; i < vars.size(); ++i) {
          var_lp_values.push_back(lp_values[vars[i]]);

          // TODO(user): a more advanced algorithm consist of adding the arcs
          // in the decreasing order of their lp_values, and for each strongly
          // connected components S along the way, try to add the corresponding
          // cuts. We can stop as soon as there is only two components left,
          // after adding the corresponding cut.
          if (lp_values[vars[i]] > 1e-6) {
            ++num_arcs_in_lp_solution;
            graph[tails[i]].push_back(heads[i]);
          }
        }
        std::vector<LinearConstraint> cuts;
        std::vector<std::vector<int>> components;
        FindStronglyConnectedComponents(num_nodes, graph, &components);
        if (components.size() == 1) return cuts;

        VLOG(1) << "num_arcs_in_lp_solution:" << num_arcs_in_lp_solution
                << " sccs:" << components.size();
        for (const std::vector<int>& component : components) {
          if (component.size() == 1) continue;
          AddIncomingAndOutgoingCutsIfNeeded(num_nodes, component, tails, heads,
                                             vars, var_lp_values,
                                             /*rhs_lower_bound=*/1, &cuts);

          // In this case, the cuts for each component are the same.
          if (components.size() == 2) break;
        }
        return cuts;
      };
  return result;
}