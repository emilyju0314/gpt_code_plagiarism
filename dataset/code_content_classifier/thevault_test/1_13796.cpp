std::shared_ptr<Subset<uml::ActivityNode, uml::ActivityNode,uml::Element>> StructuredActivityNodeImpl::getNode() const
{
	if(m_node == nullptr)
	{
		/*Subset*/
		m_node.reset(new Subset<uml::ActivityNode, uml::ActivityNode,uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_node - Subset<uml::ActivityNode, uml::ActivityNode,uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		m_node->initSubset(getContainedNode(),getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_node - Subset<uml::ActivityNode, uml::ActivityNode,uml::Element >(getContainedNode(),getOwnedElement())" << std::endl;
		#endif
		
	}

    return m_node;
}