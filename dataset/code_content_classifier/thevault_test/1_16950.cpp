static CordRep* MakeBalancedTree(CordRep** reps, size_t n) {
  // Make repeated passes over the array, merging adjacent pairs
  // until we are left with just a single node.
  while (n > 1) {
    size_t dst = 0;
    for (size_t src = 0; src < n; src += 2) {
      if (src + 1 < n) {
        reps[dst] = Concat(reps[src], reps[src + 1]);
      } else {
        reps[dst] = reps[src];
      }
      dst++;
    }
    n = dst;
  }

  return reps[0];
}