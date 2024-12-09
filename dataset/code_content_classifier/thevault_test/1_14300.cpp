std::shared_ptr<Bag<uml::PrimitiveType>> ExecutionFactoryImpl::getBuiltInTypes() const
{
	if(m_builtInTypes == nullptr)
	{
		m_builtInTypes.reset(new Bag<uml::PrimitiveType>());
		
		
	}

    return m_builtInTypes;
}