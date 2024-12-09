InformationItemImpl::InformationItemImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
:InformationItemImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}