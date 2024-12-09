void runNativeEigenMult(double * matrixLHS, double * matrixRHS, double * matrixProduct) {
    Eigen::Map<Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor>> lhs (
       matrixLHS, NUM_ROW_DIM1, NUM_COL_DIM1);
    Eigen::Map<Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor>> rhs (
       matrixRHS, NUM_ROW_DIM2, NUM_COL_DIM2);
    Eigen::Map<Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor>> product (
       matrixProduct, NUM_ROW_DIM1, NUM_COL_DIM2);
    product = lhs * rhs;
    printf("first element is %g\n", matrixProduct[0]);
    printf("last element is %g\n", matrixProduct[NUM_ROW_DIM1*NUM_COL_DIM2-1]);
}