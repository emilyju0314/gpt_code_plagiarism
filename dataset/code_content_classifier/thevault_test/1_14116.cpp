IntervalConstraintImpl::IntervalConstraintImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
:IntervalConstraintImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}