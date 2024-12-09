ControlFlowImpl::ControlFlowImpl(std::weak_ptr<uml::Namespace > par_namespace)
:ControlFlowImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}