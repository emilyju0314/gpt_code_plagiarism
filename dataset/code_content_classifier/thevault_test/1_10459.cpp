void KDTreeSearch::SearchRec(int level, KDNODE *sub_tree) {
  if (level >= tree_->KeySize) {
    level = 0;
  }

  if (!BoxIntersectsSearch(sb_min_, sb_max_)) {
    return;
  }

  results_.insert(DistanceSquared(tree_->KeySize, &tree_->KeyDesc[0], query_point_, sub_tree->Key),
                  sub_tree->Data);

  if (query_point_[level] < sub_tree->BranchPoint) {
    if (sub_tree->Left != nullptr) {
      float tmp = sb_max_[level];
      sb_max_[level] = sub_tree->LeftBranch;
      SearchRec(NextLevel(tree_, level), sub_tree->Left);
      sb_max_[level] = tmp;
    }
    if (sub_tree->Right != nullptr) {
      float tmp = sb_min_[level];
      sb_min_[level] = sub_tree->RightBranch;
      SearchRec(NextLevel(tree_, level), sub_tree->Right);
      sb_min_[level] = tmp;
    }
  } else {
    if (sub_tree->Right != nullptr) {
      float tmp = sb_min_[level];
      sb_min_[level] = sub_tree->RightBranch;
      SearchRec(NextLevel(tree_, level), sub_tree->Right);
      sb_min_[level] = tmp;
    }
    if (sub_tree->Left != nullptr) {
      float tmp = sb_max_[level];
      sb_max_[level] = sub_tree->LeftBranch;
      SearchRec(NextLevel(tree_, level), sub_tree->Left);
      sb_max_[level] = tmp;
    }
  }
}