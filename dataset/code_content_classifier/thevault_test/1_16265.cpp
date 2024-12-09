ElInfo3d(Mesh* aMesh)
      : ElInfo(aMesh)
    {
      tmpWorldVecs.resize(3);
      for (int i = 0; i < 3; i++)
        tmpWorldVecs[i].resize(3);
    }