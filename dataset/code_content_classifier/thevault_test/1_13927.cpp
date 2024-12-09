ContinuationImpl::ContinuationImpl(std::weak_ptr<uml::Namespace > par_namespace)
:ContinuationImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}