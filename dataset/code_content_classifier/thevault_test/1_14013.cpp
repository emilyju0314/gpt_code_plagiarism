StateInvariantImpl::StateInvariantImpl(std::weak_ptr<uml::Interaction > par_enclosingInteraction)
:StateInvariantImpl()
{
	m_enclosingInteraction = par_enclosingInteraction;
	m_namespace = par_enclosingInteraction;
}