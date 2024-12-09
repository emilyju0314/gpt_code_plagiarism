InputPinImpl::InputPinImpl(std::weak_ptr<uml::Namespace > par_namespace)
:InputPinImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}