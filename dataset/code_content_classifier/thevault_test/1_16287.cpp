VectorOfFixVecs(int d, int s, InitType DBG_VAR( initType ), const FixVecType& ini)
      : size(s),
        dim(d)
    {
      TEST_EXIT_DBG(initType == DEFAULT_VALUE)("wrong initType or wrong initializer\n");

      vec.resize(size);
      for (int i = 0; i < size; i++)
        vec[i] = new FixVecType(ini);
    }