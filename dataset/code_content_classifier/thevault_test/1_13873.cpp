std::shared_ptr<SubsetUnion<uml::Behavior, uml::NamedElement>> BehavioredClassifierImpl::getOwnedBehavior() const
{
	if(m_ownedBehavior == nullptr)
	{
		/*SubsetUnion*/
		m_ownedBehavior.reset(new SubsetUnion<uml::Behavior, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_ownedBehavior - SubsetUnion<uml::Behavior, uml::NamedElement >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_ownedBehavior->initSubsetUnion(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_ownedBehavior - SubsetUnion<uml::Behavior, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
	}

    return m_ownedBehavior;
}