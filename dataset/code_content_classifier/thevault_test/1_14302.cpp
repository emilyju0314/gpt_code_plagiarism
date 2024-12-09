std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::OpaqueBehaviorExecution>> ExecutionFactoryImpl::getPrimitiveBehaviorPrototypes() const
{
	if(m_primitiveBehaviorPrototypes == nullptr)
	{
		m_primitiveBehaviorPrototypes.reset(new Bag<fUML::Semantics::CommonBehavior::OpaqueBehaviorExecution>());
		
		
	}

    return m_primitiveBehaviorPrototypes;
}