InteractionImpl::InteractionImpl(std::weak_ptr<uml::Interaction > par_enclosingInteraction)
:InteractionImpl()
{
	m_enclosingInteraction = par_enclosingInteraction;
	m_namespace = par_enclosingInteraction;
}