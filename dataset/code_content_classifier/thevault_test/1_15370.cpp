void runNativeGSLMult(double * matrixLHS, double * matrixRHS, double * matrixProduct) {
    gsl_matrix_view lhs = gsl_matrix_view_array(matrixLHS, NUM_ROW_DIM1, NUM_COL_DIM1);
    gsl_matrix_view rhs = gsl_matrix_view_array(matrixRHS, NUM_ROW_DIM2, NUM_COL_DIM2);
    gsl_matrix_view product = gsl_matrix_view_array(matrixProduct, NUM_ROW_DIM1, NUM_COL_DIM2);
    gsl_blas_dgemm(CblasNoTrans, CblasNoTrans, 1.0, &lhs.matrix, &rhs.matrix, 0.0, &product.matrix);
    printf("first element is %g\n", matrixProduct[0]);
    printf("last element is %g\n", matrixProduct[NUM_ROW_DIM1*NUM_COL_DIM2-1]);
}