ArtifactImpl::ArtifactImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
:ArtifactImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}