int find(int u, const std::vector<ContigStruct>& contigs)
{
  while (contigs[u].parent != u)
    u = contigs[u].parent;
  return u;
}