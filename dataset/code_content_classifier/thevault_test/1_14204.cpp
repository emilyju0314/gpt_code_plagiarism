TimeConstraintImpl::TimeConstraintImpl(std::weak_ptr<uml::Namespace > par_Namespace, const int reference_id)
:TimeConstraintImpl()
{
	switch(reference_id)
	{	
	case umlPackage::CONSTRAINT_ATTRIBUTE_CONTEXT:
		m_context = par_Namespace;
		m_namespace = par_Namespace;
		 return;
	case umlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
		m_namespace = par_Namespace;
		m_owner = par_Namespace;
		 return;
	default:
	std::cerr << __PRETTY_FUNCTION__ <<" Reference not found in class with the given ID" << std::endl;
	}
   
}