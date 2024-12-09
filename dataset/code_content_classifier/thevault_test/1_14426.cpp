void AddStructuralFeatureValueActionActivationImpl::setAction(std::shared_ptr<uml::Action> _action)
{
	std::shared_ptr<uml::AddStructuralFeatureValueAction> _addStructuralFeatureValueAction = std::dynamic_pointer_cast<uml::AddStructuralFeatureValueAction>(_action);
	if(_addStructuralFeatureValueAction)
	{
		m_addStructuralFeatureValueAction = _addStructuralFeatureValueAction;

		//additional setter call for redefined reference ActionActivation::action
		fUML::Semantics::Actions::ActionActivationImpl::setAction(_action);
	}
	else
	{
		std::cerr<<"[AddStructuralFeatureValueActionActivation::setAction] : Could not set action because provided action was not of type 'uml::AddStructuralFeatureValueAction'"<<std::endl;
	}
}