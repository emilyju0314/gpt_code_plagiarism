std::shared_ptr<Subset<uml::Action, uml::Element>> InteractionImpl::getAction() const
{
	if(m_action == nullptr)
	{
		/*Subset*/
		m_action.reset(new Subset<uml::Action, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_action - Subset<uml::Action, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		m_action->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_action - Subset<uml::Action, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}

    return m_action;
}