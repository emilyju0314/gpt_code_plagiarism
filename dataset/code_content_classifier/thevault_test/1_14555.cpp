DestroyObjectActionImpl::DestroyObjectActionImpl(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode)
:DestroyObjectActionImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}