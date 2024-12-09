SequenceNodeImpl::SequenceNodeImpl(std::weak_ptr<uml::Namespace > par_namespace)
:SequenceNodeImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}