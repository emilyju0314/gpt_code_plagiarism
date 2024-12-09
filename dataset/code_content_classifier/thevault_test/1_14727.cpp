ExpansionNodeImpl::ExpansionNodeImpl(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode)
:ExpansionNodeImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}