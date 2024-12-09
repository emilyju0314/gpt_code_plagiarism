std::shared_ptr<Subset<uml::ProtocolConformance, uml::Element>> ProtocolStateMachineImpl::getConformance() const
{
	if(m_conformance == nullptr)
	{
		/*Subset*/
		m_conformance.reset(new Subset<uml::ProtocolConformance, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_conformance - Subset<uml::ProtocolConformance, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		m_conformance->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_conformance - Subset<uml::ProtocolConformance, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}

    return m_conformance;
}