void KDDelete(KDTREE *Tree, float Key[], void *Data) {
  int Level;
  KDNODE *Current;
  KDNODE *Father;

  /* initialize search at root of tree */
  Father = &(Tree->Root);
  Current = Father->Left;
  Level = NextLevel(Tree, -1);

  /* search tree for node to be deleted */
  while ((Current != nullptr) && (!NodeFound(Current, Key, Data))) {
    Father = Current;
    if (Key[Level] < Current->BranchPoint) {
      Current = Current->Left;
    } else {
      Current = Current->Right;
    }

    Level = NextLevel(Tree, Level);
  }

  if (Current != nullptr) { /* if node to be deleted was found */
    if (Current == Father->Left) {
      Father->Left = nullptr;
      Father->LeftBranch = Tree->KeyDesc[Level].Min;
    } else {
      Father->Right = nullptr;
      Father->RightBranch = Tree->KeyDesc[Level].Max;
    }

    InsertNodes(Tree, Current->Left);
    InsertNodes(Tree, Current->Right);
    delete Current;
  }
}