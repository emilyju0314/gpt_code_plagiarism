void AddStructuralFeatureValueActionActivationImpl::setNode(std::shared_ptr<uml::ActivityNode> _node)
{
	std::shared_ptr<uml::AddStructuralFeatureValueAction> _addStructuralFeatureValueAction = std::dynamic_pointer_cast<uml::AddStructuralFeatureValueAction>(_node);
	if(_addStructuralFeatureValueAction)
	{
		m_addStructuralFeatureValueAction = _addStructuralFeatureValueAction;

		//additional setter call for redefined reference ActionActivation::action
		fUML::Semantics::Actions::ActionActivationImpl::setNode(_node);
	}
	else
	{
		std::cerr<<"[AddStructuralFeatureValueActionActivation::setNode] : Could not set node because provided node was not of type 'uml::AddStructuralFeatureValueAction'"<<std::endl;
	}
}