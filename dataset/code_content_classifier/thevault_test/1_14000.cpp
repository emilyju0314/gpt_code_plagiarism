void DecisionNodeActivationImpl::setNode(std::shared_ptr<uml::ActivityNode> _node)
{
	std::shared_ptr<uml::DecisionNode> _decisionNode = std::dynamic_pointer_cast<uml::DecisionNode>(_node);
	if(_decisionNode)
	{
		m_decisionNode = _decisionNode;

		//additional setter call for redefined reference ActivityNodeActivation::node
		fUML::Semantics::Activities::ActivityNodeActivationImpl::setNode(_node);
	}
	else
	{
		std::cerr<<"[DecisionNodeActivation::setNode] : Could not set node because provided node was not of type 'uml::DecisionNode'"<<std::endl;
	}
}