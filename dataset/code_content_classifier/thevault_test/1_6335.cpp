void Geometry::addTriangle(DrawingObject* obj, float* a, float* b, float* c, int level, bool texCoords, float trilimit, float* normal)
{
  level--;
  //Experimental: splitting triangles by size
  if (trilimit && level <= 0)
  {
    float max = trilimit*trilimit; //Limit squared
    float a_b[3], a_c[3], b_c[3];
    vectorSubtract(a_b, a, b);
    vectorSubtract(a_c, a, c);
    vectorSubtract(b_c, b, c);
    float e1 = dotProduct(a_b,a_b);
    float e2 = dotProduct(a_c,a_c);
    float e3 = dotProduct(b_c,b_c);
    if (e1 < EPSILON || e2 < EPSILON || e3 < EPSILON)
    {
      //printf("Degenerate triangle!\n");
      return;
    }
    if (e1 >= max || e2 >= max || e3 >= max)
    {
      //printf("Edge exceeeds limit, splitting %f %f %f\n", e1, e2, e3);
      level = 1; //Force another split
    }
  }

  if (level <= 0)
  {
    //Read the triangle
    read(obj, 1, lucVertexData, a);
    read(obj, 1, lucVertexData, b);
    read(obj, 1, lucVertexData, c);

    if (texCoords)
    {
      read(obj, 1, lucTexCoordData, &a[3]);
      read(obj, 1, lucTexCoordData, &b[3]);
      read(obj, 1, lucTexCoordData, &c[3]);
    }

    if (normal)
      read(obj, 1, lucNormalData, normal);
  }
  else
  {
    //Process a triangle into 4 sub-triangles
    if (texCoords)
    {

      float ab[5] = {0.5f*(a[0]+b[0]), 0.5f*(a[1]+b[1]), 0.5f*(a[2]+b[2]), 0.5f*(a[3]+b[3]), 0.5f*(a[4]+b[4])};
      float ac[5] = {0.5f*(a[0]+c[0]), 0.5f*(a[1]+c[1]), 0.5f*(a[2]+c[2]), 0.5f*(a[3]+c[3]), 0.5f*(a[4]+c[4])};
      float bc[5] = {0.5f*(b[0]+c[0]), 0.5f*(b[1]+c[1]), 0.5f*(b[2]+c[2]), 0.5f*(b[3]+c[3]), 0.5f*(b[4]+c[4])};

      addTriangle(obj, a, ab, ac, level, texCoords, trilimit, normal);
      addTriangle(obj, ab, b, bc, level, texCoords, trilimit, normal);
      addTriangle(obj, ac, bc, c, level, texCoords, trilimit, normal);
      addTriangle(obj, ab, bc, ac, level, texCoords, trilimit, normal);

    }
    else
    {
      float ab[3] = {0.5f*(a[0]+b[0]), 0.5f*(a[1]+b[1]), 0.5f*(a[2]+b[2])};
      float ac[3] = {0.5f*(a[0]+c[0]), 0.5f*(a[1]+c[1]), 0.5f*(a[2]+c[2])};
      float bc[3] = {0.5f*(b[0]+c[0]), 0.5f*(b[1]+c[1]), 0.5f*(b[2]+c[2])};

      addTriangle(obj, a, ab, ac, level, texCoords, trilimit, normal);
      addTriangle(obj, ab, b, bc, level, texCoords, trilimit, normal);
      addTriangle(obj, ac, bc, c, level, texCoords, trilimit, normal);
      addTriangle(obj, ab, bc, ac, level, texCoords, trilimit, normal);
    }
  }
}