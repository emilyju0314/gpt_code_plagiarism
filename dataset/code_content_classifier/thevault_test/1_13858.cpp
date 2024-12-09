ExceptionHandlerImpl::ExceptionHandlerImpl(std::weak_ptr<uml::ExecutableNode > par_protectedNode)
:ExceptionHandlerImpl()
{
	m_protectedNode = par_protectedNode;
	m_owner = par_protectedNode;
}