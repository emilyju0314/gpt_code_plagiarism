void SetMatrixArrayValue( const gm::Mat4f& i_matrix, int i_arraySize, gm::Mat4f* o_matrices )
{
    for ( int matrixIndex = 0; matrixIndex < i_arraySize; ++matrixIndex )
    {
        o_matrices[ matrixIndex ] = i_matrix;
    }
}