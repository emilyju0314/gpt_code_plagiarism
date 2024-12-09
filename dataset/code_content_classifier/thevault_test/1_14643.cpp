std::shared_ptr<Subset<uml::Vertex, uml::NamedElement>> RegionImpl::getSubvertex() const
{
	if(m_subvertex == nullptr)
	{
		/*Subset*/
		m_subvertex.reset(new Subset<uml::Vertex, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_subvertex - Subset<uml::Vertex, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		m_subvertex->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subvertex - Subset<uml::Vertex, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
	}

    return m_subvertex;
}