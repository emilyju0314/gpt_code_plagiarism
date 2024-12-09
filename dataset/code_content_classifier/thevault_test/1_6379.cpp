int find_and_normalize(int u, std::vector<ContigStruct>& contigs)
{
  // Remember the given contig.
  int x = u;
  // Set u as the root, i.e., as the first contig in the scaffold.
  u = find(u, contigs);
  // Go from the given contig toward the root, and for each contig
  // encountered, set the root as its parent.
  while (contigs[x].parent != u) {
    int tmp = contigs[x].parent;
    contigs[x].parent = u;
    x = tmp;
  }
  // Return the root.
  return u;
}