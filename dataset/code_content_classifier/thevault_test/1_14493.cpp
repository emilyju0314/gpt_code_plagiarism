DecisionNodeImpl::DecisionNodeImpl(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode)
:DecisionNodeImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}