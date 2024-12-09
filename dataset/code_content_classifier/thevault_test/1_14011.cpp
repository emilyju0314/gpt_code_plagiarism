EncapsulatedClassifierImpl::EncapsulatedClassifierImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
:EncapsulatedClassifierImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}