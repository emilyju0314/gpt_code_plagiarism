ContinuationImpl::ContinuationImpl(std::weak_ptr<uml::Interaction > par_enclosingInteraction)
:ContinuationImpl()
{
	m_enclosingInteraction = par_enclosingInteraction;
	m_namespace = par_enclosingInteraction;
}