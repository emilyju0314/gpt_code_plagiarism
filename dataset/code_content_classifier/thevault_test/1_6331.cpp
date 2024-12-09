float triAngle(float v0[3], float v1[3], float v2[3])
{
  //Returns angle at v0 in radians for triangle defined by v0,v1,v2

  //Get lengths of each side of triangle adjacent to this vertex
  float e0[3], e1[3]; //Triangle edge vectors
  vectorSubtract(e0, v1, v0);
  vectorSubtract(e1, v2, v0);

  //Normalise to simplify dot product calc
  vectorNormalise(e0);
  vectorNormalise(e1);
  //Return triangle angle (in radians)
  return acos(dotProduct(e0,e1));
}