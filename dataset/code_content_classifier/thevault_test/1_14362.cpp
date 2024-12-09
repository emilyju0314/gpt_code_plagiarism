DurationObservationImpl::DurationObservationImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
:DurationObservationImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}