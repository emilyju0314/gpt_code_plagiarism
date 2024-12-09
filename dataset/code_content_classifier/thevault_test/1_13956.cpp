ClassImpl::ClassImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
:ClassImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}