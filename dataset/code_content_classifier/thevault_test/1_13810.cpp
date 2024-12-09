RemoveVariableValueActionImpl::RemoveVariableValueActionImpl(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode)
:RemoveVariableValueActionImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}