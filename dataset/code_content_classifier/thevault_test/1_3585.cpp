int CShaderAPIDx8::GetPackedDeformationInformation( int nMaskOfUnderstoodDeformations,
													 float *pConstantValuesOut,
													 int nBufferSize,
													 int nMaximumDeformations,
													 int *pDefCombosOut ) const
{
	int nCombosFound = 0;
	memset( pDefCombosOut, 0, sizeof( pDefCombosOut[0] ) * nMaximumDeformations );
	size_t nRemainingBufferSize = nBufferSize;

	for( const Deformation_t *i = m_DeformationStack + DEFORMATION_STACK_DEPTH -1; i >= m_pDeformationStackPtr; i-- )
	{
		int nFloatsOut = 4 * ( ( i->m_nNumParameters + 3 )>> 2 );
		if ( 
			( ( 1 << i->m_nDeformationType )  & nMaskOfUnderstoodDeformations ) &&
			( nRemainingBufferSize >= ( nFloatsOut * sizeof( float ) ) ) )
		{
			memcpy( pConstantValuesOut, i->m_flDeformationParameters, nFloatsOut * sizeof( float ) );
			pConstantValuesOut += nFloatsOut;
			nRemainingBufferSize -= nFloatsOut * sizeof( float );
			( *pDefCombosOut++ ) = i->m_nDeformationType;
			nCombosFound++;
		}
	}
	return nCombosFound;
}