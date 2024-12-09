void CShaderAPIDx8::RegisterSelectionHit( float minz, float maxz )
{
	if (minz < 0)
		minz = 0;
	if (maxz > 1)
		maxz = 1;
	if (m_SelectionMinZ > minz)
		m_SelectionMinZ = minz;
	if (m_SelectionMaxZ < maxz)
		m_SelectionMaxZ = maxz;
}