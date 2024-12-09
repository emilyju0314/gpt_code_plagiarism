PinImpl::PinImpl(std::weak_ptr<uml::Namespace > par_namespace)
:PinImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}