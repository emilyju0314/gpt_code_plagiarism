std::shared_ptr<Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/>> BehaviorImpl::getPostcondition() const
{
	if(m_postcondition == nullptr)
	{
		/*Subset*/
		m_postcondition.reset(new Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_postcondition - Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/ >()" << std::endl;
		#endif
		
		/*Subset*/
		m_postcondition->initSubset(getOwnedRule());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_postcondition - Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/ >(getOwnedRule())" << std::endl;
		#endif
		
	}

    return m_postcondition;
}