ModelImpl::ModelImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
:ModelImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}