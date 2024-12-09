ExpansionActivationGroupImpl::ExpansionActivationGroupImpl(std::weak_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivation > par_containingNodeActivation)
:ExpansionActivationGroupImpl()
{
	m_containingNodeActivation = par_containingNodeActivation;
}