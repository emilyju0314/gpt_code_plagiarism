TimeConstraintImpl::TimeConstraintImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
:TimeConstraintImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}