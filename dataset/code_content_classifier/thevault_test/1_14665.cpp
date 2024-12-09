InterfaceRealizationImpl::InterfaceRealizationImpl(std::weak_ptr<uml::Namespace > par_namespace)
:InterfaceRealizationImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}