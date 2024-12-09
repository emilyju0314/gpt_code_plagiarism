void KDStore(KDTREE *Tree, float *Key, void *Data) {
  auto PtrToNode = &(Tree->Root.Left);
  auto Node = *PtrToNode;
  auto Level = NextLevel(Tree, -1);
  while (Node != nullptr) {
    if (Key[Level] < Node->BranchPoint) {
      PtrToNode = &(Node->Left);
      if (Key[Level] > Node->LeftBranch) {
        Node->LeftBranch = Key[Level];
      }
    } else {
      PtrToNode = &(Node->Right);
      if (Key[Level] < Node->RightBranch) {
        Node->RightBranch = Key[Level];
      }
    }
    Level = NextLevel(Tree, Level);
    Node = *PtrToNode;
  }

  *PtrToNode = new KDNODE(Tree, Key, Data, Level);
}