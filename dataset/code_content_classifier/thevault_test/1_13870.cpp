BehavioredClassifierImpl::BehavioredClassifierImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
:BehavioredClassifierImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}