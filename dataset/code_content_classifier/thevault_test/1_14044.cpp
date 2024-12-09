ReduceActionImpl::ReduceActionImpl(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode)
:ReduceActionImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}