TimeExpressionImpl::TimeExpressionImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
:TimeExpressionImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}