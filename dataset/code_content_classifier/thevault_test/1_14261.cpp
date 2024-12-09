std::shared_ptr<Subset<uml::Interface, uml::Classifier /*Subset does not reference a union*/>> InterfaceImpl::getRedefinedInterface() const
{
	if(m_redefinedInterface == nullptr)
	{
		/*Subset*/
		m_redefinedInterface.reset(new Subset<uml::Interface, uml::Classifier /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_redefinedInterface - Subset<uml::Interface, uml::Classifier /*Subset does not reference a union*/ >()" << std::endl;
		#endif
		
		/*Subset*/
		m_redefinedInterface->initSubset(getRedefinedClassifier());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_redefinedInterface - Subset<uml::Interface, uml::Classifier /*Subset does not reference a union*/ >(getRedefinedClassifier())" << std::endl;
		#endif
		
	}

    return m_redefinedInterface;
}