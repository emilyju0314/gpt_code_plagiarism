InformationFlowImpl::InformationFlowImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
:InformationFlowImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}