SequenceNodeImpl::SequenceNodeImpl(std::weak_ptr<uml::ActivityGroup > par_superGroup)
:SequenceNodeImpl()
{
	m_superGroup = par_superGroup;
	m_owner = par_superGroup;
}