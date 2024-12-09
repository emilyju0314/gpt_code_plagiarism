ActionImpl::ActionImpl(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode)
:ActionImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}