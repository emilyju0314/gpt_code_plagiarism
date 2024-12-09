std::shared_ptr<Subset<uml::Image, uml::Element>> StereotypeImpl::getIcon() const
{
	if(m_icon == nullptr)
	{
		/*Subset*/
		m_icon.reset(new Subset<uml::Image, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_icon - Subset<uml::Image, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		m_icon->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_icon - Subset<uml::Image, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}

    return m_icon;
}