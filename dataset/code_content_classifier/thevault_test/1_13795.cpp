std::shared_ptr<Subset<uml::ActivityEdge, uml::ActivityEdge,uml::Element>> StructuredActivityNodeImpl::getEdge() const
{
	if(m_edge == nullptr)
	{
		/*Subset*/
		m_edge.reset(new Subset<uml::ActivityEdge, uml::ActivityEdge,uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_edge - Subset<uml::ActivityEdge, uml::ActivityEdge,uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		m_edge->initSubset(getContainedEdge(),getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_edge - Subset<uml::ActivityEdge, uml::ActivityEdge,uml::Element >(getContainedEdge(),getOwnedElement())" << std::endl;
		#endif
		
	}

    return m_edge;
}