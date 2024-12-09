float ComputeRadius(struct Point *centroid, struct Node *N) {
  register struct Node *n = N;
  register int i /*,ii*/;
  float distance, radius;
  struct Point data_point;
//  float dist_array[NUMDIMS];
  assert(n);
  assert(n->level == 0); // data node

  radius = 0.0;

  for (i = 0; i < NODECARD; i++)
    if (n->branch[i].child) {
	data_point=Center(&n->branch[i].rect);
        distance=Distance(centroid, &data_point,  DIST_METRIC);
        // printf("point %d = %f \n", i+1, distance);
        if (radius < distance) radius=distance;
      }
  // getchar();
  return radius;
}