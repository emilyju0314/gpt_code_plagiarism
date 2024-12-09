std::shared_ptr<Subset<uml::Behavior, uml::Classifier /*Subset does not reference a union*/>> BehaviorImpl::getRedefinedBehavior() const
{
	if(m_redefinedBehavior == nullptr)
	{
		/*Subset*/
		m_redefinedBehavior.reset(new Subset<uml::Behavior, uml::Classifier /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_redefinedBehavior - Subset<uml::Behavior, uml::Classifier /*Subset does not reference a union*/ >()" << std::endl;
		#endif
		
		/*Subset*/
		m_redefinedBehavior->initSubset(getRedefinedClassifier());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_redefinedBehavior - Subset<uml::Behavior, uml::Classifier /*Subset does not reference a union*/ >(getRedefinedClassifier())" << std::endl;
		#endif
		
	}

    return m_redefinedBehavior;
}