MatVecExpr(matrix_type const& mat, vector_type const& vec)
      : matrix(mat), vector(vec)
    {
      TEST_EXIT_DBG( num_cols(mat) == num_rows(vec), "Sizes do not match!\n");
    }