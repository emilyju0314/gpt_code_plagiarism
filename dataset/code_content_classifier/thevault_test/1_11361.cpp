std::string unity_sframe::generate_next_column_name() {
  const auto& current_column_names = this->column_names();
  std::string name = std::string("X") + std::to_string(current_column_names.size() + 1);
  std::unordered_set<std::string> current_name_set(current_column_names.begin(),
                                                   current_column_names.end());

  // Resolve conflicts if the name is already taken
  while (current_name_set.count(name)) {
    name += ".";
    size_t number = 1;
    std::string non_conflict_name = name + std::to_string(number);
    while(current_name_set.count(non_conflict_name)) {
      ++number;
      non_conflict_name = name + std::to_string(number);
    }
    name = non_conflict_name;
  }
  return name;
}