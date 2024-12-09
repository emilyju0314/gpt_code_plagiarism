std::shared_ptr<Bag<uml::Element>> ConstraintImpl::getConstrainedElement() const
{
	if(m_constrainedElement == nullptr)
	{
		m_constrainedElement.reset(new Bag<uml::Element>());
		
		
	}

    return m_constrainedElement;
}