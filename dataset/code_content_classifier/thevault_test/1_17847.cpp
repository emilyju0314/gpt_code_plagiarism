NetDef Transform::ApplyTo(const NetDef& orig_net) {
  Graph g(orig_net);
  const auto matches = PatternMatch(g);
  ReplacePattern(matches, &g);
  return g.GetNetDef();
}