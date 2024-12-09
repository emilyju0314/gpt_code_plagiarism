OpaqueBehaviorImpl::OpaqueBehaviorImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
:OpaqueBehaviorImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}