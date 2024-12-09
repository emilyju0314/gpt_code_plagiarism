InitialNodeImpl::InitialNodeImpl(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode)
:InitialNodeImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}