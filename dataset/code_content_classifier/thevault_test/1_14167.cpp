std::shared_ptr<SubsetUnion<uml::CollaborationUse, uml::Element>> ClassifierImpl::getCollaborationUse() const
{
	if(m_collaborationUse == nullptr)
	{
		/*SubsetUnion*/
		m_collaborationUse.reset(new SubsetUnion<uml::CollaborationUse, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_collaborationUse - SubsetUnion<uml::CollaborationUse, uml::Element >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_collaborationUse->initSubsetUnion(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_collaborationUse - SubsetUnion<uml::CollaborationUse, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}

    return m_collaborationUse;
}