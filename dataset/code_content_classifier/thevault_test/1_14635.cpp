std::shared_ptr<Subset<uml::Trigger, uml::Element>> AcceptEventActionImpl::getTrigger() const
{
	if(m_trigger == nullptr)
	{
		/*Subset*/
		m_trigger.reset(new Subset<uml::Trigger, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_trigger - Subset<uml::Trigger, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		m_trigger->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_trigger - Subset<uml::Trigger, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
//assert(m_trigger);
    return m_trigger;
}