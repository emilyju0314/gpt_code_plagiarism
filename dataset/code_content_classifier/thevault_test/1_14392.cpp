InformationFlowImpl::InformationFlowImpl(std::weak_ptr<uml::Package > par_owningPackage)
:InformationFlowImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}