TemplateParameterSubstitutionImpl::TemplateParameterSubstitutionImpl(std::weak_ptr<uml::TemplateBinding > par_templateBinding)
:TemplateParameterSubstitutionImpl()
{
	m_templateBinding = par_templateBinding;
	m_owner = par_templateBinding;
}