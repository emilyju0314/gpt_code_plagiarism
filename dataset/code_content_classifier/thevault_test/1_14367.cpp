CombinedFragmentImpl::CombinedFragmentImpl(std::weak_ptr<uml::Namespace > par_namespace)
:CombinedFragmentImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}