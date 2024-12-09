std::shared_ptr<Subset<uml::Port, uml::Property /*Subset does not reference a union*/>> PortImpl::getRedefinedPort() const
{
	if(m_redefinedPort == nullptr)
	{
		/*Subset*/
		m_redefinedPort.reset(new Subset<uml::Port, uml::Property /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_redefinedPort - Subset<uml::Port, uml::Property /*Subset does not reference a union*/ >()" << std::endl;
		#endif
		
		/*Subset*/
		m_redefinedPort->initSubset(getRedefinedProperty());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_redefinedPort - Subset<uml::Port, uml::Property /*Subset does not reference a union*/ >(getRedefinedProperty())" << std::endl;
		#endif
		
	}

    return m_redefinedPort;
}