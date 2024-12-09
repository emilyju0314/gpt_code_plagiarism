CombinedFragmentImpl::CombinedFragmentImpl(std::weak_ptr<uml::Interaction > par_enclosingInteraction)
:CombinedFragmentImpl()
{
	m_enclosingInteraction = par_enclosingInteraction;
	m_namespace = par_enclosingInteraction;
}