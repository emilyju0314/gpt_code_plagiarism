std::shared_ptr<Subset<uml::Classifier, uml::NamedElement>> InterfaceImpl::getNestedClassifier() const
{
	if(m_nestedClassifier == nullptr)
	{
		/*Subset*/
		m_nestedClassifier.reset(new Subset<uml::Classifier, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_nestedClassifier - Subset<uml::Classifier, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		m_nestedClassifier->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_nestedClassifier - Subset<uml::Classifier, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
	}

    return m_nestedClassifier;
}