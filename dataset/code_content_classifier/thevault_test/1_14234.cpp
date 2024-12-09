TemplateSignatureImpl::TemplateSignatureImpl(std::weak_ptr<uml::TemplateableElement > par_template)
:TemplateSignatureImpl()
{
	m_template = par_template;
	m_owner = par_template;
}