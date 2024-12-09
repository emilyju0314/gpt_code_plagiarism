WriteLinkActionImpl::WriteLinkActionImpl(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode)
:WriteLinkActionImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}