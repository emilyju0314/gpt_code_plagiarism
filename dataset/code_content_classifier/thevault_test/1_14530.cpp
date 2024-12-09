ConstraintImpl::ConstraintImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
:ConstraintImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}