ClassifierImpl::ClassifierImpl(std::weak_ptr<uml::Namespace > par_namespace)
:ClassifierImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}