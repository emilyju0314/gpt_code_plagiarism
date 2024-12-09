void PrintNix(nodeid_t s, RNodeVec_t nodes, NixVec& nv)
{
  printf("Printing Nv from %ld\n", s);
  while(1)
    {
      printf("%ld\n", s);
      fflush(stdout);
      if (!nodes[s])
        {
          printf("PrintNix Error, no node for %ld\n", s);
          break;
        }
      printf("Node %ld nixl %ld\n", s, nodes[s]->GetNixl());
      Nix_t n = nv.Extract(nodes[s]->GetNixl());
      if (n == NIX_NONE) break; // Done
      nodeid_t s1 = nodes[s]->GetNeighbor(n);
      if (s1 == NODE_NONE)
        {
          printf("Huh?  Node %ld can't get neighbor %ld\n", s, n);
          break;
        }
      s = s1;
    }
  printf("\n");
  nv.Reset();
}