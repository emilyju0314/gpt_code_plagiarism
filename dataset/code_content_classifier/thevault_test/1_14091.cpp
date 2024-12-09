InteractionImpl::InteractionImpl(std::weak_ptr<uml::Namespace > par_namespace)
:InteractionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}