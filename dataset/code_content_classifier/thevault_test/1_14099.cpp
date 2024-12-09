std::shared_ptr<Subset<uml::Message, uml::NamedElement>> InteractionImpl::getMessage() const
{
	if(m_message == nullptr)
	{
		/*Subset*/
		m_message.reset(new Subset<uml::Message, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_message - Subset<uml::Message, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		m_message->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_message - Subset<uml::Message, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
	}

    return m_message;
}