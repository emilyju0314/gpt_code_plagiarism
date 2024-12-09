static float stb__perlin_grad(int hash, float x, float y, float z)
    {
      static float basis[12][4] =
          {
              {  1, 1, 0 },
              { -1, 1, 0 },
              {  1,-1, 0 },
              { -1,-1, 0 },
              {  1, 0, 1 },
              { -1, 0, 1 },
              {  1, 0,-1 },
              { -1, 0,-1 },
              {  0, 1, 1 },
              {  0,-1, 1 },
              {  0, 1,-1 },
              {  0,-1,-1 },
          };

      // perlin's gradient has 12 cases so some get used 1/16th of the time
      // and some 2/16ths. We reduce bias by changing those fractions
      // to 5/64ths and 6/64ths, and the same 4 cases get the extra weight.
      static unsigned char indices[64] =
          {
              0,1,2,3,4,5,6,7,8,9,10,11,
              0,9,1,11,
              0,1,2,3,4,5,6,7,8,9,10,11,
              0,1,2,3,4,5,6,7,8,9,10,11,
              0,1,2,3,4,5,6,7,8,9,10,11,
              0,1,2,3,4,5,6,7,8,9,10,11,
          };

      // if you use reference permutation table, change 63 below to 15 to match reference
      // (this is why the ordering of the table above is funky)
      float *grad = basis[indices[hash & 63]];
      return grad[0]*x + grad[1]*y + grad[2]*z;
    }