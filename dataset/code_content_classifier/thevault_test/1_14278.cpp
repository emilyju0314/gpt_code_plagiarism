AssociationClassImpl::AssociationClassImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
:AssociationClassImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}