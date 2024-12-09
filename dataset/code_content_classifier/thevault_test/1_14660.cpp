std::shared_ptr<Subset<uml::Manifestation, uml::Element>> ArtifactImpl::getManifestation() const
{
	if(m_manifestation == nullptr)
	{
		/*Subset*/
		m_manifestation.reset(new Subset<uml::Manifestation, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_manifestation - Subset<uml::Manifestation, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		m_manifestation->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_manifestation - Subset<uml::Manifestation, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}

    return m_manifestation;
}