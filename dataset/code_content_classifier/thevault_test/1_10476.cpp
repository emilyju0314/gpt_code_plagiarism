SVMenuNode *SVMenuNode::AddChild(const char *txt) {
  auto *s = new SVMenuNode(-1, txt, false, false);
  this->AddChild(s);
  return s;
}