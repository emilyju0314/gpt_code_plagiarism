std::shared_ptr<Subset<uml::TemplateParameter, uml::Element,uml::TemplateParameter>> TemplateSignatureImpl::getOwnedParameter() const
{
	if(m_ownedParameter == nullptr)
	{
		/*Subset*/
		m_ownedParameter.reset(new Subset<uml::TemplateParameter, uml::Element,uml::TemplateParameter >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_ownedParameter - Subset<uml::TemplateParameter, uml::Element,uml::TemplateParameter >()" << std::endl;
		#endif
		
		/*Subset*/
		m_ownedParameter->initSubset(getOwnedElement(),getParameter());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedParameter - Subset<uml::TemplateParameter, uml::Element,uml::TemplateParameter >(getOwnedElement(),getParameter())" << std::endl;
		#endif
		
	}

    return m_ownedParameter;
}