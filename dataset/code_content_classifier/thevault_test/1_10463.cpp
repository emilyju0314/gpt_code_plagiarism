void InsertNodes(KDTREE *tree, KDNODE *nodes) {
  if (nodes == nullptr) {
    return;
  }

  KDStore(tree, nodes->Key, nodes->Data);
  InsertNodes(tree, nodes->Left);
  InsertNodes(tree, nodes->Right);
}