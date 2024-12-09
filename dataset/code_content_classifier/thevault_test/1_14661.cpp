std::shared_ptr<Subset<uml::Artifact, uml::NamedElement>> ArtifactImpl::getNestedArtifact() const
{
	if(m_nestedArtifact == nullptr)
	{
		/*Subset*/
		m_nestedArtifact.reset(new Subset<uml::Artifact, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_nestedArtifact - Subset<uml::Artifact, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		m_nestedArtifact->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_nestedArtifact - Subset<uml::Artifact, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
	}

    return m_nestedArtifact;
}