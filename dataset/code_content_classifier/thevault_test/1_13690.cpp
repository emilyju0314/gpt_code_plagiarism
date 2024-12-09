LiteralIntegerImpl::LiteralIntegerImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
:LiteralIntegerImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}