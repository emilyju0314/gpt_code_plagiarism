std::shared_ptr<Subset<uml::Port, uml::Property /*Subset does not reference a union*/>> EncapsulatedClassifierImpl::getOwnedPort() const
{
	if(m_ownedPort == nullptr)
	{
		/*Subset*/
		m_ownedPort.reset(new Subset<uml::Port, uml::Property /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_ownedPort - Subset<uml::Port, uml::Property /*Subset does not reference a union*/ >()" << std::endl;
		#endif
		
		/*Subset*/
		m_ownedPort->initSubset(getOwnedAttribute());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedPort - Subset<uml::Port, uml::Property /*Subset does not reference a union*/ >(getOwnedAttribute())" << std::endl;
		#endif
		
	}

    return m_ownedPort;
}