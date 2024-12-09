void KDWalk(KDTREE *Tree, void_proc action, void *context) {
  if (Tree->Root.Left != nullptr) {
    Walk(Tree, action, context, Tree->Root.Left, NextLevel(Tree, -1));
  }
}