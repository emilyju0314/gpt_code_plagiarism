InteractionUseImpl::InteractionUseImpl(std::weak_ptr<uml::Namespace > par_namespace)
:InteractionUseImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}