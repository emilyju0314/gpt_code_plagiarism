std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element>> DependencyImpl::getClient() const
{
	if(m_client == nullptr)
	{
		/*SubsetUnion*/
		m_client.reset(new SubsetUnion<uml::NamedElement, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_client - SubsetUnion<uml::NamedElement, uml::Element >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_client->initSubsetUnion(getSource());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_client - SubsetUnion<uml::NamedElement, uml::Element >(getSource())" << std::endl;
		#endif
		
	}
//assert(m_client);
    return m_client;
}