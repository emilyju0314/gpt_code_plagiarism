LifelineImpl::LifelineImpl(std::weak_ptr<uml::Namespace > par_namespace)
:LifelineImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}