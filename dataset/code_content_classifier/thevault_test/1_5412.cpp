static bool has_feed_operators(
    const BlockDesc& block,
    std::map<std::string, const LoDTensor*>& feed_targets,
    const std::string& feed_holder_name) {
  size_t feed_count = 0;
  for (auto* op : block.AllOps()) {
    if (op->Type() == kFeedOpType) {
      feed_count++;
      PADDLE_ENFORCE_EQ(op->Input("X")[0], feed_holder_name,
                        "Input to feed op should be '%s'", feed_holder_name);
      std::string feed_target_name = op->Output("Out")[0];
      PADDLE_ENFORCE(
          feed_targets.find(feed_target_name) != feed_targets.end(),
          "Feed operator output name '%s' cannot be found in 'feed_targets'",
          feed_target_name);
    }
  }

  if (feed_count > 0) {
    PADDLE_ENFORCE_EQ(
        feed_count, feed_targets.size(),
        "The number of feed operators should match 'feed_targets'");

    // When feed operator are present, so should be feed_holder
    auto var = block.FindVar(feed_holder_name);
    PADDLE_ENFORCE_NOT_NULL(var, "Block should already have a '%s' variable",
                            feed_holder_name);
    PADDLE_ENFORCE_EQ(var->GetType(), proto::VarType::FEED_MINIBATCH,
                      "'%s' variable should be 'FEED_MINIBATCH' type",
                      feed_holder_name);
  }

  return feed_count > 0;
}