void Fibo::display(bool showTitle) const
{
  int a = 0;
  int b = 1;
  if (showTitle) std::cout << _title << ": ";
  while (a < _n)
  {
    std::cout << a << " ";
    int aa = a;
    a = b;
    b = aa+b;
  }
  std::cout << std::endl;
}