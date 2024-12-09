InteractionUseImpl::InteractionUseImpl(std::weak_ptr<uml::Interaction > par_enclosingInteraction)
:InteractionUseImpl()
{
	m_enclosingInteraction = par_enclosingInteraction;
	m_namespace = par_enclosingInteraction;
}