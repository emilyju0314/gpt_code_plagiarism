ExpansionRegionImpl::ExpansionRegionImpl(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode)
:ExpansionRegionImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}