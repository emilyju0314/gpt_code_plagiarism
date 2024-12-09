TemplateBindingImpl::TemplateBindingImpl(std::weak_ptr<uml::TemplateableElement > par_boundElement)
:TemplateBindingImpl()
{
	m_boundElement = par_boundElement;
	m_owner = par_boundElement;
}