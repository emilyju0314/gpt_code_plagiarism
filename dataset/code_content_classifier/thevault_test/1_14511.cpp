OpaqueExpressionImpl::OpaqueExpressionImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
:OpaqueExpressionImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}