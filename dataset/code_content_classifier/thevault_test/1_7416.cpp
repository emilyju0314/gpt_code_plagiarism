std::vector<int> Fibo::get() const
{
  std::vector<int> res;
  int a = 0;
  int b = 1;
  while (a < _n)
  {
    res.push_back(a);
    int aa = a;
    a = b;
    b = aa+b;
  }
  return res;
}