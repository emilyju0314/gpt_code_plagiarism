std::shared_ptr<Subset<uml::NamedElement, uml::Element>> InformationFlowImpl::getInformationTarget() const
{
	if(m_informationTarget == nullptr)
	{
		/*Subset*/
		m_informationTarget.reset(new Subset<uml::NamedElement, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_informationTarget - Subset<uml::NamedElement, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		m_informationTarget->initSubset(getTarget());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_informationTarget - Subset<uml::NamedElement, uml::Element >(getTarget())" << std::endl;
		#endif
		
	}
//assert(m_informationTarget);
    return m_informationTarget;
}