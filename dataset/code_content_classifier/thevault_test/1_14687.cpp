ConnectableElementTemplateParameterImpl::ConnectableElementTemplateParameterImpl(std::weak_ptr<uml::TemplateSignature > par_signature)
:ConnectableElementTemplateParameterImpl()
{
	m_signature = par_signature;
	m_owner = par_signature;
}