LiteralSpecificationImpl::LiteralSpecificationImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
:LiteralSpecificationImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}