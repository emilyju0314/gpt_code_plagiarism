ProfileApplicationImpl::ProfileApplicationImpl(std::weak_ptr<uml::Package > par_applyingPackage)
:ProfileApplicationImpl()
{
	m_applyingPackage = par_applyingPackage;
	m_owner = par_applyingPackage;
}