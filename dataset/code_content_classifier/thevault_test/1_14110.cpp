ExpressionImpl::ExpressionImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
:ExpressionImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}