std::shared_ptr<Subset<uml::InterruptibleActivityRegion, uml::ActivityGroup>> ActivityNodeImpl::getInInterruptibleRegion() const
{
	if(m_inInterruptibleRegion == nullptr)
	{
		/*Subset*/
		m_inInterruptibleRegion.reset(new Subset<uml::InterruptibleActivityRegion, uml::ActivityGroup >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_inInterruptibleRegion - Subset<uml::InterruptibleActivityRegion, uml::ActivityGroup >()" << std::endl;
		#endif
		
		/*Subset*/
		m_inInterruptibleRegion->initSubset(getInGroup());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_inInterruptibleRegion - Subset<uml::InterruptibleActivityRegion, uml::ActivityGroup >(getInGroup())" << std::endl;
		#endif
		
	}

    return m_inInterruptibleRegion;
}