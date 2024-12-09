int V_BoyerMooreSearch( const byte *pNeedle, int nNeedleLength, const byte *pHayStack, int nHayStackLength )
{
	CBoyerMooreSearch search( pNeedle, nNeedleLength );
	return search.Search( pHayStack, nHayStackLength );
}