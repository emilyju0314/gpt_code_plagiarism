ConsiderIgnoreFragmentImpl::ConsiderIgnoreFragmentImpl(std::weak_ptr<uml::Interaction > par_enclosingInteraction)
:ConsiderIgnoreFragmentImpl()
{
	m_enclosingInteraction = par_enclosingInteraction;
	m_namespace = par_enclosingInteraction;
}