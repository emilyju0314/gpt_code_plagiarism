void CheckMatrixArrays( const gm::Mat4f* i_matrixA, const gm::Mat4f* i_matrixB, int i_arraySize )
{
    for ( int matrixIndex = 0; matrixIndex < i_arraySize; ++matrixIndex )
    {
        if ( i_matrixA[ matrixIndex ] != i_matrixB[ matrixIndex ] )
        {
            fprintf( stderr,
                     "MatrixA[ %d ] != MatrixB[ %d ],\n%s != %s\n",
                     matrixIndex,
                     matrixIndex,
                     i_matrixA[ matrixIndex ].GetString().c_str(),
                     i_matrixB[ matrixIndex ].GetString().c_str() );
            return;
        }
    }
}