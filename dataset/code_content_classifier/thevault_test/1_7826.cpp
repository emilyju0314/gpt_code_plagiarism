bool RTreeOverlapSphere(struct Rect *R, struct Point *point, float radius)
{
  register struct Rect *r = R;
  register int i, j;
  assert(r && point);
  
  // compute the mindist
  float squareSum = 0;
  for (register int i = 0; i < NUMDIMS; i ++)
    {
      int low = i, high = i + NUMDIMS;
      float diff = 0;

      if (point->position[i] < r->boundary[low])
	diff = r->boundary[low] - point->position[low];
      else if (point->position[i] > r->boundary[high])
	diff =  r->boundary[high] - point->position[i];
      else
	diff = 0;
      
      squareSum += diff * diff;
    }
  
  float mindist = sqrt(squareSum);
  return (mindist <= radius);
}