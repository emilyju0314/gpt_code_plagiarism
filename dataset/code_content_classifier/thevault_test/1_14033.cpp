ManifestationImpl::ManifestationImpl(std::weak_ptr<uml::Namespace > par_namespace)
:ManifestationImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}