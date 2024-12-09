ProblemData init_data_tensor(std::map<int, int> param_to_size) {
  ProblemData output;
  // Get CONSTANT_ID.
  output.init_id(CONSTANT_ID, 1);
  typedef std::map<int, int>::iterator it_type;
  for (it_type it = param_to_size.begin(); it != param_to_size.end(); ++it) {
    int param_id = it->first;
    int param_size = it->second;
    output.init_id(param_id, param_size);
  }
  return output;
}