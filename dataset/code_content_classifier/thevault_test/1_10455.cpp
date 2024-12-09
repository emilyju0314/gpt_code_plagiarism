static int NextLevel(KDTREE *tree, int level) {
  do {
    ++level;
    if (level >= tree->KeySize) {
      level = 0;
    }
  } while (tree->KeyDesc[level].NonEssential);
  return level;
}