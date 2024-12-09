ClearAssociationActionImpl::ClearAssociationActionImpl(std::weak_ptr<uml::Activity > par_activity)
:ClearAssociationActionImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}