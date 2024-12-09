const FunctionNode LikeHolder::TryOptimize(const FunctionNode& node) {
  std::shared_ptr<LikeHolder> holder;
  auto status = Make(node, &holder);
  if (status.ok()) {
    std::string& pattern = holder->pattern_;
    auto literal_type = node.children().at(1)->return_type();

    if (RE2::FullMatch(pattern, starts_with_regex_)) {
      auto prefix = pattern.substr(0, pattern.length() - 2);  // trim .*
      auto parsed_prefix = RemovePatternEscapeChars(node, prefix);
      auto prefix_node = std::make_shared<LiteralNode>(
          literal_type, LiteralHolder(parsed_prefix), false);
      return FunctionNode("starts_with", {node.children().at(0), prefix_node},
                          node.return_type());
    } else if (RE2::FullMatch(pattern, ends_with_regex_)) {
      auto suffix = pattern.substr(2);  // skip .*
      auto parsed_suffix = RemovePatternEscapeChars(node, suffix);
      auto suffix_node = std::make_shared<LiteralNode>(
          literal_type, LiteralHolder(parsed_suffix), false);
      return FunctionNode("ends_with", {node.children().at(0), suffix_node},
                          node.return_type());
    } else if (RE2::FullMatch(pattern, is_substr_regex_)) {
      auto substr =
          pattern.substr(2, pattern.length() - 4);  // trim starting and ending .*
      auto parsed_substr = RemovePatternEscapeChars(node, substr);
      auto substr_node = std::make_shared<LiteralNode>(
          literal_type, LiteralHolder(parsed_substr), false);
      return FunctionNode("is_substr", {node.children().at(0), substr_node},
                          node.return_type());
    }
  }

  // Could not optimize, return original node.
  return node;
}