void intVec::resize(int newl)
{
  int* news = new int [newl];
  int* p = news;
  int minl = (len < newl)? len : newl;
  int* top = &(s[minl]);
  int* t = s;
  while (t < top) *p++ = *t++;
  delete [] s;
  s = news;
  len = newl;
}