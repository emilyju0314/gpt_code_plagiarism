ExecutionOccurrenceSpecificationImpl::ExecutionOccurrenceSpecificationImpl(std::weak_ptr<uml::Namespace > par_namespace)
:ExecutionOccurrenceSpecificationImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}