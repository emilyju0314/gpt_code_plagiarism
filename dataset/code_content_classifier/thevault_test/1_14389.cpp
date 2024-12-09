std::shared_ptr<Bag<uml::ExecutableNode>> SequenceNodeImpl::getExecutableNode() const
{
	if(m_executableNode == nullptr)
	{
		m_executableNode.reset(new Bag<uml::ExecutableNode>());
		
		
	}

    return m_executableNode;
}