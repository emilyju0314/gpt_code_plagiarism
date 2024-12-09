void normalToPlane( float normal[3], float pos0[3], float pos1[3], float pos2[3])
{
  float vector1[3], vector2[3];

//printf(" PLANE: %f,%f,%f - %f,%f,%f - %f,%f,%f\n", pos0[0], pos0[1], pos0[2], pos1[0], pos1[1], pos1[2], pos2[0], pos2[1], pos2[2]);
  vectorSubtract(vector1, pos1, pos0);
  vectorSubtract(vector2, pos2, pos0);

  crossProduct(normal, vector1, vector2);
//printf(" %f,%f,%f x %f,%f,%f == %f,%f,%f\n", vector1[0], vector1[1], vector1[2], vector2[0], vector2[1], vector2[2], normal[0], normal[1], normal[2]);

  //vectorNormalise( normal);
}