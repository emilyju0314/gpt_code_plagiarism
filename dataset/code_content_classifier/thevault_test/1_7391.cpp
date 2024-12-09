matrix_float4x4 AAPL_SIMD_OVERLOAD matrix_make_columns(
                                   vector_float4 col0,
                                   vector_float4 col1,
                                   vector_float4 col2,
                                   vector_float4 col3) {
    return (matrix_float4x4){ col0, col1, col2, col3 };
}