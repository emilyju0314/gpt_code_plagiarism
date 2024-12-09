TemplateParameterImpl::TemplateParameterImpl(std::weak_ptr<uml::TemplateSignature > par_signature)
:TemplateParameterImpl()
{
	m_signature = par_signature;
	m_owner = par_signature;
}