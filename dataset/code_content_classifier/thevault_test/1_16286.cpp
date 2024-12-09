VectorOfFixVecs(int d, int s, InitType DBG_VAR( initType ), FixVecType const* ini)
      : size(s),
        dim(d)
    {
      TEST_EXIT_DBG(initType == VALUE_LIST)("wrong initType or wrong initializer\n");

      vec.resize(size);
      for (int i = 0; i < size; i++)
        vec[i] = new FixVecType(ini[i]);
    }