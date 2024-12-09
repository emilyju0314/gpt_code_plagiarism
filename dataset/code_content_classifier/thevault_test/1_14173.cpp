std::shared_ptr<SubsetUnion<uml::Classifier, uml::RedefinableElement>> ClassifierImpl::getRedefinedClassifier() const
{
	if(m_redefinedClassifier == nullptr)
	{
		/*SubsetUnion*/
		m_redefinedClassifier.reset(new SubsetUnion<uml::Classifier, uml::RedefinableElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_redefinedClassifier - SubsetUnion<uml::Classifier, uml::RedefinableElement >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_redefinedClassifier->initSubsetUnion(getRedefinedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_redefinedClassifier - SubsetUnion<uml::Classifier, uml::RedefinableElement >(getRedefinedElement())" << std::endl;
		#endif
		
	}

    return m_redefinedClassifier;
}