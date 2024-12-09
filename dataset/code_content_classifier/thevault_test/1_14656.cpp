ArtifactImpl::ArtifactImpl(std::weak_ptr<uml::Namespace > par_namespace)
:ArtifactImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}