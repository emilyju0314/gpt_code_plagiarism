std::shared_ptr<Subset<uml::ConnectableElement, uml::ConnectableElement>> CollaborationImpl::getCollaborationRole() const
{
	if(m_collaborationRole == nullptr)
	{
		/*Subset*/
		m_collaborationRole.reset(new Subset<uml::ConnectableElement, uml::ConnectableElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_collaborationRole - Subset<uml::ConnectableElement, uml::ConnectableElement >()" << std::endl;
		#endif
		
		/*Subset*/
		m_collaborationRole->initSubset(getRole());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_collaborationRole - Subset<uml::ConnectableElement, uml::ConnectableElement >(getRole())" << std::endl;
		#endif
		
	}

    return m_collaborationRole;
}