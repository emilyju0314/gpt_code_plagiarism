ComponentRealizationImpl::ComponentRealizationImpl(std::weak_ptr<uml::Namespace > par_namespace)
:ComponentRealizationImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}