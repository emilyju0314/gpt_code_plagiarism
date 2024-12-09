ConditionalNodeImpl::ConditionalNodeImpl(std::weak_ptr<uml::ActivityGroup > par_superGroup)
:ConditionalNodeImpl()
{
	m_superGroup = par_superGroup;
	m_owner = par_superGroup;
}