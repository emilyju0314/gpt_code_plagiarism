ControlFlowImpl::ControlFlowImpl(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode)
:ControlFlowImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}