matrix_float3x3 AAPL_SIMD_OVERLOAD matrix_make_columns(
                                   vector_float3 col0,
                                   vector_float3 col1,
                                   vector_float3 col2) {
    return (matrix_float3x3){ col0, col1, col2 };
}