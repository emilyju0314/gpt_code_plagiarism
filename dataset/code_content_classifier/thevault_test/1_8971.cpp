void FindComponents(const std::vector<FapConstraint>& constraints,
                    const std::map<int, FapVariable>& variables,
                    const int maximum_variable_id,
                    std::unordered_map<int, FapComponent>* components) {
  std::vector<int> in_component(maximum_variable_id + 1, -1);
  int constraint_index = 0;
  for (const FapConstraint& constraint : constraints) {
    const int variable_id1 = constraint.variable1;
    const int variable_id2 = constraint.variable2;
    const FapVariable& variable1 = FindOrDie(variables, variable_id1);
    const FapVariable& variable2 = FindOrDie(variables, variable_id2);
    CHECK_LT(variable_id1, in_component.size());
    CHECK_LT(variable_id2, in_component.size());
    if (in_component[variable_id1] < 0 && in_component[variable_id2] < 0) {
      // None of the variables belong to an existing component.
      // Create a new one.
      FapComponent component;
      const int component_index = constraint_index;
      InsertOrUpdate(&(component.variables), variable_id1, variable1);
      InsertOrUpdate(&(component.variables), variable_id2, variable2);
      in_component[variable_id1] = component_index;
      in_component[variable_id2] = component_index;
      component.constraints.push_back(constraint);
      InsertOrUpdate(components, component_index, component);
    } else if (in_component[variable_id1] >= 0 &&
               in_component[variable_id2] < 0) {
      // If variable1 belongs to an existing component, variable2 should
      // also be included in the same component.
      const int component_index = in_component[variable_id1];
      CHECK(ContainsKey(*components, component_index));
      InsertOrUpdate(&((*components)[component_index].variables), variable_id2,
                     variable2);
      in_component[variable_id2] = component_index;
      (*components)[component_index].constraints.push_back(constraint);
    } else if (in_component[variable_id1] < 0 &&
               in_component[variable_id2] >= 0) {
      // If variable2 belongs to an existing component, variable1 should
      // also be included in the same component.
      const int component_index = in_component[variable_id2];
      CHECK(ContainsKey(*components, component_index));
      InsertOrUpdate(&((*components)[component_index].variables), variable_id1,
                     variable1);
      in_component[variable_id1] = component_index;
      (*components)[component_index].constraints.push_back(constraint);
    } else {
      // The current constraint connects two different components.
      const int component_index1 = in_component[variable_id1];
      const int component_index2 = in_component[variable_id2];
      const int min_component_index =
          std::min(component_index1, component_index2);
      const int max_component_index =
          std::max(component_index1, component_index2);
      CHECK(ContainsKey(*components, min_component_index));
      CHECK(ContainsKey(*components, max_component_index));
      if (min_component_index != max_component_index) {
        // Update the component_index of maximum indexed component's variables.
        for (const auto& variable :
                 (*components)[max_component_index].variables) {
          int variable_id = variable.first;
          in_component[variable_id] = min_component_index;
        }
        // Insert all the variables of the maximum indexed component to the
        // variables of the minimum indexed component.
        ((*components)[min_component_index]).variables.insert(
            ((*components)[max_component_index]).variables.begin(),
            ((*components)[max_component_index]).variables.end());
        // Insert all the constraints of the maximum indexed component to the
        // constraints of the minimum indexed component.
        ((*components)[min_component_index]).constraints.insert(
            ((*components)[min_component_index]).constraints.end(),
            ((*components)[max_component_index]).constraints.begin(),
            ((*components)[max_component_index]).constraints.end());
        (*components)[min_component_index]
            .constraints.push_back(constraint);
        // Delete the maximum indexed component from the components set.
        components->erase(max_component_index);
      } else {
        // Both variables belong to the same component, just add the constraint.
        (*components)[min_component_index].constraints.push_back(constraint);
      }
    }
    constraint_index++;
  }
}