void Walk(KDTREE *tree, void_proc action, void *context, KDNODE *sub_tree, int32_t level) {
  (*action)(context, sub_tree->Data, level);
  if (sub_tree->Left != nullptr) {
    Walk(tree, action, context, sub_tree->Left, NextLevel(tree, level));
  }
  if (sub_tree->Right != nullptr) {
    Walk(tree, action, context, sub_tree->Right, NextLevel(tree, level));
  }
}