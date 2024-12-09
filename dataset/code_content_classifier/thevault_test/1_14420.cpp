InstanceValueImpl::InstanceValueImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
:InstanceValueImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}