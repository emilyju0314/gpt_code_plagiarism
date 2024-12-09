bool cykl(int root)
{
  int v = root;
  do
  {
    if ((int)t[v].size() > 1) return false;
    v = s[v];
  } while (v != root);
  return true;
}