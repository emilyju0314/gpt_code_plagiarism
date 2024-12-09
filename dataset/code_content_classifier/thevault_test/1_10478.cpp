void SVMenuNode::AddChild(SVMenuNode *svmn) {
  svmn->parent_ = this;
  // No children yet.
  if (child_ == nullptr) {
    child_ = svmn;
  } else {
    SVMenuNode *cur = child_;
    while (cur->next_ != nullptr) {
      cur = cur->next_;
    }
    cur->next_ = svmn;
  }
}