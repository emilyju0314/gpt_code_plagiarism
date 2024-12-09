dBoundingBox LocatorPrimitive::GetBoundingBox(const dMatrix &space)
{	
	return dBoundingBox(space.transform(dVector(-m_BoundingBoxRadius,-m_BoundingBoxRadius,-m_BoundingBoxRadius)),
						space.transform(dVector(m_BoundingBoxRadius,m_BoundingBoxRadius,m_BoundingBoxRadius)));
}