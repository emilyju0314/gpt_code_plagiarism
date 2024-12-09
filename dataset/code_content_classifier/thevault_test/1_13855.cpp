DurationConstraintImpl::DurationConstraintImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
:DurationConstraintImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}