void ReadStructuralFeatureActionActivationImpl::setAction(std::shared_ptr<uml::Action> _action)
{
	std::shared_ptr<uml::ReadStructuralFeatureAction> _readStructuralFeatureAction = std::dynamic_pointer_cast<uml::ReadStructuralFeatureAction>(_action);
	if(_readStructuralFeatureAction)
	{
		m_readStructuralFeatureAction = _readStructuralFeatureAction;

		//additional setter call for redefined reference ActionActivation::action
		fUML::Semantics::Actions::ActionActivationImpl::setAction(_action);
	}
	else
	{
		std::cerr<<"[ReadStructuralFeatureActionActivation::setAction] : Could not set action because provided action was not of type 'uml::ReadStructuralFeatureAction'"<<std::endl;
	}
}