std::shared_ptr<Subset<uml::Classifier, uml::NamedElement /*Subset does not reference a union*/>> ComponentRealizationImpl::getRealizingClassifier() const
{
	if(m_realizingClassifier == nullptr)
	{
		/*Subset*/
		m_realizingClassifier.reset(new Subset<uml::Classifier, uml::NamedElement /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_realizingClassifier - Subset<uml::Classifier, uml::NamedElement /*Subset does not reference a union*/ >()" << std::endl;
		#endif
		
		/*Subset*/
		m_realizingClassifier->initSubset(getClient());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_realizingClassifier - Subset<uml::Classifier, uml::NamedElement /*Subset does not reference a union*/ >(getClient())" << std::endl;
		#endif
		
	}
//assert(m_realizingClassifier);
    return m_realizingClassifier;
}