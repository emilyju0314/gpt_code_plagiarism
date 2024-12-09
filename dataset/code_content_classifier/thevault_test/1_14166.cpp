ClassifierImpl::ClassifierImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
:ClassifierImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}