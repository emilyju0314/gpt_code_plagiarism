void ReadStructuralFeatureActionActivationImpl::setNode(std::shared_ptr<uml::ActivityNode> _node)
{
	std::shared_ptr<uml::ReadStructuralFeatureAction> _readStructuralFeatureAction = std::dynamic_pointer_cast<uml::ReadStructuralFeatureAction>(_node);
	if(_readStructuralFeatureAction)
	{
		m_readStructuralFeatureAction = _readStructuralFeatureAction;

		//additional setter call for redefined reference ActionActivation::action
		fUML::Semantics::Actions::ActionActivationImpl::setNode(_node);
	}
	else
	{
		std::cerr<<"[ReadStructuralFeatureActionActivation::setNode] : Could not set node because provided node was not of type 'uml::ReadStructuralFeatureAction'"<<std::endl;
	}
}