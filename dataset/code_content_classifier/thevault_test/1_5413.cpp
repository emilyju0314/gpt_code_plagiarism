static bool has_fetch_operators(
    const BlockDesc& block, std::map<std::string, LoDTensor*>& fetch_targets,
    const std::string& fetch_holder_name) {
  size_t fetch_count = 0;
  for (auto* op : block.AllOps()) {
    if (op->Type() == kFetchOpType) {
      fetch_count++;
      PADDLE_ENFORCE_EQ(op->Output("Out")[0], fetch_holder_name,
                        "Output of fetch op should be '%s'", fetch_holder_name);
      std::string fetch_target_name = op->Input("X")[0];
      PADDLE_ENFORCE(
          fetch_targets.find(fetch_target_name) != fetch_targets.end(),
          "Fetch operator input name '%s' cannot be found in 'fetch_targets'",
          fetch_target_name);
    }
  }

  if (fetch_count > 0) {
    PADDLE_ENFORCE_EQ(
        fetch_count, fetch_targets.size(),
        "The number of fetch operators should match 'fetch_targets'");

    // When fetch operator are present, so should be fetch_holder
    auto var = block.FindVar(fetch_holder_name);
    PADDLE_ENFORCE_NOT_NULL(var, "Block should already have a '%s' variable",
                            fetch_holder_name);
    PADDLE_ENFORCE_EQ(var->GetType(), proto::VarType::FETCH_LIST,
                      "'%s' variable should be 'FETCH_LIST' type",
                      fetch_holder_name);
  }

  return fetch_count > 0;
}