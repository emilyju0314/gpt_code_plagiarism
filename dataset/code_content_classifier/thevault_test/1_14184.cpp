std::shared_ptr<SubsetUnion<uml::InputPin, uml::InputPin>> InvocationActionImpl::getArgument() const
{
	if(m_argument == nullptr)
	{
		/*SubsetUnion*/
		m_argument.reset(new SubsetUnion<uml::InputPin, uml::InputPin >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_argument - SubsetUnion<uml::InputPin, uml::InputPin >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_argument->initSubsetUnion(getInput());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_argument - SubsetUnion<uml::InputPin, uml::InputPin >(getInput())" << std::endl;
		#endif
		
	}

    return m_argument;
}