FunctionBehaviorImpl::FunctionBehaviorImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
:FunctionBehaviorImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}