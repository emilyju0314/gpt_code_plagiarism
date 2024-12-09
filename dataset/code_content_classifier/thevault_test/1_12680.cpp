void DRGMatrix::PreMultiply( DRGMatrix &Mx ) 
{
	int i, j, k;
	DRGMatrix MxTemp = *this;

	memset( &m_Mx, 0, sizeof( float ) * 16 );

    for( i=0; i<4; i++ ) 
        for( j=0; j<4; j++ ) 
            for( k=0; k<4; k++ ) 
				m_Mx( i,j) += Mx.m_Mx(i,k) * MxTemp.m_Mx(k,j);
}