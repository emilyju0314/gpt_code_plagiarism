InformationFlowImpl::InformationFlowImpl(std::weak_ptr<uml::Namespace > par_namespace)
:InformationFlowImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}