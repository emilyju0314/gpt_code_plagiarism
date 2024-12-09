CollaborationImpl::CollaborationImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
:CollaborationImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}