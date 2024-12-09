StructuredActivityNodeImpl::StructuredActivityNodeImpl(std::weak_ptr<uml::ActivityGroup > par_superGroup)
:StructuredActivityNodeImpl()
{
	m_superGroup = par_superGroup;
	m_owner = par_superGroup;
}