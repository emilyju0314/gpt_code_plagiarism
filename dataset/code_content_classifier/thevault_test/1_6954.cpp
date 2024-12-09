void PrintParents(RoutingVec_t& pred)
{
  printf("Parent vector is");
  for (RoutingVec_it i = pred.begin(); i != pred.end(); i++)
    {
      printf(" %ld", *i);
    }
  printf("\n");
}