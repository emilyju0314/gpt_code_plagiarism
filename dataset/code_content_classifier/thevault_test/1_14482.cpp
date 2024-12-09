std::shared_ptr<Subset<uml::Comment, uml::Element>> ElementImpl::getOwnedComment() const
{
	if(m_ownedComment == nullptr)
	{
		/*Subset*/
		m_ownedComment.reset(new Subset<uml::Comment, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_ownedComment - Subset<uml::Comment, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		m_ownedComment->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedComment - Subset<uml::Comment, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}

    return m_ownedComment;
}