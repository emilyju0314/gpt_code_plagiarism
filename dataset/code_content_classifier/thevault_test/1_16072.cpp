int g(const int i)
{
 static int nums[] = { 1, 2, 3, 4, 5 };
 static int n = 0;

 if(0 == i)
  throw std::exception();

 return n++, n %= sizeof(nums), n * i;
}