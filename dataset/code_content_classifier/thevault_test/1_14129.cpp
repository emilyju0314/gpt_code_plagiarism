std::shared_ptr<Subset<uml::TemplateParameterSubstitution, uml::Element>> TemplateBindingImpl::getParameterSubstitution() const
{
	if(m_parameterSubstitution == nullptr)
	{
		/*Subset*/
		m_parameterSubstitution.reset(new Subset<uml::TemplateParameterSubstitution, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_parameterSubstitution - Subset<uml::TemplateParameterSubstitution, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		m_parameterSubstitution->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_parameterSubstitution - Subset<uml::TemplateParameterSubstitution, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}

    return m_parameterSubstitution;
}