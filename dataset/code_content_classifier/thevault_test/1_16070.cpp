int g(const int i)
{
 if(0 == i)
  throw std::exception();

 return f_ident(i);
}