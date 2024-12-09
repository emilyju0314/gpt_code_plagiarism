static std::exception_ptr 
find_earliest_exception(std::shared_ptr<execution_node> tip,
                        std::set<std::shared_ptr<execution_node>>& visited) {
  if (visited.count(tip)) return std::exception_ptr();
  std::exception_ptr ret;
  for (size_t i = 0;i < tip->num_inputs(); ++i) {
    auto input = tip->get_input_node(i);
    auto input_exception = find_earliest_exception(input, visited);
    if (input_exception != nullptr) {
      ret = input_exception; 
      break;
    }
  }
  visited.insert(tip);
  if (ret == nullptr && tip->exception_occurred()) {
    return tip->get_exception();
  } else {
    return ret;
  }
}