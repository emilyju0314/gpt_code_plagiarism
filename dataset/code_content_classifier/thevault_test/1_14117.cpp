MessageImpl::MessageImpl(std::weak_ptr<uml::Interaction > par_interaction)
:MessageImpl()
{
	m_interaction = par_interaction;
	m_namespace = par_interaction;
}